#include <iostream>
#include <vector>
using namespace std;

// Faster and simpler O(n*m)
int findPeak2D(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bool peak = true;

            // up
            if(i > 0 && mat[i][j] <= mat[i-1][j])
                peak = false;

            // down
            if(i < n-1 && mat[i][j] <= mat[i+1][j])
                peak = false;

            // left
            if(j > 0 && mat[i][j] <= mat[i][j-1])
                peak = false;

            // right
            if(j < m-1 && mat[i][j] <= mat[i][j+1])
                peak = false;

            if(peak)
            {
                cout << "Row: " << i << endl;
                cout << "Column: " << j << endl;
                cout << "Peak Value: " << mat[i][j] << endl;
                return mat[i][j];
            }
        }
    }

    return -1;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> mat[i][j];

    findPeak2D(mat);

    return 0;
}

