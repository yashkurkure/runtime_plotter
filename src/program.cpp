//Add any imports that your function requires
#include "program.h"
#include <bits/stdc++.h>
using namespace std;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[],int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

    //END of your functions


//Wrapper API

    //FOR INT ARRAY
    void program::testRuntime(int arr[], int length)
    {
        //Mentiion the Function you are testing here;
        bubbleSort(arr, length);
    }

    //FOR CHAR ARRAY
    void program::testRuntime(char arr[], int length)
    {
        //Mention the Function you are testing here;

    }

    //FOR DOUBLE ARRAY
    void program::testRuntime(double arr[], int length)
    {
        //Mentiion the Function you are testing here;

    }

    //FOR FLOAT ARRAY
    void program::testRuntime(float arr[], int length)
    {
        //Mention the Function you are testing here;

    }

    //FOR INT VECTOR
    void program::testRuntime(std::vector<int> vec)
    {
        //Mention the Function you are testing here;

    }

    //FOR CHAR VECTOR
    void program::testRuntime(std::vector<char> vec)
    {
        //Mention the Function you are testing here;

    }

    //FOR DOUBLE VECTOR
    void program::testRuntime(std::vector<double> vec)
    {
        //Mention the Function you are testing here;

    }

    //FOR FLOAT VECTOR
    void program::testRuntime(std::vector<float> vec)
    {
        //Mention the Function you are testing here;

    }

