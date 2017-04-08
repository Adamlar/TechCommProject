#include "AbstractSortAlgorithm.h"
#include <fstream>

class SortClient
{
public:
	SortClient();
	~SortClient();
	SortClient(AbstractSortAlgorithm*); 
	void read_data(std::string);
	void setStrategy(AbstractSortAlgorithm*);
	void sort();
	void exportRunningTimeAndSortedData(std::string);
private:
	AbstractSortAlgorithm* sort_strategy;
	std::vector<int> data;
	std::ifstream input_stream;
	std::ofstream output_stream;
};

