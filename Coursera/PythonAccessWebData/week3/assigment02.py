#!/usr/bin/python2.7
import urllib
from BeautifulSoup import *

url = raw_input('Enter URL: ')
count = int(raw_input('Enter count: '))
pos = int(raw_input('Enter position: '))
print "Retrieving: %s" %(url)

for i in range(count):
    html = urllib.urlopen(url).read()
    soup = BeautifulSoup(html)

# Retrieve all of the anchor tags
    tags = soup('a')
    url = tags[pos-1].get('href', None)
    print "Retrieving: %s" %(url)
