#include<iostream> 
using namespace std; 
 
struct node 
 { 
     int data; 
     node*next; 
 }; 
class stack 
 { 
     node*head; 
     node*tail; 
    public: 
     stack() 
      { 
          head=nullptr; 
          tail=nullptr; 
      } 
    void push(int d) 
     { 
         node*newnode; 
         newnode=new node(); 
         newnode->data=d; 
         newnode->next=nullptr; 
         if(tail==nullptr) 
          { 
              head=newnode; 
          } 
         else 
          { 
              tail->next=newnode; 
          } 
              tail=newnode; 
     } 
    void pop() 
     { 
         node*temp; 
         temp=head; 
         while(temp->next->next!=nullptr) 
          { 
              temp=temp->next; 
          } 
         if(head==tail) 
          { 
              delete head; 
              head=nullptr; 
              tail=nullptr; 
              return; 
          } 
         node*temp2; 
         temp2=temp->next; 
         temp->next=nullptr; 
         delete temp2; 
     } 
    void display() 
     { 
         node*temp; 
         temp=head; 
         while(temp!=nullptr) 
          { 
              cout<<temp->data<<endl; 
              temp=temp->next; 
} 
} 
}; 
int main() 
{ 
} 
stack s; 
s.push(2); 
s.push(4); 
s.push(7); 
s.pop(); 
s.display(); 