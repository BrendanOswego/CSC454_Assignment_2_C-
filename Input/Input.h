#ifndef HEADER_INPUT
#define HEADER_INPUT

#include <string>

using namespace std;

class Input
{
private:
  int quarters;
  int dimes;
  int nickels;
  bool changePressed;

public:
  Input();
  Input(string line);
  int getQ() { return quarters; }
  int getD() { return dimes; }
  int getN() { return nickels; }
  int isChangePressed() { return changePressed; }
  void parseInput(string line);
};

#endif