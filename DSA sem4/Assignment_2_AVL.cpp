/*
Implement a multiplayer game system that uses an AVL tree data structure to organize and manage player data efficiently. The multiplayer game supports multiple players participating simultaneously, and the AVL tree is used to store player information such as player_id and scores (key, value pair). The system should provide following operation:
1. Player Registration
2. Leaderboard Display
3. Remove player from game
*/

#include <iostream>
using namespace std;

struct node 
{
    int player_id;
    int score;
    int height;
    node* left;
    node* right;

    node(int id, int sc) 
    {
        player_id = id;
        score = sc;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(node* root) 
{
    return root ? root->height : 0;
}

int getBalanceFactor(node* root) 
{
    return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

node* rotateRight(node* y) 
{
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

node* rotateLeft(node* x) 
{
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node* insert(node* root, int player_id, int score) 
{
    if (!root) return new node(player_id, score);

    if (player_id < root->player_id)
        root->left = insert(root->left, player_id, score);
    else if (player_id > root->player_id)
        root->right = insert(root->right, player_id, score);
    else 
    {
        cout << "Player ID already exists.\n";
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance > 1 && player_id < root->left->player_id)
        return rotateRight(root);

    if (balance < -1 && player_id > root->right->player_id)
        return rotateLeft(root);

    if (balance > 1 && player_id > root->left->player_id) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && player_id < root->right->player_id) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

node* findMin(node* root) 
{
    while (root->left) root = root->left;
    return root;
}

node* remove(node* root, int player_id) 
{
    if (!root) return NULL;

    if (player_id < root->player_id)
        root->left = remove(root->left, player_id);
    else if (player_id > root->player_id)
        root->right = remove(root->right, player_id);
    else {
        if (!root->left || !root->right) {
            node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->player_id = temp->player_id;
        root->score = temp->score;
        root->right = remove(root->right, temp->player_id);
    }

    if (!root) return NULL;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(node* root) {
    if (root) {
        inorder(root->left);
        cout << "Player ID: " << root->player_id << ", Score: " << root->score << endl;
        inorder(root->right);
    }
}

void TakeInput(node*& root) {
    int player_id, score;
    cout << "Enter Player ID (-1 to stop): ";
    cin >> player_id;

    while (player_id != -1) {
        cout << "Enter Score: ";
        cin >> score;
        root = insert(root, player_id, score);
        cout << "Enter Player ID (-1 to stop): ";
        cin >> player_id;
    }
}

int main() {
    node* root = NULL;
    int choice, player_id, score;

    do {
        cout << "\n1. Register Player\n2. Display Leaderboard\n3. Remove Player\n4. Exit\n";
        cout << "$ ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Player ID and Score: ";
                cin >> player_id >> score;
                root = insert(root, player_id, score);
                break;
            case 2:
                cout << "Leaderboard (Inorder Traversal):\n";
                inorder(root);
                break;
            case 3:
                cout << "Enter Player ID to remove: ";
                cin >> player_id;
                root = remove(root, player_id);
                break;
            case 4:
                cout<<endl<<"Segmentation fault? Just kidding.";
                break;
        }
    } while (choice != 4);

    return 0;
}


