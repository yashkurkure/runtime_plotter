#include"runner.h" 
#include"program.h"
#include<string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include<time.h>


//Constructor
runner::runner(std::string fileName)
{
    this->programFileName = fileName;
}

runner::runner(program pObject)
{
    this->pObject = pObject;
}

//Destructor
runner::~runner()
{

}

//Runs the program on the specified input
//type specifies the data type of the  comma separated list in the input string
//returns the runtime of the program on the given input
double runner::runOnInput(std::string input, int type)
{
    std::vector<std::string> inputV;
    inputParserToStringVec(input, inputV);

    if(type == runner::INT_ARRAY)
    {
        const int length = inputV.size();
        int arr[length];

        for(int i = 0; i < length; i++)
        {
            arr[i] = stoi(inputV[i]);
        }

        double ms = 0;
        double s = 0;
        for(int count = 0; count < 100; count ++)
        {
            struct timespec begin, end;


            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin); //gets cpu time

            pObject.testRuntime(arr, length);

            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); //gets cpu time

            long seconds = end.tv_sec - begin.tv_sec;
	        long nseconds = end.tv_nsec - begin.tv_nsec;
	        double elapsed = seconds + nseconds*1e-9;

            s += elapsed;
            ms+= elapsed*1e+6;

        }

        
        return ms/100;

    }

    return -1;
}

//Runs the program on the specified vector of inputs
//type specifies the data type of the  comma separated list in each string of inputV
//returns the runtime of the program on the given inputs as a vector
void runner::runOnMultiInput(std::vector<std::string> inputV, int type, std::vector<double> &out)
{
    for(auto i : inputV)
    {
        out.push_back(runOnInput(i, type));
    }
}

//Runs the program on the specified input file
//type specifies the data type of the  comma separated list in the input file on each line
//returns the runtime of the program on the given inputs in the file as a vector
void  runner::runOnInputFile(std::string inputFileName, int type, std::vector<double> &out)
{
    std::vector<std::string> lines;

    if(!fileParserToStringVec(inputFileName, lines))
    {
        std::cout<<"Could not read file "<<inputFileName << std::endl;
        exit(-1);
    }

    for(auto i : lines)
    {
        out.push_back(runOnInput(i, type));
    }

}

//Parses comma separated string into a vector
//Takes a string of format "1,2,3,4,5,6" adn returns a vector of [1,2,3,4,5,6]
void runner::inputParserToStringVec(std::string input, std::vector<std::string> &out)
{
    out.clear();
    std::stringstream ss(input);
    while(ss.good())
    {
        std::string substr;
        getline(ss, substr, ',');
        out.push_back(substr);

    }

    #ifdef DEBUG
    std::cout<<"\ninputParserToStringVec()"<<std::endl;
    for(int i = 0; i < out.size(); i++)
    {
        
        std::cout<<i<<". "<<out[i]<<std::endl;
    }
    #endif

}

 bool runner::fileParserToStringVec(std::string inputFile, std::vector<std::string> &out)
 {
     std::ifstream file(inputFile);

    if(!file) //check ifd file exists
    {
        return false;
    }

    std::string str;
    while(getline(file,str))
    {
        //Later Improvement: Trim string for whitespaces
        out.push_back(str);
    }

    #ifdef DEBUG
    std::cout<<"\nfileParserToStringVec"<<std::endl;
    for(int i = 0; i < out.size(); i++)
    {
        
        std::cout<<i<<". "<<out[i]<<std::endl;
    }
    #endif

    return true;
 }




