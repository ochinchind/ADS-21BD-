#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int cnt;
struct node {
	node *left;
	node *right;
	int key;


	node(int _key = 0) {
		left = right = NULL;
		key = _key;
	}

	node(int key, node *left, node *right) 
		: key(key), left(left), right(right) {
	}



};

struct BST {
	node *root = NULL;
	void insert(node *cur, int x) {
		node *next = NULL; 
		if (x <= cur->key) {
			if (cur->left == NULL) {
				cur->left = new node(x);
				return;
			}
			next = cur->left;
		}
		else {
			if (cur->right == NULL) {
				cur->right = new node(x);
				return;
			}
			next = cur->right;
		}
		insert(next, x);
	}

	void insert(int x) {
		if (root == NULL){

			root = new node(x);
        }
		else{
			insert(root, x);
        }
	}

	node* find(node *cur, int x) {
		if (x == cur->key)
			return cur;
		if (x < cur->key)
			return cur->left == NULL 
				? NULL 
				: find(cur->left, x);
		return cur->right == NULL
			? NULL
			: find(cur->right, x);
	}

	node* find(int x) {
		return find(root, x);
	}

	void print(node *cur, int tab = 1) {
		if (cur != NULL)
			printf("[%d]\n", cur->key);
		else {
			puts("");
			return;
		}
		for (int i = 0; i < tab; i++) putchar('\t');
		printf("L ");
		print(cur->left, tab + 1);
		for (int i = 0; i < tab; i++) putchar('\t');
		printf("R ");
		print(cur->right, tab + 1);
	}

	void print() {
		print(root);
	}



	node* del(node *cur, int x) {
		if (cur == NULL)
			return NULL;

		if (x < cur->key) {
			
			cur->left = del(cur->left, x);

		} else if (cur->key < x) {

			cur->right = del(cur->right, x);

		} else { 
			if (cur->left == NULL && cur->right == NULL) {
				delete cur;
				return NULL;
			}
			if (cur->left == NULL || cur->right == NULL) {
				node *next = cur->left != NULL 
					? cur->left
					: cur->right;
				delete cur;
				return next;
			}
			node *next = cur->right;
			while (next->left != NULL)
				next = next->left;
			cur->key = next->key;
			cur->right = del(cur->right, next->key);

		}
		return cur;
	}

	void del(int x) {
		root = del(root, x);
	}

    node* finding(node* cur, string c){
        for(int i =0; i <c.length(); i++){
            if (c.at(i) == 'L' ){
                if(cur->left !=NULL){
                    cur=cur->left;
                } else return NULL;
            }
            else {
                if(cur->right !=NULL){
                    cur = cur->right;
                } else return NULL;
            }
            

        }
        return cur;

    }
    node* finding(string x) {
		return finding(root, x);
	}


} bst;

void cnt1(node *cur){
    cnt++;
    if(cur->left != NULL){
        cnt1(cur->left);
    }
    if (cur->right != NULL){
        cnt1(cur->right);
    }
}

void print(node* cur){
    cout << cur->key << " ";
    if(cur->left != NULL){
        print(cur->left);
    }
    if (cur->right != NULL){
        print(cur->right);
    }
}

int main() {

	BST bst;
	int n, k, a;
    cin >> n;
    for(int i =0; i<n; i++){
        cin >> a;
        bst.insert(a);
    }
    cin >> k;
    node *s = bst.find(k);
    print(s);
    


	return 0;
}