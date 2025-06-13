import math

# Basic eigenvalue example (2x2 matrix only)
a, b, c, d = 4, 2, 1, 3

print(f"Matrix: [[{a}, {b}], [{c}, {d}]]")

# For 2x2 matrix, eigenvalues are roots of: λ² - (a+d)λ + (ad-bc) = 0
trace = a + d
det = a*d - b*c

print(f"Characteristic equation: λ² - {trace}λ + {det} = 0")

# Using quadratic formula
discriminant = trace**2 - 4*det
lambda1 = (trace + math.sqrt(discriminant)) / 2
lambda2 = (trace - math.sqrt(discriminant)) / 2

print(f"Eigenvalue 1: {lambda1}")
print(f"Eigenvalue 2: {lambda2}")