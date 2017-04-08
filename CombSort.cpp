#include "CombSort.h"



CombSort::CombSort()
{
}


CombSort::~CombSort()
{
	data.clear();
	data.shrink_to_fit();
}

void CombSort::sort(std::vector<int>& in_data)
{
	data = in_data;
	running_time = clock();
	this->combSort();
	running_time = clock() - running_time;
}

void CombSort::combSort()
{
	int gap = data.size();
	float shrink = 1.3;
	bool isSwapped = true;

	while (gap > 1 || isSwapped == true)
	{
		gap = floor(gap / shrink);
		if (gap <= 1)
			gap = 1;

		isSwapped = false;

		for (int i = 0; i < data.size() - gap; i++)
		{
			if (data[i] > data[i + gap])
			{
				std::swap(data[i], data[i + gap]);
				isSwapped = true;
			}
		}
	}
}

void CombSort::print()
{
	std::cout << "Comb Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void CombSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Comb Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("comb_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}
