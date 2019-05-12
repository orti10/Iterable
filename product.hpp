#pragma once
#include "range.hpp"

namespace itertools{
    template<typename T1,typename T2>

    class product{

        public:
        T1 pro_begin;
        T2 pro_end;

        product<T1,T2>(T1 begins,T2 ends){}
        class iterator{
            public:
            T1 *it;

            iterator(T1 *iterator=nullptr){
                this->it=iterator;
            }

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
        };

        iterator begin(){
            return product<T1,T2>::iterator{&pro_begin};
            
        }
        iterator end(){
            return product<T1,T2>::iterator{&pro_end};
         }
    };
};