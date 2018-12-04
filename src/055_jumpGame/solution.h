class Solution {
public:
    bool help(vector<int>& array, int end) {
        if (end == 0) return true;
        for (int i = end - 1; i >= 0; --i) {
            if (array[i] >= end - i) return help(array, i);
        }
        return false;
    }

    bool canJump(vector<int>& array) {
        return help(array, array.size() - 1);
    }
};

// for the last element, find its neighboring index that can jump to the last element, then call the index canJump
