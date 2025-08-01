class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs[0];
        for(int i = 1; i < strs.size(); i++){
            trim(strs[i],r);
        }
        return r;
    }
private:
    void trim(string s, string& r){
        //cout << "[original] " << r << "\t [string] " << s;
        int pos = 0, original = r.length();
        while(pos < s.length() && pos < r.length()){
            if (s[pos] == r[pos]) {pos++; continue;}
            break;
        }
        if (pos < original) r = r.substr(0, pos);
        //cout << "\t [new]" << r << endl;
    }
};