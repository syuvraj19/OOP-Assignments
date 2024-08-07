 
 /* Notes: 
    1. There is no header file (main_app.h) for main_app.cpp.
    2. Remove the directive: using namepace mars;
    3. LOTS OF ERROR MESSAGES FROM THE COMPILER!
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
		
		cout << x << endl;
		cout  << foo(data) << endl;  // std::cout
					     // std::endl
					     // mars::x
					     // mars::foo(data)
		
		return 0;
	}
 

