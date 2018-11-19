class Solution {
public:
    bool isValid(string s) {
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        vector<char> stack;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            switch (*iter){
            case '(': case '[': case '{': 
                stack.push_back(*iter); break;
            case ')': 
                if (stack.back() != '(') return false;
                stack.pop_back(); break;
            case ']':
                if (stack.back() != '[') return false;
                stack.pop_back(); break;
            case '}': 
                if (stack.back() != '{') return false;
                stack.pop_back(); break;
            }
        }
        if (stack.size() == 0) return true;
        else return false;
    }
};

// special cases
// 1. ''
// 2. '(){}'
// 3. '(()'
// 4. ')('


// updated on 2018.11.19
bool isValid(std::string s) {
	std::unordered_map<char, char> mc = { { '(', ')' },{ '{', '}' },{ '[', ']' } };
	std::stack<char> st;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		else {
			if (st.size() == 0) return false;
			char temp = st.top(); st.pop();
			if (mc[temp] != s[i]) return false;
		}
	}
	return st.size() > 0 ? false : true;
}
