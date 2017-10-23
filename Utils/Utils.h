#ifndef HEADER_UTILS
#define HEADER_UTILS

#include <vector>

#include "../Output/Output.cpp"
#include "../Store/Store.h"
#include "../ChangeException/ChangeException.h"

using namespace std;

class Utils {

public:
  static Utils& instance();
  static vector<Output> dispenseChange(Store *state);
};

#endif
