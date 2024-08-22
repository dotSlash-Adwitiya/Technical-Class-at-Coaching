#include<bits/stdc++.h>
using namespace std;

bool isFrequencyUnique(int n, int arr[]) {
  unordered_map<int, int> ump1, ump2;
  
  for(int i = 0; i < n; i++)
      ump1[arr[i]]++;
      
  for(auto it = ump1.begin(); it != ump1.end(); it++){
      if(ump2.find(it->second) != ump2.end())
          return false;
      ump2[it->second]++;
  }
  
  return true;
}