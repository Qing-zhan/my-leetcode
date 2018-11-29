// int to string: std::to_string(int)
// char to string: str = str + char;
// [] & at of string will return char&;
class Solution {
public:
    string countAndSay(int n) {
        string prev = "";
        if (n == 0) return prev;
        prev = "1";
        if (n == 1) return prev;

        string next = "";
        for (int i = 2; i <= n; ++i) {
            int count = 1;
            char temp = prev[0];
            for (int m = 1; m < prev.length(); ++m) {
                if (prev[m] == temp) ++count;
                else {
                    next.append(to_string(count));
                    next += temp;
                    count = 1;
                    temp = prev.at(m);
                }
            }
            next.append(to_string(count));
            next += temp;

            prev = next;
            next = "";
        }
        return prev;
    }
};
