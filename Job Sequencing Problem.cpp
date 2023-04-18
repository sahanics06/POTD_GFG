/*
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns an array ans[ ] in which ans[0] contains the count of jobs and ans[1] contains maximum profit.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

class Solution 
{
    public:
    static bool bysec(Job &a1, Job &a2)
    {
            return a1.dead<a2.dead;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, bysec);
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n; i++)
        {
            if(arr[i].dead>pq.size())
            {
                pq.push(arr[i].profit);
            }
            else if(arr[i].dead==pq.size())
            {
                if(arr[i].profit>pq.top())
                {
                    pq.pop();
                    pq.push(arr[i].profit);
                }
            }
        }
        ans.push_back(pq.size());
        int p=0;
        while(pq.size())
        {
            int tmp=pq.top();
            p+=tmp;
            pq.pop();
        }
        ans.push_back(p);
        return ans;
    } 
};
