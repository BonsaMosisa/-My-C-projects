/*
1. The system should allow users to create a new account by entering their personal information (first name, middle name, last name), unique username, PIN, and initial account balance.

2. The system should allow users to log in to their account by entering their username and PIN.

3. The system should allow users to view their account balance, withdraw money, and transfer money to another account.

4. The system should limit the number of incorrect login attempts to three before denying access to the account.

5. The system should prevent users from creating multiple accounts with the same username.

6. The system should update the account information (balance) after each transaction and store it in a file named after the user's username.

7. The system should be able to handle errors and invalid inputs gracefully and provide clear and helpful prompts to the user.
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstring>

using namespace std;

struct new_acc
{
  string F_name;
  string M_name;
  string L_name;
  string user_name;
  string pin;
  float amount;
};

// Function to login and check user's input
int login(string *user_name1, new_acc);

// Function to create a new account
new_acc create(new_acc acc_1);

// Function to display layout and options for the user
void layout_enter(string username, int *select1, new_acc acc_1);

// Function to display the selected option and perform the necessary action
void lay(string usernam, int select3, new_acc acc_3);

// Function to update the account information after a transaction
void update(string user_name, new_acc acc_1)
{
  ofstream NEWacc;
  // use array to store the name of the user
  string arr[3];
  arr[0] = acc_1.F_name;
  arr[1] = acc_1.M_name;
  arr[2] = acc_1.L_name;
  NEWacc.open(user_name + ".txt");
  for (int i = 0; i < 3; i++)
    NEWacc << arr[i] << endl;
  NEWacc << acc_1.user_name << endl;
  NEWacc << acc_1.pin << endl;
  NEWacc << acc_1.amount << endl;
  NEWacc.close();
}

int main()
{
  new_acc acc_2, acc_3;
  int x, y, select;
  string user_name;

  // Welcome message
  cout << "\t** WELCOME TO ATM MACHINE **\n";

  // Loop to display options to the user
again1:
log:
  cout << "\nplease select" << endl;
  cout << "1. Create an account\n2. Login\n3. Cancel";
  cout << endl;
  cin >> x;
  if (x == 1)
  {
    acc_3 = create(acc_2);
    cout << "successfully created\n\n";
    goto log;
  }
  else if (x == 2)
  {
    y = login(&user_name, acc_3);
    if (y == 0)
    {
      cout << "Too many attempts. Try another time.\n\n";
      goto again1;
      return 0;
    }
    else
    {
      layout_enter(user_name, &select, acc_3);
      cout << "Logged out\n";
      goto again1;
    }
  }
  else if (x == 3)
    cout << "HAVE A GOOD DAY\nCOME BACK LATER\n";
  else
    cout << "Wrong number";
  goto again1;
  return 0;
}

// Function to create a new account
new_acc create(new_acc acc_1)
{

  cout << "\nENTER YOUR FIRSTNAME: ";
  cin >> acc_1.F_name;
  cout << "ENTER YOUR MIDDLENAME: ";
  cin >> acc_1.M_name;
  cout << "ENTER YOUR LASTNAME: ";
  cin >> acc_1.L_name;

// Check if the entered username already exists
rewrite:
  cout << "ENTER YOUR USERNAME: ";
  cin >> acc_1.user_name;
  ifstream cheak;
  cheak.open(acc_1.user_name + ".txt");
  if (cheak.is_open())
  {
    cout << "Username already exists. Enter again\n";
    goto rewrite;
  }

  // Get user input for remaining account information
  cout << "ENTER PIN: ";
  cin >> acc_1.pin;
  cout << "ENTER AMOUNT: ";
  cin >> acc_1.amount;

  // Store account information in a file
  ofstream NEWacc;
  NEWacc.open(acc_1.user_name + ".txt", ios::out);
  NEWacc << acc_1.F_name << endl;
  NEWacc << acc_1.M_name << endl;
  NEWacc << acc_1.L_name << endl;
  NEWacc << acc_1.user_name << endl;
  NEWacc << acc_1.pin << endl;
  NEWacc << acc_1.amount << endl;
  NEWacc.close();

  // Read account information from the file
  ifstream acc_file(acc_1.user_name + ".txt");
  acc_file >> acc_1.F_name;
  acc_file >> acc_1.M_name;
  acc_file >> acc_1.L_name;
  acc_file >> acc_1.user_name;
  acc_file >> acc_1.pin;
  acc_file >> acc_1.amount;
  acc_file.close();

  return acc_1;
}

// Function to login and authenticate user
int login(string *user_name1, new_acc acc_1)
{
  string pin1;
  int attempt = 3;
lable1:
  string check;
  cout << "ENTER USERNAME: ";
  cin >> *user_name1;

lable2:
  cout << "ENTER PIN: ";
  cin >> pin1;
  ifstream file;
  file.open(*user_name1 + ".txt", ios::in);
  if (file.is_open())
  {
    ifstream acc_file(acc_1.user_name + ".txt");
    acc_file >> acc_1.F_name;
    acc_file >> acc_1.M_name;
    acc_file >> acc_1.L_name;
    acc_file >> acc_1.user_name;
    acc_file >> acc_1.pin;
    acc_file >> acc_1.amount;
    acc_file.close();

    // check user input
    if (acc_1.pin == pin1)
    {
      return 1;
    }

    // Handle incorrect pin attempts
    attempt--;
    if (attempt == 0)
    {
      return 0;
    }
    else if (attempt != 0)
      goto lable2;
  }
  else
  {
    cout << "Unknown username;" << endl;

    // Handle unknown username attempts
    attempt--;
    if (attempt == 0)
    {
      return 0;
    }
    goto lable1;
  }
  return 0;
}

// Function to display layout and options for the user
void layout_enter(string username, int *select1, new_acc acc_1)
{
  // Read account information from the file to update the account info
  ifstream acc_file(username + ".txt");
  acc_file >> acc_1.F_name;
  acc_file >> acc_1.M_name;
  acc_file >> acc_1.L_name;
  acc_file >> acc_1.user_name;
  acc_file >> acc_1.pin;
  acc_file >> acc_1.amount;
  acc_file.close();

  char r;
  cout << "\nHELLO, " << acc_1.F_name << endl;
re:
  // Display options to the user and get user input
  cout << "\nPlease enter what you want to do: \n1. View Balance \n2. Withdraw Money \n3. Send Money\n4. Exit" << endl;
  cin >> *select1;

  switch (*select1)
  {
  case 1:
    cout << "Your Balance is: " << acc_1.amount;

  // Asking user to continue or exit
  try_an:
    cout << "\tdo you want to continue y/n?";
    cin >> r;
    if (r == 'y')
      goto re;
    else if (r == 'n')
      break;
    else
    {
      cout << "wrong input\t";
      goto try_an;
    }
  case 2:
    float wAmount;
    cout << "Enter amount: ";
    cin >> wAmount;
    if (wAmount > acc_1.amount)
      cout << "Not suffcient! Try again ";
    else
    {
      acc_1.amount = acc_1.amount - wAmount;
      cout << "successfully withdrawed!";
      update(username, acc_1);
    }
  try_ang:
    cout << "\tdo you want to continue y/n?";
    cin >> r;
    if (r == 'y')
      goto re;
    else if (r == 'n')
      break;
    else
    {
      cout << "wrong input\t";
      goto try_ang;
    }
  case 4:
    break;
  default:
    cout << "wrong input\n";
    goto re;
    break;
  case 3:
    float amount;
    string Rname;
    int attempt = 3;
  again:
  {
    cout << "PLEASE ENTER RECEIVER USERNAME: ";
    cin >> Rname;
    cout << "PLEASE ENTER AMOUNT: ";
    cin >> amount;
    if (amount > acc_1.amount)
    {
      cout << "insufficient amount try again you have " << attempt - 1 << " attempt" << endl;
      attempt--;
      if (attempt == 0)
      {
        cout << "out if attempt\n";
        goto re;
      }
      goto again;
    }
    ifstream send;
    send.open(Rname + ".txt");
    new_acc acc_2;
    ifstream acc_file(Rname + ".txt");
    acc_file >> acc_2.F_name;
    acc_file >> acc_2.M_name;
    acc_file >> acc_2.L_name;
    acc_file >> acc_2.user_name;
    acc_file >> acc_2.pin;
    acc_file >> acc_2.amount;
    acc_file.close();
    if (!send.is_open())
    {
      cout << "invalid user name please try again you have " << attempt - 1 << " attempt" << endl;
      attempt--;
      if (attempt == 0)
      {
        cout << "out if attempt\n";
        goto re;
      }
      goto again;
    }
    else
    {
      acc_1.amount = acc_1.amount - amount;
      update(username, acc_1);
      acc_2.amount = acc_2.amount + amount;
      update(Rname, acc_2);
      send.close();
      cout << "successfully transferred\n";
    // prompt user to continue or exit
    try_anh:
      cout << "\tdo you want to continue y/n?";
      cin >> r;
      if (r == 'y')
        goto re;
      else if (r == 'n')
        break;
      else
      {
        cout << "wrong input\t";
        goto try_anh;
      }
    }
  }
  }
}
