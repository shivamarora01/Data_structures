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
     cout<<"Insert "<<data<<" at Head"<<endl;
     Node* temp = new Node(data);
     temp->next = head;
     head = temp;
}

void insertAtTail(Node* head, int data){
     cout<<"Insert "<<data<<" at Tail"<<endl;
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
     cout<<"Insert "<<data<<" at Tail"<<endl;
     Node* addingNode = new Node(data);
     while( temp->next != NULL){
         temp = temp->next;
     }
     temp->next = addingNode;
}

void insertAtMiddle(Node* &head, int position, int data){
    cout<<"Insert "<<data<<" at " <<position<<" position"<<endl;
    Node* NodeToAdd = new Node(data);
    Node* previousNode;
    Node* temp = head;
    int count = 1;
    while(count < position){
        previousNode = temp;
        temp = temp->next;
        count++;
    }
    if(position != 1){
            previousNode->next = NodeToAdd;
    }
    NodeToAdd->next = temp;
    if(position == 1){
        head = NodeToAdd;
    }
}
void insertAtMiddle2(Node* &head, int position, int data){
    cout<<"Insert "<<data<<" at " <<position<<" position"<<endl;
    Node* NodeToAdd = new Node(data);
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }
    Node* previousNode = temp;
    NodeToAdd->next = temp->next;
    temp->next = NodeToAdd;
    if(position == 1){
        head = NodeToAdd;
    }
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
    insertAtMiddle(head, 3, 4);
    print(head);
    insertAtMiddle(head, 8, 38);
    print(head);
    insertAtMiddle(head, 1, 0);
    print(head);
    insertAtMiddle2(head, 7, 15);
    print(head);
    print(head);
    insertAtMiddle2(head, 1, -15);
    print(head);
    return 0;
}