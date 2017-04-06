/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abstract_sort_algorithm.cpp
 * Author: alparslantozan
 * 
 * Created on 26 Mart 2017 Pazar, 00:06
 */

#include "abstract_sort_algorithm.h"

abstract_sort_algorithm::abstract_sort_algorithm() {
}

abstract_sort_algorithm::abstract_sort_algorithm(const abstract_sort_algorithm& orig) {
}

abstract_sort_algorithm::~abstract_sort_algorithm() {
}


void abstract_sort_algorithm::print()
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void abstract_sort_algorithm::exportRunningTime(std::string& message, std::string& file_name)
{
	if (!std::is_sorted(data.begin(), data.end()))
	{
		std::cout << message.c_str() << " failed sorting " << file_name.c_str() << " in " 
			<< (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
		return;
	}

	std::string output_path = "outputs/" + file_name;
	output_stream.open(output_path, std::fstream::app);
	auto time = std::time(nullptr);
	auto current_time = *std::localtime(&time);

	if (output_stream.is_open())
	{
		output_stream << "[ " << std::put_time(&current_time, "%d.%m.%Y %H:%M:%S") << " ] : ";
		output_stream << message.c_str() << " : " << file_name.c_str() << " : ";
		output_stream << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
		output_stream.close();
	}
	std::cout << message.c_str() << " : " << file_name.c_str() << " : ";
	std::cout << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
	output_stream.close();
}

void abstract_sort_algorithm::exportSortedData(std::string prefix, std::string& file_name)
{
	std::string output_path = "outputs/" + prefix + file_name;
	output_stream.open(output_path);

	if (output_stream.is_open())
	{
		std::ostream_iterator<int> output_iter(output_stream, "\n");
		std::copy(data.begin(), data.end(), output_iter);
	}
	output_stream.close();
}

