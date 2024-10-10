
#include <bits/stdc++.h>
using namespace std;



class Solution {
private:
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        vis[node] = 1; // Mark the current node as visited
        for (auto it : adjLs[node]) { // Iterate through adjacent nodes
            if (!vis[it]) { // If the adjacent node has not been visited
                dfs(it, adjLs, vis); // Recursive DFS call
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create adjacency list from the adjacency matrix
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) { // If there is an edge and not the same node
                    adjLs[i].push_back(j); // Add edge to adjacency list
                    adjLs[j].push_back(i); // Add edge for undirected graph
                }
            }
        }

        int vis[V + 1] = {0}; // Visited array
        int count = 0; // Counter for connected components

        // Perform DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) { // If the node has not been visited
                count++; // Increment the count of provinces
                dfs(i, adjLs, vis); // Start DFS from this node
            }
        }

        return count; // Return the total number of provinces
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int V, x;
        cin >> V; // Number of vertices
        
        vector<vector<int>> adj; // Adjacency matrix
        
        // Input the adjacency matrix
        for (int i = 0; i < V; i++) {
            vector<int> temp;
            for (int j = 0; j < V; j++) {
                cin >> x;
                temp.push_back(x); // Add each element to the temporary vector
            }
            adj.push_back(temp); // Add the row to the adjacency matrix
        }

        Solution ob; // Create Solution object
        cout << ob.numProvinces(adj, V) << endl; // Output the number of provinces
    }
    return 0;
}
// } Driver Code Ends
