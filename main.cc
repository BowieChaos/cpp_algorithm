#include <condition_variable>
#include <functional>
#include <iostream>
#include <thread>
using namespace std;

std::mutex mtx;
std::condition_variable cv;

int main() {
	
	cout << "stop" << endl;
	return 0;
}