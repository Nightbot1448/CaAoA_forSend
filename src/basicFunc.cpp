#include "../hdr/basicFunc.h"

#include <iostream>

std::string gen_random_string(size_t len)
{
	std::string alphanum("0123456789abcdefghijklmnopqrstuvwxyz");
	size_t alp_len = alphanum.size();
	std::string gen;
	for (size_t i = 0; i < len; ++i) { 
		gen += alphanum[rand() % alp_len];
	}
	return gen;
}

std::pair<std::vector<int>, size_t> naiveAlgorithm(
		const std::string &text, const std::string &_template)
{
	size_t count_of_op=0;
	std::vector<int> index;
	for(size_t i=0; i<text.size()-_template.size()+1; i++)
	{
		for(size_t j=0; j<_template.size(); j++)
		{
			count_of_op++;
			if(text[i+j] == _template[j])
			{
				if(j==_template.size()-1)
					index.push_back(i);
			}
			else
				break;
		}
	}
	return std::make_pair(index,count_of_op);
}

std::vector<int> prefix(const std::string & _template)
{
	size_t n = _template.size();
	std::vector<int> pi(n);
	for (size_t i=1; i<n; ++i)
	{
		size_t j = pi[i-1];
		while ((j > 0) && (_template[i] != _template[j]))
			j = pi[j-1];
		if (_template[i] == _template[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

std::pair<std::vector<int>, size_t> kmp(const std::string &text
		, const std::string &_template, const std::vector<int>& pi)
{
	std::vector<int> index;
	size_t j=0;
	size_t count_of_op=0;
	for (size_t i=0; i<text.size(); ++i){
		while ((j > 0) && text[i] != _template[j])
			j = pi[j-1];
		if (text[i] == _template[j])
			++j;
		if (j==_template.size())
			index.push_back(i-j+1);
		count_of_op++;
	}
	return std::make_pair(index,count_of_op+_template.size());
}

int cyclicShift(const std::string &str1, const std::string &str2)
{
	if(str1.size()!=str2.size())
		return -1;
	std::vector<int> pi=prefix(str2);
	auto index=kmp(str1+str1,str2,pi);//-------------------------------auto std::vector<int>
	if(index.first.size())
		return index.first[0];
	else
		return -1;
}