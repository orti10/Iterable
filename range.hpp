#pragma once

#include <iostream>


namespace itertools{

    template<typename T>

    class range
    {
    private:
        /* data */
    public:
        T r_begin,r_end;

        range<T>(T begins,T ends):r_begin(begins),r_end(ends){}

        class iterator{

            public:
            T it;

            iterator(T *iterator):it(iterator){}
                

            T &operator*()const{
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
            return range<T>::iterator{&r_begin};
        }
        iterator end(){
            return range<T>::iterator{&r_end};
        }
    };    
};