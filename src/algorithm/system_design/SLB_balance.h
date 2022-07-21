#pragma once
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/067358deef2841dc8110ccfea928954b?tpId=332&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D332

class SLBSolu {
public:
	unordered_map<int, bool> id_occupied;
	deque<int> ids;
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param operators int整型vector<vector<>>
	 * @return int整型vector
	 */
	vector<int> SLB(vector<vector<int> >& operators) {
		// write code here
		if (operators.empty()) {
			return {};
		}

		vector<int> ret;
		for (vector<int>& v : operators) {
			if (v[0] == 1) {
				add(v[1]);
			} else if (v[0] == 2) {
				del(v[1]);
			} else if (v[0] == 3) {
				ret.emplace_back(select());
			} else if (v[0] == 4) {
				release(v[1]);
			}
		}
		return ret;
	}

	void add(int id) {
		if (id_occupied.count(id)) {
			return;
		}
		id_occupied[id] = false;
		ids.emplace_back(id);
	}

	int select() {
		/* 		while (!ids.empty()) {
		            int front = ids.front();
		            if (id_occupied.count(front) && !id_occupied[front]) {
		                id_occupied[front] = true;
		                return front;
		            }

		            if (!id_occupied.count(front)) {
		                ids.pop_front();
		            }
		        } */
		for (auto iter = ids.begin(); iter != ids.end();) {
			if (id_occupied.count(*iter) && !id_occupied[*iter]) {
				id_occupied[*iter] = true;
				return *iter;
			}

			if (!id_occupied.count(*iter)) {
				iter = ids.erase(iter);
				continue;
			}
			iter++;
		}

		return id_occupied.size();
	}

	void del(int id) {
		if (id_occupied.count(id)) {
			id_occupied.erase(id);
		}
	}

	void release(int id) {
		if (id_occupied.count(id)) {
			id_occupied[id] = false;
		}
	}
};