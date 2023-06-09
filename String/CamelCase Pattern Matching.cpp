/*
Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase characters only.

Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

Example 1:

Input:
N=3
Dictionary=["WelcomeGeek",
"WelcomeToGeeksForGeeks","GeeksForGeeks"]
Pattern="WTG"
Output:
WelcomeToGeeksForGeeks
Explanation:
Since only WelcomeToGeeksForGeeks matches 
the pattern, it is the only answer.
Example 2:

Input:
N=8
Dictionary=["Hi","Hello","HelloWorld",
"HiTech","HiGeek","HiTechWorld",
"HiTechCity","HiTechLab"]
Pattern="HA"
Output:
-1
Explanation:
Since the pattern matches none of the words
of the string,the output is -1.
Your Task:
You don't need to read input or print anything. Your Task is to complete the function CamelCase() which takes an integer N, a Vector of strings Dictionary and a string Pattern and returns the strings in the dictionary that match the pattern, if not found any return -1.

Expected Time Complexity: O(N*|S|) S=Longest string in Dictionary
Expected Auxillary Space: O(26*N)

Constraints:
1<=N<=1000
1<=|S|<=100
1<=|Pattern|<=|S|<=100
S is the longest word in Dictionary.
*/
// Solution- Store the capital letter string and its index in vector and then compare with pattern.
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string>ans;
        vector<pair<string, int>>dict;
        for(int i=0; i<N; i++)
        {
            string tmp=Dictionary[i];
            string t="";
            for(int j=0; j<tmp.length(); j++)
            {
                if(tmp[j]>=65 && tmp[j]<=90)
                {
                    t.push_back(tmp[j]);
                }
            }
            dict.push_back({t, i});
        }
        for(int i=0; i<dict.size(); i++)
        {
            string tmp=dict[i].first;
            int j=0, n=Pattern.length(), f=0;
            if(tmp.length()<n)    continue;
            while(j<n && j<tmp.length())
            {
                if(tmp[j]!=Pattern[j])
                {
                    f=1;
                }
                j++;
            }
            if(f==0)
            {
                ans.push_back(Dictionary[dict[i].second]);
            }
        }
        if(ans.size()==0)
        {
            ans.push_back("-1");
        }
        return ans;
    }
};

// Solution without using space

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string>ans;
        int n=Pattern.length();
        for(auto x:Dictionary)
        {
            int k=0;
            for(int i=0; i<x.length(); i++)
            {
                if(k<n&& x[i]==Pattern[k])
                {
                    k++;
                }
                else if(isupper(x[i]))
                {
                    break;
                }
            }
            if(k==n)
            {
                ans.push_back(x);
            }
        }
        if(ans.size()==0)
            return {"-1"};
        return ans;
    }
};
