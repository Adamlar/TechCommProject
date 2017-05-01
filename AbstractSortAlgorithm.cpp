#include "AbstractSortAlgorithm.h"

AbstractSortAlgorithm::AbstractSortAlgorithm() {
}

AbstractSortAlgorithm::AbstractSortAlgorithm(const AbstractSortAlgorithm& orig) {
}

AbstractSortAlgorithm::~AbstractSortAlgorithm() {
}


void AbstractSortAlgorithm::print()
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void AbstractSortAlgorithm::exportRunningTime(std::string& message, std::string& file_name)
{
	auto time = std::time(nullptr);
	auto current_time = *std::localtime(&time);

	std::string output_path = "outputs/" + file_name;
	output_stream.open(output_path, std::fstream::app);

	if (!output_stream.is_open()) {
		std::cout << "Failed to open file: " << output_path.c_str() << std::endl;
		return;
	}

	if (!std::is_sorted(data.begin(), data.end())){
		std::cout << message.c_str() << " failed while sorting: " << file_name.c_str() << " in " 
			<< (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
		output_stream << "[ " << std::put_time(&current_time, "%d.%m.%Y %H:%M:%S") << " ] : ";
		output_stream << message.c_str() << " : " << file_name.c_str() << " : ";
		output_stream << "Failed.\n";
	}
	else{
		std::cout << message.c_str() << " : " << file_name.c_str() << " : ";
		std::cout << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
		output_stream << "[ " << std::put_time(&current_time, "%d.%m.%Y %H:%M:%S") << " ] : ";
		output_stream << message.c_str() << " : " << file_name.c_str() << " : ";
		output_stream << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
	}
	output_stream << "----------------\n";
	output_stream.close();
}

void AbstractSortAlgorithm::exportSortedData(std::string prefix, std::string& file_name)
{
	std::string output_path = "outputs/" + prefix + file_name;
	output_stream.open(output_path);

	if (output_stream.is_open())
	{
		std::ostream_iterator<long long int> output_iter(output_stream, "\n");
		std::copy(data.begin(), data.end(), output_iter);
	}
	output_stream.close();
}

