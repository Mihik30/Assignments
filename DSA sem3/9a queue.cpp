#include<iostream> 
using namespace std; 
 
struct node 
 { 
     int data; 
     node*next; 
 }; 
class queue 
 { 
   node*head; 
   node*tail; 
  public: 
   queue() 
    { 
        head=nullptr; 
        tail=nullptr; 
    } 
 void enqueue(int d) 
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
 void dequeue() 
  { 
      node*temp; 
      temp=head; 
      head=head->next; 
      if(head==nullptr) 
       { 
           cout<<"Queue has no elements"; 
           return; 
       } 
       delete temp; 
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
      queue q; 
      q.enqueue(1 ); 
q.enqueue(6 ); 
q.enqueue(7 ); 
q.dequeue(); 
q.display(); 
} 