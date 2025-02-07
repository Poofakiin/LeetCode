class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, unordered_set<int>> colorBalls;
        vector<int> result;
        
        for (const auto& query : queries) {
            int ball = query[0], color = query[1];
            

            if (ballColor.count(ball)) {
                int oldColor = ballColor[ball];
                colorBalls[oldColor].erase(ball);
                if (colorBalls[oldColor].empty()) {
                    colorBalls.erase(oldColor);
                }
            }
            
            ballColor[ball] = color;
            colorBalls[color].insert(ball);
            
            result.push_back(colorBalls.size());
        }
        
        return result;
    }
};