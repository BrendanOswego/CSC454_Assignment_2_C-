#ifndef HEADER_LAMBDA
#define HEADER_LAMBDA

#include <vector>

#include "../Output/Output.cpp"
#include "../Store/Store.h"
#include "../Utils/Utils.h"

using namespace std;

class Lambda {
private:
  vector<Output> dispenseCoffee(Store *state);
public:
  Lambda();
  vector<Output> output(Store *state);
};

#endif