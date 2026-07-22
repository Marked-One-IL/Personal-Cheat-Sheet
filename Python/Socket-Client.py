import socket

ADDRESS = ""
PORT = 0

def recvall(s, n):

    data = bytearray()
    while len(data) < n:
        remaining = n - len(data)
        chunk = s.recv(min(remaining, 4096))
        if not chunk: return None
        data.extend(chunk)

    return bytes(data)

def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ADDRESS, PORT))

    s.sendall("Hello, World!\n".encode(errors="ignore"))
    s.send("Hello, World!\n".encode(errors="ignore"))
    reponse = s.recv(1024).decode(errors="ignore")
    reponse2 = recvall(s, 1024).decode(error="ignore")

if __name__ == "__main__":
    main()