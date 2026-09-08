import socket
import threading

SERVER_IP = "192.168.1.100"  # Change this
PORT = 5000

def receive_messages(sock):
    while True:
        try:
            data = sock.recv(1024)
            if not data:
                break
            print(f"\nServer: {data.decode()}")
        except:
            break

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((SERVER_IP, PORT))

print("Connected to server!")

# Receive in background
threading.Thread(
    target=receive_messages,
    args=(client,),
    daemon=True
).start()

# Send messages
while True:
    message = input("Client: ")

    if message.lower() == "exit":
        break

    client.sendall(message.encode())

client.close()