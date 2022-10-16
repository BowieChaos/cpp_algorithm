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

int main() {
	std::string s;
	s.substr();
	return 0;
}