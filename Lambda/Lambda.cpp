#include "./Lambda.h"

Lambda::Lambda()
{
}

vector<Output> Lambda::output(Store *state)
{
  if (state->isChangePressed())
  {
    return Utils().instance().dispenseChange(state);
  }
  if (state->getMachineAmount() >= 100)
  {
    return dispenseCoffee(state);
  }
  vector<Output> output;
  output.push_back(Output::NOTHING);
  return output;
}

vector<Output> Lambda::dispenseCoffee(Store *state)
{
  int coffees = state->getMachineAmount() / 100;
  vector<Output> output;
  for (int i = 0; i < coffees; i++)
  {
    output.push_back(Output::COFFEE);
  }
  return output;
}