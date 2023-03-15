#include "bits/stdc++.h"
using namespace std;
int main()
{   int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = 10;
    int key = 5;
    int start = 0, end = size - 1;
    
    bool flag= false;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key)
        {
            flag = true;
        }

        if (key > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

    }
        flag?cout<<"found":cout<<"not found";

    return 0;
}