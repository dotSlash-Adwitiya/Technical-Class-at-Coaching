#include<bits/stdc++.h>
using namespace std;

// * Reverse using O(N) Time and Space
queue<int> modifyQueue(queue<int> q, int k) {
  stack<int> stk;
  int n = q.size();
  int cnt = 0;
  while(cnt < k){
      int frontEle = q.front();
      stk.push(frontEle);
      q.pop();
      cnt++;
  }
  
  queue<int> revQ;
  
  while(!stk.empty()){
      int topEle = stk.top();
      revQ.push(topEle);
      stk.pop();
  }
  
  while(!q.empty()){
      int frontEle = q.front();
      revQ.push(frontEle);
      q.pop();
  }
  return revQ;
}

// * Reverse using O(N) Time and O(K) Space
queue<int> modifyQueue(queue<int> q, int k) {
  // if(k > q.size()) return q; // * Defined in constraints it will never be the case.
  
  stack<int> stk;
  int cnt = 0;
  while(cnt < k){
      int frontEle = q.front();
      stk.push(frontEle);
      q.pop();
      cnt++;
  }
  
  while(!stk.empty()){
      int topEle = stk.top();
      q.push(topEle);
      stk.pop();
  }
  
  int size = q.size() - k;
  
  while(size--){
      int frontEle = q.front();
      q.push(frontEle); // * Shift the front Ele to the bacl
      q.pop();// * Remove from front
  }
  
  return q;
}

int main()
{
  queue<int> q;
  q.push(1);
  q.emplace(3);
  q.emplace(4);

  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }
  return 0;
}