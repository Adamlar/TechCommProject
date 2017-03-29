#include "abstract_sort_algorithm.h"

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort : public abstract_sort_algorithm
{
public:
	BubbleSort();
	~BubbleSort();
	void sort(std::vector<int>&) override;
	void bubbleSort();
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif