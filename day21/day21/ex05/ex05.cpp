#include <iostream>
#include <vector>
#include <algorithm>

bool _compare(int a, int b)
{
	if (a > b) return true;
	return false;
}

int main()
{
	std::vector<int> v1;

	v1.push_back(10);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(11);
	v1.push_back(3);

	std::sort(v1.begin(), v1.end(), _compare);

	for (int i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << std::endl;
	}

	return 0;
}
