#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct s_object {
	int hp;
	int mp;
	std::string name;
};

bool _compare(s_object a, s_object b)
{
	if (a.hp > b.hp) return true;
	return false;
}

bool _cmp(s_object a, s_object b)
{
	if (a.mp > b.mp) return true;
	return false;
}

int main()
{
	std::vector<s_object> objs;
	
	{
		s_object obj1;
		obj1.hp = 100;
		obj1.mp = 35;
		obj1.name = std::string("knight_1");
		objs.push_back(obj1);
	}
	{
		s_object obj1;
		obj1.hp = 120;
		obj1.mp = 20;
		obj1.name = std::string("knight_2");
		objs.push_back(obj1);
	}
	{
		s_object obj1;
		obj1.hp = 80;
		obj1.mp = 55;
		obj1.name = std::string("knight_3");
		objs.push_back(obj1);
	}

	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}

	std::cout << "---------------- sort : hp ------------------" << std::endl;

	std::sort(objs.begin(), objs.end(), _compare);

	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}
	
	std::cout << "---------------- sort : mp ------------------" << std::endl;

	std::sort(objs.begin(), objs.end(), _cmp);

	for (int i = 0; i < objs.size(); i++)
	{
		std::cout << objs[i].name << "," << objs[i].hp << "," << objs[i].mp << std::endl;
	}

	return 0;
}