#pragma once
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/a93bd04c71d445c090565da14990a421?tpId=332&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=

class ConsistentH {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param n int整型
	 * @param ID int整型
	 * @return int整型
	 */
	// 机器id to 区间map
	unordered_map<int, vector<int>> id_partition{{1, {0, 799}}};
	// 区间大小 to 机器id map
	unordered_map<int, set<int>> part_size_to_ids{{800, {1}}};
	// 区间大小 set
	set<int, greater<int>> part_size{800};
	int consistentHashing(int n, int ID) {
		// write code here
		for (int i = 2; i <= n; i++) {
			reHash(i);
		}
		ID = ID % 800;
		for (auto iter = id_partition.begin(); iter != id_partition.end();
		     iter++) {
			if (iter->second[0] <= ID && iter->second[1] >= ID) {
				return iter->first;
			}
		}
		return -1;
	}

	void reHash(int id) {
		int g_part_size = *part_size.begin();
		if (!part_size_to_ids.count(g_part_size) ||
		    part_size_to_ids[g_part_size].empty()) {
			cout << "error" << endl;
		}

		int id_to_change = *part_size_to_ids[g_part_size].begin();

		part_size_to_ids[g_part_size].erase(
		    part_size_to_ids[g_part_size].begin());
		if (part_size_to_ids[g_part_size].empty()) {
			part_size_to_ids.erase(g_part_size);
			part_size.erase(g_part_size);
		}

		vector<int>& part = id_partition[id_to_change];
		int mid = (part[0] + part[1] + 1) / 2;
		vector<int> left_part{part[0], mid - 1};
		vector<int> right_part{mid, part[1]};
		int new_sz = mid - part[0];
		part_size.emplace(new_sz);
		if (part_size_to_ids.count(new_sz)) {
			part_size_to_ids[new_sz].emplace(id);
			part_size_to_ids[new_sz].emplace(id_to_change);
		} else {
			part_size_to_ids[new_sz] = {id, id_to_change};
		}
		id_partition[id_to_change] = left_part;
		id_partition[id] = right_part;
		return;
	}
};