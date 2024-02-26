#mihik shah
#FY23B1D065
def convert():
  #taking input whether to find farhenheit or celcius
  print('''
  choose the option for which you have to find the value of
  1. Farhenheit
  2. Celcius''')
  opt=int(input())
  #if else iteration to find the value
  if (opt==1):#to find value in farhenheit
    print("Converting Celcius to farhenheit")
    print("enter values in celcius")#taking input
    celc=float(input())
    farh=(celc*(9/5))+32#conversion
    print("the value in fahrenheit",farh)#displaying output
  elif (opt==2):#to find value in celcius
    print("Converting farhenheit to Celcius")
    print("enter values in fahrenheit")#taking input
    farh=float(input())
    celc=(farh-32)*(5/9)#conversion
    print("the value in celcius",celc)#displaying output
  else:
    print("wrong input")#default case for inputs other than 1 and 2
#driver code
convert()#function calling