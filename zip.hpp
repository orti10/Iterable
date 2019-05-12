#pragma once
#include "range.hpp"

namespace itertools{
    template<typename T1,typename T2>

    class zip{

        public:
        T1 z_begin;
        T2 z_end;

         zip<T1,T2>(T1 begins, T2 ends){
        }

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
            return zip<T1,T2>::iterator{&z_begin};
        }
        iterator end(){
            return zip<T1,T2>::iterator{&z_end};
         }
    };
};