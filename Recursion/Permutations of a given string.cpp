/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector 
of string in lexicographical order.

Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n! * n)

Constraints:
1 <= length of string <= 5
*/

// Solution using recursion

class Solution
{
	public:
	    void solve(string s, vector<string>&ans, string tmp, vector<int>f)
	    {
	        if(tmp.length()==s.length())
	        {
	            ans.push_back(tmp);
	        }
	        for(int i=0; i<s.length(); i++)
	        {
	            if(i!=0 && s[i]==s[i-1] && !f[i-1]) continue;  // This line to avoid duplicate values. Here !f[i-1] we see we have taken NOT of f[i-1] which means 
                                                             // with the duplicate value we are again starting a new string so the previous duplicate value is not visited
                                                             // which will create duplicate value. If f[i-1] would have visited earlier then this would not have created a 
                                                             //new string because it would have considered the duplicate value in the later index which is valid 
                                                             // example- AABC, BAAC is valid.
	            if(!f[i])
	            {
	                tmp+=s[i];
	                f[i]=1;
	                solve(s, ans, tmp, f);
	                f[i]=0;
	                tmp.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    string tmp="";
		    string s=S;
		    sort(s.begin(), s.end());
		    vector<int>f(S.length(), 0);
		    solve(s, ans, tmp, f);
		    return ans;
		    // Code here there
		}
};

// Solution using swap----------------------------------------------

class Solution
{
	public:
      // Taking by reference
//     void solve(string &s, vector<string>&ans, int index)
// 	    {
// 	        if(index==s.length())
// 	        {
// 	            ans.push_back(s);
// 	            return;
// 	        }
// 	        for(int i=index; i<s.length(); i++)
// 	        {
// 	            if(i!=index && s[i]==s[index]) continue;
// 	            swap(s[i], s[index]);
// 	            solve(s, ans, index+1);
// 	            //swap(s[i], s[index]); // This doesnot work for keeping order sorted
// 	        }
//                  Example- 123   when we have 1 and 3 swap then it becomes 321 so permutatuin is 321 and 312 but we need in lexicographically. So after 1 and 3 swap 
//                  Example- ABC when index =0 and for loop is i=2, then if we swap A,C then it becomes CBA which will give lexicographically wrong solution. 
//                  So when the loop gets over for index =0 and for loop i=1, we had BCA where index value is index=1, so after completion of loop in previus recursion 
//                  for B we do swapping from i=s.length()-1 to i>index
//                  which will give from BAC to swap(i,index) i.e swap(2,1)=>BAC and then when index =0 and for loop is i=2 we swap (B,C)=> CAB 
//                  which will give correct answer
// 	        for(int i=s.length()-1; i>index; i--)
// 	        {
// 	            swap(s[i], s[index]);
// 	        }
// 	    }
  
  
	    void solve(string s, vector<string>&ans, int index)
	    {
	        if(index==s.length())
	        {
	            ans.push_back(s);
	            return;
	        }
	        for(int i=index; i<s.length(); i++)
	        {
	            if(i!=index && s[i]==s[index]) continue;  // Avoid duplicates of same string
	            swap(s[i], s[index]);
	            solve(s, ans, index+1);
	        }
	       // for(int i=s.length()-1; i>index; i--)  This line is needed if we pass the string or vector by reference, string where we are swapping.                         
	       // {                                      Because we might lose the sorted order 
	       //     swap(s[i], s[index]);
	       // }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    string tmp="";
		    string s=S;
		    sort(s.begin(), s.end());
		    //vector<int>f(S.length(), 0);
		    solve(s, ans, 0);
		    return ans;
		    // Code here there
		}
};
