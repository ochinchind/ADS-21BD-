#include <iostream>
using namespace std; 

class Node  
{  
    public: 
    int data;  
    Node* next;  
};  
  


void push(Node** head_ref, int new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 
void pushwhere(Node** head, int new_data, int position){
    position = position +1;
    while(position--){
        if (position == 0){
            Node* cur;
            push(&cur, new_data);
            cur->next = *head;
            *head = cur;
        } else head = &(*head)->next;
    }
}

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  

void reverse(Node** head_ref) {
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

int main()  
{  
    int n;
    int s;
    cin>>n;
    Node*head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
    reverse(&head);   
    cin >> n;
    cin >> s;
    pushwhere(&head, n, s);   
                                

    printList(head);              
  
    return 0;  
}