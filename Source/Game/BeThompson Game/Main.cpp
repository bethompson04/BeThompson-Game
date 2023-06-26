#include <iostream>

int main()
{
#ifdef _DEBUG
	std::cout << "GRRAAAAH DEBUG!\n";
#endif

	std::cout << "Hello There\n";

	return 0;
}