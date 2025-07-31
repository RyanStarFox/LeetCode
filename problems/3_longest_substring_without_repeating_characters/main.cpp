class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int left = 0, right = 0, max = 0;
        vector<int> charIndex(128, -1);  // ASCII字符映射
        while(right < s.length()){
            int loc = charIndex[int(s[right])];
            charIndex[int(s[right])]=right;
            right++;
            if(loc != -1 && loc >= left) {
                int l = right - left - 1;
                max = max>l?max:l;
                left = loc+1;
            }
        }
        int l = right - left;
        max = max>l?max:l;
        return max;
    }
};