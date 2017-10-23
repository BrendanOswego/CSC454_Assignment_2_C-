#include "./Input.h"

Input::Input()
{
  this->quarters = 0;
  this->dimes = 0;
  this->nickels = 0;
  this->changePressed = false;
}

void Input::parseInput(string line)
{
  this->quarters = 0;
  this->dimes = 0;
  this->nickels = 0;
  this->changePressed = false;
  int i;
  for (i = 0; i < line.size(); i++)
  {
    switch (line.at(i))
    {
    case 'q':
    {
      ++quarters;
      break;
    }
    case 'd':
    {
      ++dimes;
      break;
    }
    case 'n':
    {
      ++nickels;
      break;
    }
    case 'c':
    {
      changePressed = true;
      break;
    }
    default:
    {
      break;
    }
    }
  }
}