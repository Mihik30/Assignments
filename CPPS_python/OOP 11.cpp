#include <iostream>
#include <string>
using namespace std;
class person
{
    private:
        int code;
        string name;
    public:
        person()
        {
            code=1;
            name="n";
        }
        void get_name()
        {
            cout<<"Enter your name : ";
            cin>>name;
        }
        void get_code()
        {
            cout<<"Enter your code :";
            cin>>code;
        }
        string print_name()
        {
            return name;
        }
        int print_code()
        {
            return code;
        }
};
class account:virtual public person
{
    private:
        int pay;
    public:
        // account()
        // {
        //     pay=0;
        // }
        account(int a)
        {
            pay = a;
        }
        int print_pay()
        {
            return pay;
        }
        void payexp2(int x)
        {
            pay=x;
        }
};
class admin:virtual public person
{
    private:
        int experience;
    public:
        // admin()
        // {
        //     experience = 0;
        // }
        admin(int b)
        {
            experience = b;
        }
        int print_experience()
        {
            return experience;
        }
        void payexp(int y)
    {
       //pay=x;
       experience=y;
        
    }
};
class master : public admin , public account
{
    public:
    void print_current_data()
    {
        cout<<endl<<"Your name is : "<<print_name()<<endl;
        cout<<"Your code is : "<<print_code()<<endl;
        cout<<"Your pay is : "<<print_pay()<<endl;
        cout<<"Your experience is : "<<print_experience()<<endl;
    }
    void change(int x,int y)
    {
         payexp2(x);
        payexp(y);
    }
    master(int a , int b):admin(a),account(b){}
    
};
int main()
{
    int x,y,k;
    
    master m(0,0);
    m.get_name();
    m.get_code();
    m.print_current_data();
    // do
    // {
    //     cout<<"Enter your pay: ";
    //     cin>>x;
    //     cout<<"Enter your experience: ";
    //     cin>>y;
    // }
    //m(20,40);
    cout<<endl<<"Do you wan to change your details?\npress 1 to change or 2 to exit";
    cin>>k;
    if(k==1)
    {
        cout<<"Enter your pay: ";
        cin>>x;
        cout<<"Enter your experience: ";
        cin>>y;
       // master m1(x,y);
        //m=m1;
       m.change(x,y);
        m.print_current_data();
    }
    else if(k==2)
    {
        goto end;
    }
    else
    {
        cout<<"Enter an valid option";
    }
    
    end:
        cout<<"Thank you for working with us!";
    return 0;
}
