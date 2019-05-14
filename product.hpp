#pragma once
#include "zip.hpp"
#include <iostream>

namespace itertools{
	template<typename T1, typename T2>
	class product{

	private:
		T1 pro_begin;
		T2 pro_end;

	public:

		product(const T1 begins, const T2 ends)
			: pro_begin(begins),pro_end(ends) {}

		class iterator {

			private:
				typename T1::iterator it1_begin;
				typename T1::iterator it1_end;
				typename T2::iterator it2_begin;
				typename T2::iterator it2_end;
				
				bool check() const {
					return (it1_begin != it1_end && it2_begin != it2_end);
				}

			public:
				iterator(typename T1::iterator it1_begin, typename T1::iterator it1_end, typename T2::iterator it2_begin, typename T2::iterator it2_end):
					it1_begin(it1_begin), it1_end(it1_end),it2_begin(it2_begin), it2_end(it2_end){}

				auto operator*() {
					return std::pair(*(it1_begin), *(it2_begin));
				}
                auto operator-> ()const{
                return std::pair(&(it1_begin),&(it2_begin));
                }

				// ++i;
				iterator& operator++() {
                    if(check()){
                        it1_begin++;
                        it2_begin++;
                    }
					return *this;
				}

				// i++;
				const iterator operator++(int) {
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

        typename product::iterator begin(){
            return product::iterator{pro_begin.begin(),pro_begin.end(),pro_end.begin(),pro_end.end()};
        }
        typename product::iterator end(){
            return product::iterator{pro_begin.end(),pro_begin.end(),pro_end.end(),pro_end.end()};
         }

	}; 
}