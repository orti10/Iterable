
/**
 * A test program for itertools.
 * 
 * TEST BY ORTAL AND TOMER 
 * @since  2019-05
 */

#include <iostream>
using namespace std;

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

#define COMMA ,

using namespace itertools;
int main(){
    badkan::TestCase testcase;
    int grade=0;
    int signal =setjmp(badkan::longjmp_buffer);
    if(signal==0){
//------------------RANGE------------------------
        testcase.setname("range test");
        string str= "";
//-----------------------------------------------

        for(auto i:range(5,9)){
            str= str+to_string(i);
        }

        testcase.CHECK_OUTPUT(str,"5678");
        str="";
//-----------------------------------------------

        for(auto i:range(0,10)){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"0123456789");
        str="";
//-----------------------------------------------

        for(auto i:range(3,7)){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"3456");
        str="";
//-----------------------------------------------

        for(auto i:range(2.0,4.0)){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"2.0000003.000000");
        str="";
//-----------------------------------------------
        for(auto i:range('a','f')){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"abcde");
        str="";
//-----------------------------------------------
        for(auto i:range('g','x')){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"ghijklmnopqrstuvw");
        str="";
//-----------------------------------------------
        for(auto i:range('C','I')){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"CDEFGH");
        str="";
//-----------------------------------------------
        for(auto i:range('X','Y')){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"X");
        str="";   
//----------------CHAIN---------------------------
testcase.setname("chain test");
        for(auto i:chain(range(2,6),range(7,9))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"234578");
        str=""; 
//------------------------------------------------ 
        for(auto i:chain(range(0,2),range(3,7))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"013456");
        str=""; 
//------------------------------------------------ 
        for(auto i:chain(range(1.0,2.0),range(4.0,5.0))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"1.0000004.000000");
        str="";         
//------------------------------------------------ 
        for(auto i:chain(range('a','e'),range('A','E'))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"abcdABCD");
        str=""; 
//------------------------------------------------ 
        for(auto i:chain(string("tomer"),string("78"))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"tomer78");
        str=""; 
//------------------------------------------------ 
        for(auto i:chain(string("ort"),string("al"))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"ortal");
        str=""; 
//------------------------------------------------ 
        for(auto i:chain(range('t','z'),string("Shalom"))){
            str= str+to_string(i);
        }
        testcase.CHECK_OUTPUT(str,"tuvwxyShalom");
        str=""; 

//-------------------ZIP---------------------------
        testcase.setname("zip test");
        ostringstream s;
        for(auto pair:zip(range(2,6),range(7,9))){
            s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"234578");
        s.str("");
        s.clear();
        str="";
//------------------------------------------------ 
        for(auto pair:zip(range(0,2),range(3,7))){
            s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"013456");
        s.str("");
        s.clear();
        str="";
//------------------------------------------------ 
        for(auto pair:zip(range(1.0,2.0),range(4,9))){
           s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"1.00000045678");
        s.str("");
        s.clear();
        str="";         
//------------------------------------------------ 
        for(auto pair:zip(range('a','e'),range('A','E'))){
            s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"abcdABCD");
        s.str("");
        s.clear();
        str=""; 
//------------------------------------------------ 
        for(auto pair:zip(string("tomer"),range(7,9))){
           s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"tomer78");
        s.str("");
        s.clear();
        str=""; 
//------------------------------------------------ 
        for(auto pair:zip(string("ort"),string("al"))){
            s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"ortal");
        s.str("");
        s.clear();
        str=""; 
//------------------------------------------------ 
        for(auto pair:zip(range('t','z'),string("Shalom"))){
           s<<pair;
        }
        str=s.str();
        testcase.CHECK_OUTPUT(str,"tuvwxyShalom");
        s.str("");
        s.clear();
        str=""; 
//------------------------PRODUCT------------------
        testcase.setname("product test");

//--------------------------------------------------
        for (auto pair: product(range(1,4), string("helo"))){
          s << pair;
        }
		
        str = s.str();
        testcase.CHECK_OUTPUT(str, "1h,1e,1l,1o,2h,2e,2l,2o,3h,3e,3l,3o");
		s.str("");
        s.clear();
        str = "";
//--------------------------------------------------
        for (auto pair: product(range(5,7), string("MAN"))){
          s << pair;
        }
		
        str = s.str();
        testcase.CHECK_OUTPUT(str, "5M,5A,5N,6M,6A,6N");
		s.str("");
        s.clear();
        str = "";
//--------------------------------------------------
        for (auto pair: product(range(2,5), string("bye"))){
          s << pair;
        }
		
        str = s.str();
        testcase.CHECK_OUTPUT(str, "2b,2y,2e,3b,3y,3e,4b,4y,4e");
		s.str("");
        s.clear();
        str = "";
//-----------------POWERSET--------------------------
    testcase.setname("powerset test");
for (auto i: powerset(range(1,3))){
           s << i; 
        }
		
        str = s.str();
        testcase.CHECK_OUTPUT(str, "{},{1},{2},{1,2}");
		s.str("");
        s.clear();
        str = "";
//------------------------------------------------------

for (auto i: powerset(string("abc"))){
           s << i; 
        }
		
        str = s.str();
        testcase.CHECK_OUTPUT(str, "{},{a},{b},{a,b},{a,c},{b,c},{a,b,c}");
		s.str("");
        s.clear();
        str = "";

    grade=testcase.grade();
    } else{
        testcase.print_signal(signal);
        grade=0;
    }
    cout<<"your grade is: "<<grade<<endl;
  return 0;
    
}
