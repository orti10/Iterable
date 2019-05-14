#pragma once
//#include "range.hpp"
// #include "zip.hpp"
// #include <iostream>

namespace itertools{
	template<typename T>
	class powerset{

	private:
		T pow_it;
		

	public:

		powerset(const T its):pow_it(its) {}

		class iterator {

			private:
				typename T::iterator _it;

			public:
				iterator(typename T::iterator it):_it(it){}
					

				auto operator*() {
					std::string str ="{}";
                    return str;
				}

				// ++i;
				iterator& operator++() {
                    _it++;
					return *this;
				}

				// i++;
				const iterator operator++(int) {
					iterator temp =*this;
                    ++*this;
                    return temp;
				}

				 bool operator==(const iterator& other)const{
                return (_it==other._it); 
            }
            	bool operator!=(const iterator& other)const{
                return (_it!=other._it);
                }   
        };

        typename powerset::iterator begin(){
            return powerset::iterator(pow_it.begin());
        }
        typename powerset::iterator end(){
            return powerset::iterator(pow_it.end());
         }

	}; 
}