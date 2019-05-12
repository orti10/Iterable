#pragma once
#include "range.hpp"

namespace itertools{
    template<typename T1,typename T2>

    class chain{

        public:
        T1 c_begin;
        T2 c_end;

        chain<T1,T2>(T1 begins, T2 ends):c_begin(begins),c_end(ends){}

        class iterator{
            public:
            
            T1 it1;
            T2 it2;
            iterator(T1 *iterator1,T2 *iterator2):it1(iterator1),it2(iterator2){}

            T1 &operator*()const{
                return *it;
            }
            iterator &operator++()const{
                (*it)++;
                return *this;
            }
            const iterator &operator ++(int){
                iterator temp =*this;
                ++*(this);
                return temp;
            }
            bool operator==(iterator other)const{
                return *it==*other.it; 
            }
            bool operator!=(iterator other)const{
                return *it!=*other.it; 
            }
            auto operator->()const{
                return &(it);
            }
        };

        iterator begin(){
            return chain<T1,T2>::iterator{&c_begin};
        }
        iterator end(){
            return chain<T1,T2>::iterator{&c_end};
         }
    };
};
