#mihik shah
#FY23B1D065
#Assignment 5B
#list of elements to calculate median
lst2=[67,36,84,57,389]
n=len(lst2)
#sorting the list
lst2.sort()
#finding median
if n%2==0:
  med1=lst2[n//2]
  med2=lst2[n//2 - 1]
  median=( med1 + med2)/2

else:
  median =lst2[n//2]

#printing output
print("the median element is : "+ str(median))
print("the maximum element is : "+ str(max(lst2)))
print("the minimum element is : "+ str(min(lst2)))
