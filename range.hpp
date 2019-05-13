#pragma once


namespace itertools{
using namespace std;

    template<typename T>

    class range
    {
    private:
        T r_begin,r_end;
    public:

        range(const T begins,const T ends):r_begin(begins),r_end(ends){}
       // range<T>(const range& ran):r_begin(ran.r_begin),r_end(ran.r_end){}

        class iterator{
            private:
            T r_it;

            public:

            iterator(T iterator):r_it(iterator){}
            //iterator(const iterator &other):it(other.it){}

            T& operator*()const{
                return r_it;
            }
            //++i prefix
            iterator &operator++(){
                r_it=r_it+1;
                return *this;
            }
            //i++ postfix
            const iterator operator ++(int){
                 iterator temp =*this;
                ++*this;
                return temp;
            }
            bool operator==(const iterator& other)const{
                return r_it==other.r_it; 
            }
            bool operator!=(const iterator& other)const{
                return r_it!=other.r_it; 
            }
            T* operator-> ()const{
                return &(r_it);
            }
         //   friend ostream& operator<<(ostream& os,const iterator& it);

        };

        iterator begin(){
         return iterator(r_begin);
        }
        iterator end(){
            return iterator(r_end);
        }
    };   
    
     
}