#include<iostream> 
 using namespace std; 
 int n = 5; 
 struct node 
 { 
 string name; 
 node* next; 
 }; 
 class cqueue 
 { 
 node* front; 
 node* rear; 
 int i,j,c,count; 
 string s; 
 public: 
 cqueue() 
 { 
 front = NULL; 
 rear = NULL; 
 count = 0; 
 } 
 void table() 
 { 
 while(true) 
 { 
 cout<<"Press 1 for Customer Arrival"<<endl; 
 cout<<"Press 2 for Customer Checkout"<<endl; 
 cout<<"Press 3 for Customer List"<<endl; 
 cin>>c; 
 switch(c) 
 { 
 case 1:if(count == n) 
 cout<<"SORRY! QUEUE FULL"<<endl; 
 else 
 addbeg(); 
 break; 
 case 2:if(count == 0) 
 cout<<"QUEUE ALREADY EMPTY!"<<endl; 
else 
 delend(); 
 break; 
 case 3:display(); 
 break; 
 case 4:return; 
 default:cout<<"INVALID CHOICE!"<<endl; 
 break; 
 } 
 } 
 } 
 void addbeg() 
 { 
 count++; 
 node* nn = new node; 
 cout<<"ENTER NAME- "; 
 cin>>nn->name; 
 if(rear == NULL) 
 { 
 nn->next = nn; 
 front = nn; 
 rear = nn; 
 return; 
 } 
 nn->next = rear; 
 rear = nn; 
 } 
 void delend() 
 { 
 count--; 
 node* temp = rear; 
 if(front == rear) 
 { 
 delete temp; 
 front = NULL; 
 rear = NULL; 
 return; 
 } 
 while(temp->next!=front) 
 { 
 temp = temp->next; 
 } 
 node* temp2 = temp->next; 
 delete temp2; 
front = temp; 
 temp = rear; 
 } 
 void display() 
 { 
node* temp = rear; 
if(rear == NULL) 
{ 
cout<<"QUEUE EMPTY!"<<endl; 
return; 
} 
cout<<"CUSTOMER NAME"<<endl; 
i=0; 
while(i<count) 
{ 
cout<<temp->name<<endl; 
temp = temp->next; 
i++; 
} 
} 
}; 
int main() 
{ 
cqueue a; 
a.table(); 
return 0; 
} 