#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

int generate_random_numbers(int lower_limit, int upper_limit, int size)
{
	std::random_device random_device;
	std::mt19937 eng(random_device()); // Generate seed with Mersenne Twister pseudo-random generator
	std::uniform_int_distribution<> distr(lower_limit, upper_limit);

	std::vector<unsigned long long int> set;

	for (int n = 0; n < size; ++n) {
		set.push_back(distr(eng));
	}

	std::ofstream output_stream;

	output_stream.open("outputs/generated_set.txt", std::fstream::app);
	if (output_stream.is_open()) {
		std::ostream_iterator<int> output_iter(output_stream, "\n");
		std::copy(set.begin(), set.end(), output_iter);
	}
	output_stream.close();

	std::sort(set.begin(), set.end());
	output_stream.open("outputs/generated_set_sorted.txt", std::fstream::app);
	if (output_stream.is_open()) {
		std::ostream_iterator<int> output_iter(output_stream, "\n");
		std::copy(set.begin(), set.end(), output_iter);
	}
	output_stream.close();

	output_stream.open("outputs/generated_set_reverse_sorted.txt", std::fstream::app);
	if (output_stream.is_open()) {
		std::ostream_iterator<int> output_iter(output_stream, "\n");
		std::copy(set.rbegin(), set.rend(), output_iter);
	}

	output_stream.close();
}
