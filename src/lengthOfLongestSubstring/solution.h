class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0;
		int len = s.size();
		int max = 0;
		if (len == 0 || len == 1) return len;
		map<int, int> ci;
		while (j < len) {
			if (ci.find(s[j]) == ci.end()) {
				ci.insert(make_pair(s[j]+0, j));
				max = (j-i+1) > max ? (j-i+1) : max;
				++j;
			}
			else {
				ci.erase(ci.find(s[i]+0));
				++i;
			}
		}
		return max;
	}
};

// in this solution, map is used. While if use map<char, int> 
// will be a little bit slow, instead I choose to use map<int, int> 
// and in the insertion and erase phase, I convert the char to int
// by adding this char with 0;
//
