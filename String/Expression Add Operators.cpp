/*
Given a string S that contains only digits (0-9) and an integer target, return all possible strings to insert the binary operator ' + ', ' - ', or ' * ' between 
the digits of S so that the resultant expression evaluates to the target value.
Note:
Operands in the returned expressions should not contain leading zeros. For example, 2 + 03 is not allowed whereas 20 + 3 is fine. 
It is allowed to not insert any of the operators.
If no solution is found, return an empty string array.
Example 1:

Input:
S = "123"
target = 6
Output: { "1*2*3", "1+2+3"}
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:
Input:
S = "3456237490"
target = 9191
Output: { } 
Explanation: There are no expressions that can be created from "3456237490"  to evaluate to 9191.
Example 3:
Input:
S = "12"
target = 12
Output: { "12"} 
Explanation: S itself matches the target. No other strings are possible.
Your Task:
You don't need to read input or print anything. Your task is to complete the function addOperators() which takes string S and integer 
target as parameters and returns a list of strings that contains all valid possibilities.
Expected Time Complexity: O(|S|*4|S|)
Expected Auxiliary Space: O(|s|*3|S|)
Constraints:
1 ≤ |S| ≤ 10
S consists of only digits.
-231 ≤ target ≤ 231-1
*/

//Solution

class Solution {
  public:
    void solve(string s, int target, string newString, int val, int pre, int index, vector<string>&ans)
    {
        
        if(index==s.length())
        {
            if(val==target)
            {
                ans.push_back(newString);
            }
            return;
        }
        string tmp="";
        int n=0;
        for(int i=index; i<s.length(); i++)
        {
            n=10*n+(s[i]-'0');
            tmp+=s[i];
            if(index==0)
            {
                solve(s, target, tmp, n, n, i+1, ans);// Since index is 0 so no operation done previously
            }
            else
            {
                solve(s, target, newString+"+"+tmp, val+n, n, i+1, ans);
                solve(s, target, newString+"-"+tmp, val-n, -n, i+1, ans);
                solve(s, target, newString+"*"+tmp, val-pre+pre*n, pre*n, i+1, ans);
            }
            if(s[index]=='0')
            {
                break;// This line is for using '0' for only one time so that next number dont form with leading zero
            }
        }
    }
    vector<string> addOperators(string S, int target) {
        // code here
        vector<string>ans;
        string tmp="";
        solve(S, target, tmp, 0, 0, 0, ans);
        return ans;
    }
};
