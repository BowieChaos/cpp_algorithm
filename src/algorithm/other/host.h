#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

// https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Cmp {
public:
	bool operator()(const vector<int>& l, const vector<int>& r) {
		if (l[0] == r[0]) {
			return l[1] < r[1];
		} else {
			return l[0] < r[0];
		}
	}
};

class Host {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 计算成功举办活动需要多少名主持人
	 * @param n int整型 有n个活动
	 * @param startEnd int整型vector<vector<>>
	 * startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
	 * @return int整型
	 */
	int minmumNumberOfHost(int n, vector<vector<int>>& startEnd) {
		// write code here
		if (startEnd.empty()) {
			return 0;
		}
		sort(startEnd.begin(), startEnd.end(), Cmp());
		priority_queue<int, vector<int>, greater<int>> pq;
        pq.emplace(INT_MIN);
        int res = 0;
        for (int i = 0;i<startEnd.size();i++) {
            if (pq.top()<startEnd[i][0]) {
                pq.pop();
                res++;
            }
            pq.emplace(startEnd[i][1]);
        }
        return res;
	}
};
