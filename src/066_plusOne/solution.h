class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        int len = digits.size();
        for (int i = len - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            carry = sum >= 10 ? 1 : 0;
            result.push_back(carry > 0 ? 0 : sum);
        }

        if (carry) result.push_back(carry);

        len = result.size();
        for (int i = 0; i < len / 2; ++i) {
            swap(result[i], result[len-i-1]);
        }
        return result;
    }
};
