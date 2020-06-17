#include <iostream>
#include "range.h"
#include "accumulate.h"
#include "filterfalse.h"
#include "vector"
#include "compress.h"

using namespace itertools;
using namespace std;


struct lessThen3 {
    bool operator()(int i) const {
        return i < 3;
    }
};


int main() {
    for (int i: range(5,9))
       cout << i << " ";

    vector<int> vecInt = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};

    cout << "####  accumulate:  ####";
    cout << endl << "accumulate of range: " << endl;
    for (int i: accumulate(range(5,9)))
        cout << i << " ";      // 5 11 18 26

    cout << endl << "accumulate of vector<string>: " << endl;
    for (auto i: accumulate(vecString ))
        cout << i << " ";  // Hello HelloBye HelloByeAdam


    cout << endl << "accumulate of range with binary operator: " << endl;
    for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
        cout << i << " ";      // 5 30 210 1680

    cout << endl << "filter false all odd numbers: " << endl;
    for(auto i:filterfalse([](int x){return x%2==0;},range(4,18)))
        cout << i << " ";
    cout << endl << "filter fasle less then 3 in vector: " << endl;
    for(auto i:filterfalse(lessThen3{},vecInt))
        cout << i << " ";

    string a = "abce";
    vector<bool> vecBool = {true, true, false, true};


    for (auto i:compress(a, vecBool)) {

        cout << i << " ";

    }


    for (auto i:compress(range(5,9), vecBool)) {

        cout << i << " ";

    }



    return 0;
}
