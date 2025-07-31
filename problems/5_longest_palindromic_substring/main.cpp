class Solution {
public:
    string longestPalindrome(string s){
        //manacher 算法
        //字符串预处理
        stringstream ss;
        ss << "^";
        for (char c : s) {
            ss << "#" << c;
        }
        ss << "#$";
        string m = ss.str();
        //cout << "pre-processed string: " << m << endl;

        //manacher 算法
        int c = 0, r = 0, index_max_p = 2, max_p = 0;
        int p[m.length()-1];
        p[0] = 0;
        for (int i = 1; i <= m.length()-2; i++){
            p[i] = 0;
            if (i <= r) p[i] = min(r-i, p[2*c-i]);
            while (m[i-p[i]-1] == m[i+p[i]+1]) p[i]++;
            if (i + p[i] > r){
                c = i;
                r = i + p[i];
                if (p[i] > max_p) {
                    index_max_p = i;
                    max_p = p[i];
                }
            }
        }
        /*
        DEBUG
        cout << "p array: " << endl;
        int i = 0;
        while(i < m.length()) cout << i++ << "\t";
        cout << endl;
        for (char c : m) cout << c << "\t";
        cout << endl;
        for (int i : p) cout << i << "\t";
        cout << endl << "index: " << index_max_p << " max: " << max_p << endl;
        int left = (index_max_p - max_p-1)/2, right = max_p;
        cout << "left = " << left << " length = " << right;
        */
        return s.substr((index_max_p - max_p-1)/2, max_p);
    }
};