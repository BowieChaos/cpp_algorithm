#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

template <typename T> T sum(T arg) { return arg; }
template <typename T, typename... Ts> T sum(T arg, Ts... args) { return arg + sum(args...); }

struct Foo {
	std::unique_ptr<int> p;

	void f() {
		auto f = [=] { cout << this->p.get() << endl; };
		f();
	}
};