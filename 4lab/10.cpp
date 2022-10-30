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

    node* insertion1(vector <int> &vec, int st, int end){
        if(st > end) return NULL;

        int mid = (st + end) /2;

        node* root=new node(vec[mid]);

        root->left = insertion1(vec, st, mid-1);
        root->right = insertion1(vec, mid+1, end);
        return root;

    }

    node* insertion1(vector<int> &vec){
        return insertion1(vec, 0, vec.size() -1);
    }

    int geth(){
        return geth(root);
    }
    int geth(node *cur){
        if(cur == NULL)
        return 0;
        return max(geth(cur -> left), geth(cur -> right)) + 1;

    }


    node* show(node* cur){
        if(cur !=NULL){
            
            cout << cur->key << " ";
            show(cur->left);
            show(cur->right);
        }

    }

    void show(){
        show(root);
    }



};

int main(){
    BST bst;

    int n; cin >> n;
    vector<int> vec;
    for(int i =0; i<pow(2, n) - 1; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    bst.root = bst.insertion1(vec);
    bst.show();




}

