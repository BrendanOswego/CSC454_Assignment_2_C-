#ifndef EXCEPTION_CHANGE
#define EXCEPTION_CHANGE

#include <exception>

using namespace std;

class ChangeException : public exception
{
  virtual const char *what() const throw()
  {
    return "Cannot produce correct change";
  }
};

#endif