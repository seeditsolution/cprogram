#include <iostream>
using namespace std;

int main()
{

  int factorial=0,result=1;

  cout << "Enter Number: ";
  cin >> factorial;
  int i=1;
  while(i<=factorial)
    {
      result*=i;
      ++i;
    }
  cout << "Factorial of Number = " << result;
  
  return 0;
}
