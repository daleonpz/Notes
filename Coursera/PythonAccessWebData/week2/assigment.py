#!/usr/bin/python2.7

import socket
import re

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('www.pythonlearn.com',80))

mysock.send('GET /code/intro-short.txt HTTP/1.1\n')
mysock.send('Host: www.pythonlearn.com\n\n')

while True:
    data = mysock.recv(4096)
    if ( len(data) < 1 ) :
        break

    line = re.findall(
        'Content-Type.*|Content-Length.*|Last-Modified.*|ETag.*|Cache-Control.*',
        data);
    if( line !=[] ):
        print line

mysock.close()
