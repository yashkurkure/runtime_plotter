#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <bits/stdc++.h>

class program
{
    public:
    void testRuntime(int arr[], int length);

    //FOR CHAR ARRAY
    void testRuntime(char arr[], int length);

    //FOR DOUBLE ARRAY
    void testRuntime(double arr[], int length);

    //FOR FLOAT ARRAY
    void testRuntime(float arr[], int length);

    //FOR INT VECTOR
    void testRuntime(std::vector<int> vec);

    //FOR CHAR VECTOR
    void testRuntime(std::vector<char> vec);

    //FOR DOUBLE VECTOR
    void testRuntime(std::vector<double> vec);

    //FOR FLOAT VECTOR
    void testRuntime(std::vector<float> vec);
};

#endif