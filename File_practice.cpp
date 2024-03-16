#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  ofstream outputfile("students.txt");
  /*optional openning of the file
      ofstream outputfile;
      outputfile.open("student.txt");
  */
  cout << "Writing data to the file" << endl;
  outputfile << "bonsa" << endl;
  outputfile << "Focus ";
  outputfile << "on Your Dream";
  cout << "done";
  outputfile.close();
  return 0;
}