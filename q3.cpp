/*
III.	Given an already sorted array of positive integers, design an algorithm 
and implement it using a program to find whether a given key element is present 
in the sorted array or not. For an array arr[n], search at the indexes arr[0],
arr[2], arr[4],.....,arr[2k] andso on. Once the interval (arr[2k] < key < arr[ 2k+1] ) 
is found, perform a linear search operation from the index 2k to find the element key.
(Complexity < O(n), where n is the number of elements need to be scanned for searching):  

Jump Search

    Input format: 

The first line contains number of test cases, T. 
For each test case, there will be three input lines. 
First line contains n (the size of array). 
Second line contains n space-separated integers describing array. 
Third line contains the key element that need to be searched in the array.

    Output format: 

The output will have T number of lines.  
For each test case, output will be “Present” if the key element is found in the array, otherwise “Not Present”.  
Also, for each test case output the number of comparisons required to search the key.*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

// Binary search function 
pair<bool, int> binarySearch(int arr[], int low, int high, int key) {
    int comparisons = 0;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return {true, comparisons};
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {false, comparisons};
}

// Jump search function
pair<bool, int> jumpSearch(int arr[], int n, int key) {
    int jump = 2; 
    int left = 0, right = jump;
    int comparisons = 0;

    while (right < n && arr[right] <= key) {
        comparisons++;
        left = right;
        right += jump;
    }

    auto binaryResult = binarySearch(arr, left, min(right, n - 1), key);
    comparisons += binaryResult.second; // Add binary search comparisons to total

    return {binaryResult.first, comparisons};
}

int main() {
    ifstream inFile("INPUT/in3.txt");
    ofstream outFile("OUTPUT/out3.txt");

    int t;
    inFile >> t;

    while (t--) {
        int n, k;
        inFile >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
            inFile >> arr[i];

        inFile >> k;

        auto result = jumpSearch(arr, n, k);
        if (result.first)
            outFile << "Present ";
        else
            outFile << "Not Present ";
        
        outFile << "\nComparisons: " << result.second << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}




/////////////////////////////  input   /////////////////////////////////////
/*
3
5
12 23 36 39 41
41
8
21 39 40 45 51 54 68 72
69
10
101 246 438 561 796 896 899 4644 7999 8545
7999
*/
/////////////////////////////  output   ////////////////////////////////////
/*
Present 
Comparisons: 3
Not Present 
Comparisons: 5
Present 
Comparisons: 5
*/