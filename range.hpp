// // #pragma once
// // //#include <iostream>

// // namespace itertools{
    
// //     template<typename T>

// //     class range
// //     {
// //     private:
// //         T r_begin;
// //         T r_end;
// //     public:

// //         range(const T begins,const T ends){
// //             r_begin=begins;
// //             r_end=ends;
// //         }
// //         int length () const{
// //             return r_end.length()-r_begin.length();
// //         }
// //        // range<T>(const range& ran):r_begin(ran.r_begin),r_end(ran.r_end){}

// //         class iterator{
// //             private:
// //             T it;

// //             public:
// //             iterator(T iter = nullptr): it(iter) {}
// //             //iterator(const iterator &other):it(other.it){}

// //             T operator*()const{
// //                 return  it;
// //             }
// //             //++i prefix
// //             iterator& operator++(){
// //                 it++;
// //                 return *this;
// //             }
// //             //i++ postfix
// //             const iterator operator ++(int){
// //                 iterator temp =*this;
// //                 it++;
// //                 return temp;
// //             }
// //             bool operator==(const iterator& other){
// //                 return it==other.it;
// //             }
// //             bool operator!=(const iterator& other){
// //                 return it!=other.it; 
// //             }
            
// //             // T* operator-> ()const{
// //             //     return &(r_it);
// //             // }
// //          //   friend ostream& operator<<(ostream& os,const iterator& it);

// //         };//end of iterator class
       
// //         public:
// //         iterator begin()const{
// //          return iterator{r_begin};
// //         }
// //         iterator end()const{
// //             return iterator{r_end};
// //         }
// //     };   
        
// // }//;

// #pragma once
// #include <iostream>

// namespace itertools{
    
//     template<typename T>

//     class range
//     {
//     private:
//         T r_begin;
//         T r_end;
//     public:

//         range(const T& begins,const T& ends){
//             r_begin=begins;
//             r_end=ends;
//         }
//         // int length () const{
//         //     return r_end.length()-r_begin.length();
//         // }
//        // range<T>(const range& ran):r_begin(ran.r_begin),r_end(ran.r_end){}

//         class iterator{
//             private:
//             T it;

//             public:
//             iterator(T iter = nullptr): it(iter) {}
//             //iterator(const iterator &other):it(other.it){}

//             const T operator*()const{
//                 return  it;
//             }
//             //++i prefix
//             iterator& operator++(){
//                 it++;
//                 return *this;
//             }
//             //i++ postfix
//             const iterator operator ++(int){
//                 iterator temp =*this;
//                 it++;
//                 return temp;
//             }
//             bool operator==(const iterator& other) const {
//                 return it==other.it;
//             }
//             bool operator!=(const iterator& other) const {
//                 return it!=other.it; 
//             }
//         };//end of iterator class
       
//         public:
//         iterator begin() const{
//          return iterator(r_begin);
//         }
//         iterator end() const{
//             return iterator(r_end);
//         }
//     };
// }

// #pragma once
// //#include <iostream>

// namespace itertools{
    
//     template<typename T>

//     class range
//     {
//     private:
//         T r_begin;
//         T r_end;
//     public:

//         range(const T begins,const T ends){
//             r_begin=begins;
//             r_end=ends;
//         }
//         int length () const{
//             return r_end.length()-r_begin.length();
//         }
//        // range<T>(const range& ran):r_begin(ran.r_begin),r_end(ran.r_end){}

//         class iterator{
//             private:
//             T it;

//             public:
//             iterator(T iter = nullptr): it(iter) {}
//             //iterator(const iterator &other):it(other.it){}

//             T operator*()const{
//                 return  it;
//             }
//             //++i prefix
//             iterator& operator++(){
//                 it++;
//                 return *this;
//             }
//             //i++ postfix
//             const iterator operator ++(int){
//                 iterator temp =*this;
//                 it++;
//                 return temp;
//             }
//             bool operator==(const iterator& other){
//                 return it==other.it;
//             }
//             bool operator!=(const iterator& other){
//                 return it!=other.it; 
//             }
            
//             // T* operator-> ()const{
//             //     return &(r_it);
//             // }
//          //   friend ostream& operator<<(ostream& os,const iterator& it);

//         };//end of iterator class
       
//         public:
//         iterator begin()const{
//          return iterator{r_begin};
//         }
//         iterator end()const{
//             return iterator{r_end};
//         }
//     };   
        
// }//;

#pragma once
#include <iostream>

namespace itertools{
    
    template<typename T>

    class range
    {
    private:
        T r_begin;
        T r_end;
    public:

        range(const T& begins,const T& ends){
            r_begin=begins;
            r_end=ends;
        }

        class const_iterator{
            private:
            T it;

            public:
            const_iterator(T iter = nullptr): it(iter) {}

            const T operator*()const{
                return  it;
            }
            //++i prefix
            const_iterator& operator++(){
                it++;
                return *this;
            }
            //i++ postfix
            const const_iterator operator ++(int){
                const_iterator temp =*this;
                it++;
                return temp;
            }
            bool operator==(const const_iterator& other) const {
                return it==other.it;
            }
            bool operator!=(const const_iterator& other) const {
                return it!=other.it; 
            }
        };//end of iterator class
       
        public:
        const_iterator begin() const{
         return const_iterator(r_begin);
        }
        const_iterator end() const{
            return const_iterator(r_end);
        }
    };
}

