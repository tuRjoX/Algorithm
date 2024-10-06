#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *insertBST(node *root,int data){
    if(root == NULL){
        return new node(data);
    }
    if(data < root->data){
        root->left = insertBST(root->left,data);
    }else{
        root->right = insertBST(root->right,data);
    }
    return root;
}

void inOrder(node *root){
    if(root == NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}

int main()
{
    node *root = NULL;
    int data[14]={10, 5, 15, 2, 7, 13, 18, 1, 4, 6, 9, 12, 14, 16};

    for(int i = 0 ; i<14;i++){
        root=insertBST(root,data[i]);
    }

    cout<<"In-Order Is : ";
    inOrder(root);

    return 0;
}
