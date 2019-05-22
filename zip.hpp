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
        zip(T1 begins,T2 ends):z_begin(begins),z_end(ends){}
        
        int length () const{
            return z_begin.length();
        }
       
        class iterator{
            private:
            typename T1::iterator it1_begin;
            typename T2::iterator it2_begin;

            public:
            iterator( typename T1::iterator it1begin, typename T2::iterator  it2begin):
            it1_begin(it1begin),it2_begin(it2begin){}

            string operator*(){
                stringstream str;
                string s="";
                str<<*it1_begin;
                str<<",";
                str<<*it2_begin;
                str<<s;
                return s;
            }
            
            iterator operator++() {
               ++it1_begin;
               ++it2_begin;
               return *this;
 
            }


            std::pair<decltype(*it1_begin),decltype(*it2_begin)> operator*() const {

             return  std::pair<decltype(*it1_begin),decltype(*it2_begin)> (*it1_begin , *it2_begin);
            }
            bool operator!=(iterator other){
                return (it1_begin != other.it1_begin) && (it2_begin != other.it2_begin);
 
            }
            // bool operator==(iterator other){
            //     return **this==other;
 
            // }
            // bool operator!=(iterator other){
            //     return !(*this==other);
 
            // }

         
        }; // END OF CLASS ITERATOR
        auto begin() const{return iterator{z_begin,z_end};}
        auto end() const{
            iterator it{z_begin,z_end};
            for (size_t i = 0; i < z_begin.length(); i++)
            {
                ++it;
            }
            return it;
            
           } //return ite

    };
    
};
    //         auto operator*(){
    //             return pair(*(it1_begin),*(it2_begin));
    //         }
    //         auto operator-> ()const{
    //             return pair(&(it1_begin),&(it2_begin));
    //         }
    //         //++i
    //         iterator &operator++(){
    //             it1_begin++;
    //             it2_begin++;
    //             return *this;
    //         }
    //         //i++
    //         const iterator &operator ++(int){
    //            iterator temp =*this;
    //            ++*this;
    //             return temp;
    //         }
    //          bool operator==(const iterator& other)const{
    //             return (it1_begin==other.it1_begin)&&(it2_begin==other.it2_begin); 
    //         }
    //         bool operator!=(const iterator& other)const{
    //             return (it1_begin!=other.it1_begin)&&(it2_begin!=other.it2_begin);
    //         }
            
            
    //     };

    //     typename zip::iterator begin(){
    //         return zip::iterator{z_begin.begin(),z_begin.end(),z_end.begin()};
    //     }
    //     typename zip::iterator end(){
    //         return zip::iterator{z_begin.end(),z_begin.end(),z_end.end()};
    //      }
    // };
