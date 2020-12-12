#include<iostream>

using namespace std;

struct node{
    struct node *left;
    int data;
    struct node *right;
};

void searchElement(TREE, val);

void searchElement(TREE, val){
    if(TREE->data == val)
    {
        TREE->data=val;
        TREE->left=Tree->right=NULL;
    }
    }
