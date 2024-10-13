# Problem: Swap For Longest Repeated Character Substring

## Problem Description


You are given a string text. You can swap two of the characters in the text.

Return the length of the longest substring with repeated characters.

 

Example 1:
Input: text = "ababa"
Output: 3

Example 2:
Input: text = "aaabaaa"
Output: 6

Example 3:

Input: text = "aaaaa"
Output: 5

 
Constraints:

- 1 <= text.length <= 2 * 104
- text consist of lowercase English characters only.


SOLUTION

Language- C++

class Solution {
    bool good(unordered_map<char, int> &w, unordered_map<char, int> &m) {
        if(w.size() == 1) return true;
        if(w.size() > 2) return false;
        char a = '#', b;
        for(auto p : w) {
            a == '#' ? a = p.first : b = p.first;
        }
        if(w[a] == 1 && m.find(b) != m.end() || w[b] == 1 && (m.find(a) != m.end())) return true;
        return false;
    }
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> m, w;
        for(char c : text) m[c]++;

        int n = text.size(), i = 0, ans = 0;
        for(int j=0; j<n; j++) {
            w[text[j]]++;
            m[text[j]]--;
            if(!m[text[j]]) m.erase(text[j]);
            
            while(!good(w, m)) {
                w[text[i]]--;
                m[text[i]]++;
                if(!w[text[i]]) w.erase(text[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};