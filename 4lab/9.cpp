#include <iostream>
#include <queue>
using namespace std;
int cnt=0;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data <= data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}
void cnt1(Node *cur, int x){
    if (cur == NULL){
        return;
    }
    if (cur->data == x){
        cnt++;
    }
    cnt1(cur->left, x);
    cnt1(cur->right, x);
}

int main(){
    Node *bst = NULL;
    int n; cin >> n;
    for (int i =0; i<n; i++){
        cnt = 0;
        string str;
        int x;
        cin >> str;
        if (str == "cnt"){
            cin >> x; 
            cnt1(bst, x);
            cout << cnt << "\n";
        }
        if (str == "insert"){
            cin >> x; 
            bst = add(bst, x);
        }
        if (str == "delete"){
            cin >> x; 
            bst = deleteNode(bst, x);
        }


    }


}