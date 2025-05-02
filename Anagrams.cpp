class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        unordered_map<char, int> freq;
        
        if(s1.size() != s2.size()) return false;
        
        for(char ch: s1)
            freq[ch]++;
            
        for(char ch: s2){
            freq[ch]--;
            if(freq[ch]<0) return false;
        }
            
        for(auto &entry: freq){
            if(entry.second !=0)
                return false;
        }
        return true;
    }
};
