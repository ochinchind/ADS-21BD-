#include <iostream>
using namespace std;
#include <cmath>

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

Node* cyclicShift(Node* head, int k) {
    if(head == NULL) {
        return head;
    }

    int a = 1, v;
    Node* just = head; 
    while (just -> next != NULL){
        just = just -> next;
        a++;
    }
    v=k%a;
    if(v==a ||v==0){
        return head;
    }
    just->next = head;
    just = head;
    for(int i =0; i<k-1; i++){
        just = just->next;
    }
    head = just->next;
    just->next = NULL;
    return head;
}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}