# Runtime Plotter

Written in: C++, bash

## Aim of this project

Plot the runtime of C++ functions of the form:

func(int data[], int size)
func(char data[], int size)
func(double data[], int size)
func(float data[], int size)

func(std::vector<int> vec)
func(std::vector<char> vec)
func(std::vector<double> vec)
func(std::vector<float> vec)

## Example Usage

Let's say you have a function that bubble sorts an integer array as follows:

Source: https://www.geeksforgeeks.org/bubble-sort/

```
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
```

To test the runtime:
1. Open program.cpp (src/program.cpp)
2. Paste the above functions in program.cpp and add the following lines as shown here:

```
//STEP 1: --->Add any imports that your function requires
#include "program.h"
#include <bits/stdc++.h>
using namespace std;

//STEP 2: --->Paste the function you are testing here
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

//--->END of your functions


//Wrapper API


/*STEP 4: ---> Since the function we are testing uses an INTEGER ARRAY we use the function mentioned below the "FOR INT ARRAY" comment.
               If your function was using VECTOR<INTEGER> you would place your function call in the function below the "FOR INT VECTOR" comment
*/
    //FOR INT ARRAY
    void program::testRuntime(int arr[], int length)
    {

//STEP 5: Add the function call here and pass the arguements of the testRuntime function accrodingly to your function. 
        //Mention the Function you are testing here:
        bubbleSort(arr, length);
    }

    //FOR CHAR ARRAY
    void program::testRuntime(char arr[], int length)
    {
        //Mention the Function you are testing here:

    }

    //FOR DOUBLE ARRAY
    void program::testRuntime(double arr[], int length)
    {
        //Mentiion the Function you are testing here:

    }

    //FOR FLOAT ARRAY
    void program::testRuntime(float arr[], int length)
    {
        //Mention the Function you are testing here:

    }

    //FOR INT VECTOR
    void program::testRuntime(std::vector<int> vec)
    {
        //Mention the Function you are testing here:

    }

    //FOR CHAR VECTOR
    void program::testRuntime(std::vector<char> vec)
    {
        //Mention the Function you are testing here:

    }

    //FOR DOUBLE VECTOR
    void program::testRuntime(std::vector<double> vec)
    {
        //Mention the Function you are testing here:

    }

    //FOR FLOAT VECTOR
    void program::testRuntime(std::vector<float> vec)
    {
        //Mention the Function you are testing here:

    }
```

3. In the src folder, open a terminal and run the make command.
4. Create a file such as "input.txt" and add a comma separated list on sepearate lines. Each line is a separate input for your function. The function will be run on each line and you will be returned the runtime required for each line in **milliseconds**.

Example of a input file: (Feel free to play around with src/gen.sh to generate such a file)
```
58,46,52,7,12,31,60,71,26,2
81,24,56,23,21,70,93,54,52,85,14,62,0,13,72,87,44,7,98,31
98,76,2,23,78,57,43,40,96,62,51,83,3,7,73,76,21,21,56,59,3,2,29,41,70,69,65,30,64,39
81,84,66,29,7,32,14,14,47,90,51,89,71,89,69,22,56,37,23,16,34,97,33,31,52,56,66,62,61,33,44,35,92,91,45,11,8,83,56,14
75,30,60,90,98,70,27,17,53,99,89,66,36,92,98,38,74,6,75,27,22,57,57,39,15,95,14,55,19,57,92,63,32,23,31,37,51,32,45,2,7,75,70,19,14,49,60,88,33,7

```

5. To run the program use: *./run input.txt 0*. The 0 at the end specifies that your function accepts an integer array. This number will change based on the signature of your function. Refer to the table below to get this number:

|Function Type| Command line integer code |
| --- | --- |
| func(int data[], int size) | 0 |
| func(std::vector< int > vec) | 1 | 
| func(double data[], int size) | 2 |
| func(std::vector< double > vec) | 3 |
| func(float data[], int size) | 4 |
| func(std::vector< float > vec) | 5 |
| func(char data[], int size) | 6 |
| func(std::vector< char > vec) | 7 |
 
6. The program will print the runtime required for each input value to stdout on a separtate line. For example:
```
InputFIle, type: out, 0
2.67789  -->For input on line 1 of input.txt
4.39975  -->For input on line 2 of input.txt
3.50113  --> and so on...
2.4155
3.49676

```
