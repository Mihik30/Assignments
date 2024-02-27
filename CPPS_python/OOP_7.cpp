//7A1
#include<iostream>
using namespace std;
class complex
{
    int real;
    int imag;
    public:
    complex()
    {
        real=5;
        imag=6;
    }
    complex(int x,int y)
    {
        real=x;
        imag=y;
    }
    friend complex operator +(complex,complex);
    void display()
    {
        cout<<"the sum of complex value is: ";
        cout<<real<<"+"<<imag<<"i";
    }
};
complex operator +(complex c1,complex c2)
{
    complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag +c2.imag;
    return c3;
}
int main()
{
    cout<<"---------------------------------------"<<endl;
    int x,y;
    int m,n;
    cout<<"the value pass for c1 is: ";
    cin>>x>>y;
    cout<<endl<<"the value pass for c2 is: ";
    cin>>m>>n;
    complex c1,c2,c3;
    c1=complex(x,y);
    c2=complex(m,n);
    c3=c1+c2;
    cout<<"---------------------------------------"<<endl;
    c3.display();
    cout<<endl<<"---------------------------------------"<<endl;
    return 0;
}





//7A2
#include<iostream>
using namespace std;
class shape
{
    public:
    float area(float radius)
    {
        float pi=3.14;
        float circle;
        circle=3.14*radius*radius;
        return circle;
    }
    float area(int length,int breadth)
    {
        int rectangle;
        rectangle=length*breadth;
        return rectangle;
    }
    float area(float base,float height)
    {
        float triangle;
        triangle=0.5*base*height;
        return triangle;
    }
};

int main()
{
    shape s;
    // s.getdata();
    float M=s.area(2.33f);
    float N=s.area(2,4);
    float O=s.area(5.4f,3.7f);
    cout<<"area is: "<<M<<"\n"<<"area is: "<<N<<"\n"<<"area is: "<<O<<"\n";
}





//7B1

#include<iostream>
using namespace std;
class mihik
{
float num;
public:
void getdata()
{
cout<<"\n-------------------------------------------------\n";
cout<<"enter the decimal num: ";
cin>>num;
cout<<"\n-------------------------------------------------"; 
}
friend mihik convert(mihik);
};
mihik convert(mihik s)
{
int k;
k=s.num;
int temp=k;
if(k==0)
{
cout<<"binary number is:0";
cout<<"\n-------------------------------------------------";
 }
int binary[20],i=0,j;
while(k>0)
{
binary[i]=k%2;
k/=2;
i++;
}
cout<<"\n the conversion of decimal number of "<<temp<<" to binary number: ";
for(j=i-1;j>=0;j--)
{
cout<<binary[j];
}
cout<<"\n-------------------------------------------------";
return s;
}
int main()
{
mihik n;
n.getdata();
convert(n);
return 0;
}





//7B2

#include<iostream>
#include<string>
using namespace std;
class bank_account
{
string holder_name;
int account_no;
int balance;
public:
void getdata()
{
cout<<"-------------------------------------\n";
cout<<" name of account holder: ";
cin>>holder_name;
cout<<" account number: ";
cin>>account_no;
cout<<" balance: ";
cin>>balance;
}
friend class bank_manager;
};
class bank_manager
{
public:
void display(bank_account b1)
{
b1.getdata();
cout<<"------------------------------------\n";
cout<<"holder name: "<<b1.holder_name;
cout<<"\n account number:"<<b1.account_no;
cout<<"\n balance:"<<b1.balance;
cout<<"\n------------------------------------\n";
}
};
int main()
{
bank_account b1;
bank_manager m1;
m1.display(b1);
}

