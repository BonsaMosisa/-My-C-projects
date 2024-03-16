#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  char data[50];
  ifstream in;
  in.open("inventory.txt");
  in >> data;
  cout << data;

  in >> data;
  cout
      << data;

  in >> data;
  cout
      << data;

  in >> data;
  cout
      << data << endl;
  //===============================================
  in >> data;
  cout << data;

  in >> data;
  cout
      << data;

  in >> data;
  cout
      << data;

  in >> data;
  cout
      << data;
  in.close();
  return 0;
}