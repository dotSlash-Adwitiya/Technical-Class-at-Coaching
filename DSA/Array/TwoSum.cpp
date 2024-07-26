#include<bits/stdc++.h>
using namespace std;

// * Brute Force NAIVE Solution
// * T.C: O(n²)
vector<int> twoSum(vector<int>& nums, int target) {
  int n = nums.size();
  for(int i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
        if(nums[i] + nums[j] == target)
            return {i, j};  
    }
  }
  return {-1,-1};
}

// * Optimised Approach using Unordered_MAP
// * T.C: O(N), S.C: O(N)
// * ump[target - nums[i]]
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> ump;
  for(int i = 0; i < nums.size(); i++) {
    int currEle = nums[i];
      if(ump.find(target - currEle) != ump.end())
          return {i,ump[target - currEle]};
      ump[currEle] = i;
  }
  return {-1,-1};
}