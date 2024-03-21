#include <iostream>
using namespace std;
class account
{
    protected:
        int accout_number,type_of_account;
        char name[100];
    public:
       
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
class current : virtual public account
{
    protected:
        int balance;//,checkbook;
    public:
        void get_balance()
        {
            cout<<"Enter the amount you want to deposit: ";
            cin>>balance;
        }
        void display_balance()
        {
            cout<<"Current accout Balance: "<<balance<<endl;
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
            if(balance>200)
            {
                cout<<"you are eligible for an checkbook"<<endl;
            }
            else
            {
                cout<<"you are not eligible for an checkbook"<<endl;
            }
            
        }
    
};
class saving: virtual public account
{
    protected:
        int interest,months,withdrow,balance_saving;
    public:
        void get_savings()
        {
            cout<<"Enter the money you want to deposit in savings account: ";
            cin>>balance_saving;
        }
        void display_savings()
        {
            cout<<"Savings account balance : "<<balance_saving<<endl;
        }
        void get_interest()
        {
            cout<<"Interest rate we offer is :"<<endl<<"5 months : 6% "<<endl<<"8 months : 7% "<<endl<<"11 months : 8% "<<endl<<"15 months : 9% "<<endl<<"How many months would you like to create an FD for :";
            cin>>months;
            if(months==5)
            {
                interest=(balance_saving*(5/12)*6)/100;                                  // ((6*balance_saving)/12)*5;
            }
            else if(months==8)
            {
                interest=(balance_saving*(8/12)*7)/100;
            }
            else if(months==11)
            {
                interest=(balance_saving*(11/12)*8)/100;
            }
            else if(months==15)
            {
                interest=(balance_saving*(15/12)*9)/100;
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
class bank : public saving , public current
{
    public:
        void all_details_saving()
        {
            display_savings();
            display_interest();
        }
        void all_details_current()
        {
            display_balance();
            checkbook();
        }
        void all_details()
        {
            display_savings();
            display_interest();
            display_balance();
            checkbook();
        }
        
};
int main()
{
    int x;
    char choose;
    bank b;
    b.get_name();
    b.get_accountno();
    start:
    cout<<"Which accout do you want to create?\n press s for saving \n c for current \n a to display Overall account details: ";
    cin>>choose;
    if(choose=='s')
    {
        
        while(true)
        {
            cout<<endl<<"Enter 1 to display your details\nEnter 2 to deposit money to your savings account\nEnter 3 to create an FD\nEnter 4 withdrow money from your account\nEnter 5 to display current balance\nEnter 6 to display interest\npress 7 to exit!\npress 8 to enter main menu "<<endl;
            cin>>x;    
            switch(x)
            {
                case 1:
                    b.all_details_saving();
                    break;
                case 2:
                    b.get_savings();
                    break;
                case 3:
                    b.get_interest();
                    break;
                case 4:
                    b.withdroww();
                    break;
                case 5:
                    b.display_savings();
                    break;
                case 6:
                    b.display_interest();
                    break;
                case 7:
                    goto end;
                case 8:
                    goto start;
                default:
                    cout<<"Enter an correct option!,try again";
                
                return 0;
            }
        }
    }
    else if(choose=='c')
    {
        while(true)
        {
            cout<<endl<<"Enter 1 to display your details\nEnter 2 to deposit money to your current account\nEnter 3 to access checkbook\nEnter 4 to display current balance\npress 5 to exit!\npress 6 to enter main menu"<<endl;
            cin>>x;    
            switch(x)
            {
                case 1:
                    b.all_details_current();
                    b.display_mini_balance();
                    break;
                case 2:
                    b.get_balance();
                    b.display_mini_balance();
                    break;
                case 3:
                    b.checkbook();
                    b.display_mini_balance();
                    break;
                case 4:
                    b.display_balance();
                    b.display_mini_balance();
                    break;
                case 5:
                    goto end;
                case 6:
                    goto start;
                default:
                    cout<<"Enter an correct option!,try again";
                
                return 0;
            }
        }
    }
    else if(choose=='a')
    {
        cout<<"Overall details of your saving as well as current are:";
        b.all_details();
    }
    end: 
        cout<<"Happy banking!";
    return 0;
}
