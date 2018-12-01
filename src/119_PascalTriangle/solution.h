class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev{1};
        if (rowIndex == 0) return prev;
        vector<int> next{1,1};
        if (rowIndex == 1) return next;
        prev = next;
        for (int i = 2; i <= rowIndex; ++i) {
            next.resize(i+1, 1);
            for (int j = 1; j < i; ++j) {
                next[j] = prev[j-1] + prev[j];
            }
            prev = next;
        }
        return next;
    }
};
