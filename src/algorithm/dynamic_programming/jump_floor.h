#pragma once

// https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class JumpFloor {
public:
	int jumpFloor(int number) {
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};