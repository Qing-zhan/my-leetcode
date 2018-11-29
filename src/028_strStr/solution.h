// O(n), where n is the length of haystack
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len_hay = haystack.length();
        int len_ndl = needle.length();
        
        for (int i = 0; i <= len_hay - len_ndl; ++i) {
            int j = 0;
            for (; j < len_ndl; ++j) {
                if (needle[j] != haystack[j+i]) break;
            }
            if (j == len_ndl) return i; 
        }
        
        return -1;
    }
};
