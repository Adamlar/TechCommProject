#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <cmath>
#include <stack>
#include "AbstractSortAlgorithm.h"


class ShellSort : public AbstractSortAlgorithm
{
	std::stack<int> gaps;
public:
	void sort(std::vector<int>&) override;
	void generateGaps();
	void shellSort();
	void print() override;
	void printRunningTime(std::string&) override;
};

#endif

