#mihik shah
#FY23B1D065
#Assignment 5C
#list of elements to calculate mode
lst3=[1,1,1,2,2,2,2,3,3,4,5,6,7,7,7,7,7,7,8,8,00,000]

#creating empty list
unique=[]
mode=[]

#finding mode
for i in lst3:
  if i not in unique:
    unique.append(i)
  else:
    mode.append(i)
    unique.remove(i)

print("the mode values are : "+ str(mode))
print("the unique values are : "+ str(unique))