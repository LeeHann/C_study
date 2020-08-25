#include <iostream>

void test(int a, int b)
{
	std::cout << a + b << std::endl;
}

int main()
{
	int a = 100;
	int b[5] = { 1,2,3,4,5 };
	char* ptr1 = (char *)b;
	unsigned short* ptr2 = (unsigned short *)b;

	test(a, b[2]);

	return 0;
}

