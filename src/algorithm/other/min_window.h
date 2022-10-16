#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// NC28 最小覆盖子串
// https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MinWindow {
public:
	/**
	 *
	 * @param S string字符串
	 * @param T string字符串
	 * @return string字符串
	 */
	string minWindow(string S, string T) {
		// write code here
		if (S.empty() || T.empty()) {
			return "";
		}
		unordered_map<char, int> target_mp, window_mp;
		for (char c : T) {
			target_mp[c] += 1;
		}
		int left = 0;
		int right = 0;
		int count = 0;
		int len = INT_MAX;
		int start = 0;
		while (right < S.size()) {

			char c = S[right];
			right++;

			if (target_mp.find(c) != target_mp.end()) {
				window_mp[c]++;
				if (target_mp[c] == window_mp[c]) {
					count++;
				}
			}

			while (count == target_mp.size()) {
				if (right - left < len) {
					start = left;
					len = right - left;
				}
				char c = S[left];
				left++;
				if (target_mp.find(c) != target_mp.end()) {
					if (target_mp[c] == window_mp[c]) {
						count--;
					}
					window_mp[c]--;
				}
			}
		}

		return len == INT_MAX ? "" : S.substr(start, len);
	}
};