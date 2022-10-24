#pragma once
#include <limits.h>
#include <set>
#include <vector>
using namespace std;

// NC131 数据流中的中位数
// https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class FindMedian {
public:
	void Insert(int num) {
		if (left_set.empty() && right_set.empty()) {
			left_set.emplace(num);
			return;
		}

		if (right_set.empty()) {
			if (num >= *left_set.begin()) {
				right_set.emplace(num);
			} else {
				right_set.emplace(*left_set.begin());
				left_set.erase(left_set.begin());
				left_set.emplace(num);
			}
			return;
		}

		if (num >= *right_set.begin()) {
			right_set.emplace(num);
			while (right_set.size() > left_set.size() + 1) {
				left_set.emplace(*right_set.begin());
				right_set.erase(right_set.begin());
			}
		} else if (num <= *left_set.begin()) {
			left_set.emplace(num);
			while (left_set.size() > right_set.size() + 1) {
				right_set.emplace(*left_set.begin());
				left_set.erase(left_set.begin());
			}
		} else {
			left_set.emplace(num);
			while (left_set.size() > right_set.size() + 1) {
				right_set.emplace(*left_set.begin());
				left_set.erase(left_set.begin());
			}
		}
	}

	double GetMedian() {
		if (left_set.size() == right_set.size()) {
			return (*left_set.begin() + *right_set.begin()) / 2.0;
		}

		if (left_set.size() > right_set.size()) {
			return *left_set.begin();
		}

		return *right_set.begin();
	}

private:
	multiset<int, greater<int>> left_set;
	multiset<int, less<int>> right_set;
};