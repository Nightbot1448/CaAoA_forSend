#ifndef kmp_h
#define kmp_h

#include <vector>
#include <string>
#include <utility>

std::string gen_random_string(size_t len);
std::pair<std::vector<int>, size_t> naiveAlgorithm(
		const std::string &text, const std::string &_template);

std::vector<int> prefix(const std::string &_template);
std::pair<std::vector<int>, size_t> kmp(const std::string &text
		, const std::string &_template, const std::vector<int>& pi);
int cyclicShift(const std::string &str1, const std::string &str2);

#endif //kmp_h
