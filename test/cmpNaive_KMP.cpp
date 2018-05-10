#include "../hdr/basicFunc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

void test(size_t text_min, size_t text_size, size_t temp_min, size_t temp_size)
{
	size_t count = 0;
	for(size_t i=0; i<10; i++)
	{
		srand(time(0)%UINT_MAX);
		size_t text_len = rand() % text_size+text_min;
		std::string text = gen_random_string(text_len);
		for(size_t j=0; j<10; j++)
		{
			size_t temp_len;
			temp_len = rand() % temp_size+temp_min;
			std::string _template = gen_random_string(temp_len);
			std::vector<int> pi=prefix(_template);
			std::pair<std::vector<int>, size_t> naive_res = naiveAlgorithm(text, _template);
			std::pair<std::vector<int>, size_t> kmp_res = kmp(text, _template, pi);
			if (kmp_res.second < naive_res.second)
				count++;
		}	
	}
	std::cout << "Text length range = [" << text_min << ", " 
			  << text_min + text_size <<")" << std::endl;
	std::cout << "Template length range = [" << temp_min << ", " 
			  << temp_min + temp_size <<")" << std::endl;
	std::cout << "Algorithm is better in " << count << "/100 cases" << std::endl; 
}

int main()
{
	test(500000, 1000000, 10000, 10000);
	test(500000, 1000000, 100, 100);
	test(5000, 10000, 500, 1500);
	test(500, 1000, 100, 100);
	test(500, 1000, 10, 10);
}