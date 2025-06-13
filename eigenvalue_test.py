import numpy as np

matrix = [[4, 2], [1, 3]]
eigenvalues, eigenvectors = np.linalg.eig(matrix)

print("Matrix:")
print(matrix)
print()
print("Eigenvalues:")
print(eigenvalues)
print()
print("Eigenvectors:")
print(eigenvectors)
