#include <iostream>
#include <vector>
using namespace std; 

class Node  
{  
    public: 
    char data;  
    Node* next;  
};  
Node* head = NULL;
  
void removeDuplicates(Node *&head)  
{  
    Node *cur, *cur1, *cur2;
    cur = head;
    while (cur != NULL && cur->next != NULL){
        cur1 = cur;
        while (cur1->next != NULL){
            if (cur->data == cur1->next->data){
                cur2 = cur1->next;
                cur1->next = cur1->next->next;
                delete(cur2);
            }
            else 
                cur1 = cur1->next;
        }
        cur = cur->next;
    }


}  

int getCount(Node* head)  
{  
    int count = 0; 
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }

    return count;  
}  

void push(char new_data)  
{  
    Node* cur=head;
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next =NULL;
    if(cur == NULL){
        (head) = new_node;
    }else{
    while(cur->next !=NULL){
        cur=cur->next;
    }
    cur->next = new_node;
    }
    
    
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

void printAll(vector<int> vec){
    while(head!=NULL && vec[head->data - 'a'] > 1){
        head = head->next;
    }
    if (head == NULL){
        cout << -1 << " ";
    } else {
        cout << head ->data<< " ";
    }
}

int main()  
{  
    int n,k;
    char s;
    
    cin>>n;
    for(int j = 0; j <n; j++){
        vector <int> vec(30,0);
        cin>>k;
        head = NULL;  
        for(int i =0;i<k;i++){
            cin>>s;
            vec[s-'a']++;
            push(s);
            printAll(vec); 
        } cout << "\n";
    }
    return 0;  
}