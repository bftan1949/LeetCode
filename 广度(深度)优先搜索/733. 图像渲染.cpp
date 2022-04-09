class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //广度优先
        int initNum = image[sr][sc];
        int row = image.size(), col = image[0].size();
        stack<pair<int, int>> pixels;
        pair<int, int> pixel;

        image[sr][sc] = newColor;
        pixels.push(pair<int, int>{sr, sc});
        while (pixels.size() > 0) {
            pixel = pixels.top();
            pixels.pop();
            if (pixel.first + 1 < row && image[pixel.first + 1][pixel.second] == initNum) {
                pixels.push(pair<int, int>{pixel.first + 1, pixel.second});
                image[pixel.first + 1][pixel.second] = newColor;
            }
            if (pixel.first - 1 >= 0 && image[pixel.first - 1][pixel.second] == initNum) {
                pixels.push(pair<int, int>{pixel.first - 1, pixel.second});
                image[pixel.first - 1][pixel.second] = newColor;
            }
            if (pixel.second + 1 < col && image[pixel.first][pixel.second + 1] == initNum) {
                pixels.push(pair<int, int>{pixel.first, pixel.second + 1});
                image[pixel.first][pixel.second + 1] = newColor;
            }
            if (pixel.second - 1 >= 0 && image[pixel.first][pixel.second - 1] == initNum) {
                pixels.push(pair<int, int>{pixel.first, pixel.second - 1});
                image[pixel.first][pixel.second - 1] = newColor;
            }
        }
        return image;
    }
};
