#ifndef HEADER_DELTA
#define HEADER_DELTA

#include <vector>

#include "../Store/Store.h"
#include "../Input/Input.h"
#include "../Output/Output.cpp"
#include "../Utils/Utils.h"

using namespace std;

class Delta
{
private:
  void checkChange(Store *state);
  void checkCoffees(Store *state, Input *input);
  void addCoins(Store *state, Input *input);

public:
  Delta();
  Store *stateChange(Store *state, Input *input);
};

#endif