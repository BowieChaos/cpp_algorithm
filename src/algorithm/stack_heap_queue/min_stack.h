#pragma once
#include <limits.h>
#include <stack>
using namespace std;

// NC90 包含min函数的栈
// https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MinStack {
public:
	void push(int value) {
		if (min_stk.empty()) {
            min_stk.push(value);
        } else if (value < min()) {
            min_stk.push(value);
        } else {
            min_stk.push(min_stk.top());
        }
        stk.push(value);
	}
	void pop() { 
        min_stk.pop();
        stk.pop();
    }
	int top() {
        return stk.top();
    }
	int min() {
        return min_stk.top();
    }

private:
	stack<int> stk;
	stack<int> min_stk;
};