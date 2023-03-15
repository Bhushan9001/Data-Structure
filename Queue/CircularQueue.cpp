#include "iostream"
using namespace std;
class CircularQ{
    public:
    int *arr;
    int front , rear ,n;
    

    CircularQ(int size){
        int n = size;
        arr = new int[n];
        front = -1;
        rear =-1;
    }

    bool Enqueue(int ele){
        if(front == -1){
            front =0;
            rear =0;
        }
        else if((front == 0 && rear == n-1)||( rear == (front-1)%(n-1))){
            return false;
        }
        else if(rear == n-1 && front != 0){
            rear = 0;
        }
        
        arr[rear++] = ele;
        return true;

    }

    int Dequeue(){
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front]  = -1;
        if(front == rear-1){
            front = rear =-1;
        }
        else if(front == n-1){
            front =0;
        }
        else{

            front++;
        }

        return ans;
    }

};



int main(){
    CircularQ q(5);
    cout<<q.Enqueue(5)<<endl;
    cout<<q.Enqueue(6)<<endl;
    cout<<q.Enqueue(4)<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Dequeue()<<endl;
    

return 0;
}