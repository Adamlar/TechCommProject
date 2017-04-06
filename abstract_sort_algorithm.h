/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abstract_sort_algorithm.h
 * Author: alparslantozan
 *
 * Created on 26 Mart 2017 Pazar, 00:06
 */

#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>

#ifndef ABSTRACT_SORT_ALGORITHM_H
#define ABSTRACT_SORT_ALGORITHM_H

class abstract_sort_algorithm 
{
	public:
		abstract_sort_algorithm();
		abstract_sort_algorithm(const abstract_sort_algorithm& orig);
		virtual ~abstract_sort_algorithm();
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

