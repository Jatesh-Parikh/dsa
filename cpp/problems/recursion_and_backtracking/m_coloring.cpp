// Time Coplexity - O(n * m ^ n), where n = number of nodes and m is the number of colors
// Space Complexity - O(n)
// Auxiliary Space - O(n)

#include <vector>

using namespace std;

class Solution {
    private:
    bool is_safe(int node, vector<int>& color, vector<vector<int>>& graph, int n, int current_color) {
        for (int k = 0; k < n; k++) {
            if (k != node && graph[k][node] == 1 && color[k] == current_color) return false;
        }
        return true;
    }

    bool solve(int node, vector<int>& color, vector<vector<int>>& graph, int n, int m) {
        if (node == n) {
            return true;
        }

        for (int i = 1; i <= m; i++) {
            if (is_safe(node, color, graph, n, i)) {
                color[node] = i;
                if (solve(node + 1, color, graph, n, m)) {
                    return true;
                } else {
                    color[node] = 0;
                }
            }
        }

        return false;
    }

    public:
    bool m_coloring(vector<vector<int>>& graph, int n, int m) {
        vector<int> color(n, 0);
        
        if(solve(0, color, graph, n, m)) return true;
        
        return false;
    }
};