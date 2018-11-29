class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.at(i) == ' ' && count > 0) return count;
            if (s.at(i) != ' ') ++count;
        }
        return count;
    }
};
