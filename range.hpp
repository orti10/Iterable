

#pragma once
#include <iostream>

namespace itertools{
    
    template<typename T>

    class range
    {
    private:
        T r_begin;
        T r_end;
    public:

        range(const T& begins,const T& ends){
            r_begin=begins;
            r_end=ends;
        }

        class const_iterator{
            private:
            T it;

            public:
            const_iterator(T iter = nullptr): it(iter) {}

            const T operator*()const{
                return  it;
            }
            //++i prefix
            const_iterator& operator++(){
                it++;
                return *this;
            }
            //i++ postfix
            const const_iterator operator ++(int){
                const_iterator temp =*this;
                it++;
                return temp;
            }
            bool operator==(const const_iterator& other) const {
                return it==other.it;
            }
            bool operator!=(const const_iterator& other) const {
                return it!=other.it; 
            }
        };//end of iterator class
       
        public:
        const_iterator begin() const{
         return const_iterator(r_begin);
        }
        const_iterator end() const{
            return const_iterator(r_end);
        }
    };
}

