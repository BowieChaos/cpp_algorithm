#pragma once

#include <deque>
#include <string>
#include <algorithm>
using namespace std;

// NC89 字符串变形
// https://www.nowcoder.com/practice/c3120c1c1bc44ad986259c0cf0f0b80e?tpId=295&tqId=44664&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class RevString {
public:
	string trans(string s, int n) {
		if (n == 0)
			return s;
		string res;
		for (int i = 0; i < n; i++) {
			if (s[i] <= 'Z' && s[i] >= 'A') //⼤⼩写转换
				res += s[i] - 'A' + 'a';
			else if (s[i] >= 'a' && s[i] <= 'z')
				res += s[i] - 'a' + 'A';
			else
				res += s[i]; //空格直接复制
		}
		reverse(res.begin(), res.end()); //翻转整个字符串
		for (int i = 0; i < n; i++) {
			int j = i;
			while (j < n && res[j] != ' ') //以空格为界，⼆次翻转
				j++;
			reverse(res.begin() + i, res.begin() + j);
			i = j;
		}
		return res;
	}
};