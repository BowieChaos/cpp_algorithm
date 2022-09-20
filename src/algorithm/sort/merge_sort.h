#pragma once

#include <iostream>
#include <vector>

void Merge(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
    int alength = A.size();
    int blength = B.size();
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) { // 这个是保证两个表是都是非空
        if (A[i] < B[j]) {
            C.push_back(A[i++]);
        } else {
            C.push_back(B[j++]);
        }
    }

    while (i < A.size()) {  // B表已经空了,那么我们将A表的值直接送入到C中
        C.push_back(A[i++]);
    }
    while (j < B.size()) {  // A表已经空了,将B表的数据直接送入到C中
        C.push_back(B[j++]);
    }
}

void MergeSort(std::vector<int>& unorder_array) {
    int length = unorder_array.size();
    std::vector<int> A;
    std::vector<int> B;
    if (length <= 1)
        return;

    for (int i  = 0; i < length; ++i) {
        if (i < (length >> 1)) {
            A.push_back(unorder_array[i]);
        } else {
            B.push_back(unorder_array[i]);
        }
    }
    MergeSort(A);   // 左边的数据归并
    MergeSort(B);   // 右边的数据归并
    unorder_array.clear();  // 首先清除数据
    Merge(A, B, unorder_array); // 归并排序

}
void display(std::vector<int>& unorder_array) {
    for (auto it = unorder_array.begin(); it < unorder_array.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
int main()
{
    std::vector<int> unorder_array;
    int data;
    std::cin >> data;
    unorder_array.push_back(data);
    while (std::cin.get() != '\n') {
        std::cin >> data;
        unorder_array.push_back(data);
    }
    std::cout << "orgin seq is: ";
    display(unorder_array); // 显示未进行排序的数据
    MergeSort(unorder_array);   // 归并排序
    std::cout << "merge sort is: ";
    display(unorder_array); // 归并排序之后数据

    return 0;
}
