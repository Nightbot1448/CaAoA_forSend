#include "../hdr/basicFunc.h"
#include <cassert>
#include <iostream>

using namespace std;

void TestPref(){
    assert(prefix(" ")==vector<int>({0}));
    assert(prefix("a")==vector<int>({0}));
    assert(prefix("asdfg")==vector<int>({0,0,0,0,0}));
    assert(prefix("saaas")==vector<int>({0,0,0,0,1}));
    assert(prefix("asasa")==vector<int>({0,0,1,2,3}));
    assert(prefix("aaaaa")==vector<int>({0,1,2,3,4}));
    assert(prefix("aaabaaa")==vector<int>({0,1,2,0,1,2,3}));
    assert(prefix("aabaaab")==vector<int>({0,1,0,1,2,2,3}));
    assert(prefix("abcdabcabcdabcdab")==vector<int>({0,0,0,0,1,2,3,1,2,3,4,5,6,7,4,5,6}));
}

void TestKmp(){
    assert(kmp("a","a",vector<int>({0})).first==vector<int>({0}));
    assert(kmp("a","s",vector<int>({0})).first.size()==0);
    assert(kmp("a","sdf",vector<int>({0})).first.size()==0);
    assert(kmp("asa","a",vector<int>({0})).first==vector<int>({0,2}));
    assert(kmp("asa","s",vector<int>({0})).first==vector<int>({1}));
    assert(kmp("aaaa","aa",vector<int>({0,1,2})).first==vector<int>({0,1,2}));
    assert(kmp("aaaasaaasssasaaasaasaaaasaaa","aasaas",vector<int>({0,1,0,1,2,3})).first==vector<int>({14}));
}

void TestCyclicShift()
{
    assert(cyclicShift("b","b")==0);
    assert(cyclicShift("aaa","aaa")==0);
    assert(cyclicShift("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaal","laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")==31);
    assert(cyclicShift("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaal","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaala")==1);
    assert(cyclicShift("aa","a")==-1);
    assert(cyclicShift("aaaab","aaaac")==-1);
    assert(cyclicShift("aaaab","aacaa")==-1);
}

int main(){
    // TestPref();
    // TestKmp();
    // TestCyclicShift();
    cout<<"Correct!\n";
    return 0;
}
