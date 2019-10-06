from socket import *
s = socket(AF_INET, SOCK_STREAM)
s.connect(("www.w3schools.com", 80))
s.send(bytes("GET /index.html HTTP/1.0\n\n", "utf-8"))

# data = s.recv(100)

## Receive & assemble all data
max_size = 1000
fragments = []
while True:
    chunk = s.recv(max_size)
    if not chunk:
        break
    fragments.append(str(chunk, "utf-8"))

data = "".join(fragments)
print(data)


s.close()