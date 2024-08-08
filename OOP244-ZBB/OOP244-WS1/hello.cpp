#include <cstring>
#include <iostream>
using namespace std;

#include "hello.h"

namespace mars{
  
   int foo(const char* s){
   
       cout << "hello: " << s << endl;
       return strlen(s);
	   
   }
   
} // end namespace
