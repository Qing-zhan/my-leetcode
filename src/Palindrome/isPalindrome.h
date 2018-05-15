// Solution 1
// store all the digits of a given number in a vector, 
// then compare the digits from begin to end
bool isPalindrome(int x) {
    if (x < 0) return false;
    else if ( x >= 0 && x <= 9) return true;
    else {
        vector<int> temp;
        while (x > 9) {
            temp.push_back((x%10));
            x /= 10;
        }
        temp.push_back(x);
        int size = temp.size();
        int index = 0;
        while (index < size / 2) {
            if (temp[index] != temp[size-index-1]) return false;
            index++;
        }
        return true;
    }
}


// Solution 2
// reverse the number and compare reverse with original number
bool isPalindrome(int x) {
    if (x < 0) return false;
    else {
        int sum = 0;
        int temp = x;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return temp == sum;
    }
}


// Solution 3
//         sum    x
// 1221:   0      1221
//         1      122
//         12     12

// 12321:  0       12321
//         1       1232
//         12      123
//         123     12
//整体的思路跟 reverse 类似，但是简化了 reverse 过程，即不需要完全 reverse；
bool isPalindrome(int x) {
    if (x >= 0 && x <= 9) return true;
    else if (x < 0 || x % 10 == 0) return false;
    else {
        int sum = 0;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return x == sum || x == sum / 10;
    }
}