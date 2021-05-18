#include "program.h"
#include "runner.h"
#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main(int argc, char* argv[])
{
	//string programFile = nullptr;
	//string inputFile = nullptr;

	if(argc == 3)
	{
		string inputFile(argv[1]);
		cout<<"InputFIle, type: "<< inputFile <<", "<<stoi(argv[2])<< endl;
		program program;
		runner runner(program);

		vector<double> out;
		runner.runOnInputFile(inputFile, stoi(argv[2]), out);

		for(auto i : out)
		{
			cout<< i << endl;
		}
	}
	else
	{
		cout<<"Please Specfiy input file and input type";
		return -100;
	}

	/*
	struct timespec begin, end;
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin); //gets cpu time

	for(int i = 0; i < 1000; i++)
	{
		for(int k = 0;k < 1000; k++)
		{
			for(int j = 0; j < 1000; j++ )
			{
			}
		}
	}

	//clock_gettime(CLOCK_REALTIME, &end); //gets wall time

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); //gets cpu time

	long seconds = end.tv_sec - begin.tv_sec;
	long nseconds = end.tv_nsec - begin.tv_nsec;
	double elapsed = seconds + nseconds*1e-9;

	cout<<"Time elapsed = "<<elapsed<<endl;
	*/

	return 0;
}
