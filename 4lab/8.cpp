#include <iostream>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
 
struct node{
    int key;
    node *left, *right;
    node(int x){
        key = x;
        left=right=NULL;
    }

};

struct BST{
    node *root = NULL;
    int cnt=0;
    
    void insert(int x){
        if(root ==NULL){
            root= new node(x);
        } else {
            insert(root,x);
        }
    }
    void insert(node *cur, int x){
        if(x< cur->key){
            if(cur->left == NULL){
                cur->left = new node(x);
            } else{
                insert(cur->left, x);
            }

        }
        if(x > cur->key){
            if(cur->right == NULL){
                cur->right = new node(x);
            } else {
                insert(cur->right,x);
            }
        }

    }

    int geth(){
        return geth(root);
    }
    int geth(node *cur){
        if(cur == NULL)
        return 0;
        return max(geth(cur -> left), geth(cur -> right)) + 1;

    }

    node* change(node *cur){
        if(cur!=NULL){
            change(cur->right);
            cur->key += cnt;
            cnt = cur->key;
            change(cur->left);

        }
    }

    node* change(){
        change(root);
    }

    node* show(node* cur){
        if(cur !=NULL){
            show(cur->right);
            cout << cur->key << " ";
            show(cur->left);
        }

    }

    void show(){
        show(root);
    }



};

int main(){
    BST bst;

    int n; cin >> n;
    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        bst.insert(x);
    }

    bst.change();
    bst.show();




}

