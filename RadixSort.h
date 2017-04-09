#include "AbstractSortAlgorithm.h"

#ifndef RADIXSORT_H
#define RADIXSORT_H

class RadixSort:
	public AbstractSortAlgorithm{
public:
	RadixSort();
	~RadixSort();
	void sort(std::vector<int>&) override;
	void print() override;
	void printRunningTime(std::string&) override;
private:
	int max_digit;
	void radix();
	std::vector<int> getRespondingArray(int);
	int getRespondingDigit(int, int);
	int getDigit(int number){ return (int)log10(number) + 1; }
	void countingSortForRadix(std::vector<int>&);
	};

#endif