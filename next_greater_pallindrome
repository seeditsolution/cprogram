// C++ Program to find the closest Palindrome 
// number 
#include <bits/stdc++.h> 
using namespace std; 

// function check Palindrome 
bool isPalindrome(string n) { 
for (int i = 0; i < n.size() / 2; i++) 
	if (n[i] != n[n.size() - 1 - i]) 
	return false; 
return true; 
} 

// convert number into String 
string convertNumIntoString(int num) { 

// base case: 
if (num == 0) 
	return "0"; 

string Snum = ""; 
while (num > 0) { 
	Snum += (num % 10 - '0'); 
	num /= 10; 
} 
return Snum; 
} 

// function return closest Palindrome number 
int closestPlandrome(int num) { 

// case1 : largest palindrome number 
// which is smaller to given number 
int RPNum = num - 1; 

while (!isPalindrome(convertNumIntoString(abs(RPNum)))) 
	RPNum--; 

// Case 2 : smallest palindrome number 
// which is greater than given number 
int SPNum = num + 1; 

while (!isPalindrome(convertNumIntoString(SPNum))) 
	SPNum++; 

// check absolute difference 
if (abs(num - RPNum) > abs(num - SPNum)) 
	return SPNum; 
else
	return RPNum; 
} 

// Driver program to test above function 
int main() { 
int num = 121; 
cout << closestPlandrome(num) << endl; 
return 0; 
} 
