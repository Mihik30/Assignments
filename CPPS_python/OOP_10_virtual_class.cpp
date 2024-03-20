#include <iostream>
using namespace std;
class student
{
    protected:  
        int roll_no;
    public:
        void get_no()
        {
            cout<<"Enter your roll number :";
            cin>>roll_no;
        }
        void put_no()
        {
            cout<<"Roll Numebr : "<<roll_no<<endl;
        }
};
class test: virtual public student
{
    protected:
        int marks1,marks2;
    public:
        void get_marks()
        {
            cout<<"Enter your marks : ";
            cin>>marks1>>marks2;
        }
        void put_marks()
        {
            cout<<"Marks : "<<marks1<<"\t"<<marks2<<endl;
        }
};
class sports: virtual public student
{
    protected:
        int score;
    public:
        void get_score()
        {
            cout<<"Enter Score : ";
            cin>>score;
        }
        void put_score()
        {
            cout<<"Score : "<<score<<endl;
        }
};
class result : public test , public sports
{
    protected:
        int total;
    public:
        void put_total()
        {
            total = marks1+marks2+score;
            cout<<"Total : "<<total<<endl;
        }
};
int main()
{
    result m;
    
    m.get_no();
    m.put_no();
    
    m.get_marks();
    m.put_marks();
    
    m.get_score();
    m.put_score();
    
    m.put_total();

    return 0;
}
