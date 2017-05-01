#include "AbstractSortAlgorithm.h"

#ifndef RADIXSORT_H
#define RADIXSORT_H

class RadixSort:
	public AbstractSortAlgorithm{
public:
	RadixSort();
	~RadixSort();
	void sort(std::vector<long long int>&) override;
	void print() override;
	void printRunningTime(std::string&) override;
private:
	int max_digit;
	void radix();
	std::vector<long long int> getRespondingArray(int);
	long long int getRespondingDigit(long long int, int);
	int getDigit(long long int number){ return (int)log10((long long int)number) + 1; }
	void countingSortForRadix(std::vector<long long int>&);
	};

#endif
