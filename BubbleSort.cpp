#include "BubbleSort.h"



BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
	data.clear();
	data.shrink_to_fit();
}

void BubbleSort::sort(std::vector<long long int>& in_data)
{
	data = in_data;
	running_time = clock();
	bubbleSort();
	running_time = clock() - running_time;
}

void BubbleSort::bubbleSort()
{
	long long int temp;
	for (int i = 0; i <= data.size() - 1; i++)
	{
		for (int j = data.size() - 1; j >= i + 1; j--)
		{
			if (data[j] < data[j - 1])
			{
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	}

}

void BubbleSort::print()
{
	std::cout << "Bubble Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void BubbleSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Bubble Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("bubble_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}
