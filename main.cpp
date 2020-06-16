#include <iostream>
#include "range.h"
#include "accumulate.h"
#include "vector"

using namespace itertools;
using namespace std;

template<class T>
 void print(const T &x)  {
    int sum = 0;
    for (auto item:x) {
        sum += item;
        std::cout << sum << std::endl;

    }
}

int main() {
//    for (int i: range(5,9))
//       cout << i << " ";
//
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
    cout << endl << endl;

    cout << endl << "accumulate of range with binary operator: " << endl;
    for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
        cout << i << " ";      // 5 30 210 1680

    return 0;
}
