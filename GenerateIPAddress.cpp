class Solution {
    public:
    
    //check if the part of string can be a valid segment or not
    bool isValid(string s){
        if(s.length() > 1 && s[0]=='0') return false;
        int val= stoi(s);
        return (val>=0 && val<=255);
    }
    
    //start is the curr index
    void backtrack(string &s, int start, vector<string> &path, vector<string> &res){
        //if 4 segments are found and entire string has been traversed push paths
        if(path.size()==4){
            if(start==s.length()){
                res.push_back(path[0]+"."+path[1]+"."+path[2]+"."+path[3]);
            }
            return ; //exits the recursion
        }
        
        //try to make segments of size 1,2 or 3
        for(int len=1; len<=3; len++){
            //if curr idx + len of segment taken falls greater than s.length break
            if(len+start > s.length()) break;
            string part= s.substr(start, len);
            if(isValid(part)){
                path.push_back(part);
                backtrack(s, start+len, path, res);
                path.pop_back(); //to try-out diff combinations arising from diff branch
            }
        }
    }
    
    vector<string> generateIp(string s) {
        vector<string> path;
        vector<string> res;
        backtrack(s, 0, path, res);
        return res;
    }
};
