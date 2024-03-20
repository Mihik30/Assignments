#include <iostream>
using namespace std;
class account
{
    private:
        int accout_number,type_of_account;
        char name[10];
    public:
        // void get_balance()
        // {
        //     cout<<"Enter the amount you want to deposit: ";
        //     cin>>balence;
        // }
        void get_name()
        {
            cout<<"Enter your name: ";
            cin>>name;
        }
        void get_accountno()
        {
            cout<<"Enter your account number: ";
            cin>>accout_number;
        }
        // void display_balance()
        // {
        //     cout<<"Balance: "<<balance;
        // }
        void display_name()
        {
            cout<<"Name: "<<name<<endl;
        }
        void display_accountno()
        {
            cout<<"Account number: "<<accout_number<<endl;
        }
        void details()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Account number: "<<accout_number<<endl;
        }
    
};
class current : public account
{
    private:
        int balance;//,checkbook;
    public:
        void get_balance()
        {
            cout<<"Enter the amount you want to deposit: ";
            cin>>balance;
        }
        void display_balance()
        {
            cout<<"Balance: "<<balance<<endl;
        }
        void display_mini_balance()
        {
            if(balance<200)
            {
                cout<<"There must be minimum of ₹200 in your account"<<endl<<"₹20 penalty will be charged "<<endl;
                balance-=20;
                cout<<"So your current balance is : "<<balance<<endl;
            }
        }
        void checkbook()
        {
            cout<<"checkbook"<<endl;
        }
    
};
class saving: public account
{
    private:
        int interest,months,withdrow,balance_saving;
    public:
        void get_savings()
        {
            cout<<"Enter the money you want to deposit in savings account: ";
            cin>>balance_saving;
        }
        void display_savings()
        {
            cout<<"Savings are : "<<balance_saving<<endl;
        }
        void get_interest()
        {
            cout<<"Interest rate we offer is :"<<endl<<"5 months : 6% "<<endl<<"8 months : 7% "<<endl<<"11 months : 8% "<<endl<<"15 months : 9% "<<endl<<"How many months would you like to create an FD for :";
            cin>>months;
            if(months==5)
            {
                interest=(balance_saving*5*6)/100;                                  // ((6*balance_saving)/12)*5;
            }
            else if(months==8)
            {
                interest=(balance_saving*8*7)/100;
            }
            else if(months==11)
            {
                interest=(balance_saving*11*8)/100;
            }
            else if(months==15)
            {
                interest=(balance_saving*15*9)/100;
            }
            else
            {
                cout<<"Enter an valid no of months!";
            }
            
            cout<<"Your Interest is : "<<interest<<endl;
        }
        void withdroww()
        {
            cout<<"Enter the money you want to withdrow: ";
            cin>>withdrow;
            
            balance_saving=balance_saving-withdrow;
            
            cout<<"new balance is : "<<balance_saving<<endl;
        }
        void display_interest()
        {
            cout<<"Your Interest is : "<<interest<<endl;
        }
    
};
int main()
{
    int x,x1;
    char choose;
    current c;
    saving s;
    cout<<"Which accout do you want to create? press s for saving & c for current: ";
    cin>>choose;
    if(choose=='s')
    {
        s.get_name();
        s.get_accountno();
        while(true)
        {
            cout<<endl<<"Enter 1 to display your details\nEnter 2 to deposit money to your savings account\nEnter 3 to create an FD\nEnter 4 withdrow money from your account\nEnter 5 to display current balance\nEnter 6 to display interest\npress 7 to exit! "<<endl;
            cin>>x;    
            switch(x)
            {
                case 1:
                    s.details();
                    break;
                case 2:
                    s.get_savings();
                    break;
                case 3:
                    s.get_interest();
                    break;
                case 4:
                    s.withdroww();
                    break;
                case 5:
                    s.display_savings();
                    break;
                case 6:
                    s.display_interest();
                    break;
                case 7:
                    goto end;
                default:
                    cout<<"Enter an correct option!,try again";
                
                return 0;
            }
        }
    }
    else if(choose=='c')
    {
        c.get_name();
        c.get_accountno();
        c.get_balance();
        while(true)
        {
            cout<<endl<<"Enter 1 to display your details\nEnter 2 to deposit money to your current account\nEnter 3 to access checkbook\nEnter 4 to display current balance\npress 5 to exit!"<<endl;
            cin>>x1;    
            switch(x1)
            {
                case 1:
                    c.details();
                    c.display_mini_balance();
                    break;
                case 2:
                    c.get_balance();
                    c.display_mini_balance();
                    break;
                case 3:
                    c.checkbook();
                    c.display_mini_balance();
                    break;
                case 4:
                    c.display_balance();
                    c.display_mini_balance();
                    break;
                case 5:
                    goto end;
                default:
                    cout<<"Enter an correct option!,try again";
                
                return 0;
            }
        }
    }
    else
    {
        cout<<"invalid choice";
    }
    end: 
        cout<<"Happy banking!";
    return 0;
}
