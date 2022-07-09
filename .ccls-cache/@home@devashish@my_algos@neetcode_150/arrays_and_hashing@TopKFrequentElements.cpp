#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> umap;
        for(auto x: nums){
            umap[x]++;
        }
        for(auto x: umap){
            pq.push({x.second, x.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


int main(){
    vector<int> v = {2,1,1,2,2,3};
    int k = 2;
    vector<int> ans = Solution().topKFrequent(v,k);
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
}
