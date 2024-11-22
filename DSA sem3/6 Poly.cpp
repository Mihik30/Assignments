#include<iostream>
 using namespace std;
 struct Node{
 int coeff;
 int power;
 Node* next;
 };
 class Student{
 Node* head;
 Node* tail;
 public:
 Student(){
 head=nullptr;
 tail=nullptr;
 }
 void add_end(int c , int p){
 Node* newNode;
 newNode= new Node;
 newNode->coeff=c;
 newNode->power=p;
 newNode->next=nullptr;
 if(tail==nullptr){
 head=newNode;
 }
 else{
 tail->next=newNode;
 }
 tail=newNode;
 }
 void Polynomial(Student list1, Student list2){
 Student result;
 Node* ptr1;
 ptr1=list1.head;
 Node* ptr2;
 ptr2=list2.head;
 while(ptr1!=nullptr && ptr2!=nullptr){
 if(ptr1->power==ptr2->power){
result.add_end(ptr1->coeff+ptr2->coeff,ptr1->power);
 ptr1=ptr1->next;
 ptr2=ptr2->next;
 }
 else if(ptr1->power>ptr2->power){
 result.add_end(ptr1->coeff,ptr1->power);
 ptr1=ptr1->next;
 }
 else if(ptr1->power<ptr2->power){
 result.add_end(ptr2->coeff,ptr2->power);
 ptr2=ptr2->next;
 }
 }
 while(ptr1!=nullptr){
 result.add_end(ptr1->coeff,ptr1->power);
 ptr1=ptr1->next;
 }
 while(ptr2!=nullptr){
 result.add_end(ptr2->coeff,ptr2->power);
 ptr2=ptr2->next;
 }
 Node* ptr3;
 ptr3=result.head;
 while(ptr3!=nullptr){
 cout<<ptr3->coeff<<"x^"<<ptr3->power<<"";
 ptr3=ptr3->next;
 }
 }
 };
 int main(){
 Student s;
 Student s1;
 Student s2;
 int c,p;
 cout<<"Enter value of coeff"<<endl;
 cin>>c;
 cout<<"Enter power"<<endl;
 cin>>p;
 int x,y;
 cout<<"Enter value of coeff"<<endl;
 cin>>x;
cout<<"Enter power"<<endl;
 cin>>y;
 s.add_end(c,p);
 s1.add_end(x,y);
 s2.Polynomial(s,s1);
 }