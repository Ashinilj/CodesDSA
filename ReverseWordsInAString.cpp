class Solution {
  public:
    string reverseWords(string &s) {
        vector<string> words;
        
        string newStr="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                newStr += s[i];
            }
            else if(!newStr.empty()){
                    words.push_back(newStr);
                    newStr="";
            }
        }
        
        if(!newStr.empty())
            words.push_back(newStr);
        
        reverse(words.begin(), words.end());
        
        string res="";
        for(int i=0; i<words.size(); i++){
            res += words[i];
            if (i != words.size() - 1) res += " ";
        }
        return res;
    }
};
