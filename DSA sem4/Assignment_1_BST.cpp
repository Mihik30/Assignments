/*
Consider the Dictionary Implementations which allow for efficient storage and retrieval of
key-value pairs using binary search trees. Each node in the tree store (key, value) pair. The
dictionary should support the following operations efficiently:
1. Insert word (Handle insertion of duplicate entry)
2. Delete word
3. Search specific word
4. Display dictionary (Traversal)
5. Mirror image of dictionary
6. Create a copy of dictionary
7. Display dictionary level wise 
*/

#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

struct node
{
	node* left;
	node* right;
	string word;
	int key;
	
	node(string word , int key)
	{
		left = NULL;
		right = NULL;
		this->word = word; //add this-> to avoid shadowing
		this->key = key;
	}
};

void levelOrderTraversal(node* root)
{
    int noofnodes = 0;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
	    node* temp = q.front();
	    q.pop();
	    
	    if(temp == NULL)
	    {
	        cout<<endl;
	        if(!q.empty())
	        {
	            q.push(NULL);
	        }
	    }
	    else
	    {
	    	noofnodes++;
	        cout<<temp->word;//<<" : " <<temp->key<<"|";
	        if(temp->left)
    	    {
    	        q.push(temp->left);
    	    }
    	    if(temp->right)
    	    {
    	        q.push(temp->right);
    	    }
	    }
	    
	}
// 	cout<<endl<<"Number of Nodes are : "<<noofnodes<<endl;
}


node* InsertBST(node* &root, string word , int key)
{
    
	if(root==NULL)
	{
		root = new node(word , key);
		return root;
	}
	
	
	if(key > root->key)
	{
		InsertBST(root->right , word , key);
	}
	else if(key < root->key)
	{
		InsertBST(root->left , word , key);
	}
	else if(root->key == key) //this is to not accept duplicate values
	{
	    cout<<"Already Present"<<endl;
	    return root;
	}
	
	return root;
	
}
void TakeInput(node* &root)
{
	string word;
	int key;
	cout<<"Insert Word : ";
	cin>>word;
	cout<<"Insert key value : ";
	cin>>key;
	
	while(key != -1)
	{
		InsertBST(root , word , key);
		cout<<"Insert Word : ";
		cin>>word;
		cout<<"Insert key value : ";
		cin>>key;
	}
}
int minValue(node* &root)
{
	node* temp = root;
	
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->key;
}
void Inorder(node* &root)
{
	if(root == NULL)
	{
		return ;
	}
	
	Inorder(root->left);
	cout<<root->key << " : "<<root->word<<endl;
	Inorder(root->right);
}
void inOrderTraversal(node *root)
{
	stack<node *> treeStack;
	node *currentNode = root;

	while (currentNode != NULL || treeStack.empty() == false)
	{
        //condition to check if the node is leftmost node 
		while (currentNode != NULL)
		{
			// step 3 of our algorithm
			treeStack.push(currentNode);
			currentNode = currentNode->left;
		}
		
		currentNode = treeStack.top();
		treeStack.pop();
        // cout statement to print the node data
		cout << currentNode->key <<" ";
        
        // statement to process right subtree 
		currentNode = currentNode->right;
	} 
}


bool SearchRecursive(node* root , string del)
{
	if(root==NULL)
	{
		return false;
	}
	
	if(del > root->word)
	{
		SearchRecursive(root->right , del);
	}
	else if(del < root->word)
	{
		SearchRecursive(root->left , del);
	}
	else if(root->word == del)
	{
	    return true;
	}
	
	return false;
	
}

bool Searchitrative(node* root , int k)
{
    node* temp = root;
    while(temp!=NULL)
    {
        if (temp->key == k)
        {
            return true;
        }
        
        else if(temp->key > k)
        {
            temp = temp->left;
        }
        else if(temp->key < k)
        {
            temp = temp->right;
        }
    }
    
    return false;
}

node* DeleteNode(node* &root , int val)
{
	//base case 
	if(root == NULL)
	{
		return root;
	}
	
	//if data of the node is equal to the value we want to delete
	if(root->key == val)
	{
		//0 child
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		
		//1 child
		
			//only left node
		if(root->left != NULL && root->right == NULL)
		{
			node* tempp = root->left;
			delete root;
			return tempp;
		}
		
			//only right node
		if(root->left == NULL && root->right != NULL)
		{
			node* tempp = root->right;
			delete root;
			return tempp;
		}
		
		//2 children
		if(root->left != NULL && root->right != NULL)
		{
			int mini = minValue(root->right);
			root->key = mini;
			root->right = DeleteNode(root->right , mini);
			return root;
			
		}
	}
	
	else if(root->key > val)//if data of the node is less then the value we want to delete
	{
		root->left = DeleteNode(root->left , val);
	}
	else
	{
		root->right = DeleteNode(root->right , val);
	}
	
	return root;
}

void mirror(node* root) {
    if (root == nullptr)
        return ;
    
    // Invert the left and right subtree
    mirror(root->left);
    mirror(root->right);
  
    // Swap the left and right subtree
    swap(root->left, root->right);
}

int main()
{
	node* root = NULL;
	int c,del,key,secc;
	string keyval1 , word,sec;
	do
	{
		cout<<endl<<"1. Insert word\n2. Delete word\n3. Search specific word\n4. Search specific key\n5. Display dictionary (InOrder)\n6. Mirror image of dictionary\n7. Create a copy of dictionary\n8. Display dictionary level wise\n9. Exit"<<endl;         
		cout<<"$ ";
		cin>>c;
		
		switch(c){
			case 1:
				cout<<"Insert Word : ";
				cin>>word;
				cout<<"Insert key value : ";
				cin>>key;
				InsertBST(root , word , key);
				break;
			case 2:
				cout<<endl<<"Enter the key element of the word you want to delete : ";
				cin>>del;
				root = DeleteNode(root , del);
				break;
			case 3:
				cout<<endl<<"Enter the word you want to search : ";
				cin>>sec;
				keyval1 = (SearchRecursive(root , sec) == true) ? "Value found using recursive method" : "Valuse not found" ;
				cout<<keyval1;
				break;
			case 4:
				cout<<endl<<"Enter the key you want to search : ";
				cin>>secc;
				keyval1 = (Searchitrative(root , secc) == true) ? "Value found using Itrative method" : "Valuse not found" ;
				cout<<keyval1;
				break;
			case 5:
				cout<<endl<<"Displaying the dictionary (InOrder): "<<endl;
				Inorder(root);
				break;
			case 6:
				mirror(root);
				levelOrderTraversal(root);
				break;
			case 7:
				cout<<"ehhh idk..";
				break;
			case 8:
				cout<<endl<<"Displaying Level wise : "<<endl;
				levelOrderTraversal(root);
				break;
			case 9:
				cout<<endl<<"Happy Programming"<<endl;
				break;
		}
	}while(c != 9);

	
	return 0;
}
