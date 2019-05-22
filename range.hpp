#pragma once
//#include <iostream>

namespace itertools{
    
    template<typename T>

    class range
    {
    private:
        T r_begin;
        T r_end;
    public:

        range(const T begins,const T ends){
            r_begin=begins;
            r_end=ends;
        }
        int length () const{
            return r_end.length()-r_begin.length();
        }
       // range<T>(const range& ran):r_begin(ran.r_begin),r_end(ran.r_end){}

        class iterator{
            private:
            T it;

            public:
            iterator(T iter = nullptr): it(iter) {}
            //iterator(const iterator &other):it(other.it){}

            T operator*()const{
                return  it;
            }
            //++i prefix
            iterator& operator++(){
                it++;
                return *this;
            }
            //i++ postfix
            const iterator operator ++(int){
                iterator temp =*this;
                it++;
                return temp;
            }
            bool operator==(const iterator& other){
                return it==other.it;
            }
            bool operator!=(const iterator& other){
                return it!=other.it; 
            }
            
            // T* operator-> ()const{
            //     return &(r_it);
            // }
         //   friend ostream& operator<<(ostream& os,const iterator& it);

        };//end of iterator class
       
        public:
        iterator begin()const{
         return iterator{r_begin};
        }
        iterator end()const{
            return iterator{r_end};
        }
    };   
        
}//;

