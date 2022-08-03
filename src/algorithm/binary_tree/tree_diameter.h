#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// 多叉树的直径
// https://www.nowcoder.com/practice/a77b4f3d84bf4a7891519ffee9376df3?tpId=117&tqId=37812&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

struct Interval {
	int start;
	int end;
};

class Solution {
public:
	/**
	 * 树的直径
	 * @param n int整型 树的节点个数
	 * @param Tree_edge Interval类vector 树的边
	 * @param Edge_value int整型vector 边的权值
	 * @return int整型
	 */
	int end = 0;
	int ret = 0;
	unordered_map<int, vector<pair<int, int>>> mp;
	int solve(int n, vector<Interval>& Tree_edge, vector<int>& Edge_value) {
		// write code here
		if (n <= 1) {
			return 0;
		}

		for (int i = 0; i < Tree_edge.size(); i++) {
			mp[Tree_edge[i].start].push_back({Tree_edge[i].end, Edge_value[i]});
			mp[Tree_edge[i].end].push_back({Tree_edge[i].start, Edge_value[i]});
		}
		dfs(0, -1, 0);
		dfs(end, -1, 0);
		return ret;
	}

	void dfs(int start, int pre, int sum) {
		bool is_end = true;

		for (int i = 0; i < mp[start].size(); i++) {
			if (mp[start][i].first != pre) {
				is_end = false;
				dfs(mp[start][i].first, start, sum + mp[start][i].second);
			}
		}

		if (is_end && ret < sum) {
			ret = sum;
			end = start;
		}
		return;
	}
};