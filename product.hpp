#pragma once
#include "iostream"

namespace itertools{
	template<typename T1, typename T2>
	class product{

	private:
		T1 pro_begin;
		T2 pro_end;

	public:

		product(const T1 begins, const T2 ends)
			: pro_begin(begins),pro_end(ends) {}
		
		int length () const{
            return pro_begin.length()* pro_end.length();
        }
		class iterator {

			private:
			typename T1::iterator it1_begin;
            typename T2::iterator it2_begin;
			typename T2::iterator FLAG;

			public:
				iterator(typename T1::iterator it1begin,typename T2::iterator it2begin):
					it1_begin(it1begin),it2_begin(it2begin),FLAG(it2_begin){}

			iterator operator++() {
               ++it1_begin;
               ++it2_begin;
               return *this;
 
            }

            std::pair<decltype(*it1_begin),decltype(*it2_begin)> operator*() const {

             return  std::pair<decltype(*it1_begin),decltype(*it2_begin)> (*it1_begin , *it2_begin);
            }

            bool operator!=(iterator other){
                if((it1_begin != other.it1_begin) && (it2_begin != other.it2_begin)){
                    it2_begin = FLAG;
                    ++it1_begin;
                }
                return (it1_begin != other.it1_begin);
 
            }
		//  bool operator==(iterator other){
        //         return **this==other;
 
        //     }
        //     bool operator!=(iterator other){
        //         return !(*this==other);
 
        //     }

         
        }; // END OF CLASS ITERATOR
 		iterator begin() const{
            return iterator{pro_begin,pro_end};
        }
        iterator end() const{
            iterator it{pro_begin,pro_end};
            for (size_t i = 0; i < pro_begin.length()+pro_end.length(); i++)
            {
                ++it;
            }
            return it;
            
           } //return it


    };
};

// 				auto operator*() {
// 					return std::pair(*(it1_begin), *(it2_begin));
// 				}
//                 auto operator-> ()const{
//                 return std::pair(&(it1_begin),&(it2_begin));
//                 }

