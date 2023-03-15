#include "bits/stdc++.h"
using namespace std;
class Queue{
    public:
    int *arr;
    int front;
    int rear;
    int n ;

    Queue(int size){
        n = size;
        arr = new int[n];
        front = 0;
        rear = 0;

    }

    void enqueue(int ele){
         if(rear == n){
            return;
         }
         else{
            arr[rear++] = ele;
         }
    }

    int dequeue(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front++] =-1;
            if(front == rear){
                front =0;
                rear =0;
            }
        return ans;
        }
    }
};
int main(){
      Queue q(5);
      q.enqueue(4);
      q.enqueue(5);
      q.enqueue(6);
      cout<<q.dequeue();
return 0;
}