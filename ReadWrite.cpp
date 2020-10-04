#include <iostream>

#include <fstream>

using namespace std;

int main() {

  ofstream MyFile("sample.txt");

  cout<<"Writing into a file\n";

  string data;

  cout<<"Enter your name : \n";

  cin>>data;

  

 MyFile << data << endl;

 cout<<"Enter your age : ";

 cin>>data;

  MyFile << data << endl;

 

  MyFile.close();

  string myText;

ifstream MyReadFile("sample.txt");

cout<<"Reading from a file\n";

while (getline (MyReadFile, myText)) {

  cout << myText<<endl;

}

MyReadFile.close();

return 0;

}
