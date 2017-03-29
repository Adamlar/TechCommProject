/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alparslantozan
 *
 * Created on 26 Mart 2017 Pazar, 00:01
 */

#include <cstdlib>
#include "SortClient.h"
#include "MergeSort.h"
#include "BubbleSort.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	SortClient client;
	vector<abstract_sort_algorithm*> algorithms;
	std::string file_name = "Resources/1k-10k.txt";

	MergeSort *m = new MergeSort();
	BubbleSort *b = new BubbleSort();
	/* add algorithms to container. */
	algorithms.push_back(m);
	algorithms.push_back(b);

	client.read_data(file_name);

	for (int i = 0; i < algorithms.size(); i++)
	{
		/* Strategy Pattern: set the strategy of the client as one of the derived sort algorithm class objects. */
		client.setStrategy(algorithms[i]);
		client.sort();
		client.printRunningTime(file_name); /*create outputs/ folder if it does not exist. */
		/*TODO: Add a method to export sorted data so we can check if the algorithms are implemented correctly or not. */
	}
    return 0;
}

