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

    void insertright(node *cur, int x, int y){
        if(cur == NULL){
            return;
        }
        if (cur->key == x){
            cur->right = new node(y);
        } else {
            if(cur->left != NULL)
                insertright(cur->left, x , y);
            if(cur->right != NULL)
                insertright(cur->right, x , y);
        }

    }
    void insertright(int x, int y){
        if(root == NULL){
            root = new node(x);
            root->right = new node(y);
        }
        insertright(root, x, y);

    }

    void insertleft(node *cur, int x, int y){
        if(cur == NULL){
            return;
        }
        if (cur->key == x){
            cur->left = new node(y);
        } else {
            if(cur->left != NULL)
                insertleft(cur->left, x , y);
            if(cur->right != NULL)
                insertleft(cur->right, x , y);
        }

    }
    void insertleft(int x, int y){
        if(root == NULL){
            root = new node(x);
            root->left = new node(y);
        }
        insertleft(root, x, y);

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

    void suming(node* cur, int arr[]){
        if (cur == NULL) return;
        if (cur->left != NULL && cur->right != NULL){
            arr[0] += 1;
        }
        suming(cur->left, arr);
        suming(cur->right, arr);
    }

    void suming(int arr[]){
        suming(root, arr);
    }

    void levelsum(node *cur, int h, int arr[]){
        if (cur == NULL) return;

        arr[h] += 1;
        levelsum(cur->left, h+1, arr);
        levelsum(cur->right, h+1, arr);
    }

    void levelsum(int h, int arr[]){
        levelsum(root, h, arr);
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



    int arr[1] = {0};
    bst.suming(arr);
    cout << arr[0];
    


}

