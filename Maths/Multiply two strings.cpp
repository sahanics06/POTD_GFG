/*
Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. 
There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253
Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which 
takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

Constraints:
1 ≤ length of s1 and s2 ≤ 103

*/

// Solution 

class Solution{
  public:
    /*You are required to complete below function */
    string multiply(string &s1, char ch, int pos) // Multiply one string to one character of other string
    {
        int n=s1.length();
        int num=ch-'0';
        int carry=0;
        string ans="";
        for(int i=n-1; i>=pos; i--)
        {
            int t=s1[i]-'0';
            int prod=t*num;
            prod+=carry;
            carry=prod/10;
            int tx=prod%10;
            ans.push_back(tx+'0');
        }
        if(carry) ans.push_back(carry+'0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string add(string &s1, string &s2, int count) // Addition after every multiplication
    {
        while(count)
        {
            s2.push_back('0');
            count--;
        }
        int i=s1.length()-1, j=s2.length()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry==1)
        {
            int sum=carry;
            if(i>=0) sum+=(s1[i]-'0');
            if(j>=0) sum+=(s2[j]-'0');
            int num=sum%10;
            carry=sum/10;
            i--;
            j--;
            ans.push_back(num+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n=s1.length(), m=s2.length();
       bool neg=false;
       int i=0, j=0;
       if(s1[i]=='-')
       {
           neg=!neg;
           i++;
       }
       while(i<n && s1[i]=='0') i++;
       if(s2[j]=='-')
       {
           neg=!neg;
           j++;
       }
       
       while(j<m && s2[j]=='0') j++;
       if(i==n || j==m) return "0";
       int xero=0;
       string ans=multiply(s1, s2[m-1], i);
       for(int k=m-2; k>=j; k--)
       {
           string tmp=multiply(s1,s2[k], i);
           xero++; // After every multiplication the zero increases by 1 from right to left.
           ans=add(ans,tmp,xero);
       }
       i=0; 
       while(i<ans.length() && ans[i]=='0') // Pass the preceding zero
       {
           i++;
       }
       ans=ans.substr(i);
       if(neg)
            return '-'+ans;
        
        return ans;
       
    }

};
