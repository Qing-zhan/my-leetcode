class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        result.push_back(vector<int>{1});
        if (numRows == 1) return result;
        result.push_back(vector<int>{1,1});
        if (numRows == 2) return result;
        for (int i = 3; i <= numRows; ++i) {
            vector<int> temp(i, 1);
            for (int j = 1; j < i-1; ++j) {
                temp[j] = result[i-2][j-1] + result[i-2][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};
