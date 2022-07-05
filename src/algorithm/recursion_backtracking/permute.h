#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/4bcf3081067a4d028f95acee3ddcd2b1?tpId=295&tqId=2188893&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class cmp {
public:
	bool operator()(const vector<int>& left, const vector<int>& right) {
		int len = left.size();
		for (size_t i = 0; i < left.size(); i++) {
			if (left[i] != right[i]) {
				return left[i] < right[i];
			}
		}
		return false;
	}
};

class Permute {
public:
	vector<vector<int> > permute(vector<int>& num) {
		vector<vector<int> > ret_vec;
		if (num.empty()) {
			return ret_vec;
		}
		permute_core(num, 0, ret_vec);
		sort(ret_vec.begin(), ret_vec.end(), cmp());
		return ret_vec;
	}

	void permute_core(vector<int>& num, int index,
	                  vector<vector<int> >& ret_vec) {
		if (index == num.size()) {
			ret_vec.emplace_back(num);
			return;
		}
		for (size_t i = index; i < num.size(); i++) {
			swap(num[index], num[i]);
			permute_core(num, index + 1, ret_vec);
			swap(num[index], num[i]);
		}
		return;
	}
};