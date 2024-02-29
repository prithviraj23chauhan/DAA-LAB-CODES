/*
    Given an unsorted array of integers, design an algorithm and a program to sort the
    array using insertion sort. Your program should be able to find number of
    comparisons and shifts ( shifts - total number of times the array elements are shifted
    from their place) required for sorting the array.

    Input Format:
        The first line contains number of
        test cases, T. For each test case,
        there will be two input lines. First
        line contains n (the size of array).
        Second line contains space-separated integers describing array.

    Output Format:
        The output will have T number of lines.
        For each test case T, there will be
        three output lines. First line will give
        the sorted array.
        Second line will give total number of comparisons.
        Third line will give total number of shift operations required.
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class sort{
    public:
        int comparisons,shifts;

        sort(){
            comparisons = shifts = 0;

        }
        void insertion(vector <int>& arr){
            int i,j,temp;
            for(i=1;i<arr.size();i++){

                temp=arr[i];
                j=i-1;
                
                while( j+1  ){
                    if(arr[j]>temp){
                        arr[j+1]=arr[j];
                        j--;
                        shifts++;
                        comparisons++;
                    }
                    else    
                    {
                        comparisons++;
                        break;
                    }
                }
                arr[j+1]=temp;

            }
        }


};
int main()
{
    ifstream inFile("INPUT/in7.txt");
    ofstream outFile("OUTPUT/out7.txt");
    int t,n,temp;
    int swaps,comp;
    sort s1;

    inFile>>t;
    while(t--){
        inFile>>n;
        vector <int> vrr;
        while(n--){
            inFile>>temp;
            vrr.push_back(temp);
        }
        s1.insertion(vrr);
        for(auto i : vrr){
            outFile<<i<<" ";
        }
        outFile<<endl;
        outFile<<"comparissons = "<<s1.comparisons<<endl;
        outFile<<"shifts = "<<s1.shifts<<endl<<endl;
        

    }
    inFile.close();
    outFile.close();
}
/////////////////////////////  input   /////////////////////////////////////
/*
3
8 
-23 65 -31 76 46 89 45 32 
10 
54 65 34 76 78 97 46 32 51 21 
15  
63 42 223 645 652 31 324 22 553 -12 54 65 86 46 325
*/
/////////////////////////////  output   ////////////////////////////////////
/*

*/