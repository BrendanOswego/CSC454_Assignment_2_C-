#include "./Delta.h"

Delta::Delta()
{
}

Store *Delta::stateChange(Store *state, Input *input)
{
  Store *temp = state;
  checkChange(temp);
  checkCoffees(temp, input);
  addCoins(temp, input);
  temp->setChangePressed(input->isChangePressed());
  return temp;
}

void Delta::checkChange(Store *state)
{
  if (state->isChangePressed())
  {
    vector<Output> output = Utils().instance().dispenseChange(state);
    for (int i = 0; i < output.size(); i++)
    {
      int machineAmount = state->getMachineAmount();
      switch (output.at(i))
      {
      case Output::QUARTER:
      {
        state->setQ(state->getQ() - 1);
        state->setMachineAmount(machineAmount - 25);
        break;
      }
      case Output::DIME:
      {
        state->setD(state->getD() - 1);
        state->setMachineAmount(machineAmount - 10);
        break;
      }
      case Output::NICKEL:
      {
        state->setN(state->getN() - 1);
        state->setMachineAmount(machineAmount - 5);
        break;
      }
      default:
      {
        break;
      }
      }
    }
  }
}

void Delta::checkCoffees(Store *state, Input *input)
{
  while ((state->getMachineAmount() / 100) > 0)
  {
    state->setMachineAmount(state->getMachineAmount() - 100);
  }
}

void Delta::addCoins(Store *state, Input *input)
{
  state->setQ(state->getQ() + input->getQ());
  state->setD(state->getD() + input->getD());
  state->setN(state->getN() + input->getN());
  int addedAmount = (input->getQ() * 25) + (input->getD() * 10) + (input->getN() * 5);
  state->setMachineAmount(state->getMachineAmount() + addedAmount);
}