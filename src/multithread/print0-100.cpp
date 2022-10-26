#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex mx;
condition_variable cv;
int number = 0;
void func1() {
	unique_lock<mutex> lc(mx);
	while (number <= 100) {
		while (number % 3 == 0 && number <= 100) {
			cout << number << " ";
			number++;
			cv.notify_all();
		}
		cv.wait(lc);
	}
	cv.notify_all();
}

void func2() {
	unique_lock<mutex> lc(mx);
	while (number <= 100) {
		while (number % 3 == 1 && number <= 100) {
			cout << number << " ";
			number++;
			cv.notify_all();
		}
		cv.wait(lc);
	}
}

void func3() {
	unique_lock<mutex> lc(mx);
	while (number <= 100) {
		while (number % 3 == 2 && number <= 100) {
			cout << number << " ";
			number++;
			cv.notify_all();
		}
		cv.wait(lc);
	}
}

int main() {
	thread s1(func1);
	thread s2(func2);
	thread s3(func3);
	s1.join();
	s2.join();
	s3.join();
	return 0;
}
