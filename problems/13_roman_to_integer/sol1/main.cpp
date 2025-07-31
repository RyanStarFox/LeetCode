class Solution {
public:
    int romanToInt(string s) {
        int c = 0; //current
        int r = 0; //result
        s+='K';
        while(c < s.length()-1){
            r += trans(s,c++);
        }
        return r;
    }
private:
    int trans(string s, int c){
        //cout << "current loc " << c << " scanning " << s[c] << " get ";
        switch(s[c]){
            case 'M':
                //cout << 1000 << endl;
                return 1000;
                break;
            case 'D':
                //cout << 500 << endl;
                return 500;
                break;
            case 'L':
                //cout << 50 << endl;
                return 50;
                break;
            case 'V':
                //cout << 5 << endl;
                return 5;
                break;
            default:
                int next = s[c+1];
                switch(s[c]){
                    case 'C':
                        if (next == 'D'|| next == 'M'){
                            //cout << -100 << endl;
                            return -100;
                        }
                        //cout << 100 << endl;
                        return 100;
                        break;
                    case 'X':
                        if (next == 'L'|| next == 'C'){
                            //cout << -10 << endl;
                            return -10;
                        }
                        //cout << 10 << endl;
                        return 10;
                        break;
                    case 'I':
                        if (next == 'V'|| next == 'X'){
                            //cout << -1 << endl;
                            return -1;
                        }
                        //cout << 1 << endl;
                        return 1;
                        break;
                    default:
                        assert(false);
                    }
        }           
    }
};