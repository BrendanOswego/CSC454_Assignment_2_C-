#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "./Store/Store.h"
#include "./Lambda/Lambda.h"
#include "./Delta/Delta.h"
#include "./ChangeException/ChangeException.h"
#include "./Output/Output.cpp"

using namespace std;

void printOutput(vector<Output> output)
{
  cout << "[";
  for (int i = 0; i < output.size(); i++)
  {
    switch (output.at(i))
    {
    case Output::NOTHING:
    {
      cout << "NOTHING";
      break;
    }
    case Output::COFFEE:
    {
      cout << "COFFEE";
      break;
    }
    case Output::QUARTER:
    {
      cout << "QUARTER";
      break;
    }
    case Output::DIME:
    {
      cout << "DIME";
      break;
    }
    case Output::NICKEL:
    {
      cout << "NICKEL";
      break;
    }
    }
    if (i < (output.size() - 1))
    {
      cout << " ";
    }
  }
  cout << "]" << endl;
}

int main(int argc, char **argv)
{
  string userInput;
  Lambda *lambda = new Lambda();
  Delta *delta = new Delta();
  Store *initState = new Store(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  Store *temp = nullptr;
  Input *input = new Input();
  while (getline(cin, userInput))
  {
    try
    {
      if (userInput == "quit")
        break;
      temp = initState;
      input->parseInput(userInput);
      vector<Output> output = lambda->output(temp);
      printOutput(output);
      initState = delta->stateChange(temp, input);
    }
    catch (exception &e)
    {
      cout << e.what() << endl;
      break;
    }
  }
  delete initState;
  delete lambda;
  delete delta;
  delete input;
  return 0;
}