#include "bits/stdc++.h"
using namespace std;
class Dequeue{
    public:
    int *arr;
    int front;
    int rear;
    int n;

    Dequeue(int size){
        n = size;
        arr = new int[size];
        front = -1;
        rear =-1;
    }

    void push_front(int ele){
          if((front == 0 && rear == n-1)||( rear == (front-1)%(n-1))){
             return;
          }
          if(front == -1){
            front = 0;
            rear =0;
          }
          else if(front == 0 && rear != n-1){
            front = n-1;
          }
          else {
            front --;
          }
          arr[front] = ele;
    }
    void push_back(int ele){
       
         if((front == 0 && rear == n-1)||( rear == (front-1)%(n-1))){
             return;
            }
            if(rear == -1){
                front = 0;
                rear = 0;
            }
            else if(rear == n-1 && front !=0){
                rear = 0;
            }
            else{
                rear++;
            }

            arr[rear] = ele;
        
           
    }
    int pop_front(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front]  = -1;
        if(front == rear-1){
            front = rear =-1;
        }
        else if(front == n-1){
            front = 0;
        }
        else{

            front++;
        }

        return ans;
    }
    int pop_back(){ 
        if(rear == -1){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear-1){
            front =-1;
            rear =-1;
        }
        else if( rear == 0){
            rear = n-1;
        }
        else{
            rear--;
        }

        return ans;
    }
};
int main(){
     Dequeue dq(5);

     dq.push_front(5);
     dq.push_back(10);
     dq.push_back(4);
     dq.push_back(11);
     cout<<dq.pop_back()<<endl;
     cout<<dq.pop_front()<<endl;
     cout<<dq.pop_front()<<endl;
     cout<<dq.pop_back()<<endl;

return 0;
}