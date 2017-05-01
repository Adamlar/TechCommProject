#include "SortClient.h"


SortClient::SortClient()
{
}


SortClient::~SortClient()
{
}

SortClient::SortClient(AbstractSortAlgorithm* sort_strategy)
{
	this->sort_strategy = sort_strategy;
}

void SortClient::setStrategy(AbstractSortAlgorithm* sort_strategy)
{
	this->sort_strategy = sort_strategy;
}

void SortClient::read_data(std::string file_name)
{
	input_stream.open(file_name, std::fstream::in);
	std::istream_iterator<long long int> input_iter(input_stream);

	int temp;
	std::copy(input_iter, std::istream_iterator<long long int>(), std::back_inserter(data));
	/*
	while (input_stream.good())
	{
		input_stream >> temp;
		data.push_back(temp);
	}
	*/
	input_stream.close();
}

void SortClient::sort()
{
	this->sort_strategy->sort(data);
}

void SortClient::exportRunningTimeAndSortedData(std::string file_name)
{
	sort_strategy->printRunningTime(file_name);
}
