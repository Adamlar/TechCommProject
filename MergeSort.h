#include "AbstractSortAlgorithm.h"
#include <climits>

#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort : public AbstractSortAlgorithm
{
public:
	MergeSort();
	~MergeSort();
	void sort(std::vector<int>&) override;
	void mergeSort(int, int);
	void merge(int, int, int);
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif