#ifndef _RUNNER_H
#define _RUNNER_H

#include"program.h"
#include<string>
#include <iostream>
#include <bits/stdc++.h>

class runner
{
    //Variables
    public:
        program pObject;
        std::string programFileName; //fileName of program we are testing
        const static int INT_ARRAY = 0;
        const static int INT_VECTOR = 1;
        const static int DOUBLE_ARRAY = 2;
        const static int DOUBLE_VECTOR = 3;
        const static int FLOAT_ARRAY = 4;
        const static int FLOAT_VECTOR = 5;
        const static int CHAR_ARRAY = 6;
        const static int CHAR_VECTOR = 7;

    private:
        double runtime;
        std::vector<int> inputSizes; //Vector stores the size of each input the function is run on.s
        void inputParserToStringVec(std::string input, std::vector<std::string> &out);
        bool fileParserToStringVec(std::string inputFile, std::vector<std::string> &out);
    
    public:
        runner(std::string fileName);
        runner(program pObject);
        ~runner();
        double runOnInput(std::string input, int type);
        void runOnMultiInput(std::vector<std::string> inputV, int type, std::vector<double> &out);
        void runOnInputFile(std::string inputFileName, int type, std::vector<double> &out);
        void getInputSizes(std::vector<int> &out);
};

#endif
