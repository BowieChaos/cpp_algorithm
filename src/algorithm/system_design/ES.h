#pragma once
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/7ba676741a3c4920b7846476be520779?tpId=332&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D332

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param ID int整型vector
	 * @param content string字符串vector
	 * @param word string字符串
	 * @return int整型vector
	 */
	vector<int> invertedIndex(vector<int>& ID, vector<string>& content,
	                          string word) {
		// write code here
		vector<int> ret;
		if (ID.empty() || content.empty()) {
			return ret;
		}

		unordered_map<string, vector<int>> ES_index;
		for (int i = 0; i < content.size(); i++) {
			vector<string> tokens;
			split(content[i], tokens, " ");

			for (string s : tokens) {
				if (ES_index.count(s)) {
					if (ES_index[s].back() != ID[i]) {
						ES_index[s].emplace_back(ID[i]);
					}
				} else {
					ES_index[s] = {ID[i]};
				}
			}
		}
		if (ES_index.count(word)) {
			return ES_index[word];
		}
		return ret;
	}

	void split(const std::string& str, std::vector<std::string>& tokens,
	           const std::string delim = " ") {
		tokens.clear();

		char* buffer = new char[str.size() + 1];
		std::strcpy(buffer, str.c_str());

		char* tmp;
		char* p = strtok_r(buffer, delim.c_str(), &tmp); // 第一次分割
		do {
			tokens.push_back(p); // 如果 p 为 nullptr，则将整个字符串作为结果
		} while ((p = strtok_r(nullptr, delim.c_str(), &tmp)) != nullptr);
		// strtok_r 为 strtok 的线程安全版本。
	}
};