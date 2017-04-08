#include "AbstractSortAlgorithm.h"

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

class CountingSort :
	public AbstractSortAlgorithm
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