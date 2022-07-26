#pragma once
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/b179375027fc4b4db692730c8be99618?tpId=332&tqId=2603646&ru=/exam/oj&qru=/ta/system-design/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D332

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param dict string字符串vector
	 * @param strings string字符串vector
	 * @return string字符串vector<vector<>>
	 */
	vector<vector<string>> typeahead(vector<string>& dict,
	                                 vector<string>& strings) {
		// write code here
		vector<vector<string>> ret;
		if (strings.empty() || dict.empty()) {
			return ret;
		}
		for (string& s : strings) {
			vector<string> tmp_vec;

			for (string& dic : dict) {
				if (dic.find(s) != string::npos) {
					tmp_vec.emplace_back(dic);
				}
			}
			ret.emplace_back(tmp_vec);
		}
		return ret;
	}
};