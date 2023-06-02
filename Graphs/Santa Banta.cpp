/*
Santa is still not married. He approaches a marriage bureau and asks them to hurry the process. The bureau checks the list of eligible girls of size N and hands it over to 
Santa. Santa being conscious about his marriage is determined to find a girl with maximum connections so that he can gather more information about her. Accordingly, he 
looks to figure out the maximum number of girls (from the list) who know each other to achieve the above purpose.
In order to finalize the girl, he needs to find the Kth prime. Where k = largest group of girls who know each other. Considering Santa's poor knowledge of Maths, he seeks 
Banta's help for the answer. Now you, a fan of Santa Banta Jokes, take this prestigious opportunity to solve the problem.

In case no of connections is zero, print "-1". Here the connection between girls is represented by a 2-D array arr of dimension M*2, where M is the number of connections.

Note :
1. Suppose girl "a" knows girl "b" and girl "b" knows girl "c", then girl "a" also knows girl "c". Transitivity holds here.
2. Consider 1 as a composite number.
3. For precompute function given in the template you just have to complete it and use it wherever required, do not call it again and again, it is already being called by 
driver function before executing test cases. 

Example 1:

Input : 
arr[] = {{1,2},{2,3},{3,4},{4,5},{6,7},{9,10}}
N = 10 and M = 6
Output : 
11
Explanation:
Here in this graph there are 4 groups. 
In 1st group: (1 -> 2 -> 3 -> 4 -> 5) are 
there. In 2nd group: (6 -> 7) are there.
In 3rd group: (8) is there.
In 4th group: (10 -> 9) are there.
In these 4 group the maximum number of 
value is 5. So, K = 5 and the 5th prime number 
is 11. Return 11.
Example 2:

Input : 
arr[ ] = {{1, 2}}
N = 2 and M = 1 
Output : 
3
Explanation:
In this Example there will only be a 
single group of 2 girls, and hence the 
value of K is 2, The 2nd prime is 3.
Your Task:

This is a function problem. The input is already taken care of by the driver code. You only need to complete the function helpSanta() that takes a number of girls (n), 
a number of connections (m), an adjacency list of girls connections (g), and return the Kth prime no if there are no connections then return -1. The driver code takes care 
of the printing.
Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N + M).
Constraints:
1 ≤ n ≤ 105
0 ≤ m ≤ 105
1 ≤ u, v ≤ n
*/

// Solution using Union and finding number of nodes in a component

class Solution{
public:
    vector<int>rank;
    vector<int>parent;
    vector<int>child;
    int MAX_SIZE=1e6;
    vector<int> primes;
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
        {
            return;
        }
        if(rank[x]>rank[y])
        {
            parent[y]=x;
            child[x]+=child[y];
        }
        else if(rank[y]>rank[x])
        {
            parent[x]=y;
            child[y]+=child[x];
        }
        else
        {
            parent[x]=y;
            child[y]+=child[x];
            rank[y]++;
        }
        
    }
    void precompute(){
        // using sieve of eratosthenes in O(N) TC
        vector<bool> isPrime(MAX_SIZE,true);
        vector<int> SPF(MAX_SIZE);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<MAX_SIZE;i++){
            if(isPrime[i]){
                primes.push_back(i);
                SPF[i]=i;
            }
            for(int j=0; j<primes.size() and i*primes[j]<MAX_SIZE and primes[j]<=SPF[i]; j++){
                isPrime[i*primes[j]]=false;
                SPF[i*primes[j]]=primes[j];
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        rank.resize(n+1);
        parent.resize(n+1);
        child.resize(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
            rank[i]=1;
            child[i]=1;
        }
        int count=0;
        for(int i=1; i<=n; i++)
        {
            for(auto x:g[i])
            {
                Union(i,x);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(count<child[i])
            {
                count=child[i];
            }
        }
        if(count==1)
            return -1;
        //cout<<count;
        return primes[count-1];
    }
};

// Solution using DFS

class Solution{
public:
    int MAX_SIZE=1e6;
    vector<int> primes;
    int dfs(vector<vector<int>>&g, vector<int>&vis, int i)
    {
        vis[i]=1;
        int tmp=1;
        for(auto x:g[i])
        {
            if(vis[x]==-1)
            tmp+=dfs(g, vis, x);
        }
        return tmp;
    }
    void precompute(){
        // using sieve of eratosthenes in O(N) TC
        vector<bool> isPrime(MAX_SIZE,true);
        vector<int> SPF(MAX_SIZE);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i<MAX_SIZE;i++){
            if(isPrime[i]){
                primes.push_back(i);
                SPF[i]=i;
            }
            for(int j=0; j<primes.size() and i*primes[j]<MAX_SIZE and primes[j]<=SPF[i]; j++){
                isPrime[i*primes[j]]=false;
                SPF[i*primes[j]]=primes[j];
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int>vis(n+1, -1);
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==-1)
                {
                    int tmp=dfs(g, vis, i);
                    ans=max(ans, tmp);
                }
        }
        if(ans==1)
            return -1;
        return primes[ans-1];
    }
};
