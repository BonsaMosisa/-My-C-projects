#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ofstream out("inventory.txt");
  out << "Banana unit price: " << 39.95 << endl;
  out << "Mango Unit Price: " << 19.95 << endl;
  out.close();
  return 0;
}
