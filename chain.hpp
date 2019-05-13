#pragma once
//#include "range.hpp"

namespace itertools{
    template<typename T1,typename T2>

    class chain{
        private:
        T1 c_begin;
        T2 c_end;
        public:
        

        chain(const T1 begins,const T2 ends):c_begin(begins),c_end(ends){}

        class iterator{
            
            private:
            typename T1::iterator it1_begin;
            typename T1::iterator it1_end;
            typename T2::iterator it2_begin;
            bool checkIndicator()const{
                if(it1_begin!=it1_end) return *(it1_begin);
                return *(it2_begin);
            }
            public:
            
            iterator(typename T1::iterator it1begin,typename T1::iterator it1end,typename T2::iterator it2begin)
            :it1_begin(it1begin),it1_end(it1end),it2_begin(it2begin){}
            //iterator(const iterator &other):it1_begin(other.it1_begin),it1_end(other.it1_end),it2_begin(other.it2_begin){}

            auto operator*(){
                
                if(checkIndicator()){
                    return &(it1_begin);
                }
                return &(it2_begin);
            }
            //++i
            iterator &operator++(){
                if(checkIndicator()){
                    (it1_begin)++;
                    return *this;
                }
                
                    (it2_begin)++;
                    return *this;
            }
            //i++
            const iterator &operator ++(int){
                iterator temp =*this;
                ++*this;
                return temp;
            }
            bool operator==(const iterator& other)const{
                return (it1_begin==other.it1_begin)&&(it2_begin==other.it2_begin); 
            }
            bool operator!=(const iterator& other)const{
                return (it1_begin!=other.it1_begin)&&(it2_begin!=other.it2_begin);
            }
            
        };

        typename chain::iterator begin(){
            return chain::iterator(c_begin.begin(),c_begin.end(),c_end.begin());
        }
        typename chain::iterator end(){
            return chain::iterator(c_begin.end(),c_begin.end(),c_end.end());
         }
    };
}
