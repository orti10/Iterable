#pragma once
#include <iostream>
namespace itertools{

    
    template<typename T1,typename T2>
    class zip{
        private:
        T1 z_begin;
        T2 z_end;
        public:
        

         zip(const T1 begins,const T2 ends):z_begin(begins),z_end(ends){}

        class iterator{
            private:
            typename T1::iterator it1_begin;
            typename T1::iterator it1_end;
            typename T2::iterator it2_begin;


            public:

            iterator(typename T1::iterator it1begin,typename T1::iterator it1end,typename T2::iterator it2begin):
            it1_begin(it1begin),it1_end(it1end),it2_begin(it2begin){}

            auto operator*(){
                return pair(*(it1_begin),*(it2_begin));
            }
            auto operator-> ()const{
                return pair(&(it1_begin),&(it2_begin));
            }
            //++i
            iterator &operator++(){
                it1_begin++;
                it2_begin++;
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

        typename zip::iterator begin(){
            return zip::iterator{z_begin.begin(),z_begin.end(),z_end.begin()};
        }
        typename zip::iterator end(){
            return zip::iterator{z_begin.end(),z_begin.end(),z_end.end()};
         }
    };
// template<typename T1,typename T2>

//     class pair {
//        private:
//         T1 t1;
//         T2 t2;
//         public:
//         pair(T1 _t1,T2 _t2):t1(_t1),t2(_t2){}

//         template<typename C1,typename C2>
//         friend std::ostream& operator <<(std::ostream& os,const pair<C1,C2> mypair);

//     };

}

template<typename C1,typename C2>
ostream& operator<< (ostream& os,const pair<C1,C2>& mypair){
    os << mypair.first << "," << mypair.second;
    return os;
}
