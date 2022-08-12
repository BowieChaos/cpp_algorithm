#pragma once
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// 集合的所有子集(一)
// https://www.nowcoder.com/practice/c333d551eb6243e0b4d92e37a06fbfc9?tpId=117&tqId=37731&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class cmp {
public:
	bool operator()(const vector<int>& v1, const vector<int>& v2) {
		if (v1.size() != v2.size()) {
			return v1.size() < v2.size();
		} else {
			auto length = v1.size();
			for (int i = 0; i < length; i++) {
				if (v1[i] != v2[i])
					return v1[i] < v2[i];
			}
		}
		return false;
	}
};

class Subsets {
public:
	vector<vector<int> > ret;
	vector<vector<int> > subsets(vector<int>& S) {
		vector<int> visited;
		traverse(0, S, visited);
		sort(ret.begin(), ret.end(), cmp());
		return ret;
	}

	void traverse(int index, vector<int>& s, vector<int> visited) {
		if (index == s.size()) {
			ret.emplace_back(visited);
			return;
		}

		traverse(index + 1, s, visited);
		visited.emplace_back(s[index]);
		traverse(index + 1, s, visited);
		return;
	}
};