#include "AbstractSortAlgorithm.h"

#ifndef BUCKETSORT_H
#define BUCKETSORT_H

class BucketSort :
	public AbstractSortAlgorithm{
public:
	BucketSort();
	~BucketSort();
	void sort(std::vector<long long int>&) override;
	void print() override;
	void printRunningTime(std::string&) override;
private:
	void bucket(int, long long int);
	void insertionSortForBucketSort();
};

#endif
