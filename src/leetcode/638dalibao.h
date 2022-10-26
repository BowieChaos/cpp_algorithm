#pragma once

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	map<vector<int>, int> memo;    //存储已计算过的需求情况及对应的最小价格
	vector<vector<int>> usefulSpe; //有效礼包
	int n;                         //在售物品数量

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		n = price.size();

		//获取有效礼包
		for (vector<int>& pkg : special) {
			int pay = 0; //礼包内物品总价
			for (int i = 0; i < n; i++) {
				pay += pkg[i] * price[i];
			}
			if (pay > pkg[n]) { //售价小于物品总价，礼包有效
				usefulSpe.push_back(pkg);
			}
		}

		//记忆化搜索
		return dfs(price, needs);
	}

	int dfs(vector<int>& price, vector<int> curNeeds) {
		if (memo.count(curNeeds) == 0) {  //当前需求情况未计算过
			int pay = 0;                  //当前需求对应的最低花费
			for (int i = 0; i < n; i++) { //直接单件购买所有物品作为初始值
				pay += curNeeds[i] * price[i];
			}
			for (vector<int>& pkg : usefulSpe) {    //遍历礼包
				vector<int> nextNeeds;              //选用该礼包后剩余的物品需求
				for (int i = 0; i < n; i++) {       //遍历物品
					if (curNeeds[i] - pkg[i] < 0) { //不能购买超出指定数量的物品，直接跳出
						break;
					}
					nextNeeds.push_back(curNeeds[i] - pkg[i]);
				}
				if (nextNeeds.size() == n) {                        //判断当前礼包是否可用
					pay = min(pay, pkg[n] + dfs(price, nextNeeds)); //深度搜索
				}
			}
			memo[curNeeds] = pay; //记忆化
		}
		return memo[curNeeds]; //返回当前需求情况对应的最小花费
	}
};
