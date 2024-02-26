#mihik shah
#FY23B1D065
#Assignment 6B
# Python code to demonstrate naive
# method to compute gcd ( recursion )
def hcf(a, b):
  if(b == 0):
    return a
  else:
    return hcf(b, a % b)
a = 6086
b = 498
# prints output
print("The gcd is : ", end="")
print(hcf(6086, 498))
