/*
    Given an unsorted array of integers, design an algorithm and implement a program to sort this
    array using selection sort. Your program should also find number of comparisons and number of
    swaps required.
    
    Input Format:
        The first line contains number of test cases, T.
        For each test case, there will be two input lines.
        First line contains n (the size of array).
        Second line contains space-separated integers describing array.

    Output Format:
        The output will have T number of lines.
        For each test case T, there will be three output lines.
        First line will give the sorted array.
        Second line will give total number of comparisons.
        Third line will give total number of swaps required.
*/

#include<iostream>
#include<fstream>
#include<vector>


using namespace std;


void selection_sort( vector <int>& vrr, int& comp,int& swaps)
{
    comp = 0;
    swaps = 0;
    
    for (int i = 0 ; i < vrr.size()-1 ;i++){
        int smallest = i;
        for(int j= i+1; j<vrr.size() ; j++){
            comp++;
            if(vrr[smallest] > vrr[j])
            {
                smallest = j;
            }
        }
        if(i != smallest)
        {
            int temp = vrr[i];
            vrr[i] = vrr[smallest];
            vrr[smallest] = temp;
            swaps++;
        }
    }
}

int main()
{
    ifstream inFile("INPUT/in8.txt");
    ofstream outFile("OUTPUT/out8.txt");
    int t,n,temp;
    int swaps,comp;

    inFile>>t;
    while(t--){
        inFile>>n;
        vector <int> vrr;
        while(n--){
            inFile>>temp;
            vrr.push_back(temp);
        }
        selection_sort(vrr,comp,swaps);
        for(auto i : vrr){
            outFile<<i<<" ";
        }
        outFile<<endl;
        outFile<<"comparissons = "<<comp<<endl;
        outFile<<"swaps = "<<swaps<<endl<<endl;
        

    }
    inFile.close();
    outFile.close();
}

/////////////////////////////  input   /////////////////////////////////////
/*
5
5 
3 4 2 6 5
6
1 2 5 3 7 4
10
9 2 8 5 4 7 3 6 1 0
3
3 2 1
20
19 5 2 67 23 87 13 1 98 32 76 8 3 10 19 54 56 34 55 66
*/
/////////////////////////////  output   ////////////////////////////////////
/*
2 3 4 5 6 
comparissons = 10
swaps = 3

1 2 3 4 5 7 
comparissons = 15
swaps = 3

0 1 2 3 4 5 6 7 8 9 
comparissons = 45
swaps = 6

1 2 3 
comparissons = 3
swaps = 1

1 2 3 5 8 10 13 19 19 23 32 34 54 55 56 66 67 76 87 98 
comparissons = 190
swaps = 15


*/
