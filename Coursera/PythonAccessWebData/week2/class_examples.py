#!/usr/bin/python2.7

import socket
# AF_INET ,internet socket,  SOCK_STREAM to send data
# open a socket of my PC
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# connect to server
mysock.connect(('www.py4inf.com',80))

# HTTP/1.0 web protocol
mysock.send('GET http://www.py4inf.com/code/romeo.txt HTTP/1.0\n\n')

while True:
    # up to 512 character at a time
    data = mysock.recv(512)
    if ( len(data) <1 ):
        break
    print data
mysock.close()

##### using urllib
import urllib
fhand = urllib.urlopen('http://www.py4inf.com/code/romeo.txt ')

for line in fhand:
    print line.strip()
