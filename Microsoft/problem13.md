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


SOLUTION

Language- C++

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i =0; i<s.length(); i++){
            int len1 = expandCenter(s, i, i);
            int len2 = expandCenter(s, i, i+1);
            int len = max(len1, len2);
            if(len>end-start){
                start = i - (len-1)/2;
                end = i+len/2;

            }
        }
        return s.substr(start, end-start+1);
    }
    int expandCenter(string s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;

        }
        return right-left -1;
    }
};