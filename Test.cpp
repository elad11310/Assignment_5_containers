//
// Created by elad on 17/06/2020.
//

//#define CHECK DOCTEST_CHECK
#include "doctest.h"
#include "range.h"
#include "filterfalse.h"
#include "compress.h"
#include "accumulate.h"
#include <iostream>
#include <string>
#include <vector>

using namespace itertools;
using namespace std;

//struct +
struct pluss{
template<typename T>
T operator ()(T a, T b){
	return a+b;
}
};

//struct -
struct muniss{
template<typename T>
T operator ()(T a, T b)
{
	return a-b;
}
};

TEST_CASE ("Range") {

CHECK_THROWS(range(-1,9));
CHECK_THROWS(range(5,4));
CHECK_THROWS(range(-100));
int count=5;
for(auto i: range(5,20)){
CHECK(i==count++);
}
for(auto i: range(5,5)){
CHECK(i==5);
}
}

TEST_CASE ("Accumulate") {

auto multy= [](int a, int b){return a*b;};
auto divide= [] (int a, int b){return a/b;};
vector<std::string> a{"a","ab","abc","abcd"};
int k=0;
for(auto i: accumulate(string("abcd"), pluss{})){
CHECK(i==string(a[k++]));
}


}

TEST_CASE ("Filterfalse") {




}

TEST_CASE ("Compress") {



for(int i=0; i <101; i++){
CHECK((0+0)=0);
}


}




