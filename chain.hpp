#pragma once
#include <iterator>
#include<iostream>

namespace itertools{
    template<typename T1,typename T2>

    class chain{
        private:
        T1 c_begin;
        T2 c_end;
        
        public:
        chain(T1 begins,T2 ends):c_begin(begins),c_end(ends){}
        
        int length () const{
            return c_begin.length()+ c_end.length();
        }
        class iterator{
            
            public:
            typename T1::iterator it1_begin;
            typename T2::iterator it2_begin;
            bool flag=true;
            // bool checkIndicator(){
            //     if(it1_begin==it1_end) return true;
            //     return false;
            // }
            
            iterator(typename T1::iterator it1begin,typename T2::iterator it2begin)
            :it1_begin(it1begin),it2_begin(it2begin){}
            //iterator(const iterator &other):it1_begin(other.it1_begin),it1_end(other.it1_end),it2_begin(other.it2_begin){}
            
            auto operator*()const{
                
                if(flag==true){
                    return *(it1_begin);
                }
                else
                return *(it2_begin);
            }
            //++i
            iterator &operator++(){
                if(flag==true){
                    ++(it1_begin);
                }
                else
                    ++(it1_begin);
                return *this;
            }
            //i++
            const iterator &operator ++(int){
                iterator temp =*this;
                ++*this;
                return temp;
            }

            
            bool operator!=(const iterator& other){
                if(flag==true &&  !(it1_begin!=other.it1_begin)) flag=false;
                if(flag==true) return  it1_begin != other.it1_begin;
                else
                return  it2_begin != other. it2_begin;
            }
            
        };

        iterator begin() const{
            return iterator{c_begin,c_end};
            //return iterator<decltype(c_begin.begin()),decltype(c_end.begin())>(c_begin.begin(), c_end.begin()); 
        }
        iterator end() const{
            iterator it{c_begin,c_end};
            for (size_t i = 0; i < c_begin.length()+c_end.length(); i++)
            {
                ++it;
            }
            return it;
            //return iterator<decltype(c_begin.end()),decltype(c_end.end())>(c_begin.end(), c_end.end()); 
            
        } 
    };
};

