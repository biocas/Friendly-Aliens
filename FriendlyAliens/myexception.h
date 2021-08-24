#include <exception>
using namespace std; 

//customised exception for invalid menu choice
class myexception: public exception {
  virtual const char* what() const throw() {
		return "Something went wrong";
	}
} myex;