#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;


void insertion_sort(int parent_array[], int no_of_elements)
{
    for (int j = 1; j < no_of_elements; j++)
    {
        int i,temp_value;
        //Storing the value of element at jth in a temp_value
        temp_value = parent_array[j];
        i = j - 1;
        //Loop to compare the values
        while (i >= 0 && parent_array[i] > temp_value)
        {
            parent_array[i + 1] = parent_array[i];
            i = i - 1;
        }
        parent_array[i + 1] = temp_value;
    }
}

void display_output(int parent_array[], int no_of_elements)
{
    int i;
    for (i = 0; i < no_of_elements; i++)
    {
        cout << parent_array[i] << " ";

    }
}

int main(int argc, const char* argv[])
{
	int no_of_elements;

	cout << "Enter the number of elements: ";
	cin >> no_of_elements;

	//Using File Handling to store random numbers in a file
	ofstream file;
	int parent_array[1000]{};
	int i;
	file.open("InsertionSort.txt");
	if (!file)
	{
		cerr << "No such file exists, try again!" << endl;
		exit(1);
	}

	for (i = 0; i < no_of_elements; i++)
	{
		parent_array[i] = (rand() % 1000) + 1;
		file << parent_array[i];
	}

	file.close();

	//Displaying the input array
	cout << "Before implementing Insertion sort: " << "\n";
	display_output(parent_array, no_of_elements);

	auto start1 = std::chrono::high_resolution_clock::now();
	//Calling Insertion sort function to sort the input array
	quick_sort(parent_array, no_of_elements);
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;

	cout << "\n\nAfter implementing Insertion sort we get: " << "\n";
	display_output(parent_array, no_of_elements);

	std::cout << "\n\nQuick Sort Time Elapsed: " << elapsed1.count() << "s\n";
	return 0;
}
