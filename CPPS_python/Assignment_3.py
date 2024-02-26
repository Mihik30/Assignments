#mihik shah
#FY23B1D065
# Python3 code to demonstrate working of
#declaring a string
string= 'pccoe2023'

#printing orignal string
print('The orignal string is: ' + string)

# Initializing right rotate
right_rot = int(input("enter the value for rotating string towards right"))

# Initializing left rotate
left_rot = int(input("enter the value for rotating string towards right"))

# Right and Left Shift characters in String
# Using String multiplication and string slicing
result = (string * 3)[len(string) + right_rot - left_rot: 2 * len(string) + right_rot - left_rot]

# Printing result
print("The string after rotation is : " + str(result))
