// Problem link: https://leetcode.com/problems/squares-of-a-sorted-array/
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int r = nums.size() - 1;
     int l = 0;
     vector<int> ret(r + 1);
     int idx = r;
     while(l <= r){
        if(abs(nums[l]) >= abs(nums[r])){
            ret[idx] = nums[l] * nums[l];
            l++;
        }else{
            ret[idx] = nums[r] * nums[r];
            r--;
        }
        idx--;
     }
     return ret;   
    }
};