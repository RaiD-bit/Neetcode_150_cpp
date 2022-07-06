// problem statement: https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int z = 0;
        set<int> s;
        for(auto num: nums){
            // z = num^z;
            if(s.find(num) == s.end()){
                s.insert(num);
            }else{
                return true;
            }
        }
        return false;

    }
};


int main (int argc, char *argv[])
{
    vector<int> v = {1,2,3,1};
    bool s = Solution().containsDuplicate(v);
    cout << s << endl;
    return 0;
}
