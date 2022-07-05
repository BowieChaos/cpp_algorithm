#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class StringPermute {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param str string字符串
	 * @return string字符串vector
	 */
	vector<string> Permutation(string str) {
		// write code here
		vector<string> ret_vec;
		if (str.empty()) {
			return ret_vec;
		}
		set<string> st;
		traverse(str, 0, st);
		ret_vec.assign(st.begin(), st.end());
		return ret_vec;
	}

	void traverse(string& str, int index, set<string>& ret_vec) {
		if (index == str.size()) {
			ret_vec.emplace(str);
			return;
		}
		for (size_t i = index; i < str.size(); i++) {
			swap(str[i], str[index]);
			traverse(str, index + 1, ret_vec);
			swap(str[i], str[index]);
		}
		return;
	}
};