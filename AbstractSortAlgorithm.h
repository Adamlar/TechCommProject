#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>

#ifndef ABSTRACT_SORT_ALGORITHM_H
#define ABSTRACT_SORT_ALGORITHM_H

class AbstractSortAlgorithm 
{
	public:
		AbstractSortAlgorithm();
		AbstractSortAlgorithm(const AbstractSortAlgorithm& orig);
		virtual ~AbstractSortAlgorithm();
		virtual void sort(std::vector<int>&) = 0;
		virtual void print();
		virtual void printRunningTime(std::string&) = 0;
		virtual void exportRunningTime(std::string&, std::string&); /* common method to export running times to a txt file. */
		virtual void exportSortedData(std::string prefix, std::string& file_name);
	protected:
		std::vector<int> data;
		clock_t running_time;
		std::ofstream output_stream;
};

#endif /* ABSTRACT_SORT_ALGORITHM_H */

