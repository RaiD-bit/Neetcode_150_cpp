#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        // the first simple approach is to just sort the
        // strings if the strings are equal then it is a 
        // anagram otherwise not
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
        
    }

    bool isAnagram_time_efficient(string s, string t){
        /*  in this Solution we store the frequency count of each char of one string
            * then we iterate over the other string if find that the current element
            * exitst in the map we decrement its frequency and if the frequency is 0
            * we remove it from the map this ensures that is all the char of one type 
            * are encountered in string t we should not encounter the same char again.
            * so if we dont find the char in the map it means that it is extra in second
            * string.
        */
        unordered_map<char, int> umap;
        for(auto x: s){
            umap[x]++;
        }

        for(auto x: t){
            if(umap.find(x) == umap.end()){
                return false;
            }else{
                umap[x]--;
                if(umap[x] == 0){
                    umap.erase(x);
                }
            }
        }
        return true;

    }
};

int main (int argc, char *argv[])
{
    string s = "anagram";
    string t = "nagaram";
    bool ans = Solution().isAnagram(s,t);
    cout << ans << endl;
    return 0;
}

