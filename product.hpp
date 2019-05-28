#pragma once
#include "iostream"

namespace itertools{
	template<typename T1, typename T2>
	class product{

	private:
		T1 pro_begin;
		T2 pro_end;

	public:

		product(T1 begins, T2 ends)
			: pro_begin(begins),pro_end(ends) {}
		
		
		class const_iterator {

			private:
            typename T1::const_iterator it1_begin;
            typename T1::const_iterator it1_end;
            typename T2::const_iterator it2_begin;
            typename T2::const_iterator it2_end;

			typename T2::const_iterator it2_start;

			public:
				const_iterator(const typename T1::const_iterator& it1begin, const typename T1::const_iterator& it1end,
            const typename T2::const_iterator&  it2begin, const typename T2::const_iterator& it2end):
            it1_begin(it1begin), it1_end(it1end),it2_start(it2begin), it2_begin(it2begin), it2_end(it2end) {}
            
			const_iterator& operator++() {
                ++it2_begin;
                if(it2_begin == it2_end){
                    ++it1_begin;
                    if(it1_begin != it1_end){
                        it2_begin = it2_start;
                    }
                }
               return *this;
 
            }

            auto operator*() const {
                return  std::pair(*it1_begin , *it2_begin);
            }

            bool operator==(const_iterator other){
                // if((it1_begin == it1_end || it2_start == it2_end) && (other.it1_begin == other.it1_end || other.it2_start == other.it2_end)) {
                //     return true;
                // }

                return !(*this != other);
 
            }

            bool operator!=(const_iterator other) {
               return (it1_begin != other.it1_begin) && (it2_begin != other.it2_begin);
 
            }

        }; // END OF CLASS ITERATOR
 		auto begin() const{
            return const_iterator(pro_begin.begin(), pro_begin.end() ,pro_end.begin(), pro_end.end());
        }
        auto end() const{
            return const_iterator(pro_begin.end(), pro_begin.end() ,pro_end.end(), pro_end.end());
            
           } //return it
    

    };
}

