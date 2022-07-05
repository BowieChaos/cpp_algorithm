#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/a43a2b986ef34843ac4fdd9159b69863?tpId=295&tqId=2188893&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class PermuteUnique {
public:
	vector<vector<int>> permuteUnique(vector<int>& num) {
		vector<vector<int>> ret_vec;
		if (num.empty()) {
			return ret_vec;
		}
		set<vector<int>> st;
		traverse(num, 0, st);
		ret_vec.assign(st.begin(), st.end());
		return ret_vec;
	}

	void traverse(vector<int>& num, int index, set<vector<int>>& st) {
		if (index == num.size()) {
			st.emplace(num);
			return;
		}
		for (size_t i = index; i < num.size(); i++) {
			swap(num[index], num[i]);
			traverse(num, index + 1, st);
			swap(num[index], num[i]);
		}
		return;
	}
};