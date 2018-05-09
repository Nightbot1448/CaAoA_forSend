#include <iostream>	
#include "../hdr/basicFunc.h"

void print(const std::vector<int>& index){ //print result
	for(const auto& it: index){
		std::cout<<it;
		if(it!=index[index.size()-1])
			std::cout<<", ";
	}
	std::cout << std::endl;
}
	
int main()
{
	std::string _template, text;
	std::cout<<"Template:" << std::endl;
	std::cin>>_template;
	std::cout<<"Text:" << std::endl;
	std::cin>>text;
	if(_template.size() < 15000 && text.size()<5000000)
	{
		std::vector<int> pi=prefix(_template);
		auto kmp_res = kmp(text,_template	,pi);
		if(kmp_res.first.size()){
			print(kmp_res.first);
		}
		else
			std::cout << "-1" << std::endl;
	}
	else
		std::cout << "out of range" << std::endl;
	return 0;
}