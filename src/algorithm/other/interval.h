#pragma once

#include <algorithm>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

struct Interval {
	int start;
	int end;
	Interval()
	    : start(0)
	    , end(0) {}
	Interval(int s, int e)
	    : start(s)
	    , end(e) {}
};

class Cmp {
public:
	bool operator()(const Interval& l, const Interval& r) {
		if (l.start != r.start) {
			return l.start < r.start;
		} else {
			return l.end < r.end;
		}
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), Cmp());
		vector<Interval> ret_vec;
		if (intervals.empty()) {
			return ret_vec;
		}

		int left = intervals[0].start;
		int right = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start>right) {
                ret_vec.emplace_back(left, right);
                left = intervals[i].start;
                right = intervals[i].end;
                continue;
            }

            if (intervals[i].start == right) {
                right = intervals[i].end;
                continue;
            }

            right = max (right, intervals[i].end);

		}
        ret_vec.emplace_back(left, right);
        return ret_vec;
	}
};