// Problem link: https://leetcode.com/problems/sqrtx/
class Solution {
public:
    int mySqrt(int x) {
        int r = x, l = 0;
        if(x == 1)
            return 1;
        while(r > l + 1){
            int mid = l + (r - l) / 2;
            (long long)mid * mid <= x ? l = mid : r = mid;
        }
        return l;
    }
};