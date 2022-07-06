#pragma once

#include <stack>

// https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Fibonacc {
public:
	int Fibonacci(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		int left = 0;
		int right = 1;
		for (int i = 1; i < n; i++) {
			int sum = left + right;
			int tmp = right;
			right = sum;
			left = tmp;
		}
		return right;
	}
};