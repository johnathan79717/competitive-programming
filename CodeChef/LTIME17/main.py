T = int(input())

for t in range(T):
	N = int(input())
	S = input()
	done = False
	for s in S:
		if s == 'Y':
			print('NOT INDIAN')
			done = True
			break
		elif s == 'I':
			print('INDIAN')
			done = True
			break
	if not done:
		print('NOT SURE')