/*
Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.
Example 2:

Input:
s = "sdfs"
Output: 
0
Explanation: 
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
You do not have to take any input or print anything. You need to complete the function checkPangram() that takes a 
string as a parameter and returns true if the string is a Panagram, or else it returns false.

Expected Time Complexity: O( |s| )
Expected Auxiliary Space: O(1)
|s| denotes the length of the input string.

Constraints:
1 ≤ |s| ≤ 104
Both Uppercase & Lowercase are considerable

*/

// Solution

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int>arr(26,0);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
                continue;
            int tmp=tolower(s[i]);
            if(tmp>=('a'+0) && tmp<=('z'-0))
                arr[tmp-'a']++;
        }
        for(int i=0; i<26; i++)
            if(arr[i]==0)
                return false;
        return true;
    }

};
