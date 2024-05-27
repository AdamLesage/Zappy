##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## data_encryption
##

def encrypt_data(data: str, key: str) -> str:
    """Encrypt data with a given key"""
    encrypted_data = ""
    for i in range(len(data)):
        encrypted_data += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    return encrypted_data

def decrypt_data(data: str, key: str) -> str:
    """Decrypt data with a given key"""
    decrypted_data = ""
    for i in range(len(data)):
        decrypted_data += chr(ord(data[i]) ^ ord(key[i % len(key)]))
    return decrypted_data
