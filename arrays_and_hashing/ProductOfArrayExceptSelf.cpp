#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l;
        vector<int> r;
        int n = nums.size();
        l.push_back(1);
        r.push_back(1);
        for(int i = 0; i<n; i++){
            l.push_back(l.back()*nums[i]);
            r.push_back(r.back()*nums[n-i-1]);
        }
        l.push_back(1);
        r.push_back(1);
        reverse(r.begin(), r.end());
        vector<int> ans;
        for(int i = 1; i<=n; i++){
            ans.push_back(l[i-1]*r[i+1]);
        }
        return ans;
    }
};

int main(){
    vector<int> v = {1, 2, 3, 4};
    vector<int> ans = Solution().productExceptSelf(v);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
}
