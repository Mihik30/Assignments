//4A) Write a C++ program to sort a list of numbers in ascending order.

#include<iostream>
using namespace std;
class mihik
{
int n,arr[1000];
public:
void getdata()
{
cout<<"Enter the no. of array element:";
cin>>n;
for (int i=0;i<n;i++)
{
cout<<"Enter array element of "<<i<<":";
cin>>arr[i];
}
}
void sorting()
{
int i,j;
for (i=n-1;i>0;i--)
{
for(j=0;j<i;j++)
{
if(arr[j+1]<arr[j])
{
int temp;
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
Void showdata()
{
for (int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
}
};
int main()
{
mihik P1;
P1.getdata();
P1.sorting();
P1.showdata();
return 0;
}


//4B1)WAP to Dynamically allocate memory for 10 integers using new.

#include <iostream>
using namespace std;
int main() 
{
int *p[10];
for (int i=0;i<10;i++)
{
p[i]=new int[10];
}
for (int j=0;j<10;j++)
{
cout<<"Enter the number of "<<j<<"th position:";
cin>>*p[j];
}
for (int j=0;j<10;j++)
{
cout<<*p[j]<<" ";
}
return 0;
}


//4B2) WAP to C++ Program to store GPA of n number of students and display it
using new and also deallocate the memory using delete.

#include <iostream>
using namespace std;
class student
{
float GPA;
int roll;
public:
student()
{
GPA=0;
roll=0;
}
void getdata()
{
cout<<"Enter the roll of student:";
cin>>roll;
cout<<"Enter GPA of student:";
cin>>GPA;
}
void display()
{
cout<<roll<<endl<<GPA<<endl;
}
};
int main()
{
int i=0;
int n=1;
student *s[60];
do{
s[i]=new student();
s[i]->getdata();
s[i]->display();
cout<<"Do you want to continue?";
cin>>n;
i++;
}while(n==1);
delete s[i-1];
cout<<s[i];
return 0;
}
