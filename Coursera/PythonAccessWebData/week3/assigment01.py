#!/usr/bin/python2.7

import urllib 
from BeautifulSoup import *

url = raw_input('Enter -')
html = urllib.urlopen(url).read()

soup = BeautifulSoup(html)
tags = soup('span')

sum = 0
for tag in tags:
    #print tag
    #print tag.get('href', None)
    sum += int(tag.contents[0])
    #print tag.attrs

print sum
