/*
You are given an array of size N. Rearrange the given array in-place such that all the negative numbers occur before all non-nagative numbers.
(Maintain the order of all -ve and non-negative numbers as given in the original array).
Example 1:
Input:
N = 4
Arr[] = {-3, 3, -2, 2}
Output:
-3 -2 3 2
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 3, 2. 
Example 1:
Input:
N = 4
Arr[] = {-3, 1, 0, -2}
Output:
-3 -2 1 0
Explanation:
In the given array, negative numbers
are -3, -2 and non-negative numbers are 1, 0.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function Rearrange() which takes the array Arr[] and its size N as inputs and returns 
the array after rearranging with spaces between the elements of the array.
Expected Time Complexity: O(N. Log(N))
Expected Auxiliary Space: O(Log(N))
Constraints:
1 ≤ N ≤ 105
-109 ≤ Elements of array ≤ 109
*/

//Solution using mergesort. TC-O(NlogN), Space-O(log(N))

class Solution
{
    public:
        void merge(int arr[], int left, int mid, int right)
        {
            int i=left;
            while(i<=mid&&arr[i]<0)
            {
                i++;
            }
            int j=mid+1;
            while(j<=right&&arr[j]<0)
            {
                j++;
            }
            int k=i, l=j-1, tmp=mid;
            while(i<tmp)
            {
                swap(arr[i++], arr[tmp--]);
            }
            tmp=mid+1;
            j--;
            while(tmp<j)
            {
                swap(arr[tmp++], arr[j--]);
            }
            while(k<l)
            {
                swap(arr[k++], arr[l--]);
            }
        }
        void mergesort(int arr[], int left, int right)
        {
            if(left<right)
            {
                int m=left+(right-left)/2;
                mergesort(arr, left, m);
                mergesort(arr, m+1, right);
                merge(arr, left, m, right);
            }
        }
        void Rearrange(int arr[], int n)
        {
            mergesort(arr, 0, n-1);
        }
};

// Solution using brute force method. TC-O(N), Space- O(N) better TC than mergesort

class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            vector<int>pos, neg;
            int i=0, j=0;
            while(i<n)
            {
                if(arr[i]>=0)
                {
                    pos.push_back(arr[i]);
                }
                else
                {
                    neg.push_back(arr[i]);
                }
                i++;
            }
            for(int i=0; i<neg.size(); i++)
            {
                arr[i]=neg[i];
            }
            for(int i=neg.size(); i<n; i++)
            {
                arr[i]=pos[j];
                j++;
            }
        }
};
