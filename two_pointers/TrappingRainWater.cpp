#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // not a two pointer solution 
    int trap(vector<int>& height) {
        int n = height.size();
        int mx = INT_MIN;
        vector<int> l;
        for(int i = 0; i<n; i++){
            if(height[i]<mx){
                l.push_back(mx);
            }
            else{
                mx = height[i];
                l.push_back(INT_MIN);
            }
        }
        vector<int> r;
        mx = INT_MIN;
        for(int i = n-1; i>=0; i--){
            if(height[i]<mx){
                r.push_back(mx);
            }
            else{
                mx = height[i];
                r.push_back(INT_MIN);
            }
        }
        reverse(r.begin(),r.end());

        int ans = 0;
        for(int i = 0; i<n; i++){
            // cout << l[i] << " " << r[i] << endl;
            int mn = min(l[i],r[i]);
            if(mn != INT_MIN){
                ans += (mn-height[i]);
            }
        }
        return ans;
    }
};

int main (int argc, char *argv[])
{
    
    return 0;
}
