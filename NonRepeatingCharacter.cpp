class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        unordered_map<char,int> freq;
        
        for(char ch: s){
            freq[ch]++;
        }
        
        for(char ch: s){
            if(freq[ch]==1){
                return ch;
                break;
            }
        }
        return '$';
    }
};
