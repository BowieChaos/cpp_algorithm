#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/c76408782512486d91eea181107293b6?tpId=295&tqId=1008753&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class NumNQueen {
public:
	/**
	 *
	 * @param n int整型 the n
	 * @return int整型
	 */
	int count = 0;
	vector<int> chessBoard;
	int Nqueen(int n) {
		// write code here
		if (n == 0) {
			return 0;
		}
		chessBoard.resize(n);
		for (size_t i = 0; i < n; i++) {
			chessBoard[i] = -1;
		}
		traverse(0, n);
		return count;
	}

	void traverse(int row, int n) {
		if (row == n) {
            this->count++;
            this->chessBoard[row-1] = -1;
			return;
		}
		for (size_t i = 0; i < n; i++) {
			if (check(i, row)) {
				chessBoard[row] = i;
				traverse(row + 1, n);
				chessBoard[row] = -1;
			}
		}
		return;
	}

	bool check(int col, int row) {
		for (size_t i = 0; i < row; i++) {
			if (chessBoard[i] == col) {
				return false;
			}
			if (chessBoard[i] + i == row + col) {
				return false;
			}
			if (chessBoard[i] - i == col - row) {
                return false;
            }
		}
        return true;
	}
};