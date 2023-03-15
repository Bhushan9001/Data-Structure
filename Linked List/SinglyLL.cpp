#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }


};

void print(Node* head){
    
    while(head){ 

        cout<<head->data<<" ";
        head = head->next;

    }
    cout<<endl;
}

void insertatHead(Node* &head ,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertatTail(Node* &head , int d){
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    Node* newNode = new Node(d);
    temp->next = newNode;

    
}
void insertatPos(Node* &head , int d , int pos){
    Node* temp = head;
    int count = 1;
    if(pos == 1){
        insertatHead(head,d);
        return;
    }
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void deleteNode(Node* &head , int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* cur = head;
        Node* prev = NULL;
        int count = 1;
        while(count<pos){
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next= cur->next;
        cur->next = NULL;
        delete cur;

    }
}

Node* revereseLL(Node* head){
    if(!head) return NULL;
    Node* cur = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node* midNode(Node* head){
    if(!head) return NULL;
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


int main(){
    Node* node = new Node(6);
    Node* head = node;


    insertatHead(head , 50);
    insertatTail(head,9);
    insertatTail(head,5);
    insertatPos(head,7,3);
    print(head);
    deleteNode(head,2);
    print(head);
    // print(revereseLL(head));
    // Node* mid = midNode(head);
    // cout<<mid->data<<endl;

return 0;
}