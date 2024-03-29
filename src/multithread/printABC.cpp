#include <condition_variable>
#include <iostream>
#include <thread>
std::mutex mtx;
std::condition_variable cv;
int ready = 0;
void PrintString_1() {
	std::unique_lock<std::mutex> lk(mtx);
	int cnt = 0;
	while (cnt < 10) {
		while (ready != 0)
			cv.wait(lk);
		std::cout << std::this_thread::get_id() << " : "
		          << "A" << std::endl;
		ready = 1;
		cnt++;
		cv.notify_all();
	}
}

void PrintString_2() {
	std::unique_lock<std::mutex> lk(mtx);
	int cnt = 0;
	while (cnt < 10) {
		while (ready != 1)
			cv.wait(lk);
		std::cout << std::this_thread::get_id() << " : "
		          << "B" << std::endl;
		ready = 2;
		cnt++;
		cv.notify_all();
	}
}

void PrintString_3() {
	std::unique_lock<std::mutex> lk(mtx);
	int cnt = 0;
	while (cnt < 10) {
		while (ready != 2)
			cv.wait(lk);
		std::cout << std::this_thread::get_id() << " : "
		          << "C" << std::endl;
		ready = 0;
		cnt++;
		cv.notify_all();
	}
}

int main() {
	std::thread t1(PrintString_1);
	std::thread t2(PrintString_2);
	std::thread t3(PrintString_3);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}