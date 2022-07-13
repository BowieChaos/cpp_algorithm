#pragma once

// https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MergeArray {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m - 1, j = n - 1,
		    p = m + n - 1; // i,j指针指向原末尾，p指针指向合并后的A末尾
		while (i >= 0 && j >= 0) { // ~i  <==>
			// i>=0,因为-1取反过后返回的是0，位运算一般情况比其他运算符速度要快
			A[p--] = A[i] > B[j]
			             ? A[i--]
			             : B[j--]; //合并A、B数组，
			                       //比较i,j指针指向的元素，将大的那个丢进去
		}
		while (~j) { //如果B数组还有剩余，则直接全部移到A数组中
			A[p--] = B[j--];
		}
		/*此处如果出现A数组有剩余的情况，理论上应该执行while(i>=0)A[p--]=A[i--]
		但是如果A有剩余必然有p==i(出现剩余的情况，只有可能一个出现剩余，不可能出现AB数组都剩余的情况)
		（如果出现AB都剩余，就跟第一个for循环矛盾了)
		既然对于指针p==i，那么此时这个while循环就会显得很多余
		*/
	}
};