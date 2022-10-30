#include <iostream>
using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
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

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = (*head_ref);  
    if(*head_ref == NULL){   
        (*head_ref) = new_node;  
    } else {
            Node* tail = new Node();
            tail = *head_ref;
            if(tail->data != new_data){
                (*head_ref) = new_node;  
            }
              
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

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      

    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}