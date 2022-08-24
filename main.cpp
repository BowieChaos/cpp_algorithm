#include<iostream>
#include<future>
#include<thread>

using namespace std;

void thread_set_promise(std::promise<int>& promiseObj)
{
	cout << "In a thread, making data..." << endl;
	std::this_thread::sleep_for(chrono::milliseconds(1000));
	promiseObj.set_value(35);
}
int main()
{

	promise<int> promiseObj;
	future<int> futureObj=promiseObj.get_future();
	thread t(&thread_set_promise, std::ref(promiseObj));
	cout << futureObj.get() << endl;
	t.join();
	cout << "Finished!!!\n" << endl;
	
	system("pause");
	return 0;
}
