
class Solution {
    int index = 0;
    string decode(const string& s) {
        string result;
        while (index < (int)s.size() && s[index] != ']') {
            if (isdigit(s[index])) {
                int num = 0;
                while (index < (int)s.size() && isdigit(s[index])) {
                    num = num * 10 + (s[index] - '0');
                    index++;
                }
                index++; 
                string decoded = decode(s);
                index++; 
                for (int i = 0; i < num; i++) {
                    result += decoded;
                }
            }
            else {
                result += s[index];
                index++;
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        index = 0;
        return decode(s);
    }
};
