import socket
import threading

def handle_client(client_socket, address):
    echo_req = client_socket.recv(1024)
    print(f"[-] Received from {address} : {echo_req.decode('utf-8')}")
    client_socket.send(echo_req)
    client_socket.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', 8888))
    server_socket.listen()
    print()
    print("[#] Server listening on port 8888.... ")
    while True:
        client_socket, address = server_socket.accept()
        print()
        print(f"[!] Connected with {address}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket, address))
        client_handler.start()

def main():
    start_server()

if __name__=="__main__":
    main()

