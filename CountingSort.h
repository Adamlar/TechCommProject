#include "abstract_sort_algorithm.h"

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

class CountingSort :
	public abstract_sort_algorithm
{
public:
	CountingSort();
	~CountingSort();
	void sort(std::vector<int>&) override;
	void countingSort(int, int);
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif