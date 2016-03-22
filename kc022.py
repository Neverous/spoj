import sys
data = sys.stdin.read()
data = data.split(u'\n')
for line in data:
	if not line:
		continue

	line = line.split()
	which = int(line[0]) - 1
	numbers = list(reversed(sorted(list(set([int(n) for n in line[1:] if n])))))
	try:
		print numbers[which]

	except:
		print u'-'
