#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string upd = "";
        for(auto c: s){
            if(isalpha(c) || isdigit(c)){
                upd+=tolower(c);
            }
        }
        int lo = 0, hi = upd.size()-1;
        while(lo < hi){
            if(upd[lo] != upd[hi]){
                return false;
            }
            lo++;hi--;
        }
        return true;
    }
};

int main(){

}
