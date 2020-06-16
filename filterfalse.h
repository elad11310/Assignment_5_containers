//
// Created by elad on 16/06/2020.
//

#ifndef MATALA5_CONTAINERS_FILTERFALSE_H
#define MATALA5_CONTAINERS_FILTERFALSE_H


template<typename myFunc, typename Container>
class filterfalse {

    Container x;
    myFunc f;
public:
    filterfalse(myFunc F, Container X) : x(X), f(F) {}


    class iterator {
        typename Container::iterator itBegin;
        typename Container::iterator itEnd;
        myFunc func;

    public:

        iterator(  typename Container::iterator begin,  typename Container::iterator end,myFunc f):
        itBegin(begin), itEnd(end), func(f){}

        auto operator* (){
            return
        }

    };


    iterator begin() { return iterator(x.begin(), x.end(), f); }

    iterator end() { return iterator(x.end(), x.end(), f); }

};


#endif //MATALA5_CONTAINERS_FILTERFALSE_H
