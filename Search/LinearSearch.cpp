#include "bits/stdc++.h"
using namespace std;
int main(){
  int arr[10] = {0,1,2,3,4,5,6,7,8,9};
  int num;
  cin>>num;
  bool flag = false;
  for (int i = 0; i < 10; i++)
      if(arr[i] == num)
          flag = !flag;
  
   flag?cout<<"found":cout<<"not found";
      
   
  
return 0;
}