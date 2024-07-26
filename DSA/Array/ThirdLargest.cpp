// * Asked in coding round of 3-4 Companies in our college
#include<bits/stdc++.h>
using namespace std;

int thirdLargest(int arr[], int n) {
  int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    for(int i = 0; i < n; i++) {
      if (arr[i] > first) {
          third = second;
          second = first;
          first = arr[i];
        } 
      else if (arr[i] > second) {
          third = second;
          second = arr[i];
      } 
      else if(arr[i] > first) 
        third = arr[i];
    }
    return third;
}

int main()
{
  int arr[] ={12, 12, 3,3,4,1};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << thirdLargest(arr, n);

  return 0;
}