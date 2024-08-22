#include<bits/stdc++.h>
using namespace std;

class QueueUsingTwoStacks {
  stack<int> stk1, stk2;
  public:
    void enqueue(int x) {
        stk1.push(x);
    }

    int dequeue() {
      if(stk1.empty())
          return -1;
          
      while(stk1.size() != 1){
          int topEle = stk1.top();
          stk2.push(topEle);
          stk1.pop();
      }
      
      int ans = stk1.top(); // * Store last element before removal
      stk1.pop(); // * remove the last element
      
      // * Transfer all elements back to stk1
      while(!stk2.empty()){
          int topEle = stk2.top();
          stk1.push(topEle);
          stk2.pop();
      }
      return ans;
    }
};