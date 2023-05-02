/*
Given the root of a n-ary tree find the number of duplicate subtrees in the n-ary tree. Two trees are duplicates if they have the same structure with the same node values.

Example 1:

Input:
1 N 2 2 3 N 4 N 4 4 3 N N N N N

Output: 
2
Explanation: 
[4], [3] are duplicate subtree.
Example 2:

Input:
1 N 2 3 N 4 5 6 N N N N

Output: 
0
Explanation: 
No duplicate subtree found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function duplicateSubtreeNaryTree() which takes the root of the n-ary tree as input and returns an integer value as a number of duplicate subtrees.

Expected Time Complexity: O(n), n is the total no of nodes
Expected Space Complexity: O(n2)

Constraints:
   1 <= n < 103
   1 <= node.key< 103
   
*/

// Solution- While returning from leaf node we add one * at back which means one child for that parent. So if left and right child are present then parent
// node will receive left*right*. if we dont do this then for different structure also we will have same string. Example if a is parent of b and b is parent of c
// then string formed is abc and if a is parent of both b and c then also string formed is abc as because we append every child node to string and then return 
// to parent. Since whole structure has to be same for duplicate subtree. So for both cases we have same string so, we put star.

class Solution{
public:
    string solve(Node *root, unordered_map<string, int>&m)
    {
        if(root==NULL)
            return "";
        int val=root->data;
        string tmp=to_string(val);
        for(int i=0; i<root->children.size(); i++)
        {
            string t=solve(root->children[i], m);
            tmp+=t+'*';
        }
        m[tmp]++;
        return tmp;
        
    }
    int duplicateSubtreeNaryTree(Node *root){
        // Code here
        unordered_map<string, int>m;
        solve(root, m);
        int c=0;
        for(auto x:m)
        {
            if(x.second>1)
                c++;
        }
        // for(auto x:m)
        // {
        //     cout<<x.first<<"  "<<x.second<<endl;
        // }
        return c;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string p;
            getline(cin,p);
        }
        string str;
        getline(cin,str);
        stringstream st(str);
        vector<string> s;
        string y;
        while(st>>y){
            s.push_back(y);
        }
        N_ary_Tree *tree = new N_ary_Tree();
        Node *curr;
        queue<Node*> q;
        for(int i=0;i<s.size();i++){
            if (i == 0){
                curr=tree->add(stoi(s[0]));
            }
            else if(s[i] == " "){
                continue;
            }
            else if(q.size() and s[i] == "N"){
                curr = q.front();
                q.pop();
            }
            else if(s[i] != "N"){
                q.push(tree->add(stoi(s[i]), curr));
            }
        }
        Solution ob;
        int res = ob.duplicateSubtreeNaryTree(tree->root);
        cout<<res<<endl;
    }
}
