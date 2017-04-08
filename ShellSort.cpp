#include "ShellSort.h"


void ShellSort::sort(std::vector<int>& in_data)
{
	data = in_data;
	running_time = clock();
	generateGaps();
	shellSort();
	running_time = clock() - running_time;
}

void ShellSort::generateGaps(){
	int gap = 1;
	int k = 1;
	do {
		gaps.push(gap);
		gap = std::pow(4, k) + 3 * pow(2, k - 1) + 1;
		k++;
	} while (gap < data.size());

}

void ShellSort::shellSort()
{
	while (!gaps.empty()) {
		int gap = gaps.top();
		gaps.pop();
		for (int i = gap; i < data.size(); i++) {
			int temp = data[i];
			int j;
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
				data[j] = data[j - gap];
			}
			data[j] = temp;
		}
	}
}

void ShellSort::print()
{
	std::cout << "Insertion Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void ShellSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Shell Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("shell_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}