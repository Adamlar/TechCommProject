#include "abstract_sort_algorithm.h"

#ifndef COMBSORT_H
#define COMBSORT_H

class CombSort :
	public abstract_sort_algorithm
{
public:
	CombSort();
	~CombSort();
	void sort(std::vector<int>&) override;
	void combSort();
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif