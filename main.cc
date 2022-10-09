#pragma once
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct File {
	std::string name;
	bool isDirectory;
	vector<File*> children;
	int depth;
};

File* constructFileTree(vector<File*>& files) {
	if (files.empty()) {
		return nullptr;
	}
	File* root = files[0];
	stack<File*> stk;
	stk.emplace(root);
	int cur_index = 1;
	while (cur_index < files.size()) {
		while (cur_index < files.size() && files[cur_index]->isDirectory) {
			stk.top()->children.emplace_back(files[cur_index]);
			stk.emplace(files[cur_index]);
			cur_index++;
		}
		auto cur_dir = stk.top();
		while (cur_index < files.size() && !files[cur_index]->isDirectory) {
			cur_dir->children.emplace_back(files[cur_index]);
			cur_index++;
		}
		if (cur_index >= files.size()) {
			break;
		}

		while (cur_index < files.size() && files[cur_index]->isDirectory) {
			stk.top()->children.emplace_back(files[cur_index]);
			stk.emplace(files[cur_index]);
			cur_index++;
		}

		stk.pop();
		stk.top()->children.emplace_back(files[cur_index]);
		stk.emplace(files[cur_index]);
		cur_index++;
		
	}
	return root;
}

int main() { return 0; }