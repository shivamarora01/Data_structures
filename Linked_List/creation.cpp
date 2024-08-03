#include <iostream>
using namespace std;
class Node {
    public:
     int data;
     Node* next;

     Node(int data){
        this->data = data;
        this->next = NULL;
     }
};

void insertAtHead(Node* &head, int data){
     Node* temp = new Node(data);
     temp->next = head;
     head = temp;
}

void insertAtTail(Node* head, int data){
     Node* addingNode = new Node(data);
     Node* temp = head;
     Node* lastNode;
     while( temp != NULL){
         lastNode = temp;
         temp = temp->next;
     }
     lastNode->next = addingNode;
}

void insertAtTail2(Node* temp, int data){
     Node* addingNode = new Node(data);
     while( temp->next != NULL){
         temp = temp->next;
     }
     temp->next = addingNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtHead(head , 5);
    print(head);
    insertAtHead(head , 2);
    print(head);
    insertAtTail2(head , 20);
    print(head);
    insertAtTail2(head , 28);
    print(head);
    insertAtHead(head , 1);
    print(head);
    return 0;
}