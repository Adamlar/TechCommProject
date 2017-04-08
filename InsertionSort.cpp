#include "InsertionSort.h"


void InsertionSort::sort(std::vector<int>& in_data)
{
	data = in_data;
	running_time = clock();
	insertionSort();
	running_time = clock() - running_time;
}

void InsertionSort::insertionSort()
{
	int temp, j;
	for (int i = 1; i < data.size(); i++) {
		temp = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > temp) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp;
	}
}

void InsertionSort::print()
{
	std::cout << "Insertion Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void InsertionSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Insertion Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("insertion_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}