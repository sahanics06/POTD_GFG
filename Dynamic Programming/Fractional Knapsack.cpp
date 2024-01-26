/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

Example 1:

Input:
N = 3, W = 50
value[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.000000
Explanation:
Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, 
to fit it into weight 20. so it becomes (120/30)*20=80, so the total weight becomes 60+100+80.0=240.0
Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
Example 2:

Input:
N = 2, W = 50
value[] = {60,100}
weight[] = {10,20}
Output:
160.000000
Explanation:
Take both the items completely, without breaking.
Total maximum value of item we can have is 160.00 from the given capacity of sack.
Your Task :
Complete the function fractionalKnapsack() that receives maximum capacity , array of structure/class and size N and 
returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= W <= 109
1 <= valuei, weighti <= 104

*/

// Solution Sort the array based on ratio value/weight  and then simple loop and add into answer

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a, Item b)
    {
        return (double)a.value/a.weight<(double)b.value/b.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        double ans=0;
        for(int i=n-1; i>=0; i--)
        {
            if(W>=arr[i].weight)
            {
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                double oneUnit = (double)arr[i].value/(double)arr[i].weight;
                ans+= (double)oneUnit*W;
                return ans;
            }
        }
        return ans;
    }
        
};
