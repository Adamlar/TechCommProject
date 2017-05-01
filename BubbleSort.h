#include "AbstractSortAlgorithm.h"

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort : public AbstractSortAlgorithm
{
public:
	BubbleSort();
	~BubbleSort();
	void sort(std::vector<long long int>&) override;
	void bubbleSort();
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif
