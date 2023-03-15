#include "bits/stdc++.h"
using namespace std;
class Stack{

    public:
    int size , top1 , top2 ;
    int *arr;

    Stack(int size){
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];

    }

    void push1(int ele){
        if(top2-top1 > 1){
             arr[++top1] = ele;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    void push2(int ele){
        if(top2-top1 > 1){
            arr[--top2] = ele;
        }
    }

    void pop1(){
        if(top1>=0){
            cout<<arr[top1--]<<endl;
        }
    }
    void pop2(){
        if(top2 < size){
            cout<<arr[top2++];
        }
    }
    void peek1(){
        cout<< arr[top1]<<endl;
    }
    void peek2(){
        cout<< arr[top2]<<endl;
    }
};
int main(){
    Stack st(5);
    st.push1(5);
    st.push2(6);
    st.push2(7);
    st.peek2();
    st.push1(9);
    st.peek1();

return 0;
}