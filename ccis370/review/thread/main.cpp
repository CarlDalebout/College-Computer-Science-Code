// C++ program to demonstrate
// multithreading using three
// different callables.
#include <iostream>
#include <thread>


bool flag = 0;

class thread_obj
{
	public:
	void operator()(int & ret, int x)
	{
		while(flag);
		ret += x;
		flag = 1;
	}
};

// Driver code
int main()
{
	int value = 3;
	std::cout << "Threads 1 and 2 and 3 "
		"operating independently" << std::endl; 	

// This thread is launched by using
for(int i = 0; i < 10; ++i)
{
	// function pointer as callable
	std::thread th1(thread_obj(), value, 1);
	std::thread th2(thread_obj(), value, -1);

	std::cout << value << '\n';
	// Wait for thread 1 and 2 to finish
	th1.join();
	th2.join();
}

return 0;
}