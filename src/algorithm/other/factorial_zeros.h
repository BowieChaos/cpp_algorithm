

// NC129 阶乘末尾0的数量
// https://www.nowcoder.com/practice/aa03dff18376454c9d2e359163bf44b8?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117
class Solution {
public:
	/**
	 * the number of 0
	 * @param n long长整型 the number
	 * @return long长整型
	 */
	long long thenumberof0(long long n) {
		// write code here
		long long ans = 0;
		long long d = 5;
		while (n >= d) {
			ans += n / d;
			d = d * 5;
		}
		return ans;
	}
};