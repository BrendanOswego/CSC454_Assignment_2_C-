#ifndef HEADER_STORE
#define HEADER_STORE

class Store
{
private:
  int quarters;
  int dimes;
  int nickels;
  int machineAmount;
  bool changePressed;
  int coffees;

public:
  Store();
  Store(int quarters, int dimes, int nickels);
  int getQ() { return quarters; }
  int getD() { return dimes; }
  int getN() { return nickels; }
  int getMachineAmount() { return machineAmount; }
  bool isChangePressed() { return changePressed; }
  void setQ(int q) { this->quarters = q; }
  void setD(int d) { this->dimes = d; }
  void setN(int n) { this->nickels = n; }
  void setChangePressed(bool c) { this->changePressed = c; }
  void setMachineAmount(int m) { this->machineAmount = m; }

};

#endif