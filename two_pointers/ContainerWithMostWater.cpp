// problem link: https://leetcode.com/problems/container-with-most-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int lo = 0, hi = n-1;
        int ans = INT_MIN;
        
        while(lo < hi){
            ans = max(ans, min(heights[lo],heights[hi])*(hi-lo));
            if(heights[lo] < heights[hi])
                lo++;
            else
                hi--;
        }
        return ans;
    }
};

int main(){
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(v) << endl;

}
