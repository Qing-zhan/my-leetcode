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

// updated on 2018.11.19
std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string result = "";
	std::string& first = strs[0];
	for (int i = 0; i < first.length(); ++i) {
		bool flag = true;
		for (int s = 1; s < strs.size(); ++s) {
			if (first[i] != strs[s][i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			// string + char !!!
			result += first[i];
		}
		else {
			break;
		}
	}
	return result;
}
