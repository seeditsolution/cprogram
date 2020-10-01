#include<iostream>

using namespace std;

int main()
{
    int number = 0;
    int max = 0;

    cout << "\nEnter the numbers : ";
    for (int i = 0; i < 100; i++)
    {        
        cin >> number;
            if (number > max)
            {
                max = number;
            }
    }
    cout << "\n Maximum Number "<<max;
    return 0;
}
