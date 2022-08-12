#pragma once;
#include <deque>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class LFU_b {
public:
	/**
	 * lfu design
	 * @param operators int整型vector<vector<>> ops
	 * @param k int整型 the k
	 * @return int整型vector
	 */
	unordered_map<int, int> k_v;
	map<int, deque<int>> count_k;
	unordered_map<int, int> k_count;

	vector<int> LFU(vector<vector<int>>& operators, int k) {
		// write code here
		this->capacity = k;
		if (operators.empty() || operators[0].empty()) {
			return ret_vec;
		}
		for (int i = 0; i < operators.size(); i++) {
			if (operators[i][0] == 1) {
				set(operators[i][1], operators[i][2]);
			} else {
				auto v = get(operators[i][1]);
				ret_vec.emplace_back(v);
			}
		}
		return ret_vec;
	}

	void set(int key, int val) {
		if (k_v.count(key)) {
			k_v[key] = val;
			int pre_count = k_count[key];
			int new_count = ++k_count[key];
			auto& dq_1 = count_k[pre_count];
			int index = 0;
			for (; index < dq_1.size(); index++) {
				if (dq_1[index] == key) {
					break;
				}
			}
			dq_1.erase(dq_1.begin() + index);
			if (dq_1.empty()) {
				count_k.erase(pre_count);
			}
			if (count_k.count(new_count)) {
				count_k[new_count].emplace_back(key);
			} else {
				count_k[new_count] = {key};
			}
			return;

		} else {
			if (k_v.size() < this->capacity) {
				k_v[key] = val;
				k_count[key] = 1;
				if (count_k.count(1)) {
					count_k[1].emplace_back(key);
				} else {
					count_k[1] = {key};
				}
			} else {
				int key_to_del = count_k.begin()->second.front();
				count_k.begin()->second.pop_front();
				if (count_k.begin()->second.empty()) {
					count_k.erase(count_k.begin());
				}
				k_v.erase(key_to_del);
				k_count.erase(key_to_del);

				k_v[key] = val;
				k_count[key] = 1;
				if (count_k.count(1)) {
					count_k[1].emplace_back(key);
				} else {
					count_k[1] = {key};
				}
			}
		}
	}

	int get(int key) {
		if (k_v.count(key)) {
			int pre_count = k_count[key];
			int new_count = ++k_count[key];
			auto& dq_1 = count_k[pre_count];
			int index = 0;
			for (; index < dq_1.size(); index++) {
				if (dq_1[index] == key) {
					break;
				}
			}
			dq_1.erase(dq_1.begin() + index);
			if (dq_1.empty()) {
				count_k.erase(pre_count);
			}
			if (count_k.count(new_count)) {
				count_k[new_count].emplace_back(key);
			} else {
				count_k[new_count] = {key};
			}
			return k_v[key];
		}
		return -1;
	}

private:
	vector<int> ret_vec;
	int capacity = 0;
};