class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto [rd, cd] : directions){
                int nr = r+rd, nc = c+cd;

                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && image[nr][nc] == originalColor){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        
        return image;
    }
};