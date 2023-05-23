/*
Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
In case the kth smallest element doesn't exist return -1. 

Example 1:

Input:
n = 2, q = 3
range[] = {{1, 4}, {6, 8}}
queries[] = {2, 6, 10}
Output: 
2 7 -1
Explanation: 
After combining the given ranges, 
the numbers become 1 2 3 4 6 7 8. As here 2nd 
element is 2, so we print 2. As 6th element is 
7, so we print 7 and as 10th element doesn't 
exist, so weprint -1.
Example 2:

Input:
n = 2, q = 2
range[] = {{2, 6}, {5, 7}} 
queries[] = {5, 8}
Output: 
6 -1
Explantion: 
After combining the ranges, we'll take Union of 
range= {2,3,4,5,6,7}, here  5th smallest number 
will be 6 and 8th smallest number does not exists.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function kthSmallestNum() which takes a n * 2 array denoting the ranges and an array denoting the queries.

Expected Time Complexity: O(nlogn+q*n)
Expected Auxiliary Space: O(q)

Constraints:
1 <= n <= 103
1 <= range[i][0] <= range[i][1] <= 2*109
1 <= q <= 500
1 <= queries[i] <= 2*109
*/

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<int>ans;
        sort(range.begin(), range.end());
        for(int i=0; i<q; i++)
        {
            int c=0, k=queries[i];
            int left=range[0][0], right=range[0][1];
            c=right-left+1;
            if(c>=k)
            {
                //cout<<i<<" "<<k<<" "<<left+k-1<<endl;
                ans.push_back(left+k-1);
                continue;
            }
            for(int j=1; j<n; j++)
            {
                if(range[j][1]<=right)
                {
                    continue;
                }
                else
                {
                    if(range[j][0]>right)
                    {
                        int t=c;
                        c+=range[j][1]-range[j][0]+1;
                        if(c>=k)
                        {
                            ans.push_back(range[j][0]+k-t-1);
                            break;
                        }
                    }
                    else
                    {
                        int t=c;
                        c+=range[j][1]-right;
                        if(c>=k)
                        {
                            ans.push_back(right+k-t);
                            break;
                        }
                    }
                    right=range[j][1];
                }
                
            }
            if(c<k)
            {
                ans.push_back(-1);
            }
        }
        return ans;
        
    } 
};

// Solution -- All the intervals which can be merged into one interval are merged and then done the rest part.

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        vector<pair<int, int>>v;
        vector<int>ans;
        sort(range.begin(), range.end());
        pair<int, int>tmp;
        tmp={range[0][0], range[0][1]};
        for(int i=1; i<n; i++)
        {
            if(tmp.second>=range[i][0])
            {
                tmp.second=max(tmp.second, range[i][1]);
            }
            else
            {
                v.push_back({tmp.first, tmp.second});
                tmp={range[i][0], range[i][1]};
            }
        }
        v.push_back({tmp.first, tmp.second});
        n=v.size();
        for(int i=0; i<q; i++)
        {
            int c=0, k=queries[i];
            int left=v[0].first, right=v[0].second;
            c=right-left+1;
            if(c>=k)
            {
                ans.push_back(left+k-1);
                continue;
            }
            for(int j=1; j<n; j++)
            {
                int t=c;
                c+=(v[j].second-v[j].first+1);
                if(c>=k)
                {
                    ans.push_back(v[j].first+k-t-1);
                    break;
                }
            }
            if(c<k)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    } 
};
