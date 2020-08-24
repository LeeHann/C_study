#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect_1;

    vect_1.push_back(1);
    vect_1.push_back(2);
    vect_1.push_back(3);
    vect_1.push_back(4);
    vect_1.push_back(5);

    std::cout << "Size : " << vect_1.size() << ", capacity : " << vect_1.capacity() << std::endl;
    std::cout << "MaxSize : " << vect_1.max_size() << std::endl;

    /*
    std::cout << vect_1[0] << std::endl;
    std::cout << vect_1[1] << std::endl;
    std::cout << vect_1[2] << std::endl;
    std::cout << vect_1[3] << std::endl;
    std::cout << vect_1[4] << std::endl;
    */

    for (auto i = vect_1.begin(); i != vect_1.end(); i++)
    {
        std::cout << *i << std::endl;
    }
   
    vect_1[0] = 10;
    std::cout << vect_1[0] << std::endl;
    std::cout << "use []" << vect_1[0] << std::endl;
    std::cout << "use at" << vect_1.at(0) << std::endl;

    vect_1.pop_back();
    vect_1.insert(vect_1.begin(), 20);
    vect_1.insert(vect_1.begin()+3, 33);
    vect_1.erase(vect_1.begin() + 2);
    std::cout << "------------------------------" << std::endl;

    for (auto i = vect_1.begin(); i != vect_1.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    vect_1.erase(vect_1.end()-1); // == vect_1.pop_back();

    std::cout << "------------------------------" << std::endl;

    for (auto i = vect_1.begin(); i != vect_1.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    return 0;
}
