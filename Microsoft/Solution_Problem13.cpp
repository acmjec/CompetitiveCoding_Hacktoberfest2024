// problem - Longest palindromic Substring

#include<bits/stdc++.h>
using namespace std;

    string longestPalindrome(string s) 
    {
       int n=s.length();
       if(n<=1)return s;
       int st=0;
        int max_len=1;
        
        //odd
        
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            
            int len=r-l-1;
            if(max_len<len)
            {
                max_len=len;
                st=l+1;
            }
        }
        
        
        //even
        
        for(int i=0;i<n-1;i++)
        {
            int l=i,r=i+1;
            
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            
            int len=r-l-1;
            if(max_len<len)
            {
                max_len=len;
                st=l+1;
            }
        }
        
        return s.substr(st,max_len);
        
    }
int main()
{
    string str;
    cin>>str;
    
    cout<<longestPalindrome(str);
    return 0;
}

//Explanation -

// A palindromic substring can be of even length or odd length & mirros around its center,
//if it is of odd length  then it will have one character in center otherwise there will be two characters in center.
//So first check for such odd length substr considering each char of given string as center check its left & right chars 
//whether they are equal or not and get the the palindromic substring of maximum possible length using formula (r-l-1),
//then compairing with curr maxlen ,similarly check for even length substrings which are palindromes considering each two consecutive chars as center 
//and checking in their left and right .

