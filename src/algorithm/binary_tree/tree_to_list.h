#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

// NC64 二叉搜索树与双向链表
// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=117&tqId=37854&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	vector<TreeNode*> TreeList; //定义一个数组，根据中序遍历来存储结点。

	void inorder(TreeNode* root) {
		if (!root)
			return;
		inorder(root->left);
		TreeList.push_back(root);
		inorder(root->right);
	}

	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree)
			return pRootOfTree;
		inorder(pRootOfTree);
		for (int i = 0; i < TreeList.size() - 1; i++) { //根据数组中的顺序将结点连接，注意i的范围。
			TreeList[i]->right = TreeList[i + 1];
			TreeList[i + 1]->left = TreeList[i];
		}
		return TreeList[0]; //数组的头部存储的是双向链表的第一个结点。
	}
};

class Solution {
public:
	TreeNode* preNode; // preNode一定是全局变量。
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree)
			return pRootOfTree;
		TreeNode* p = pRootOfTree;
		while (p->left)
			p = p->left; //找到双向链表的开头。
		inorder(pRootOfTree);
		return p;
	}

	void inorder(TreeNode* root) {
		if (!root)
			return;
		inorder(root->left);
		//当前结点中需要进校的调整。
		root->left = preNode;
		if (preNode) {
			preNode->right = root;
		}
		preNode = root; //更新preNode，指向当前结点，作为下一个结点的前继。

		inorder(root->right);
	}
};