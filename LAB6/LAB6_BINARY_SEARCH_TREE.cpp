//LAB6 BINARY SEARCH TREE OPERATIONS
//SHOVIT NEPAL
#include<iostream>
#include<windows.h>
using namespace std;


class BST
{
    int data;
    BST *left, *right;


public:
    BST();

    BST(int);

    BST* Insert(BST*, int); //insert function

    void Inorder(BST*); //Inorder traversal

    void Preorder(BST*);

    void Postorder(BST*);
    BST* checkKey(BST* root,int value);
};

//Default Constructor definition.
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{

}

//Parameterized Constructor definition.
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

//INSERT function definition.
BST* BST::Insert(BST* root, int value)
{
    if(!root)
    {
        return new BST(value);
    }

    if(value>root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

//Inorder traversal function.
void BST::Inorder(BST* root)
{
    if(root){
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}
}
void BST::Preorder(BST* root)
{
    if(root){
    cout<<root->data<<endl;
    Preorder(root->left);
    Preorder(root->right);
}
}
void BST::Postorder(BST* root)
{
    if(root){
    Postorder(root->left);
    Postorder(root->right);

    cout<<root->data<<endl;
}
}
BST* BST::checkKey(BST* root,int value)
{
    if(!root)
         cout<<"Key not found!";
    else if(value==root->data)
        cout<<"Key Found"<<endl;

    else{
            if(value<root->data)
            checkKey(root->left, value);



            else
            checkKey(root->right, value);

        }
}
int main()
{
    BST b, *root = NULL;
    int num=0;
    int choice, val, i;
    do{
    cout<<"CHOOSE ONE OPERATION:"<<endl;
    cout<<"1. CREATE BST"<<endl;
    cout<<"2. TRAVERSING IN INORDER, PREORDER & POSTORDER"<<endl;
    cout<<"3. SEARCH KEY"<<endl;
    cout<<"4. EXIT"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
        cout<<"Enter the number of total key:"<<endl;
        cin>>num;
        cout<<"Enter keys:";
        for(i=0;i<num;i++){
        cin>>val;
        root = b.Insert(root,val);
       // b.Insert(root,val);
        }

       break;

    }
    case 2:
    {
    cout<<"Inorder:"<<endl;
    b.Inorder(root);
    cout<<"Preorder:"<<endl;
    b.Preorder(root);
    cout<<"Postorder:"<<endl;
    b.Postorder(root);

    break;
    }
    case 3:
        {
           int key;
           cout<<"Enter KEY:"<<endl;
           cin>>key;
           b.checkKey(root, key);
           break;
        }
    case 4:
        {
            exit(0);
        }
    default :
        {
            cout<<"Invalid input";
            break;
        }
    }
    }while(choice!=4);
    return 0;
    }

