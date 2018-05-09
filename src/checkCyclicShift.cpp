#include <iostream>
#include "../hdr/basicFunc.h"

int main()
{
    std::string str1, str2;
    std::cout<<"Str1:\n";
    std::cin>>str1;
    std::cout<<"Str2:\n";
    std::cin>>str2;
    std::cout << cyclicShift(str1,str2) << std::endl;
    return 0;
}