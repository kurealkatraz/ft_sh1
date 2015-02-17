import sys

f = open('bin', 'rwU')

for line in f:
	i = 0
	while line[i] != '\n':
		sys.stdout.write(line[i])
		i += 1
	sys.stdout.write(':')
	sys.stdout.write('/opt/X11/bin/')
	print line,

f.close()
