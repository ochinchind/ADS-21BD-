#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    Node* temp1 = new Node();
    Node* temp = node;
    temp1 = node; 
    Node* temp2 = new Node();
    temp2 = head;
    p++;
    if(p == 1)
    {
        temp1->next = head;
        head = temp1;
        return head;
    }
    
    for(int i=0;i<p-2;i++)
    {
        temp2 = temp2->next;
    }
    
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}

 
Node* remove(Node* head, int p){
    if (head == NULL) {
      return head;
   }
   struct Node* temp = head;
   Node* prev = NULL;
   if (p == 0) {
      head = head->next;
      return head;
   }
   int i = 0;
   while(temp!=NULL){
        if(i == p){
            prev->next=temp->next;
            delete temp;
        }
        prev =temp;
        temp=temp->next;
        i++;
   }
   return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if(p1 == p2){
        return head;
    }
    
    Node* cur = head;
    Node* a = new Node();
    int p3 = p1;
    p3++;
    while(p3--){
        if(p3==0){
            a->val = cur->val;
            break;
        } else cur=cur->next;
    }
    
    head = remove(head, p1);

    head = insert(head, a, p2);
    return head;
}
 
Node* reverse(Node* head){
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (head);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}
 
void print(Node* head){
    if (head == NULL){
        cout << "-1";
    } else
    while (head!=NULL)  
    {  
        cout<<head->val<<" ";  
        head = head->next;  
    }  
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int x){
    if(head == NULL) {
        return head;
    }

    int a = 1, v;
    Node* just = head; 
    while (just -> next != NULL){
        just = just -> next;
        a++;
    }
    v=x%a;
    if(v==a ||v==0){
        return head;
    }
    just->next = head;
    just = head;
    for(int i =0; i<x-1; i++){
        just = just->next;
    }
    head = just->next;
    just->next = NULL;
    return head;
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

Node* cyclic_right(Node* head, int x){
    int a = getCount(head);
    if(x == 0|| a==x){
        return head;
    }
    int b = a-x;
    head = cyclic_left(head, b);
    return head;

}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
