#include <cstdlib>
#include "SortClient.h"
#include "BubbleSort.h"
#include "CombSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "RadixSort.h"
#include "BucketSort.h"

using namespace std;

int main(int argc, char** argv) {
	SortClient client;
	vector<AbstractSortAlgorithm*> algorithms;
	std::string file_name = argv[1];

	BubbleSort *bubble_sort = new BubbleSort();
	CombSort *comb_sort = new CombSort();
	InsertionSort *insertion_sort = new InsertionSort();
	ShellSort *shell_sort = new ShellSort();
	RadixSort *radix_sort = new RadixSort();
	BucketSort *bucket_sort = new BucketSort();

	/* add algorithms to container. */
	algorithms.push_back(bubble_sort);
	algorithms.push_back(comb_sort);
	algorithms.push_back(insertion_sort);
	algorithms.push_back(shell_sort);
	algorithms.push_back(radix_sort);
	algorithms.push_back(bucket_sort);

	client.read_data(file_name);

	for (int i = 0; i < algorithms.size(); i++)
	{
		/* Strategy Pattern: set the strategy of the client as one of the derived sort algorithm class objects. */
		client.setStrategy(algorithms[i]);
		client.sort();
		client.exportRunningTimeAndSortedData(file_name); /* you should create outputs/ folder if it does not exist. */
	}
	return 0;
}

