#include <iostream>
using namespace std;
struct node 
{
    int data;
    node *next;
    node(int s) 
    {
        data =s;
        next =NULL;
    }
};
class browes
{
    public:
    node *top;
    browes()
    {
        top=NULL;
    }
    void add(int y)
    {
        node *new_node =new node (y);
        new_node->next=top;
        top=new_node;
        cout<<"PAGE PUSHED"<<y<<endl;
    }
    void viewprev()
    {
        if(top==NULL)
        {
            cout<<"NO PREV PAGE"<<endl;
        }
        if(top->next==NULL)
        {
            cout<<"NO PREV PAGE"<<endl;
        }
        else
        {
            node *temp=top;
            top=top->next;
            delete(temp);
            cout<<"previous "<<top->data;
        }
    }
    
    void view()
    {
        if(top==NULL)
        {
            cout<<"NO CURRENT PAGE";
        }
        else
        {
            cout<<" CURRENT PAGE"<<top->data<<endl;
        }
    }
    
    void checkempty()
    {
        if(top==NULL)
        {
             cout<<"EMPTY";
        }
        else
        {
            cout<<"NOT EMPTY";
        }
    }

};

int main() 
{
    browes aa;
    // cout<<"------"<<endl;
    aa.add(8);
    aa.add(6);
    aa.view();
    // cout<<"------"<<endl;
    // cout<<"------"<<endl;
    aa.viewprev();
    // cout<<"------"<<endl;
    aa.view();
    // cout<<"------"<<endl;
    aa.checkempty();

    return 0;
}
