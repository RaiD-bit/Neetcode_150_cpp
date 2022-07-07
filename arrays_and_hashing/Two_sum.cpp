// problem link: https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       /* there are multiple ways to solve  this problem. In this approach 
        * i will use unordered_map. I will iterate over the nums array and for 
        * each item i will check if curr item is present in the map with value as current index
        * If its not present 
        * i will put target - curr element into the map.
        * if it present it means there exist it complement in the array and we have already
        * encountered it.
        * Lets have a dry run
        * array : [2 7 11 15]
        *          ^          check if two is present     umap = {} since not present put 9 - 2 in the map
        *                                                  map becomes {{7, 0}}
        * array   [2 7 11 15]
        *            ^        check if 7 is present  --> yes it is there in the map so we have got our ans.
        *                     we can return {current index, umap[nums[current index]]}
       */

        unordered_map<int, int> umap;
        for(int i = 0; i<nums.size(); i++){
            if(umap.find(nums[i]) == umap.end()){
                umap[target - nums[i]] = i;
            }else{
                return {umap[nums[i]], i};
            }
        }
        return {};
    }

};


int main (int argc, char *argv[])
{
    vector<int> v = {2, 7, 11, 15};
    vector<int> s = Solution().twoSum(v, 9);
    cout << s[0] << " " << s[1] << endl;
    return 0;
}
