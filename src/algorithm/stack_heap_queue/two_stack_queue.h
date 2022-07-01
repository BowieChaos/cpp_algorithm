#pragma once
#include <stack>

using namespace std;
//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class StackToQueue {
public:
	void push(int node) {
        stack1.push(node);
	}

	int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
	stack<int> stack1;
	stack<int> stack2;
};