
/*

IV. Given a sorted array of positive integers containing few duplicate elements
    design an algorithm and implement it using a program to find whether the given 
    key element is present in the array or not. If present, then also find the number
    of copies of given key. (Time Complexity = O(log n))
    Input format:
    The first line contains number of test cases, T. For each test case, there will
    be three input lines. First line contains n (the size of array).
    Second line contains space-separated integers describing array.
    Third line contains the key element that need to be searched in the array.
    Output format:
    The output will have T number of lines.
    For each test case T, output will be the key element and its number of copies i
    the array if the key element is present in the array otherwise print “ Key not present”.

*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to find the frequency of a key in a sorted array
int findFrequency(vector<int>& arr, int key) {
    int n = arr.size();
    int left = 0, right = n - 1;

    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            
            int count = 1; 
            int l = mid - 1;
            int r = mid + 1;

           
            while (l >= 0 && arr[l] == key) {
                count++;
                l--;
            }

       
            while (r < n && arr[r] == key) {
                count++;
                r++;
            }
            return count;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

  
    return 0;
}

int main() {
    ifstream inFile("INPUT/in4.txt");
    ofstream outFile("OUTPUT/out4.txt");

    int t;
    inFile >> t;

    while (t--) {
        int n;
        inFile >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            inFile >> arr[i];

        int key;
        inFile >> key;

        
        int frequency = findFrequency(arr, key);

        
        
        outFile << key << " - " << frequency << endl;
        
    }

    inFile.close();
    outFile.close();

    return 0;
}

/////////////////////////////  input   /////////////////////////////////////
/*
2 
10 
235 235 278 278 763 764 790 853 981 981
981
15
1 2 2 3 3 5 5 5 25 75 75 75 97 97 97
75
*/
/////////////////////////////  output   ////////////////////////////////////
/*
981 - 2
75 - 3
*/