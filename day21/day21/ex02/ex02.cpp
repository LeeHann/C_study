#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string str1 = "hello string";
    std::string str2 = "30";
    int myint;
    int mynum = 40;
    float _pi = 3.14;

    std::stringstream(str2) >> myint; // string -> int
    myint++;

    str1 = str1 + std::to_string(mynum) + "," + std::to_string(_pi); // int, float -> string

    std::cout << str1 << "," << myint << std::endl;
   
    return 0;
}

