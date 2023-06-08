/*
Given two integers N (1<=N<=9) and K. Find the kth permutation sequence of first N natural numbers. Return the answer in string format.
Example 1:
Input: N = 4, K = 3
Output: 1324
Explanation: 
Permutations of first 4 natural numbers:
1234,1243,1324,1342,1423,1432.....
So the 3rd permutation is 1324. 
Example 2:
Input: N = 3, K = 5
Output: 312
Explanation: 
Permutations of first 3 natural numbers:
123,132,213,231,312,321.
So the 5th permutation is 312. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function kthPermutation() which takes two integers N and K as input parameters and returns a 
string denoting the kth permutation.
Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
Constraints:
1 <= N <= 9
1 <= K <= N!
*/

//Solution
class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        string ans="";
        vector<int>numbers;
        int fact=1;
        for(int i=1; i<n; i++)
        {
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k=k-1;
        while(true)
        {
            ans+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0)
            {
                break;
            }
            k=k%fact;
            fact=fact/numbers.size();
        }             
        return ans;
    }
};
