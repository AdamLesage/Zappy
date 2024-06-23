#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "USAGE: $0 host port"
    exit 0
fi

USERNAME="Anonymous"
PASS=""

HOST=$1
PORT=$2
MKFIFO=`which mkfifo`
TAIL=`which tail`
NC="`which nc` -C"
TIMEOUT=1 #max time before reading server response

getcode()
{
  local OUT=$1
  sleep $TIMEOUT
  local data=`$TAIL -n 1 $OUT`
  echo "$data"
  return $data
}

print_failed()
{
    echo "$1 test failed"
    echo "Expected reply: $2"
    echo "Received : ["`$TAIL -n 1 $3 | cat -e`"]"
    echo "KO"
}

print_succeeded()
{
  echo "$1 test succeeded"
  echo "OK"  
  kill_client "$2" "$3" 2>&1 >/dev/null
}

launch_client()
{
  local host=$1
  local port=$2
  local PIPE=$3
  local OUT=$4

  $MKFIFO $PIPE
  ($TAIL -f $PIPE 2>/dev/null | $NC $host $port &> $OUT &) >/dev/null 2>/dev/null

  sleep $TIMEOUT
  local reply=$(getcode "$OUT")
  echo "$reply"
  if [[ "$reply" == *"WELCOME"* ]]; then
    return 1
  else
    echo "Connection to $host:$port failed"
    echo "Received : ["`$TAIL -n 1 $OUT |cat -e`"]"
    return 0
  fi
}

launch_test_expected()
{
  local test_name=$1
  local cmd=$2
  local expected=$3
  local PIPE=$4
  local OUT=$5

  echo "Sending [$cmd^M$]"
  echo "$cmd" >$PIPE
  local reply=$(getcode "$OUT")
  if [[ "$reply" != *"$expected"* ]]; then
    kill_client "$PIPE" "$OUT"
    clean "$PIPE" "$OUT"
    return 1
  fi
}

launch_test()
{
  local test_name=$1
  local cmd=$2
  local PIPE=$3
  local OUT=$4

  echo "Sending [$cmd^M$]"
  echo "$cmd" >$PIPE
}

kill_client()
{
  local PIPE=$1
  local OUT=$2
  local nc=`which nc`

  if [ `pidof $TAIL | wc -l` -ne 0 ]; then
    killall $TAIL &>/dev/null
  fi
  if [ `pidof $nc | wc -l` -ne 0 ]; then
    killall $nc &>/dev/null
  fi  
  rm -f $PIPE $OUT &> /dev/null
}

clean()
{
  local PIPE=$1
  local OUT=$2
  rm -f $PIPE $OUT log &>/dev/null
}

# Simple authentication
test00()
{
  local test_name="Authentication"
  local client_id=$1

  local PIPE="fifo_$client_id"
  local OUT="outfile_$client_id"

  local cmd1=$'name1\n'
  local expected1=$'9\n10 10\n'

  launch_client $HOST $PORT "$PIPE" "$OUT"
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  launch_test_expected "$test_name" "$cmd1" "$expected1" "$PIPE" "$OUT"
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  print_succeeded "$test_name" "$PIPE" "$OUT"
  return 0
}

testclient()
{
  local test_name="Authentication"
  local client_id=$1

  local PIPE="fifo_$client_id"
  local OUT="outfile_$client_id"

  local cmd1=$'name1\n'
  local expected1=$'9\n10 10\n'

  launch_client $HOST $PORT "$PIPE" "$OUT"
  if [[ ! $? -eq 1 ]]; then
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  launch_test "$test_name" "$cmd1" "$PIPE" "$OUT"
  kill_client "$PIPE" "$OUT"
  return 0
}

multi_client_test_parallel()
{
  local client_count=$1
  local pids=()

  for ((i=1; i<=client_count; i++)); do
    testclient $i &
    pids+=($!)
  done

  for pid in "${pids[@]}"; do
    wait $pid || {
      echo "A client test failed."
      return 1
    }
  done
  print_succeeded "multi_client_test" "$PIPE" "$OUT"
}

test_split_command()
{
  local test_name="split_commande"
  local client_id=$1

  local PIPE="fifo_split"
  local OUT="outfile_split"

  local cmd=$'na'
  local cmd2=$'me1\n'
  local expected=$'9\n10 10\n'


  launch_client $HOST $PORT "$PIPE" "$OUT"
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  launch_test "$test_name" "$cmd1" "$PIPE" "$OUT"
  launch_test_expected "$test_name" "$cmd1" "$exepcted" "$PIPE" "$OUT"


  if [[ ! $? -eq 1 ]]; then
    echo "ko $test_name"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  print_succeeded "$test_name" "$PIPE" "$OUT"
  return 0
}

test_command()
{
  local test_name="command"

  local PIPE="fifo_command"
  local OUT="outfile_command"

  local cmd1=$'name1\n'

  launch_client $HOST $PORT "$PIPE" "$OUT"
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  launch_test "$test_name" "$cmd1" "$PIPE" "$OUT"
  for ((i=1; i<=1000; i++)); do
    launch_test "$test_name" "Forward" "$PIPE" "$OUT"
  done
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client "$PIPE" "$OUT"
    return 1
  fi

  print_succeeded "$test_name" "$PIPE" "$OUT"
  kill_client "$PIPE" "$OUT"
  return 0
}

# Run the multi-client test with a specified number of clients
CLIENT_COUNT=10
test00 1
multi_client_test_parallel $CLIENT_COUNT
test_split_command 1
test_command