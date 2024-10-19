# Problem: Longest Palindromic Substring

## Problem Description

Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 

Constraints:

- 1 <= s.length <= 1000
- s consist of only digits and English letters.



/// C++ Solution

class Solution {
public:
    string longestPalindrome(string s) {

     if(s.length() <= 1) return s;
        int max_len = 1;
        int n = s.length();
        int st = 0, end = 0;
        
        // Odd length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        // Even length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        return s.substr(st, max_len);

    }
};


