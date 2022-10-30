#include <iostream>
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
        if(x<= cur->key){
            if(cur->left == NULL){
                cur->left = new node(x);
            } else{
                insert(cur->left, x);
            }

        } else if(cur->right == NULL){
            cur->right = new node(x);
        } else {
            insert(cur->right,x);
        }

    }

    int geth(){
        return geth(root);
    }
    int geth(node *cur){
        if(cur == NULL)
        return 0;
        else {
            int lefth = geth(cur->left);
            int righth = geth(cur->right);

            if(lefth>righth){
                return lefth+1;
            } else {
                return righth+1;
            }

        }

    }

    void levelsum(node *cur, int h, int arr[]){
        if (cur == NULL) return;

        arr[h] += cur->key;
        levelsum(cur->left, h+1, arr);
        levelsum(cur->right, h+1, arr);
    }

    void levelsum(int h, int arr[]){
        levelsum(root, h, arr);
    }


};

int main(){
    BST bst;
    int n,x; cin >> n;
    for(int i =0; i<n; i++){
        cin >> x;
        bst.insert(x);
    }

    int h = bst.geth();
    cout << h << "\n";

    int arr[h] = {0};
    bst.levelsum(0, arr);
    for(int i =0; i<h; i++){
        cout << arr[i]<< " ";
    }



}

