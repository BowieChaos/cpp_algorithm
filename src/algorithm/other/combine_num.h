#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC46 加起来和为目标值的组合(二)
// https://www.nowcoder.com/practice/75e6cd5b85ab41c6a7c43359a74e869a?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& num, int target) {
		vector<vector<int>> ans;

		vector<int> path;
		sort(num.begin(), num.end());
		dfs(ans, num, path, target, -1);
		return ans;
	}

	void dfs(vector<vector<int>>& ans, vector<int>& num, vector<int>& path, int target, int index) {
		if (target == 0) {
			ans.push_back(path);
			return;
		}
		int pre = -1;
		for (int i = index + 1; i < num.size(); i++) {
			if (target >= num[i]) {
				if (num[i] == pre)
					continue;
				pre = num[i];
				path.push_back(num[i]);
				dfs(ans, num, path, target - num[i], i);
				path.pop_back();
			}
		}
	}
};