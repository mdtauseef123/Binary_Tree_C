#include<bits/stdc++.h>
using namespace std;


struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};


struct Node *root=NULL;


struct Node* create_node(int num){
    struct Node *new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=num;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}


void create_binary_tree(){
    struct Node *temp;
    int num;
    queue<struct Node*> node;
    printf("Enter the root value:- ");
    scanf("%d",&num);
    root=create_node(num);
    node.push(root);
    while(!node.empty()){
        temp=node.front();
        node.pop();
        printf("Enter the left child of %d:- ",temp->data);
        scanf("%d",&num);
        if(num!=-1){
            struct Node *left_child=create_node(num);
            temp->left=left_child;
            node.push(left_child);
        }
        printf("Enter the right child of %d:- ",temp->data);
        scanf("%d",&num);
        if(num!=-1){
            struct Node *right_child=create_node(num);
            temp->right=right_child;
            node.push(right_child);
        }
    }
}


void preorder_traversal(struct Node *temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}


void inorder_traversal(struct Node *temp){
    if(temp!=NULL){
        inorder_traversal(temp->left);
        printf("%d ",temp->data);
        inorder_traversal(temp->right);
    }
}


void postorder_traversal(struct Node *temp){
    if(temp!=NULL){
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->data);
    }
}


int main(){
    create_binary_tree();
    printf("Pre-order Traversal:- \n");
    preorder_traversal(root);
    printf("\nIn-order Traversal:- \n");
    inorder_traversal(root);
    printf("\nPost-order Traversal:- \n");
    postorder_traversal(root);
    return 0;
}
