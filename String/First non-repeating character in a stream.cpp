/*
Given an input stream A of n characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has 
appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. 
If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
 

Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after 
processing the input stream.
 

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
 

Constraints:
1 <= n <= 105
  */

// Solution using queue. Here we have to find answer inplace or we can do s+='new character' but if we write s=s+'new character' then we will get TLE as this will also take
//  O(N) time for creating new string which will lead O(N^2) rather then O(N).

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int arr[26]={0};
		    queue<char>q;
		    for(int i=0; i<A.length(); i++)
		    {
		        arr[A[i]-'a']++;
		        if(arr[A[i]-'a']==1)
		        {
		            q.push(A[i]);
		        }
		        while(!q.empty() && arr[q.front()-'a']!=1)
		        {
		            q.pop();
		        }
		        if(q.size()==0)
		        {
		            A[i]='#';
		        }
		        else
		        {
		            A[i]=q.front();
		        }
		    }
		    return A;
		}

};
