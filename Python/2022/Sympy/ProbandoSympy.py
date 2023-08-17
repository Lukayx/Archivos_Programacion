from sympy import *
init_printing()

x = symbols("x")
y = Function("y")

print(diff(y(x)) - 9*x + 7*x)

x = input()

asd = scal