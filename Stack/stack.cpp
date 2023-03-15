#include "bits/stdc++.h"
using namespace std;
class Stack {
        public:
        int *arr;
        int top;
        int size;
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int ele){
            if(size-top > 1){
                arr[++top] = ele;
                
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
        }
        void pop(){
                if(top>=0){
                    top--;
                }
                else{
                    cout<<"Stack Underflow";
                }
        }
        void peek(){
           if(top>=0 && top < size){
               cout<<arr[top]<<endl;
           }
           else{
              cout<<"stack is empty"<<endl;
           }
        }
        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }
        void print(){
            for (int i = 0; i <= top; i++)
            {
                cout<<i[arr]<<" "<<endl;
            }
            
        }
};
int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.pop();
    st.isEmpty() ? cout<<"stack is Empty" : cout<<"stack is not Empty";


return 0;
}