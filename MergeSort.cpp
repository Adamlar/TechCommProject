#include "MergeSort.h"

MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
	data.clear();
	data.shrink_to_fit();
}

void MergeSort::sort(std::vector<long long int>& in_data)
{
	data = in_data;
	running_time = clock();
	this->mergeSort(0, data.size() - 1);
	running_time = clock() - running_time;
}

void MergeSort::mergeSort(int low_bound, int upper_bound)
{
	int mid;
	if (low_bound < upper_bound)
	{
		mid = (low_bound + upper_bound) / 2;
		mergeSort(low_bound, mid);
		mergeSort(mid + 1, upper_bound);
		merge(low_bound, mid, upper_bound);
	}
}

void MergeSort::merge(int low_bound, int mid, int upper_bound)
{
	int i = 0;
	int j = 0;
	int n1 = mid - low_bound + 1; // size of left array
	int n2 = upper_bound - mid; // size of right array
	std::vector<long long int> left_arr(n1 + 1);
	std::vector<long long int> right_arr(n2 + 1);

	for (; i < n1; i++) // creating left array
	{
		left_arr[i] = data[low_bound + i];
	}
	for (; j < n2; j++) // creating right array
	{
		right_arr[j] = data[mid + j + 1];
	}

	left_arr[i] = INT_MAX; // sentinel
	right_arr[j] = INT_MAX; // sentinel

	for (int i = 0, j = 0, k = low_bound; k <= upper_bound; k++) // comparing left and right arrays.
	{
		if (left_arr[i] <= right_arr[j])
			data[k] = left_arr[i++];
		else
			data[k] = right_arr[j++];
	}
}

void MergeSort::print()
{
	std::cout << "Merge Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void MergeSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Merge Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("merge_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}
