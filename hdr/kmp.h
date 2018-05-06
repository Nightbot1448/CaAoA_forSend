#ifndef kmp_h
#define kmp_h

#include <vector>
#include <string>

std::vector<int> prefix(std::string _template);
std::vector<int> kmp(std::string text, std::string _template, const std::vector<int>& pi);
int cyclicShift(std::string str1, std::string str2);

#endif //kmp_h
