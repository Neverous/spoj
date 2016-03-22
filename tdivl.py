import sys
data = sys.stdin.read()
data = data.split(u'\n')
numbers = int(data[0])
for n in xrange(numbers):
	a, b = data[n + 1].split(u' ')
	a = int(a)
	b = int(b)
	if a / b * b == a:
		print "TAK"

	else:
		print "NIE"
