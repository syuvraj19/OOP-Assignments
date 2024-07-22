 
 /* Notes: 
    1. There is no header file (main_app.h) for main_app.cpp.
    2. Remove the directive: using namepace mars;
    3. Use the scope resolution operator ::
       a) std::
       b) mars::

    updated on 9/08/2020
  */
 
 #include <cstring>
 #include <iostream>
// using namespace std;
 
 #include "hello.h"
 
// using namespace mars;
 
 
    int main(void){
	
       char * data;
		
       data = new char[7];
       strcpy(data, "Apples");
		
       std::cout << mars::x << std::endl;   // std::cout
       std::cout << mars::foo(data) 
		 << std::endl;   
		
       return 0;
    }
 

