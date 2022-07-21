#pragma once
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/a93bd04c71d445c090565da14990a421?tpId=332&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=

struct computer {
	int start;
	int end;
	int index;
	int range() const { return end - start; }
};
struct CCCCCC {
	bool operator()(const computer& a, const computer& b) const {
		return a.range() == b.range() ? a.index < b.index
		                              : a.range() > b.range();
	}
};
class ConHash {
public:
	int consistentHashing(int n, int ID) {
		set<computer, CCCCCC> s;
		computer c;
		c.start = 0;
		c.end = 799;
		c.index = 1;
		s.insert(c);
		int ind = ID % 800;
		int res = 1;
		for (int i = 2; i <= n; i++) {
			auto c = *s.begin();
			s.erase(s.begin());
			computer ne;
			ne.start = (c.start + c.end) / 2 + 1;
			ne.end = c.end;
			ne.index = i;
			c.end = (c.start + c.end) / 2;
			s.insert(c);
			s.insert(ne);
			if (ind >= ne.start && ind <= ne.end)
				res = ne.index;
			else if (ind >= c.start && ind <= c.end)
				res = c.index;
		}
		return res;
	}
};