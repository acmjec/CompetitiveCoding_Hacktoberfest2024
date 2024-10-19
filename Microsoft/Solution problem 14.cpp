#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxLength(string text){
        int n = text.size();
        vector<int> chars[26];
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            chars[text[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < 26; i++){
            int cur = 1;
            int prev = 0;
            int temp = 0;
            for(int j = 1; j < chars[i].size(); j++){
                if(chars[i][j] == chars[i][j - 1]+ 1) cur++;
                else{
                    prev = 0;
                    if(chars[i][j] == chars[i][j - 1] + 2) prev = cur;
                    cur = 1;
                }
                temp = max(temp, cur + prev);
            }
            if(chars[i].size() > temp) temp += 1;
            ans= max(temp, ans);
        }


        return ans;
    }
};

int main(){
    string s = "aaabaaa";
    Solution obj;
    cout<<"Longest substring len after 2 swaps is : "<<obj.maxLength(s);
    return 0;
}