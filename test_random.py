import random
print 5
for i in range(5):
	n = random.randint(1, 5)
	k = random.randint(1, 1000000000)
	print n, k
	for i in range(n):
		print random.randint(1, 1000000000)