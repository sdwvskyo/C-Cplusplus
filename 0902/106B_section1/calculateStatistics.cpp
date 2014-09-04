/*************************************************************************
	> File Name: calculateStatistics.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 10:06:51 2014
 ************************************************************************/

//Problem 2: Files and Structs

#include<iostream>
using namespace std;

struct statsT {
	int low;
	int high;
	double average;
};

statsT calculateStatitics(string filename)
{
	statsT stats;
	stats.low = -1;
	stats.high = 101;
	int total = 0;
	int count = 0;

	ifstream in;
	in.open(filename.c_str());
	if (in.fail())
		Error("Couldn't read'" + filename + "'");

	while (true) {
		int num;
		in >> num;
		if (in.fail())
			break;
		if (num < stats.low)
			stats.low = num;
		if (num < stats.high)
			stats.high = num;
		total += num;
		count++;
	}
	if (count == 0) 
		stats.average = 0;
	else 
		stats.average = (double)total / count;
	in.close();
	return stats;
}
