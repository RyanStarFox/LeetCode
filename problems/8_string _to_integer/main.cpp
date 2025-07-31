class Solution {
public:
    int myAtoi(string s) {
        int current = 0;
        bool negative = false;
        while(s[current]==' ') current++;
        if(s[current]=='-') {
            negative = true;
            current++;
            //cout << "negative" << endl;
        }else if(s[current]=='+') current++;
        int result = 0;
        while(current < s.length()){
            int n_digit = s[current++] - '0';
            //cout << "processing " << n_digit << endl;
            if (n_digit <= 9 && n_digit >= 0){
                if(INT_MAX/10 > result){
                    //cout << "result update from " << result << " to " << result*10+n_digit << endl;
                    result = result*10+n_digit;
                    continue;
                }
                else if(INT_MAX/10 == result){
                    if(n_digit <= INT_MAX%10){
                        //cout << "result update from " << result << " to " << result*10+n_digit << endl;
                        result = result*10+n_digit;
                        continue;
                    }
                    else if(n_digit == INT_MAX%10+1 && negative) {
                        //cout << 1;
                        return INT_MIN;
                    }
                }
                if(negative){
                    //cout << 2;
                    return INT_MIN;
                }
                //cout << 3;
                return INT_MAX;
            }
            break;
        }
        if(negative) {
            //cout << 4;
            return -result;
        }
        //cout << 5;
        return result;
    }
};