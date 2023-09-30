/*
Given a boolean matrix of size RxC where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 
then all the cells in its ith row and jth column will become 1.

Example 1:

Input:
R = 2, C = 2
matrix[][] = {{1, 0},
              {0, 0}}
Output: 
1 1
1 0 
Explanation:
Only cell that has 1 is at (0,0) so all 
cells in row 0 are modified to 1 and all 
cells in column 0 are modified to 1.

Example 2:

Input:
R = 4, C = 3
matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}
Output: 
1 1 1
1 1 1
1 1 1
1 0 0 
Explanation:
The position of cells that have 1 in
the original matrix are (0,0), (1,0)
and (2,0). Therefore, all cells in row
0,1,2 are and column 0 are modified to 1. 
Your Task:
You dont need to read input or print anything. Complete the function booleanMatrix() that takes the matrix as input parameter 
and modifies it in-place.

Expected Time Complexity: O(R * C)
Expected Auxiliary Space: O(R + C) 

Constraints:
1 ≤ R, C ≤ 1000
0 ≤ matrix[i][j] ≤ 1

*/

//********************************************************************************************************************

// Optimal Solution 
// T.C- O(N*M)
// Space- Constant

class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n=matrix.size(), m=matrix[0].size();
        int col_0;
        // To avoid extra space we mark 0th row and 0th col as 1 for 
        // presence of 1's in thpse particular rows and column. 
        // We see that [0][0] is intersecting for both 0th row and 0th col. 
        // So for 0th row we keep in new variable col_0
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                {
                    if(j==0)
                    {
                        matrix[i][0]=1;
                        col_0=1;
                    }
                    else
                    {
                        matrix[0][j]=1;
                        matrix[i][0]=1;
                    }
                }
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][0] || matrix[0][j])
                {
                    matrix[i][j]=1;
                }
            }
        }
        // Now for 0th row and 0th column
        // We dont change the 0th column value because if we change the
        // 0th column value by looking col_0 then whole column 0 will become
        // 1 and so let say in matrix[0][4]=0, So [0][4]'s value is dependent 
        // on matrix[0][0] and col_0 value. Now if we change matrix[0][0] 
        // value which was initially 0 by looking col_0 then now matrix[0][0] 
        // will become 1 and then when we try to change the 0th row value then
        // for matrix[0][4 we will check matrix[0]][0] which now has become 1 so it 
        // will make matrix[0][4] as 1 which will become wrong. 
        // So we first complete 0th row because column 0 is not dependent on 
        // row 0
        if(matrix[0][0]==1)
        {
            for(int i=1; i<m; i++)
            {
                matrix[0][i]=1;
            }
        }
        if(col_0==1)
        {
            for(int i=0; i<n; i++)
            {
                matrix[i][0]=1;
            }
        }
    }
};

//**********************************************************************************************


// Solution Brute force

class Solution
{   
    public:
    int n,m;
    void solve(vector<vector<int>>&mat, int i, int j)
    {
        for(int k=0; k<m; k++)
        {
            if(mat[i][k]!=1)
            {
                mat[i][k]=-1;
            }
        }
        for(int k=0; k<n; k++)
        {
            if(mat[k][j]!=1)
            {
                mat[k][j]=-1;
            }
        }
    }
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        n=matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                {
                    solve(matrix, i, j);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==-1)
                {
                    matrix[i][j]=1;
                }
            }
        }
    }
};

//**********************************************************************************************************

// Solution- Using only 1-D vector of length row and column to mark which row or column neeeds to be 1. Then checking this vector 
// and modifying the matrix

class Solution
{   
    public:
    int n,m;
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        n=matrix.size(), m=matrix[0].size();
        vector<int>row(n,0), col(m,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j]=1;
                }
            }
        }
    }
};
