#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "AbstractSortAlgorithm.h"


class InsertionSort : public AbstractSortAlgorithm
{
public:
	void sort(std::vector<int>&) override;
	void insertionSort();
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif