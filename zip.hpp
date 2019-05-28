#pragma once
#include <sstream>
#include "iostream"

namespace itertools{

    
    template<typename T1,typename T2>
    class zip{
        private:
        T1 z_begin;
        T2 z_end;
        
        public:
        zip(const T1& begins,const T2& ends):z_begin(begins),z_end(ends){}
       
        class const_iterator{
            private:
            typename T1::const_iterator it1_begin;
            typename T1::const_iterator it1_end;
            typename T2::const_iterator it2_begin;
            typename T2::const_iterator it2_end;

            public:
            const_iterator(const typename T1::const_iterator& it1begin, const typename T1::const_iterator& it1end,
            const typename T2::const_iterator&  it2begin, const typename T2::const_iterator& it2end):
            it1_begin(it1begin), it1_end(it1end), it2_begin(it2begin), it2_end(it2end) {}
            
            const_iterator operator++() {
               ++it1_begin;
               ++it2_begin;
               return *this;
            }


            auto operator*() const {
                return  std::pair(*it1_begin , *it2_begin);
            }
            bool operator!=(const_iterator other){
                return (it1_begin != other.it1_begin) && (it2_begin != other.it2_begin);
 
            }

            // bool operator==(iterator other){
            //     return **this==other;
 
            // }
            // bool operator!=(iterator other){
            //     return !(*this==other);
 
            // }
 template<typename T, typename S>
   friend ostream& operator<<(ostream& os, const pair<T, S> mp);
    
         
        }; // END OF CLASS ITERATOR
        const_iterator begin() const{return const_iterator(z_begin.begin(),z_begin.end(),z_end.begin(), z_end.end());}
        const_iterator end() const{return const_iterator(z_begin.end(),z_begin.end(),z_end.end(), z_end.end());
            
           } //return ite

    };

    template<typename T, typename S>
    ostream& operator<<(ostream& os, const pair<T, S> mp) {
        return os << mp.first << "," << mp.second;
    }
    
}