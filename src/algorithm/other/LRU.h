#pragma once
#include <deque>
#include <unordered_map>
using namespace std;
// https://www.nowcoder.com/practice/5dfded165916435d9defb053c63f1e84?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj
class Solution {
public:
	unordered_map<int, int> mp;
	deque<int> dq;

	Solution(int capacity) {
		// write code here
		this->capacity = capacity;
	}

	int get(int key) {
		// write code here
		if (mp.count(key)) {
			int dq_index = 0;
			for (; dq_index < dq.size(); dq_index++) {
				if (dq[dq_index] == key) {
					break;
				}
			}
			dq.erase(dq.begin() + dq_index);
			dq.push_front(key);
			return mp[key];
		} else {
			return -1;
		}
	}

	void set(int key, int value) {
		// write code here
		if (!mp.count(key)) {
			if (mp.size() == capacity) {
				int key_to_del = dq.back();
				dq.pop_back();
				mp.erase(key_to_del);
				mp[key] = value;
				dq.push_front(key);
			} else {
				mp[key] = value;
				dq.push_front(key);
			}
		} else {
			int dq_index = 0;
			for (; dq_index < dq.size(); dq_index++) {
				if (dq[dq_index] == key) {
					break;
				}
			}
			dq.erase(dq.begin() + dq_index);
			dq.push_front(key);
			mp[key] = value;
		}
	}

private:
	int capacity;
};