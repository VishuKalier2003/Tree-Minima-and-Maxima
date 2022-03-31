#include <iostream>
using namespace std;
class Node                // Node class for creating Node template for Binary Tree
{
    public:    // Data members of every Node
    int data;
    Node* left;
    Node* right;
    Node* root;
    public:
    Node(int val)    // Parametrized Constructor
    {
        data = val; left = NULL;
        right = NULL; root = NULL;
    }
};
class BinaryTree     // Binary Tree class for Implementing Binary tree
{
    public:
    Node* InsertNodeInTree(Node* root, int val)    // Inserting Nodes by Recursion
    {        // Recursive Call Function
        if(root == NULL)
            return new Node(val);   // Insert the Node and backtrack
        if(val <= root -> data)         // If value is lower than the root Node, Insert at Left
            root -> left = InsertNodeInTree(root -> left, val);
        if(val > root -> data)          // If value is higher than the root Node, Insert at Right
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    public:
    void DisplayTree(Node* root)   // Displaying Tree with Nodes in In-order
    {
        if(root == NULL)    // If Root empties backtrack
            return;
        DisplayTree(root -> left);   // Recursive Call to the Left Subtree
        cout << "Node : " << endl;
        if(root -> left != NULL)
            cout << "\t" << root -> data << " ---> " << root -> left -> data << "\t (Occupied)" << endl;
        else
            cout << "\t" << root -> data << "\t\t (Empty)" << endl;
        if(root -> right != NULL)
            cout << "\t" << root -> data << " ---> " << root -> right -> data << "\t (Occupied)" << endl;
        else
            cout << "\t" << root -> data << "\t\t (Empty)" << endl;
        DisplayTree(root -> right);    // Recursive Call to the Right Subtree
    }
    int TreeMinimum(Node* root)   // Finding the minimum value in the Tree
    {
        if(root == NULL)   // If no Tree is available, return truncated value
            return -1;
        Node* temp = root;
        while(temp -> left != NULL)   // Traversing throught the Leftmost branch
            temp = temp -> left;
        return temp -> data;
    }
    int TreeMaximum(Node* root)   // Finding the maximum value in the Tree
    {
        if(root == NULL)    // If no Tree is available, return truncated value
            return -1;
        Node* temp = root;
        while(temp -> right != NULL)   // Traversing throught the Rightmost branch
            temp = temp -> right;
        return temp -> data;
    }
};
int main()
{
    Node* root = NULL;      // Root pointer reference set to NULL
    BinaryTree binarytree;     // Object creation
    int x, s;
    cout << "Enter the Root Node of the Binary Tree : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Setting Root Node value
    cout << "Enter the Number of Nodes to be Inserted in the Binary Tree : ";
    cin >> s;
    for(int i = 0; i < s ; i++)   // For Loop for setting Node entries of the Tree
    {
        cout << "Enter Node value to be Inserted : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);   // Inserting Nodes
    }
    binarytree.DisplayTree(root);       // Displaying Tree
    x = binarytree.TreeMinimum(root);                  // Getting Minimum Node's value
    cout << "The Minimum Node value of the Binary Tree is : " << x << endl;
    x = binarytree.TreeMaximum(root);                  // Getting Maximum Node's value
    cout << "The Maximum Node value of the Binary Tree is : " << x << endl;
    return 0;     // End of the program
}