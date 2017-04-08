#include "AbstractSortAlgorithm.h"

#ifndef COMBSORT_H
#define COMBSORT_H

class CombSort :
	public AbstractSortAlgorithm
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