class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        
        if (strs.size() == 0) return common;
        if (strs.size() == 1) return strs[0];

        char c;
        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[i] == "") return common;
            c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i + 1) return common;
                if (strs[j][i] == c)
                    continue;
                else
                    return common;
            }
            common.push_back(c);
        }
        return common;
    }
};


// Special cases
// 1. []
// 2. ['c', 'c']
// 3. ['flow', 'flight', 'flower']
// 4. ['nice']
// 5. ['', 'word']
// 6. ['abnormal', 'abc', 'abort']