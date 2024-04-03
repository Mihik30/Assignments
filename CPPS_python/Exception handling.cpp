/******************************************************************************

1. Write a C++ program that prompts the user to input two integers and then performs division.
Handle the division by zero exception using try-catch blocks and display an appropriate error message.
Use try-catch blocks to handle the exception.Display a meaningful error message if the user attempts to divide by zero.
Ensure that the program continues to execute after handling the exception.

*******************************************************************************/



#include <iostream>
using namespace std;
int main()
{
    int a,b;
    start:
        cout<<"Enter Two Numbers : ";
        cin>>a>>b;
        try
        {
            
            if(b<=0)
            {
                throw b;
            }
            else
            {
                int result = a/b;
                cout<<result<<endl;
            }
        }
        catch(int a)
        {
            //do{
                cout<<"Division by 0 not possible"<<endl;//<<endl<<"Enter a new number : ";
                // cin>>b;
                goto start;
            //}while(b!=0);
        }

    return 0;
}


/******************************************************************************

2. Create a C++ program for a library management system. Implement a class Book with attributes like book ID, title, and author. 
Implement a checkout method that throws a custom exception BookUnavailableException if the book is already checked out. 
Handle this exception appropriately in the main program.
Define a custom exception class BookUnavailableException.Implement a method checkout() in the Book class that throws BookUnavailableException 
if the book is already checked out.Handle the exception in the main program using try-catch blocks.Provide a user-friendly message when the exception occurs.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;
class book
{
    protected:
        int book_id,book_id1;
        string author,title,author1,title1;
    public:
       book()
       {
           book_id = 1045;
           author = "Jeffrey Archer";
           title = "Honour Among Thieves";
           book_id1 = 1046;
           author1 = "Naval Ravikant";
           title1 = "The Almanack Of Naval Ravikant";
       }
        void print_0()
        {
            cout<<"book Id : "<<book_id<<endl<<"Author : "<<author<<endl<<"Title : "<<title<<endl;
        }
        void print_1()
        {
            cout<<"book Id : "<<book_id1<<endl<<"Author : "<<author1<<endl<<"Title : "<<title1<<endl;
        }
};
class BookUnavailableException : public book
{
    public:
        void checkout()
        {
            cout<<"You have checked out the following :"<<endl;
        }
};
int main()
{
    BookUnavailableException b;
    int i;
    cout<<"Welcome to library!"<<endl;
    start:
        try
        {
            cout<<"Your Options for checkout are: "<<endl;
            b.print_0();
            b.print_1();
            cout<<"Enter the book you want to check out (1 for first , 2 for second)"<<endl;
            cin>>i;
            if(i==1)
            {
                b.checkout();
                b.print_0();
            }
            else if(i == 2)
            {
                b.checkout();
                b.print_1();
            }
            else
            {
                throw i;
            }
        }
        catch(int x)
        {
            cout<<"BookUnavailableException!"<<endl;
            goto start;
        }
    return 0;
}

 /******************************************************************************
 
 3.Implement a program to handle Arithmetic exception, Array Index Out of Bounds. 
 The user enters two numbers Num1 and Num2. The division of Num1 and Num2 is displayed. 
 If Num1 and Num2 are not integers, the program would throw a Number Format Exception. 
 If Num2 were zero, the program would throw an Arithmetic Exception. 
 Display the exception
 
 *******************************************************************************/
#include<iostream>
using namespace std;
class arr
{
    private:
        int ar[100],n,k;
    public:
        void get_array()
        {
            cout<<"Enter the size of array: ";
            cin>>n;
            for(int i = 0 ; i < n ; i++)
            {
                cin>>ar[i];
            }
        }
        void outofbound()
        {
            try
            {
                cout<<endl<<"Enter the position you want to print : ";
                cin>>k;
                if(k>n)
                {
                    throw k;
                }
                else
                    cout<<ar[k-1];
            }
            catch(int)
            {
                cout<<"Array Index Out of Bounds"<<endl;
                outofbound();
            }
        }
};
class nums
{
    private:
        int num1,num2;
    public:
        void get_num()
        {
            cout<<endl<<"Enter two numbers : ";
            cin>>num1>>num2;
        }
        void check_int()
        {
            try
            {   
                if(num2!=0)
                {
                    float Division = num1/num2;
                    cout<<"Division is : "<<Division<<endl;
                    //throw num2;
                }
                else
                {
                    throw num2;
                }
                
                if(num1 || num2 != int(num1) || int(num2))
                {
                    throw "c";
                }
                // else
                // {
                //     throw num2;
                //     // int Division = num1/num2;
                //     // cout<<"Division is : "<<Division<<endl;
                // }    
            }
            catch(char)
            {
                cout<<"Number Format Exception"<<endl;
                get_num();
                //throw;
            }
            catch(int)
            {
                cout<<"Arithmetic Exception"<<endl;
                get_num();
                //throw;
            }
        }
};
int main()
{
    arr a;
    a.get_array();
    a.outofbound();
    nums n;
    n.get_num();
    n.check_int();
    // try
    // {
    //     n.get_num();
    //     n.check_int();
    // }
    // catch(...)
    // {
    //     n.get_num();
    //     n.check_int();
    // }
    
    return 0;
}


/******************************************************************************

4. Create a C++ class named Television that has data members to hold the model number and the screen size in inches, and the price. 
If more than four digits are entered for the model, if the screen size is smaller than 12 or greater than 70 inches, 
or if the price is negative or over $5000 then throw an integer. Write a main() function that instantiates a television object, 
allows user to enter data and displays the data members .If an exception is caught, replace all the data member values with zero values

*******************************************************************************/
#include <iostream>
using namespace std;
class television
{
    private:
        int model_numebr1,screen_size1,price1;
    public:
        television(int model_numebr, int screen_size ,int price)
        {
            model_numebr1=model_numebr;
            screen_size1=screen_size;
            price1=price;
            model_numebr1=0;
            screen_size1=0;
            price1=0;
        }
        void print_data()
        {
            cout<<endl<<"Model numebr : "<<model_numebr1;
            cout<<endl<<"Screen size : "<<screen_size1;
            cout<<endl<<"Price : "<<price1;
        }
};
int main()
{
    int model_numebr,screen_size,price;
    cout<<"Enter model numebr : ";
    cin>>model_numebr;
    cout<<"Enter screen size : ";
    cin>>screen_size;
    cout<<"Enter price : ";
    cin>>price;
    
    try
    {
        if(model_numebr>=1000 || screen_size<12 || screen_size>70 || price<0 || price>5000)
        {
            throw television(model_numebr,screen_size,price);
        }
        else
        {
            cout<<"No exception caught!";
            cout<<endl<<"Model numebr : "<<model_numebr;
            cout<<endl<<"Screen size : "<<screen_size;
            cout<<endl<<"Price : "<<price;
        }
    }
    catch(television t)
    {
        cout<<"exception caught successfully!";
        t.print_data();
    }

    return 0;
}
