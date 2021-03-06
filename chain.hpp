#pragma once
#include<iostream>
using namespace std;

namespace itertools{
    template<typename T1,typename T2>

    class chain{
        private:
        T1 t1;
        T2 t2;
        
        public:
        chain(const T1& begins,const T2& ends):t1(begins),t2(ends){ }
        
        class const_iterator {
            public: 
                typename T1::const_iterator t1Begin;
                typename T1::const_iterator t1End;
                typename T2::const_iterator t2Begin;
                typename T2::const_iterator t2End;

                const_iterator(const typename T1::const_iterator& it1Begin, const typename T1::const_iterator& it1End
                ,const typename T2::const_iterator& it2Begin, const typename T2::const_iterator& it2End) :
                 t1Begin(it1Begin), t1End(it1End), t2Begin(it2Begin), t2End(it2End) { }

                const auto operator*() {
                    if (t1Begin != t1End) { return *t1Begin; }
                    return *t2Begin;
                }

                const const_iterator& operator++() {
                    if(t1Begin != t1End) { ++t1Begin; }
                    else { ++t2Begin; }
                    return *this;
                }

                bool operator!=(const const_iterator& it) {
                    if (t1Begin != it.t1Begin || t2Begin != it.t2Begin) { return true; }
                    return false;
                }
        };

        const_iterator begin() const { return const_iterator(t1.begin(), t1.end(), t2.begin(), t2.end()); }
        const_iterator end() const { return const_iterator(t1.end(), t1.end(), t2.end(), t2.end()); }
    };
}

