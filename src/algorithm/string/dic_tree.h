#pragma once

#include <algorithm>
#include <deque>
#include <set>
#include <string>
#include <vector>
using namespace std;

// NC124 字典树的实现
// https://www.nowcoder.com/practice/a55a584bc0ca4a83a272680174be113b?tpId=117&tqId=37832&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class treeNode {
public:
	int pre_num = 0;
	vector<treeNode*> childs{vector<treeNode*>(26, nullptr)};
	bool end = false;
	treeNode(){};
	treeNode(const treeNode&) = delete;
	treeNode(treeNode&&) = delete;
	~treeNode() {
		for (auto c : childs) {
			if (c != nullptr) {
				delete c;
			}
		}
	};
};

class Solution {
public:
	treeNode* root = new treeNode();

	/**
	 *
	 * @param operators string字符串vector<vector<>> the ops
	 * @return string字符串vector
	 */
	vector<string> trieU(vector<vector<string>>& operators) {
		// write code here
		vector<string> ret_vec;
		if (operators.empty() || operators[0].empty()) {
			return ret_vec;
		}
		for (auto& op : operators) {
			if (op[0] == "1") {
				insert(op[1]);
			} else if (op[0] == "2") {
				del(op[1]);
			} else if (op[0] == "3") {
				if (search(op[1])) {
					ret_vec.emplace_back("YES");
				} else {
					ret_vec.emplace_back("NO");
				}
			} else {
				ret_vec.emplace_back(to_string(prefix_num(op[1])));
			}
		}
		return ret_vec;
	}

	void insert(string word) {
		treeNode* theNode = root;
		for (char c : word) {
			int index = c - 'a';
			if (theNode->childs[index] == nullptr) {
				theNode->childs[index] = new treeNode();
			}
			theNode = theNode->childs[index];
			theNode->pre_num++;
		}
		theNode->end = true;
	}

	void del(string word) {
		treeNode* theNode = root;
		for (char c : word) {
			int index = c - 'a';
			if (theNode->childs[index] == nullptr) {
				return;
			}
			theNode = theNode->childs[index];
			theNode->pre_num--;
		}
		if (theNode->pre_num == 0) {
			theNode->end = false;
		}
	}

	bool search(string word) {
		treeNode* theNode = root;
		for (char c : word) {
			if (theNode->childs[c - 'a'] == nullptr) {
				return false;
			}
			theNode = theNode->childs[c - 'a'];
		}
		return theNode->end;
	}

	int prefix_num(string word) {
		treeNode* theNode = root;
		for (char c : word) {
			if (theNode->childs[c - 'a'] == nullptr) {
				return 0;
			}
			theNode = theNode->childs[c - 'a'];
		}
		return theNode->pre_num;
	}
};
