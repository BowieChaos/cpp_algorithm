#pragma once
#include <bits/stdc++.h>
#include <cstring>
#include <deque>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/1ea25727949c4945be2356a9e9569050?tpId=332&tqId=2603646&ru=%2Fexam%2Foj&qru=%2Fta%2Fsystem-design%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D332

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param s1 string字符串vector
	 * @param s2 string字符串vector
	 * @param n int整型
	 * @return int整型vector
	 */
	vector<int> BloomFilter(vector<string>& s1, vector<string>& s2, int n) {
		// write code here
		vector<int> ret;
		for (int i = 0; i < n; i++) {
			v_mod.push_back(10000 + rand() % 10001);
		}

		add(s1, n);
		for (auto& s : s2) {
			if (contains(s, n)) {
				ret.emplace_back(1);
			} else {
				ret.emplace_back(0);
			}
		}
		return ret;
	}

	int generate_key(int i, int mod, const string& str) {
		int key = 0;
		for (auto& c : str) {
			key = (i * key + c) % mod;
		}
		return key;
	}

	void add(vector<string>& s1, int n) {
		for (int i = 1; i <= n; i++) {
			for (auto& s : s1) {
				int k = generate_key(i, v_mod[i - 1], s);
				bits.set(k);
			}
		}
	}

	int contains(const string& s, int n) {
		for (int i = 1; i <= n; i++) {
			int k = generate_key(i, v_mod[i - 1], s);
			if (!bits[k]) {
				return 0;
			}
		}
		return 1;
	}

	std::bitset<20000> bits;
	vector<int> v_mod;
};