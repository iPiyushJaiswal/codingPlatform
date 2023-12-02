/*Problem GFG (Easy)

Brothers From Different Roots


Question link: https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

---------------------------

Logic: Inorder

---------------------------

Complexity: 

Method 1 : Inorder

Time Complexity= O(2n)

Space Complexity= O(2n) 

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Inorder
*/

class Solution
{
public:
    void inorder(Node* root,vector<int>&inord)
    {
        if(!root)
        return;
        inorder(root->left,inord);
        inord.push_back(root->data);
        inorder(root->right,inord);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>inord1;
        vector<int>inord2;
        inorder(root1,inord1);
        inorder(root2,inord2);
        int ans=0;
        int n=inord1.size();
        int i=0;
        int j=inord2.size()-1;
        while(i<n && j>=0)
        {
            int val=x-inord1[i];
            if(val<0)
            break;
            if(inord2[j]>val)
            j--;
            else if(inord2[j]==val)
            {
                ans++;
                i++;
                j--;
            }
            else
            i++;
        }
        return ans;
    }
};