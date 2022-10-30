#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node* temp = new Node(s);
	tail = head;
	Node* cur = head;
	while (cur){
		tail = cur;
		cur = cur->next;
	}
	if(head ==NULL){
		head=tail=temp;
	}else{
		tail ->next = temp;
		tail = temp;
	}
	cnt++;
}
void add_front(string s){
    Node* new_node = new Node(s);
	new_node->next = head;
    head = new_node;
	cnt++;
}
bool empty(){
    if (head == NULL ){
        return true;
    }
    return false;
}
void erase_front(){
    if(cnt == 0){
		head =NULL;
	} else{
		head = head->next;
	}
	cnt--;
}
void erase_back(){
	Node* temp = head;
	Node* prev=NULL;
	if (cnt == 0 || cnt ==1){
		head = NULL;
	} else{
		while(temp!=NULL){
			if(temp->next == NULL){
				prev->next = temp->next;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	cnt--;
}
string front(){
	Node* cur = head;
	return cur ->val;
}
string back(){
	tail = head;
	Node* cur = head;
	while(cur){
		tail = cur;
		cur=cur->next;
	}
	return tail->val;

}
void clear(){
	Node* temp = NULL;
  	while(head != NULL) {
    	temp = head;
    	head = head->next;
    	free(temp);
  	}
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}