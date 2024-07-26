#include<bits/stdc++.h>
using namespace std;

// * T.C: O(nlogn + mlogm)
// * S.C: O(1)
bool isAnagram(string a, string b){
  int n = a.size(), m = b.size();
  if(n != m) //  *For TC - aab aaab
      return false;
      
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  for(int i = 0, j = 0; i < n && j < m; j++, i++) {
      if(a[i] != b[j])
          return false;
  }

  return true;
}

// * T.C: O(n) (Optimised Approach)
// * S.C: O(1)
bool isAnagram(string a, string b){
  int n = a.size(), m = b.size();
  if(n != m) //  *For TC - aab aaab
      return false;
  
  int freq[26] = {0};
  
  for(int i = 0; i < n; i++) freq[a[i] - 'a']++;
      
  for(int j = 0; j < m; j++) freq[b[j] - 'a']--;
      
  for(int i = 0; i < 26; i++){
      if(freq[i] != 0){
          return false;
      }
  }
  return true;
}
