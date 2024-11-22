//singly link list 
#include <iostream> 
#include <string> 
using namespace std; 
struct node 
   { 
    string song,title; 
    node*next; 
   }; 
class playlist 
    { 
      node*head; 
      node*tail; 
    public: 
      playlist() 
      { 
          head=nullptr; 
          tail=nullptr; 
      } 
  void add_beg(string s, string t) 
    { 
        node*newnode; 
        newnode=new node(); 
        newnode->song=s; 
        newnode->title=t; 
        if(head==nullptr) 
        { 
            tail=newnode; 
        } 
        else 
        { 
            newnode->next=head; 
        } 
        head=newnode; 
    } 
  void add_end(string s, string t) 
    { 
        node*newnode; 
        newnode=new node(); 
        newnode->song=s; 
        newnode->title=t; 
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
  void add_pos(string s, string t, int position) 
    { 
        node*newnode; 
        newnode=new node(); 
        newnode->song=s; 
        newnode->title=t; 
        node*temp; 
        temp=head; 
        for(int i=1;i<position-1;i++) 
        { 
            temp=temp->next; 
        } 
        newnode->next=temp->next; 
        temp->next=newnode; 
    } 
  void delete_beg() 
    { 
        node*temp; 
        temp=head; 
        head=temp->next; 
        delete temp; 
    } 
  void delete_end() 
    { 
        node*temp; 
        temp=head; 
        while(temp->next->next!=nullptr) 
        { 
            temp=temp->next; 
        } 
        node*temp2; 
        temp2=temp->next; 
        temp->next=nullptr; 
        delete temp2; 
    } 
  void delete_pos(int position) 
    { 
        node*temp; 
        temp=head; 
        for(int i=1;i<position-1;i++) 
        { 
            temp=temp->next; 
        } 
        node*temp2; 
        temp2=temp->next; 
        temp->next=temp2->next; 
        delete temp2; 
    } 
   void display() { 
        node *temp = head; 
        while (temp != nullptr)  
        { 
            cout << temp->song << " " << temp->title << endl; 
            temp = temp->next; 
        } 
    } 
     
    }; 
int main() 
  { 
    playlist p; 
    int choice; 
    string song,title; 
    int position; 
   while (true) { 
        cout << "\nPreference Menu:\n"; 
        cout << "1. Insert at Beginning\n"; 
        cout << "2. Insert at End\n"; 
        cout << "3. Insert at Position\n"; 
        cout << "4. Delete from Beginning\n"; 
        cout << "5. Delete from End\n"; 
        cout << "6. Delete from Position\n"; 
        cout << "7. Display Playlist\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter song name: "; 
            cin >> song; 
            cout << "Enter title: "; 
            cin >> title; 
            p.add_beg(song, title); 
            break; 
        case 2: 
            cout << "Enter song name: "; 
            cin >> song; 
            cout << "Enter title: "; 
            cin >> title; 
            p.add_end(song, title); 
            break; 
        case 3: 
            cout << "Enter song name: "; 
            cin >> song; 
            cout << "Enter title: "; 
            cin >> title; 
            cout << "Enter position: "; 
            cin >> position; 
            p.add_pos(song, title, position); 
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
            cout << "Playlist:\n"; 
            p.display(); 
            break; 
        case 8: 
            cout << "Exiting program. Goodbye!\n"; 
            return 0; 
        default: 
            cout << "Invalid choice! Please try again.\n"; 
        } 
    } 
} 