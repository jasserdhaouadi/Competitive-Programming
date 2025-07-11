// Problem link: https://leetcode.com/problems/two-sum/
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        for(int i=0; i<(int)nums.size(); i++){
            if(m.find(target-nums[i]) != m.end()){
                return {m[target-nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {0, 0};
    }
};
