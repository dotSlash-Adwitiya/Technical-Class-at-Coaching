#include<bits/stdc++.h>
using namespace std;

class Stack {
  private:
    int *arr;
    int topEle;
    int capacity;
  public:
    Stack(); // * Non-PArameterized
    Stack(int x); // * Parameterized
    bool isEmpty(); // * Check if empty O(1)
    int size(); //* O(1)
    void push(int x); // * O(1)
    void pop(); // * O(1)
    int top(); // * O(1)
};

Stack::Stack(){
  arr = new int[10];
  this->topEle = -1;
  capacity = 10;
}

Stack::Stack(int x){
  arr = new int[x];
  this->topEle = -1;
  capacity = x;
}

bool Stack::isEmpty(){
  return topEle == -1; // * == returns a boolean value
}

int Stack::size(){
  return this->topEle+1; // * Because indexing is done from 0
}

void Stack::push(int x){
  if(this->topEle == this->capacity-1)
    cout << "STACKOVERFLOW!!" << endl;
  else
    this->arr[++this->topEle] = x;
}

void Stack::pop(){
  if(this->isEmpty())
    cout << "STACKUNDERFLOW!!" << endl;
  else
    this->topEle--; 
}

int Stack::top(){
  if(this->isEmpty()){
    cout << "STACK is EMPTY" << endl;
    return -1;
  }
  else 
      return this->arr[topEle];
}

int main()
{
  Stack stk;
  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);
  stk.push(6);
  stk.push(7);
  stk.push(8);
  stk.push(9);
  stk.push(10);
  stk.push(1);

  while(!stk.isEmpty()){
    cout << stk.top() << " ";
    stk.pop();
  }

  cout << endl;
  stk.pop();

  return 0;
}