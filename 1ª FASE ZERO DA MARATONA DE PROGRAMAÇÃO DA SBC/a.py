n = int(input())

for _ in range(n):
	nome = input()
	notas = list(map(float, input().split(' ')))

	print(nome, end=": ")
	if len(notas) == 1:
		print("%.1f"%(notas[0]/2))
	else:
		if len(notas) == 4:
			notas.sort()
			del notas[0]

		print("%.1f"%(sum(notas)/len(notas)))
