#include "CountingSort.h"



CountingSort::CountingSort()
{
}


CountingSort::~CountingSort()
{
	data.clear();
	data.shrink_to_fit();
}

void CountingSort::sort(std::vector<int>& in_data)
{
	data = in_data;
	int max = *std::max_element(data.begin(), data.end());
	int min = *std::min_element(data.begin(), data.end());
	running_time = clock();
	this->countingSort(min, max);
	running_time = clock() - running_time;

}

void CountingSort::countingSort(int min, int max)
{
	std::vector<int> count(max - min + 1);
	std::fill(count.begin(),count.end(), 0);

	for (int i = 0; i < data.size(); i++)
	{
		count[data[i] - min]++;
	}

	int index = 0;
	for (int i = min; i <= max; i++) 
	{
		while (count[i - min] > 0)
		{
			data[index++] = i;
			count[i - min]--;
		}
	}
}

void CountingSort::print()
{
	std::cout << "Counting Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void CountingSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Counting Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("counting_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}
