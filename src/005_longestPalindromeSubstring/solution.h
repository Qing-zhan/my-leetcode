// O(n^3)
// special cases: 0000000000000000000000, aaabaaaa
class Solution {
public:
    string longestPalindrome(string s) {
	string result = "";
	if (s.length() == 0) return result;
	else if (s.length() == 1) return s;

	for (int i = 0; i < s.length(); ++i) {
		int left = i, right = s.length() - 1;
		for (int j = s.length() - 1; j > i; --j) {
			right = j;
			if (right - left + 1 < result.length()) continue;
			while (right > left && s[right] != s[left]) --right;
			int l_temp = left, r_temp = right;
			while (l_temp < r_temp) {
				if (s[l_temp] != s[r_temp]) break;
				++l_temp;
				--r_temp;
			}
			if (l_temp >= r_temp) {
				if ((right - left + 1) > result.length()) {
					result = s.substr(left, right - left + 1);
				}
			}
		}
	}

	return result; 
    }
};

// O(n^2)
class Solution {
public:
    void help(string& s, int i, int j, int& start, int& end) {
        while (i >= 0 && j < s.length()) {
            if (s[i] == s[j]) {
                --i;
                ++j;
            }
            else {
                break;
            }
        }

        if (--j - ++i > end - start) {
            start = i;
            end = j;
        }

        return;
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < int(s.length()) - 1; ++i) {
            help(s, i, i, start, end);
            help(s, i, i+1, start, end);
        }
        return s.substr(start, end-start+1);
    }
};


// Note: s.length() is a size_t type, if it is 0, and minus 1 will result in unexpected value, thus it's nessecary to use type cast int
