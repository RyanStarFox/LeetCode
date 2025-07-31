class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i = 0, r = 0;   //index, result
        int c, n = m[s[0]];    //current, next
        while(i++ <= s.length()-1){
            c = n;
            n = m[s[i]];
            if (c >= n) r += c;
            else r -= c;
        }
        r += n;
        return r;
    }
};