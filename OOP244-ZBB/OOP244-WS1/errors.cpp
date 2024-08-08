 /* Notes: 
    1. There is no header file (main_app.h) for main_app.cpp.
    2. Use the directive: using namespace mars;
    3. g++ main_app.cpp hello.cpp
 */
 
 #include <cstring>
 #include <iostream>
// using namespace std;   // using a namespace
 
// #include "hello.h"
// using namespace mars;  // using a namespace
 
 // the main module: main_app.cpp
 int main(){

     char * data;             // 1. declare a pointer
		
     data = new char[7];      // 2. allocate memory storage, referenced by
			      //    the pointer
     strcpy(data, "Apples");
		
     cout << x << endl;          // std::cout, mars:x, std::endl
    
     cout << foo(data) << endl;  // mars:foo()
					
     delete [] data;          // 3. deallocate the memory storage
     
     return 0;

}// end main
 

