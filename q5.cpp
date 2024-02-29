/*
    Given a sorted array of positive integers, design an algorithm and implement it
    using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

    Input format:
        The first line contains number of
        test cases, T. For each test case,
        there will be two input lines. First
        line contains n (the size of array).
        Second line contains space-separated integers describing array.

    Output:
        The output will have T number of lines.
        For each test case T, print the value of i, j and k, if found else print “No sequence
        found”.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int left,int right ,int key) {
    

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Key found, return index
        } else if (arr[mid] < key) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Key not found
}

// Function to find three indices i, j, k such that arr[i] + arr[j] = arr[k]
vector<int> findIndices(vector<int>& arr) {
    int n = arr.size();

    // Fix one element (arr[i]) and find the other two (arr[j], arr[k]) using two-pointer technique
    for (int i = 0; i < n - 2; ++i) {
        
        for(int j = i+1 ; j < n-1 ;j++){
            int k = binarySearch(arr,j+1,n-1,arr[i]+arr[j]);
            if(k != -1)
            {
                return {i,j,k};
            }
        }
        
    }

    // If no such indices found
    return {};
}



int main() {
    ifstream inFile("INPUT/in5.txt");
    ofstream outFile("OUTPUT/out5.txt");

    int t;
    inFile >> t;

    while (t--) {
        int n;
        inFile >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            inFile >> arr[i];

        // Find the indices
        vector<int> sol = findIndices(arr);

        // Output the result
        if (!sol.empty()) {
            outFile << sol[0]+1 << ", " << sol[1]+1 << ", " << sol[2]+1 << endl;
        } else {
            outFile << "No sequence found" << endl;
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}


/////////////////////////////  input   /////////////////////////////////////
/*
3 
5 
1 5 84 209 341 
10
24 28 48 71 86 89 92 120 194 201
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666
*/
/////////////////////////////  output   ////////////////////////////////////
/*

No sequence found
2, 7, 8
1, 6, 9

*/