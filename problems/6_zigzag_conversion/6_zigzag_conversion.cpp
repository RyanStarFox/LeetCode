class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result = "";
        int divisor = 2*numRows-2;
        int curr = 0, end = s.length();
        while(curr < s.length()){
            result += s[curr];
            curr += divisor;
        }
        for(int i = 1; i <= numRows-2; i++){
            curr = i;
            int n = 2*i, m = divisor - n;
            bool flag = false;
            while(curr < s.length()){
                result += s[curr];
                flag = !flag;
                if(flag) curr += m;
                else curr += n;
            }
        }
        curr = numRows-1;
        while(curr < s.length()){
            result += s[curr];
            curr += divisor;
        }
        return result;
    }
};