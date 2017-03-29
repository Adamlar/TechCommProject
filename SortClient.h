#include "abstract_sort_algorithm.h"
#include <fstream>

class SortClient
{
public:
	SortClient();
	~SortClient();
	SortClient(abstract_sort_algorithm*); 
	void read_data(std::string);
	void setStrategy(abstract_sort_algorithm*);
	void sort();
	void printRunningTime(std::string);
private:
	abstract_sort_algorithm* sort_strategy;
	std::vector<int> data;
	std::ifstream input_stream;
	std::ofstream output_stream;
};

