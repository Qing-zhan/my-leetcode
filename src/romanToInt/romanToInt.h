// iterate the string from right to left, when 'I' 'X' 'C' occurs,
// res should be compare with certain digits to determine situation
int romanToInt (string s) {
	int res = 0;
	for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
		switch(*iter) {
			case 'I': res += (res >=5 ? -1 : 1); break;
			case 'V': res += 5; break;
			case 'X': res += 10 * (res >= 50 ? -1 : 1); break;
			case 'L': res += 50; break;
			case 'C': res += 100 * (res >= 500 ? -1 : 1); break;
			case 'D': res += 500; break;
			case 'M': res += 1000; break;
			default: res = -1;
		}
	}
	return res;
}

// updated on 2018.11.16
int romanToInt(std::string s) {
	std::unordered_map<char, int> mai = { 
    { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },
    { 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
	if (s.length() == 1) return mai[s[0]];
	int result = mai[s[s.length() - 1]];
	for (int i = s.length() - 2; i >= 0; --i) {
		if (mai[s[i]] < mai[s[i + 1]]) result = result - mai[s[i]];
		else result = result + mai[s[i]];
	}
	return result;
}
