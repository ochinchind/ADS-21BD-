
// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;
  
// A linked list Node
struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
  
// Size of linked list
int size = 0;
  
// function to create and return a Node
Node* getNode(int data)
{
    // allocating space
    Node* newNode = new Node();
  
    // inserting the required data
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}
  
// function to insert a Node at required position
void insertPos(Node** current, int pos, Node* node){
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else {
        pos++;
        while (pos--) {
            if (pos == 0) {
                Node* temp = node;
                temp->next = *current;
                *current = temp;
            }
            else
              current = &(*current)->next;
        }
        size++;
    }
}
  
// This function prints contents 
// of the linked list 
void printList(struct Node* head){
    while (head != NULL) {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}
  
// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    Node* head = NULL;
    head = getNode(3);
    head->next = getNode(5);
    head->next->next = getNode(8);
    head->next->next->next = getNode(10);
  
    size = 4;
  
    cout << "Linked list before insertion: ";
    printList(head);
  
    int data = 12, pos = 3;
    insertPos(&head, pos, new Node(data));
    cout << "Linked list after insertion of 12 at position 3: ";
    printList(head);
    data = 1, pos = 1;

  
    return 0;
}