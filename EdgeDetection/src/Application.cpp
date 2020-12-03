#include <iostream>
#include <functional>

int main() {
	// std::cout << "Hello world" << std::endl;
	[out = std::ref(std::cout << "Hello ")] (){out.get() << "C++"; }();
	return 0;
}