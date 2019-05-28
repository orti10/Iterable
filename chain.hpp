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
        
        class iterator {
            public: 
                decltype(t1.begin()) t1Begin;
                decltype(t1.end()) t1End;
                decltype(t2.begin()) t2Begin;
                decltype(t2.end()) t2End;

                iterator(T1& a, T2& b) : t1Begin(a.begin()), t1End(a.end()), t2Begin(b.begin()), t2End(b.end()) { }

                iterator(T1& a, T2& b, bool isEnd) : t1Begin(a.end()), t1End(a.end()), t2Begin(b.end()), t2End(b.end()) { }

                auto operator*() {
                    if (t1Begin != t1End) { return *t1Begin; }
                    return *t2Begin;
                }

                iterator& operator++() {
                    if(t1Begin != t1End) { ++t1Begin; }
                    else { ++t2Begin; }
                    return *this;
                }

                bool operator!=(const iterator& it) {
                    if (t1Begin != it.t1Begin || t2Begin != it.t2Begin) { return true; }
                    return false;
                }
        };

        auto begin() { return iterator(t1, t2); }
        auto end() { return iterator(t1, t2, true); }
    };
}

