/*Problem GFG (Medium)

Insert and Search in a Trie


Question link:	https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

---------------------------

Logic: Trie 

---------------------------

Complexity: 

Method 1 : Trie 

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Trie 
*/

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            int n=key.size();
            TrieNode* temp=root;
            for(int i=0;i<n;i++)
            {
                if(temp->children[key[i]-'a']==NULL)
                {
                    temp->children[key[i]-'a']=new TrieNode();
                }
                temp=temp->children[key[i]-'a'];
            }
            temp->isLeaf=true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
            int n=key.size();
            TrieNode* temp=root;
            for(int i=0;i<n;i++)
            {
                if(temp->children[key[i]-'a']==NULL)
                return false;
                temp=temp->children[key[i]-'a'];
            }
            return (temp->isLeaf);
        }
};