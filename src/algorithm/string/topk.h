#pragma once

#include <algorithm>
#include <deque>
#include <map>
#include <string>
#include <vector>
using namespace std;

// NC97 字符串出现次数的TopK问题
// https://www.nowcoder.com/practice/fd711bdfa0e840b381d7e1b82183b3ee?tpId=117&tqId=37809&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * return topK string
	 * @param strings string字符串vector strings
	 * @param k int整型 the k
	 * @return string字符串vector<vector<>>
	 */
	vector<vector<string> > topKstrings(vector<string>& strings, int k) {
		vector<vector<string> > res;
		map<string, int> m;

		for (auto s : strings)
			++m[s];
		for (auto it = m.begin(); it != m.end(); ++it)
			res.push_back({it->first, to_string(it->second)});

		sort(res.begin(), res.end(), [](vector<string>& a, vector<string>& b) {
			if (a[1] == b[1])
				return a[0] < b[0];
			return stoi(a[1]) > stoi(b[1]);
		});
		res.resize(k);

		return res;
	}
};
