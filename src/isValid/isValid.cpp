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