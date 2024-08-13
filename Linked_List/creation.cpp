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

void deleltionByValue(Node* &head, int value){
    cout<<"Delete value "<<value<<" from Linked List"<<endl;
    Node* curr = head;
    Node* prev = nullptr;
    Node* ahead = nullptr;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    ahead = curr->next;
    if(prev == nullptr){
        head = head->next;
    }
    else{
        prev->next = ahead;
    }
}

void deleltionByPosition(Node* &head, int position){
    cout<<"Delete value by Position "<<position<<" from Linked List"<<endl;
    Node* curr = head;
    Node* prev = nullptr;
    int count = 1;
    Node* ahead = nullptr;
    if(position == 1){
        head = head->next;
        delete curr;
    }
    else{
    while(count <= position - 1){
        prev = curr;
        curr = curr->next;
        count++;
    }
    ahead = curr->next;
    prev->next = ahead;
    }
}

void reverseFromMiddle(Node* &head, int left, int right){
    int count = 1;
    Node* temp = head;
    Node* prevLeft = nullptr;
    while(count < right){
        if(count < left){
            prevLeft = temp;
        }
    temp = temp->next;
    count++;
    }
    Node* mainRight;
    Node* mainLeft;
    Node* rightNext;
    if(prevLeft == nullptr){
         mainLeft = head;
         head = temp;
         mainRight = temp;
         rightNext = temp->next;
    }
    else{
    mainLeft = prevLeft->next;
    mainRight = temp;
    prevLeft->next = temp;
    rightNext = temp->next;
    }
    int counter = 0;
    Node* temp1 = mainLeft;
    Node* prev = nullptr;
    while(counter <= right-left){
        Node* nextNode = temp1->next;
        temp1->next = prev;
        prev = temp1;
        temp1 = nextNode;
        counter++;
    }
    mainLeft->next = rightNext;
}

Node* rotateList(Node* head, int k){
    int n = 0;
    Node* temp = head;
    Node* tail;
    while(temp != nullptr){
        n++;
        tail = temp;
        temp = temp->next;
    }
    cout<<"count "<<n<<endl;
    k = k%n;
    cout<<"updated k "<<k<<endl;
    if(k == 0 || k == n){
        return head;
    }
    int i = 1;
    temp = head;
    while(i < n-k){
        temp = temp->next;
        i++;
    }
    Node* lastBeforeRotate = temp;
    cout<<"lastBeforeRotate "<<lastBeforeRotate->data<<endl;
    Node* newHead = temp->next;
    tail->next = head;
    lastBeforeRotate->next = nullptr;
    return newHead;
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
    insertAtMiddle2(head, 1, -15);
    print(head);
    deleltionByValue(head, 10);
    print(head);
    deleltionByValue(head, 38);
    print(head);
    deleltionByValue(head, -15);
    print(head);
    deleltionByValue(head, 1);
    print(head);
    deleltionByPosition(head, 2);
    print(head);
    deleltionByPosition(head, 5);
    print(head);
    deleltionByPosition(head, 1);
    print(head);
    insertAtMiddle(head, 1, 2);
    print(head);
    insertAtMiddle2(head, 5, 25);
    print(head);
    // reverseFromMiddle(head, 2, 4);
    // print(head);
    reverseFromMiddle(head, 1, 4);
    print(head);
    reverseFromMiddle(head, 1, 4);
    print(head);
    Node* newHead = rotateList(head, 3);
    print(newHead);
    return 0;
}