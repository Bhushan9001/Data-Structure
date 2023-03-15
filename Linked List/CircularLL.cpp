#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
          int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Node with value "<<val<<" is deleted"<<endl;
    }
};
void print(Node* tail){
     Node* temp = tail;
     do
     {
        cout<<tail->data<<" ";
        tail = tail->next;
     } while (tail!=temp);
     cout<<endl;
     
}
void insert(Node* tail , int ele , int d){
        Node* newNode = new Node(d);
        if(tail == NULL){
            tail = newNode;
            newNode->next = tail;
        }
        else{
            Node* cur = tail;
            while(cur->data != ele){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
}
void deleteNode(Node* &tail , int d){
    Node* prev = tail;
    Node* cur = prev->next;
    while(cur->data !=d){
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    if(cur == prev)
        tail = NULL;
    else if(tail == cur)
        tail = cur->next;
    
    cur->next = NULL;
    delete cur;
    
}
int main(){
    Node* node = new Node(5);
    Node* tail = node;
    insert(tail ,5,4 );
    insert(tail,4,3);
    insert(tail,4,2);
    deleteNode(tail,2);
    print(tail);

return 0;
}