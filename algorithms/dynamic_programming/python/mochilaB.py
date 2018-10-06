def knapsack(capacidade, pesos, valores, itens):

	matrix = []
	
	for i in range(itens + 1):
		
		matrix.append([])
		
		for j in range(capacidade + 1):
			
			matrix[i].append(0)
			
	
	
	for i in range(1,itens + 1):
		
		for j in range(1,capacidade + 1):
			
			if j >= pesos[i]:
				

				matrix[i][j] = max(matrix[i-1][j], valores[i] + matrix[i-1][j-pesos[i]])
				
			else:

				matrix[i][j] = matrix[i-1][j]
			
	return matrix[itens][capacidade]
		

print knapsack(8, [0,4,2,1,1], [0,10,2,1,2], 4)
