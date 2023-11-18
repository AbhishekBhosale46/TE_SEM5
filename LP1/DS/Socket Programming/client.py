import socket

def send_data():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('127.0.0.1', 8888))
    print()
    message = input("Enter message to echo : ")
    client_socket.send(message.encode('utf-8'))
    response = client_socket.recv(1024)
    print(f"[!] Received echo from server : {response.decode('utf-8')}")
    print()
    client_socket.close()

def main():
    send_data()

if __name__ == "__main__":
    main()