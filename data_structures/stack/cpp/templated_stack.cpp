#include <exception>
#include <iostream>

#include "Stack.hpp"

/*
 * Main is only used to test different
 * methods on my stack
 *
 */

int main(void) {
	Stack<int> s;

	std::cout << "Initializing stack" << std::endl;

	for (int i = 0; i < 10; ++i)
		s.push(i);

	std::cout << "Done!" << std::endl;

	while ( !s.empty() )
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "Popping off another (inexistant) element" << std::endl;

	try 
	{
		s.pop();
	} 
	catch (std::exception& e)
	{
		std::cerr << "[ERR] " << e.what() << std::endl;
	}

	return 0;
}
