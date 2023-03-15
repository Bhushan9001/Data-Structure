#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next!= NULL){
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }
        cout<<"Node with data "<<val<<" is deleted"<<endl;
    }
};
void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void insertatHead(Node* &head , int d){
    
    Node* newNode = new Node(d);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertatTail(Node* &head , int d){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node(d);
    temp->next = newNode;
    newNode->prev = temp;

}
void insertatPos(Node* &head , int d , int pos){
    if(pos == 1){
        insertatHead(head,d);
        return;
    }
    int count = 1;
    Node* temp = head;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insertatTail(head,d);
        return;
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        if(cur->next == NULL){
            cur->prev = NULL;
            prev->next = NULL;
            delete cur;
        }
        else{
            cur->next->prev = prev;
            prev->next = cur->next;
            cur->prev = NULL;
            cur->next = NULL;
            delete cur;
        }
    }
    
}
int main(){
       Node* node = new Node(9);
       Node* head = node;
       insertatHead(head,10);
       insertatTail(head,6);
       insertatPos(head,7,2);
       print(head);
       deleteNode(head,2);
       print(head);
return 0;
}