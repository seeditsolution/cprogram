#include <stdio.h>
int main()
 {
	int x,y,z;
	
	std::cout << "Enter 1st Number:";
	std::cin >> x;
	std::cout << "\nEnter 2nd Number:";
	std::cin >> y;
	std::cout << "\nEnter 3rd Number:";
	std::cin >> z;
	
	if(x > y && y > z )
	{
		std::cout << "\nLargest Number is ", x;
	}
	else if(y > x && y > z )
	{
		std::cout << "\nLargest Number is ", y;
	}
	else
	{
		std::cout << "\nLargest Number is ", z;
	}
	return 0;
 }
