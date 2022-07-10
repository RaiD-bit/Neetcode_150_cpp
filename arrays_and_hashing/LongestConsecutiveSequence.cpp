// problem: https://leetcode.com/problems/longest-consecutive-sequence/
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutiveMethod1(vector<int>& nums) {
       /* the first approach that comes to mind is sort the array
        * then iterate over the array and keep track of consecutive sequence.
        * At the end return the longest one.
        * In this case the time complexity will be nlogn(due to sorting)
        * Also we will need to keep the array unique as there may be duplicates.
        */
        if(nums.size() == 0)
            return 0;
        unordered_set<int> us;
        vector<int> nums1;
        for(auto x: nums){
            if(us.find(x) == us.end()){
                us.insert(x);
                nums1.push_back(x);
            }
        }
        sort(nums1.begin(), nums1.end());
        int ans = 1;

        int n = nums1.size();
        int last = -1;
        for(int i = 0; i<n-1; i++){
            if(nums1[i] + 1 != nums1[i+1]){
                ans = max(ans,i - last);
                last = i;
            }
        }
        ans = max(ans, n-1-last);
        return ans;

    }

    int longestConsecutiveMethod2(vector<int>& nums) {
        /* This is a better way of solving this problem because it does it in O(n) time and O(n) space
            * We first go over the array and populate a set with elements of the array.
            * Then again we go over the array and for every element we check if its predecessor
            * is present in the set or not. because every element that doesnt have a predecessor
            * is a candidate from were a sequence of consecutive elements may start. So whenever we find
            * an element like this. We move to see in the forward direction to see how many consecutive 
            * element are there starting from here. we update ans every time a candidate is found to get the final
            * ans
        */
        int n = nums.size();
        if(n == 0)
            return 0;
        unordered_set<int> us;
        for(auto num: nums){
            us.insert(num);
        }
        int ans = 0;

        for(int i = 0; i<n; i++){
            if(us.find(nums[i]-1) == us.end()){
                int c = 1;
                while(us.find(nums[i]+c) != us.end()){
                    c+=1;
                }
                ans = max(ans,c);
            }
        }
        return ans;
    }

};

int main(){
    vector<int> v = {100,4,200,1,3,2};
    cout << Solution().longestConsecutiveMethod2(v) << endl;
}
