import socket
import threading

HOST = "0.0.0.0"   # Listen on all network interfaces
PORT = 5000

def receive_messages(conn):
    while True:
        try:
            data = conn.recv(1024)
            if not data:
                break
            print(f"\nClient: {data.decode()}")
        except:
            break

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print(f"Server listening on port {PORT}...")

conn, addr = server.accept()
print(f"Client connected: {addr}")

# Receive in background
threading.Thread(target=receive_messages, args=(conn,), daemon=True).start()

# Send messages
while True:
    message = input("Server: ")

    if message.lower() == "exit":
        break

    conn.sendall(message.encode())

conn.close()
server.close()