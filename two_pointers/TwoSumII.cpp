#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int lo = 0, hi = numbers.size()-1;
        while(lo < hi){
            if(target < numbers[lo] + numbers[hi]){
                hi--;
            }
            else if(target > numbers[lo] + numbers[hi]){
                lo++;
            }
            else{
                return {lo+1,hi+1};
            }
        }
        return ans;
    }
};
int main(){

}
