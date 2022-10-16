#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC36 在两个长度相等的排序数组中找到上中位数
// https://www.nowcoder.com/practice/6fbe70f3a51d44fa9395cfc49694404f?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型https://blog.csdn.net/qq_34342154/article/details/78462679
     */
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        int left1 = 0;
        int right1 = arr1.size() - 1;
        int left2 = 0;
        int right2 = arr1.size() - 1;
        while (left1 < right1 && left2<right2) {
            int mid1 = (left1 + right1) / 2;
            int mid2 = (left2 + right2) / 2;
            int offset = ((right1 - left1 + 1) % 2)^1;
            if (arr1[mid1] == arr2[mid2]) {
                return arr1[mid1];
            }
            else if (arr1[mid1] < arr2[mid2]) {
                left1 = mid1 + offset;
                right2 = mid2;
            }
            else {
                right1 = mid1;
                left2 = mid2 + offset;
            }
        }
        return min(arr1[left1], arr2[left2]);
    }
};