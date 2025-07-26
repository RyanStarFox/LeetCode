class Solution {
public:
    int reverse(int x) {
        if(x==-2147483648) return 0;
        if(x < 0) return -reverse(-x);
        int result = 0;
        while (x > 0){
            if(result > INT_MAX/10) return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};