#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> twoSum(int target,int lo, int hi, vector<int> &nums){
        vector<vector<int>> ans;
        // cout << lo << " " << hi <<endl;
        while(lo < hi){
            if(nums[lo] + nums[hi] == target){
                ans.push_back({lo, hi});
                lo++;
                hi--;
            }
            else if(target > nums[lo] + nums[hi]){
                lo++;
            }
            else{
                hi--;
            }
        }
        // for(auto x: ans){
        //     cout << x[0] << " " << x[1] <<endl;
        // }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(i-1>=0 && nums[i] == nums[i-1]){
                continue;
            }
            else{
                vector<vector<int>> temp = twoSum(0-nums[i], i+1, n-1, nums);
                for(auto x: temp){
                   ans.push_back({nums[i],nums[x[0]],nums[x[1]]}); 
                }
            }
            
        }

        for(auto x: ans){
            cout << x[0] << " " << x[1]  << " " << x[2] <<endl;
        }
        return ans;
    }
};
int main (int argc, char *argv[])
{
    // vector<int> v = {-1,0,1,2,-1,-4};
    vector<int> v = {0,0,0,0};
    Solution().threeSum(v);
    return 0;
}
