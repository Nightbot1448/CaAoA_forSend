#include "../hdr/kmp.h"

std::vector<int> prefix(std::string _template){
	size_t n = _template.size();
	std::vector<int> pi(n);
	for (size_t i=1; i<n; ++i){
		size_t j = pi[i-1];
		while ((j > 0) && (_template[i] != _template[j]))
			j = pi[j-1];
		if (_template[i] == _template[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

std::vector<int> kmp(std::string text, std::string _template, const std::vector<int>& pi){
	std::vector<int> index;
	size_t j=0;
	for (size_t i=0; i<text.size(); ++i){
		while ((j > 0) && text[i] != _template[j])
			j = pi[j-1];
		if (text[i] == _template[j])
			++j;
		if (j==_template.size())
			index.push_back(i-j+1);
	}
	return index;
}

int cyclicShift(std::string str1, std::string str2)
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