#include "./Store.h"

Store::Store(){}

Store::Store(int quarters, int dimes, int nickels)
{
  this->quarters = quarters;
  this->dimes = dimes;
  this->nickels = nickels;
  this->machineAmount = 0;
  this->changePressed = false;
}