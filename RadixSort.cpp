#include "RadixSort.h"

RadixSort::RadixSort(){

}

RadixSort::~RadixSort()
{
	data.clear();
	data.shrink_to_fit();
}

void RadixSort::sort(std::vector<int>& in_data)
{
	this->data = in_data;
	this->max_digit = (int)log10(*std::max_element(data.begin(), data.end())) + 1;
	running_time = clock();
	radix();
	running_time = clock() - running_time;
}

void RadixSort::radix()
{
	for (int i = 1; i <= this->max_digit; i++)
	{
		std::vector<int> data(getRespondingArray(i));
		countingSortForRadix(data);
	}
}

std::vector<int> RadixSort::getRespondingArray(int n)
{
	std::vector<int> data;
	for (int i = 0; i < this->data.size(); i++)
		data.push_back(getRespondingDigit(this->data[i], n));
	return data;
}

int RadixSort::getRespondingDigit(int a, int n)
{
	if (n>getDigit(a))
		return 0;
	else{
		for (int i = 1; i < n; i++)
			a /= 10;
		return a % 10;
	}
}

void RadixSort::countingSortForRadix(std::vector<int>& data)
{
	std::vector<int> temp(this->data.size());
	std::vector<int> counts(10,0);
	for (int i = 0; i < this->data.size(); i++)
		counts[data[i]]++;
	for (int i = 1; i < 10; i++)
		counts[i] += counts[i - 1];
	for (int i = this->data.size() - 1; i >= 0; i--)
	{
		counts[data[i]]--;
		temp[counts[data[i]]] = this->data[i];
	}
	this->data = temp;
}

void RadixSort::print()
{
	std::cout << "Radix Sort: " << std::endl;
	AbstractSortAlgorithm::print();
}

void RadixSort::printRunningTime(std::string& file_name)
{
	int pos = file_name.find("/");
	std::string out_file_name = file_name.substr(pos + 1, file_name.size() - 1);
	std::string message = "Radix Sort";
	AbstractSortAlgorithm::exportSortedData(std::string("radix_sort_"), out_file_name);
	AbstractSortAlgorithm::exportRunningTime(message, out_file_name);
}
