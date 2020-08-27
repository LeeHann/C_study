#%%
import socket

#tcp 서버 객체
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind(("127.0.0.1", 8282))
server_socket.listen(5)

while True :
  print('wait connect')
  client_socket,addr = server_socket.accept()
  print(f'connect {addr}')

  print('wait data')
  data = client_socket.recv(1024)
  print(f'received : {addr} : {data.decode()}')

  resstr = 'HTTP/1.1 200 OK\r\n'

  resstr += 'Content-Type: text/plain\r\n\r\n'
  resstr += 'hello text'
  
  # resstr += 'Content-Type: text/html\r\n\r\n'
  # resstr += '<!DOCTYPE HTML>\r\n'
  # resstr += '<html>\r\n'
  # resstr += '<h1>hello http</h1>'
  # resstr += '<html>\r\n'
  
  client_socket.sendall(resstr.encode())
  client_socket.close()
# %%
