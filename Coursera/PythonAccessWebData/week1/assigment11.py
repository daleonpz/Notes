import urllib2
import re

#data = urllib2.urlopen('http://python-data.dr-chuck.net/regex_sum_42.txt')
data = urllib2.urlopen('http://python-data.dr-chuck.net/regex_sum_304523.txt')
total = 0

for line in data:
	num = map(int, re.findall('[0-9]+',line) )
	total += sum(num)

print total
