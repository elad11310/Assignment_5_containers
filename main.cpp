#include <iostream>
#include "range.h"
#include "accumulate.h"
#include "filterfalse.h"
#include "vector"
#include "compress.h"
#include <list>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;


using namespace itertools;
using namespace std;


struct lessThen3 {
    bool operator()(int i) const {
        return i < 3;
    }
};

const int MIN_TESTS = 100;

struct ReporterCounter: public ConsoleReporter {
    ReporterCounter(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            std::cout << 100 << std::endl;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl << 0  << std::endl;
        }
    }
};

int main() {
        vector<int> vecInt = {1,2,3,4};
    set<int> s1 {3,4,5,6,7,8};
    list<int> mylist;
    mylist.insert(begin(mylist),5);
    mylist.insert(end(mylist),4);
    mylist.insert(end(mylist),2);
    for (int i: accumulate(vecInt)){
        cout << i << " ";
    }
//    for (int i: range(5,4))
//       cout << i << " ";
//    auto multy= [](int a, int b){return a*b;};
//    auto divide= [] (int a, int b){return a/b;};
//    vector<std::string> a{"a","ab","abc","abcd"};
//    vector<std::string> ddd{"a","b","c","d"};
//    int k=0;
//    for(auto i: accumulate(ddd)){
//               cout<<i <<endl;
//        k++;
//    }
//    vector<int> vecInt = {1,2,3,4};
//    vector<string> vecString = {"Hello", "Bye", "Adam"};
//    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};
//
//    cout << "####  accumulate:  ####";
//    cout << endl << "accumulate of range: " << endl;
//    for (int i: accumulate(range(5,9)))
//        cout << i << " ";      // 5 11 18 26
//
//    cout << endl << "accumulate of vector<string>: " << endl;
//    for (auto i: accumulate(vecString ))
//        cout << i << " ";  // Hello HelloBye HelloByeAdam
//
//
//    cout << endl << "accumulate of range with binary operator: " << endl;
//    for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
//        cout << i << " ";      // 5 30 210 1680
//
//    auto multy= [](int a, int b){return a*b;};
//    auto divide= [] (int a, int b){return a/b;};
//
//    cout << endl << "filter false all odd numbers: " << endl;
//    for(auto i:filterfalse([](int x){return x%2==0;},range(4,18)))
//        cout << i << " ";
//    cout << endl << "filter fasle less then 3 in vector: " << endl;
//    for(auto i:filterfalse(lessThen3{},vecInt))
//        cout << i << " ";
//
//    string a = "abce";
//    vector<bool> vecBool = {true, true, false, true};
//
//
//    for (auto i:compress(a, vecBool)) {
//
//        cout << i << " ";
//
//    }
//
//
//    for (auto i:compress(range(5,9), vecBool)) {
//
//        cout << i << " ";
//
//    }
//
//

    return 0;
}
