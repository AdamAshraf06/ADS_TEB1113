#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

//TASK 1:EASY:PRINT MATRIX IN SNAKE PATTERN
/*
void printSnakePattern(vector<vector<int>> &matrix) {

    //Obtain the rows and collums automatically
    int rows = matrix.size();
    int cols = matrix[0].size();

    //Go through each rows
    for (int i = 0;i < rows;i++) {

        //Print from L-to-R if value row is even
        if (i%2 == 0) {
            for (int j = 0;j < cols;j++) {
                cout << matrix[i][j]<<" ";
            }
        }

        //Print from R-to-L if value row is odd
        else {
            for (int j=cols-1;j>=0;j--) {
                cout << matrix[i][j]<<" ";
            }
        }
    }

}

int main() {

    //Set the value of Matrix
    vector<vector<int>> matrix=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //Calling the function
    printSnakePattern(matrix);
    return 0;
}
*/
//---------------------------------------------------------------------------------------------------------------------
//TASK 2:MEDIUM:MATRIX MEDIAN
/*
int findMedian(vector<vector<int>> &matrix) {

    //Obtain the rows and collums automatically
    int rows = matrix.size();
    int cols = matrix[0].size();

    //Flat the matrix into 1D
    vector<int> flat;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flat.push_back(matrix[i][j]);
        }
    }

    //Sort Array
    sort(flat.begin(), flat.end());

    int size = flat.size();

    //Print the sorted array
    for (int i = 0; i < flat.size(); i++)
    {
        cout << flat[i] << " ";
    }

    cout << endl;

    //Print out the median
    cout<<"The Median Is: ";
    if (size%2==1) {
        cout<< flat[size/2];
    }
    else {
        cout<< (flat[size/2-1] + flat[size/2])/2;
    }


}

int main() {
    vector<vector<int>> matrix=
    {
        {1,3,7},
        {8,5,9},
        {4,3,1}
    };

    findMedian(matrix);
    return 0;
}
*/
//---------------------------------------------------------------------------------------------------------------------
//TASK 3:HARD:ROTATE IMAGE 90 DEGREE
vector<vector<int>>rotateMatrix(vector<vector<int>>&matrix) {

    //Obtain the rows and collums automatically
    int rows = matrix.size();
    int cols = matrix[0].size();

    //Create the swapped matrix dimensions
    vector<vector<int>> res(cols, vector<int>(rows, 0));

    //loop through each rows and collums of the original matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            //rotate the elements
            res[j][rows-i-1] = matrix[i][j];
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix{
            { 1, 2, 3, 4 },
            { 5, 6, 7, 8 },
            { 9, 10, 11, 12 },
        };

    vector<vector<int>> res = rotateMatrix(matrix);

    //print the rotated matrix row-by-row
    for (auto& row : res) {
        for (auto& x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}