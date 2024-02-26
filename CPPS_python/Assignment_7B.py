#mihik shah
#FY23B1D065
class square():
  def __init__(self,length):

    self.length=length
  def area(self):
    return self.length*self.length
a=int(input("Enter length of square: "))

obj=square(a)
print("Area of square:",obj.area())
print()