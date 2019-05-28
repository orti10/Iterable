#include "iostream"
#include <set> // for set operations
#include <cmath>
#include <iostream>
#include <iterator>

using namespace std;

namespace itertools {
        
    template <class T> 
    class powerset {
    
    private: 
        T iterable; // start point
        uint sizeOfSet;

    public:
    powerset(T start) : iterable(start) {
        sizeOfSet = 0;
        for(auto i : start) {
            ++sizeOfSet;
        }
    } 
        class const_iterator {

        private:
        const T& fullSet;
        uint size;


        public:
            const_iterator(const T& a, uint ind): 
            fullSet(a) , size(ind) {}

            auto operator*() const {
                std::set<typename std::remove_reference<typename std::remove_const<decltype(*(iterable.begin()))>::type>::type> ms = {};
                int i = 1;
                for (auto element : fullSet) {
                    if (i & size) {
                        cout<<"ASDASDA: "<<element<< "      ";
                        ms.insert(element);
                        i = i << 1;
                    }
                }
                return ms;
            }

            const_iterator& operator++() {
                ++size;
                return *this;
            }

            const const_iterator& operator++(int) {
                const_iterator temp = *this;
                ++size;
                return temp;
            }

            bool operator!=(const const_iterator& other) {
                return !(size == other.size);
            }

        }; // END OF CLASS ITERATOR

        auto begin() const{
            return const_iterator(iterable, 0);
        }
        auto end() const{
            return const_iterator(iterable, sizeOfSet);
            } //return it
    };
    
template <typename D>
std::ostream &operator<<(std::ostream &os, const std::set<D> &S)
{

    os << "{";

    auto it = S.begin();
    if(it != S.end())
    { // first element is without comma seperator.
        os << *it; 
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}
}