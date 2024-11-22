#include<iostream>
#include<string>
using namespace std;

struct node
 {
     string data;
     int priority;
     node*next;
     node*prev;
 };
class job
 {
     node*head;
     node*tail;
    public:
     job()
      {
          head=nullptr;
          tail=nullptr;
      }
     void priority(string d, int p)
      {
          node*newnode;
          newnode=new node();
          newnode->data=d;
          newnode->priority=p;
          if(head==nullptr)
           {
               newnode->next=nullptr;
               newnode->prev=nullptr;
               tail=newnode;
               head=newnode;
           }
          else if(head==tail)
           {
               if(newnode->priority>tail->priority)
                {
                    newnode->next=head;
                    head->prev=newnode;
                    head=newnode;
                }
                 else 
                  {
                      tail->next=newnode;
                      newnode->prev=tail;
                      tail=newnode;
                  }
           }
          else
              {
                  node*temp;
                  temp=head;
                  if(temp->priority<newnode->priority)
                   {
                       newnode->next=temp;
                       temp->prev=newnode;
                       newnode->prev=nullptr;
                       head=newnode;
                       return;
                   }
                  while(temp->next!=nullptr && temp->next->priority>=newnode->priority)
                   {
                       temp=temp->next;
                   }
                   if(temp->next==nullptr)
                    {
                        tail->next=newnode;
                        newnode->prev=tail;
                        tail=newnode;
                        return;
                    }
                    newnode->next=temp->next;
                    temp->next=newnode;
              }
      }
    void delete_beg()
     {
         node*temp;
         temp=head;
         if(head==nullptr)
         {
             cout<<"Deletion not possible";
             return;
         }
         if(head==tail)
          {
              temp=head;
              delete temp;
              head=nullptr;
              tail=nullptr;
          }
          else
           {
               head=head->next;
               head->prev=nullptr;
               delete temp;
           }
     }
    void display()
     {
         node*temp;
         temp=head;
         while(temp!=nullptr)
          {
              cout<<temp->data<<" ";
              temp=temp->next;          }
     }
 };
 int main()
  {
      job j;
      j.priority("sweeping", 2);
      j.priority("manager", 4);
      j.priority("plant_head", 6);
      j.priority("worker", 5);
      j.priority("sweeper2", 2);
      j.display();
      return 0;
  }