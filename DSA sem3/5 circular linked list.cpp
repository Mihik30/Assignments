//circular linked list 
#include <iostream> 
using namespace std; 
 
struct node 
   { 
    string route; 
    node*next; 
   }; 
class delivery 
  { 
    node*head; 
    node*tail; 
  public: 
    delivery() 
    { 
        head=nullptr; 
        tail=nullptr; 
    } 
void add_beg(string r) 
    { 
        node*nn; 
        nn=new node(); 
        nn->route=r; 
        nn->next=head; 
        if(head==nullptr) 
        { 
            nn->next=nn; 
            tail=nn; 
        } 
        else 
            { 
                tail->next=nn; 
                nn->next=head; 
                 
            } 
            head=nn; 
    } 
 void add_end(string r) 
    { 
        node*nn; 
        nn=new node(); 
        nn->route=r; 
        nn->next=head; 
        if(tail==nullptr) 
        { 
            nn->next=nn; 
            head=nn; 
             
        } 
        else 
            { 
                tail->next=nn; 
                nn->next=head; 
                 
            } 
            tail=nn; 
    } 
 void add_pos(string r, int position) 
    { 
        int i; 
        node*nn; 
        nn=new node(); 
        nn->route=r; 
        node*temp; 
        temp=head; 
        if(position<1) 
         { 
             cout<<"No position found"; 
             return; 
         } 
        if(position==1) 
        { 
            add_beg(r); 
            return; 
        } 
        for(i=1;i<position-1;i++) 
        { 
            temp=temp->next; 
        } 
       if(temp==tail) 
       { 
           add_end(r); 
           return; 
       } 
       nn->next=temp->next; 
       temp->next=nn; 
    } 
 void delete_beg() 
    { 
        node*temp; 
        temp=head; 
        head=head->next; 
        tail->next=head; 
        delete temp; 
    } 
 void delete_end() 
    { 
        node*temp; 
        temp=head; 
        while(temp->next!=tail) 
        { 
            temp=temp->next; 
        } 
        node*temp2; 
        temp2=temp->next; 
        temp->next=head; 
        delete temp2; 
    } 
 void delete_pos(int position) 
    { 
        if(position<1) 
        { 
            cout<<"Enter another position"; 
            return; 
        } 
        if(position==1) 
        { 
            delete_beg(); 
        } 
        int i; 
        node*temp; 
        temp=head; 
        for(i=1;i<position-1;i++) 
        { 
            temp=temp->next; 
        } 
        if(temp==tail) 
        { 
            delete_end(); 
        } 
        node*temp2; 
        temp2=temp->next; 
        temp->next=temp2->next; 
        delete temp2; 
    } 
 void display() 
    { 
        node*temp; 
        temp=head; 
        while(temp!=nullptr) 
        { 
            cout<<temp->route<<" "; 
            temp=temp->next; 
            if(temp==head) 
         { 
            return; 
         } 
        } 
             
    } 
  }; 
int main() 
 { 
     delivery p; 
     int choice; 
     int position; 
     string route; 
     while (true)  
     { 
        cout << "\nPreference Menu:\n"; 
        cout << "1. Insert at Beginning\n"; 
        cout << "2. Insert at End\n"; 
        cout << "3. Insert at Position\n"; 
        cout << "4. Delete from Beginning\n"; 
        cout << "5. Delete from End\n"; 
        cout << "6. Delete from Position\n"; 
        cout << "7. Display route\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice)  
        { 
        case 1: 
            cout << "Enter route name: "; 
            cin >> route; 
            p.add_beg(route); 
            break; 
        case 2: 
            cout << "Enter route name: "; 
            cin >> route; 
            p.add_end(route); 
            break; 
        case 3: 
            cout << "Enter route name: "; 
            cin >> route; 
            cout << "Enter position: "; 
            cin >> position; 
            p.add_pos(route, position); 
            break; 
        case 4: 
            p.delete_beg(); 
            break; 
        case 5: 
            p.delete_end(); 
            break; 
        case 6: 
            cout << "Enter position to delete: "; 
            cin >> position; 
            p.delete_pos(position); 
            break; 
        case 7: 
            cout << "ROUTES:\n"; 
            p.display(); 
            break; 
        case 8: 
            cout << "Exiting program. Goodbye!\n"; 
            return 0; 
        default: 
            cout << "Invalid choice! Please try again.\n"; 
        } 
    } 
 
 
    return 0; 
 } 