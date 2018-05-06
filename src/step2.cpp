#include <iostream>
#include "../hdr/kmp.h"

int cycle(std::string str1, std::string str2)
{
    if(str1.size()!=str2.size())
        return -1;
    std::vector<int> pi=prefix(str2);
    std::vector<int> index=kmp(str1+str1,str2,pi);
    if(index.size())
        return index[0];
    else
        return -1;
}

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