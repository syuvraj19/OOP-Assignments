
// Source: //http://www.cplusplus.com/doc/oldtutorial/namespaces/

// namespaces
#include <iostream>
using namespace std;

namespace first
{
  int var = 5;
}

namespace second
{
  double var = 3.1416;
}

int main (void) {

  // avoid naming conflicts

  cout << first::var << endl;
  cout << second::var << endl;
  return 0;
}
