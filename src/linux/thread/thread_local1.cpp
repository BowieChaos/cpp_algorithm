#include <iostream>
#include <string>
#include <thread>
class Wigdet {
public:
	explicit Wigdet(const std::string& strName);     // 构造
	Wigdet(const Wigdet& othre);                     // copy构造
	Wigdet& operator=(const Wigdet& othre) = delete; // assign 构造
	Wigdet(Wigdet&& othree) = delete;
	Wigdet& operator=(Wigdet&&) = delete;
	~Wigdet();
	friend void PrintMsg(const Wigdet& widget, const std::string& msg);
	friend void PrintNum(const Wigdet& widget);
	int Add();    // 调用一次+1
	int GetNum(); // 返回m_num
private:
	std::string m_strThreadName;
	int m_num; // 试着在不同的线程查看不同的结果
};

Wigdet::Wigdet(const std::string& strThreadName)
    : m_strThreadName(strThreadName)
    , m_num(0) {
	PrintMsg(*this, "构造函数被调用。");
}

Wigdet::~Wigdet() { PrintMsg(*this, "析构函数被调用。"); }

int Wigdet::Add() { return ++m_num; }

int Wigdet::GetNum() { return m_num; }

Wigdet::Wigdet(const Wigdet& othre)
    : m_strThreadName(othre.m_strThreadName)
    , m_num(othre.m_num) {
	PrintMsg(*this, "copy 构造函数被调用。");
}

// 打印消息的友元函数
void PrintMsg(const Wigdet& widget, const std::string& msg) {
	std::cout << "线程id: " << std::this_thread::get_id() << "\t" << widget.m_strThreadName << msg << std::endl;
}

void PrintNum(const Wigdet& widget) {
	// 由于std::cout 并非原子操作，会产生竞争
	// 为了方便，使一个线程结束了再启动另外一个线程，便于分析
	std::cout << "线程id: " << std::this_thread::get_id() << "\t" << widget.m_strThreadName << " 当前num值："
	          << widget.m_num << std::endl;
}

// 全局thread_local 测试
thread_local Wigdet global_wigdet(std::string("global_var"));

void Foo() {
	PrintNum(global_wigdet);
	global_wigdet.Add();
	PrintNum(global_wigdet);
}

int main() {
	std::cout << "主线程ID :" << std::this_thread::get_id() << std::endl;
	Foo(); // 主线程调用；
	       // 使用超长延时使代码按照书写方式运行，便于分析。
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread A(Foo); // 线程A调用
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread B(Foo); // 线程B调用
	A.join();
	B.join();
}
