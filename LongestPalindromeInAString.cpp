class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        if(n==0) return "";
        int start=0, maxLen=1;
        
        for(int i=0; i<n ; i++){
            expandAtCenter(s, i, i, start, maxLen);
            expandAtCenter(s, i, i+1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    
    void expandAtCenter(string &s, int left, int right, int &start, int &maxLen){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            if(right-left+1>maxLen){
                maxLen= right-left+1;
                start=left;
            }
            left--;
            right++;
        }
    }
    
};
