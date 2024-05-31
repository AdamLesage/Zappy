import socket
import threading
import time
import sys
sys.path.append("..")
from models.Agent import Agent
import unittest

def find_available_port():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('localhost', 0))
    port = sock.getsockname()[1]
    sock.close()
    return port

def create_server(port, backlog):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', port))
    server.listen(backlog)
    return server

class ServerThread(threading.Thread):
    def __init__(self, port):
        threading.Thread.__init__(self)
        self.server = create_server(port, 1)
        self.client_socket = None
        self.running = True
        self.lock = threading.Lock()

    def run(self):
        self.server.settimeout(1)
        start_time = time.time()
        while self.running:
            try:
                with self.lock:
                    if not self.running:
                        break
                    client_socket, addr = self.server.accept()
                with self.lock:
                    if self.running:  # Check if still running after accept
                        self.client_socket = client_socket
                        client_socket.sendall(b"WELCOME\n")
                        client_socket.sendall(b"19\n15 15\n")
                        client_socket.sendall(b"look\n")
                        time.sleep(1)
                        client_socket.sendall(b"dead\n")
            except socket.timeout:
                continue
            if time.time() - start_time >= 2:
                self.stop()

    def stop(self):
        with self.lock:
            self.running = False
            if self.server:
                self.server.close()
            if self.client_socket:
                self.client_socket.close()

class TestAgent(unittest.TestCase):
    def test01_createAgent(self):
        """Test the creation of an agent"""
        agent = Agent(4242, "Team1")
        self.assertEqual(agent.port, 4242)
        self.assertEqual(agent.team_name, "Team1")
        self.assertEqual(agent.ip, "localhost")
        self.assertEqual(agent.client, None)
        self.assertEqual(agent.agentInfo.world_width, 0)
        self.assertEqual(agent.agentInfo.world_height, 0)

    def test02_executeCommand(self):
        """Test the execution of a command"""
        # Get an available port
        port = find_available_port()
        server_thread = ServerThread(port)
        server_thread.start()

        time.sleep(1)  # Give the server a moment to start

        try:
            agent = Agent(port, "Team1")
            agent.connect_to_server()
        finally:
            server_thread.stop()

# if __name__ == "__main__":
#     unittest.main()
