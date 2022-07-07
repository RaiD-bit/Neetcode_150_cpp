// problem: https://leetcode.com/problems/group-anagrams/ 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       /*
            * first approach that comes to my mind is to create a map for vectors
            * we will then iterate through this strs array we will create a copy of this string and
            * sort the string to check if the string is present in map.
            * if(string present in map){
            *    append the curr string to map[sorted string]
            * }
            * else{
            *    create a new key, value pair for the map and append the current string to 
            *    it.
            * }
            *
            * at the end we will iterate through the generated map and form out required ans.
            *
    * */
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            umap[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto item: umap){
            ans.push_back(item.second);
        }
        return ans;
    }
};


int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    for(auto x: ans){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }

}
