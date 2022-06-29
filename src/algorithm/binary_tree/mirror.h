#pragma once

#include "../../model/b_tree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

class Mir {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (pRoot == nullptr) {
            return pRoot;
        }
        TreeNode* left = pRoot->left;
        pRoot->left = Mirror(pRoot->right);
        pRoot->right = Mirror(left);
        return pRoot;
    }
};