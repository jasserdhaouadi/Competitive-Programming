// Problem link: https://leetcode.com/problems/find-center-of-star-graph/description/
#include <vector>
class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        if(edges[0][0] == edges[1][0])
            return edges[0][0];
        if(edges[0][0] == edges[1][1])
            return edges[0][0];
        return edges[0][1];
    }
};