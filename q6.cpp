/*
Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element.
Output format:
The output will have T number of lines.
For each test case T, output will be the total count i.e. number of times such pair exists.
*/

#include<iostream>
#include<fstream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int count_pair(vector<int>& vrr, int key) {
        int count = 0;
        map<int, int> hmap;

        for (int i = 0; i < vrr.size(); i++) {
            hmap[vrr[i]]++;
        }
        for (int i = 0; i < vrr.size(); i++) {
            count += hmap[vrr[i] - key];
        }
        return count;
    }
};

int main() {
    ifstream inFile("INPUT/in6.txt");
    ofstream outFile("OUTPUT/out6.txt");
    int t, n, temp;
    Solution s1;

    inFile >> t;
    while (t--) {
        inFile >> n;
        vector<int> vrr;
        while (n--) {
            inFile >> temp;
            vrr.push_back(temp);
        }
        int key;
        inFile >> key;
        int pairs = s1.count_pair(vrr, key);
        outFile << pairs << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}


/////////////////////////////  input   /////////////////////////////////////
/*
2 
5 
1 51 84 21 31
20
10
24 71 16 92 12 28 48 14 20 22
4
*/
/////////////////////////////  output   ////////////////////////////////////
/*
2
4
*/