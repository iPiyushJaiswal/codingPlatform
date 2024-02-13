/*Problem GFG (Medium)

Clone an Undirected Graph


Question link:	https://www.geeksforgeeks.org/problems/clone-graph/1

---------------------------

Logic: BFS

---------------------------

Complexity: 

Method 1 : BFS

Time Complexity= O(v+e)

Space Complexity= O(v) unordered_map
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
        return NULL;
        queue<Node*>q;
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,int>vis;
        q.push(node);
        vis[node]++;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                mp[temp]=new Node(temp->val);
                for(auto it:temp->neighbors)
                {
                    if(vis.find(it)==vis.end())
                    {
                        q.push(it);
                        vis[it]++;
                    }
                }
            }
        }
        vis.clear();
        q.push(node);
        vis[node]++;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                for(auto it:temp->neighbors)
                {
                    if(vis.find(it)==vis.end())
                    {
                        q.push(it);
                        vis[it]++;
                    }
                    mp[temp]->neighbors.push_back(mp[it]);
                }
            }
        }
        return mp[node];
    }
};