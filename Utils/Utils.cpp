#include "./Utils.h"

Utils &Utils::instance()
{
  static Utils singleton;
  return singleton;
}

vector<Output> Utils::dispenseChange(Store *state)
{
  vector<Output> output;
  int tempAmount = state->getMachineAmount();
  int totalQ = state->getQ();
  int totalD = state->getD();
  int totalN = state->getN();
  int qDispensed = 0, dDispensed = 0, nDispensed = 0;
  while (((tempAmount / 25) > 0) && (totalQ > qDispensed))
  {
    qDispensed++;
    tempAmount -= 25;
  }
  while (((tempAmount / 10) > 0) && (totalD > dDispensed))
  {
    dDispensed++;
    tempAmount -= 10;
  }
  while (((tempAmount / 5) > 0) && (totalN > nDispensed))
  {
    nDispensed++;
    tempAmount -= 5;
  }
  if (tempAmount > 0) {
    throw ChangeException();
  }
  int i;
  for (i = 0; i < qDispensed; i++)
    output.push_back(Output::QUARTER);
  for (i = 0; i < dDispensed; i++)
    output.push_back(Output::DIME);
  for (i = 0; i < nDispensed; i++)
    output.push_back(Output::NICKEL);
  return output;
}