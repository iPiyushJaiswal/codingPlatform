/*Problem GFG (Medium)

K Sum Paths


Question link: https://www.geeksforgeeks.org/problems/k-sum-paths/1

---------------------------

Logic: 2 approach

---------------------------

Complexity: 

Method 1 : preorder

Time Complexity= O(n*h*h))

Space Complexity= O(h)

-----------------------------
Method 2 : Unordered Map Subarray sum equal to k 

Time Complexity= O(n)

Space Complexity= O(h)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: preorder
*/

class Solution{
  public:
  int mod=1e9 +7;
    void rec(Node* root,int k,vector<int>&path,int &ans)
    {
        if(!root)
        return;
        path.push_back(root->data);
        rec(root->left,k,path,ans);
        rec(root->right,k,path,ans);
        int sum=0;
        for(int i=path.size()-1;i>=0;i--)
        {
            sum+=path[i];
            if(sum==k)
            ans=(ans+1)%mod;
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int>path;
        int ans=0;
        rec(root,k,path,ans);
        return ans%mod;
    }
};

/*-------------------------------------------------------------
Method 2: Unordered Map Subarray sum equal to k 
*/

class Solution{
  public:
    void rec(Node* root,int k,unordered_map<int,int>&mp,int &ans,int &sum)
    {
        if(!root)
        return;
        sum+=root->data;
        if(mp.find(sum-k)!=mp.end())
        {
            ans=ans+mp[sum-k];
        }
        ++mp[sum];
        rec(root->left,k,mp,ans,sum);
        rec(root->right,k,mp,ans,sum);
        --mp[sum];
        sum-=root->data;
        if(mp[sum]==0)
        mp.erase(sum);
    }
    int sumK(Node *root,int k)
    {
        // code here
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=1;
        int sum=0;
        rec(root,k,mp,ans,sum);
        return ans;
    }
};