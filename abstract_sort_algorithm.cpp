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
	std::string output_path = "outputs/" + file_name;
	output_stream.open(output_path, std::fstream::app);
	std::time_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	if (output_stream.is_open())
	{
		output_stream << "[ " << std::ctime(&current_time) << " ] : ";
		output_stream << message.c_str() << " : " << file_name.c_str() << " : ";
		output_stream << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
		output_stream.close();
	}
	std::cout << message.c_str() << " : " << file_name.c_str() << " : ";
	std::cout << (float)running_time / CLOCKS_PER_SEC << " seconds." << std::endl;
}

