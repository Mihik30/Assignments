#include<iostream> 
#include<string> 
using namespace std; 
 
struct node 
{ 
    string data; 
    node*next; 
    node*prev; 
}; 
 
class Editor 
{ 
    node*head; 
    node*tail; 
     
    public: 
    Editor() 
    { 
        head=NULL; 
        tail=NULL; 
    } 
     
void add_beg(string d) 
{ 
    node*newnode; 
    newnode=new node; 
    newnode->data=d; 
    newnode->next=head; 
     
    if (head==NULL) 
    { 
        tail=newnode; 
    } 
    head=newnode; 
    newnode->prev=NULL; 
} 
 
void add_end(string d) 
{ 
    node*newnode; 
    newnode=new node; 
    newnode->data=d; 
    newnode->next=NULL; 
     
    if(tail==NULL) 
    { 
        newnode->prev=NULL; 
    } 
    else 
    { 
        newnode->prev=tail; 
    } 
    tail->next=newnode; 
    tail=newnode; 
} 
 
void add_pos(string d , int pos) 
{ 
    node*newnode; 
    newnode=new node; 
    newnode->data=d; 
     
    node*temp; 
    temp=head; 
     
    if(pos==1) 
    { 
        add_beg(d); 
        return; 
    } 
    for(int i=1;i<pos-1;i++) 
    { 
    temp=temp->next; 
    } 
    node*temp2; 
    temp2=temp->next; 
    newnode->next=temp2; 
    temp2->prev=newnode; 
    newnode->prev=temp; 
    temp->next=newnode; 
    } 
     
void del_beg() 
{ 
    node*temp; 
    temp=head; 
head=head->next; 
delete temp; 
head->prev=NULL; 
} 
void del_end() 
{ 
node*temp; 
temp=head; 
if(temp->next==NULL) 
{ 
} 
head=NULL; 
tail=NULL; 
delete temp; 
return; 
while(temp->next->next!=NULL) 
{ 
} 
temp=temp->next; 
node*temp2; 
temp2=temp->next; 
temp->next=NULL; 
delete temp2; 
} 
void del_pos(int pos) 
{ 
    if(pos==1) 
    { 
        del_beg(); 
        return; 
    } 
    node*temp; 
    temp=head; 
     
    for(int i=1;i<pos-1;i++) 
    { 
        temp=temp->next; 
    } 
    node*temp2; 
    node*temp3; 
    temp2=temp->next; 
    temp3=temp2->next; 
    temp3->prev=temp; 
    temp->next=temp3; 
    delete temp2; 
} 
 
void display() 
{ 
    node*temp=head; 
    while(temp!=NULL) 
    { 
        cout<<temp->data<<" "; 
        temp=temp->next; 
    } 
} 
 
}; 
 
int main() 
{ 
    int choice; 
    string data; 
    int pos; 
     
    Editor dl; 
    while(true) 
    { 
        cout<<endl<<"Choose method:"<<endl; 
        cout<<"1. insert text beg:"<<endl; 
        cout<<"2. insert text end:"<<endl; 
        cout<<"3. insert text pos:"<<endl; 
        cout<<"4. delete text beg:"<<endl; 
        cout<<"5. delete text end:"<<endl; 
        cout<<"6. delete text pos:"<<endl; 
        cout<<"7. Display:"<<endl; 
        cin>>choice; 
         
        switch(choice) 
        { 
            case 1: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.add_beg(data); 
  
            break; 
             
             case 2: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.add_end(data); 
 
            break;  
             
            case 3: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.add_pos(data,pos); 
 
            break; 
             
            case 4: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.del_beg(); 
    
            break; 
             
            case 5: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.del_end(); 
   
            break;  
             
            case 6: 
            cout<<"Enter your data:"; 
            cin>>data; 
            dl.del_pos(pos); 
     
            break; 
             
            case 7: 
            cout<<"Display:"<<endl; 
            dl.display(); 
            break; 
         
             
            default: 
            cout<<"exit"; 
            break; 
        } 
         
    } 
 
} 