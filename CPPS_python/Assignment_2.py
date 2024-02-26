#mihik shah
#FY23B1D065
#fibonacci series
first=0
second=1
avg=1
#terms=int(input("enter the terms"))
terms=10
if(terms<=0):
  print("please enter positive integers ")

elif(terms==1):
  print("fibonacci series--",0)
  
else:
  print("fibonacci series is")
  print(first)
  print(second)
  for i in range(terms-2):
    next=first+second
    first=second
    second=next
    avg=avg+next
    print(next)
print("average:",avg/10)