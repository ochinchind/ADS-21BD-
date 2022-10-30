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

    void insroot(){
        root = new node(1);
    }

    void inser(int x, int y, int z){
        insert(root, x, y, z);
    }
    
    void insert(node *cur, int x, int y, int z){
        if(cur!=NULL){
            if(cur->key == x){
               insert1(cur, x, y,z);
            }
            insert(cur->left, x, y,z);
            insert(cur->right, x,y,z);
        }
    }
    void insert1(node *cur, int x, int y, int z){
        if(z == 0) cur->left = new node(y);
        if (z == 1) cur->right = new node(y);

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
    bst.insroot();
    for(int i =1; i<n; i++){
        int x,y,z;
        cin >> x >> y >> z;
        bst.inser(x,y,z);
    }

    int h = bst.geth();

     int mx = 0;
    int arr[h] = {0};
    bst.levelsum(0, arr);
    for(int i =0; i <h; i++){
        if (arr[i] > mx){
            mx = arr[i];
        }
    }
    cout << mx;
    


}

