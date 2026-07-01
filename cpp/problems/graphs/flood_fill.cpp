#include <vector>
using namespace std;

class Solution {
    private:
        void dfs(
            int row, 
            int col, 
            vector<vector<int>>& ans, 
            vector<vector<int>>& image, 
            int new_color, 
            int delta_row[], 
            int delta_col[], 
            int ini_color
        ) {
            ans[row][col] = new_color;

            int n = image.size();
            int m = image[0].size();

            for (int i = 0; i < 4; i++) {
                int new_row = row + delta_row[i];
                int new_col = col + delta_col[i];

                if (
                    new_row >= 0 && 
                    new_row < n && 
                    new_col >= 0 && 
                    new_col < m && 
                    image[new_row][new_col] == ini_color && 
                    ans[new_row][new_col] != new_color
                ) {
                    dfs(new_row, new_col, ans, image, new_color, delta_row, delta_col, ini_color);
                }
            }
        } 

    public:
        vector<vector<int>> flood_fill(vector<vector<int>>& image, int sr, int sc, int new_color) {
            int ini_color = image[sr][sc];

            if (ini_color == new_color) {
                return image;
            }

            vector<vector<int>> ans = image;
            
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};

            dfs(sr, sc, ans, image, new_color, delta_row, delta_col, ini_color);
            
            return ans;
        }    
};