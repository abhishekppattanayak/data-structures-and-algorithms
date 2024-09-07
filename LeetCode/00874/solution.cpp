// LeetCode 874 Walking Robot Simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // time complexity : O(nm logk)
        // space complexity : O(k)
        
        map<pair<int, int>, bool> m;

        for (const vector<int>& o : obstacles)
            m[{o[0], o[1]}] = true;

        int x = 0, y = 0;

        vector<pair<int, int>> delta = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int idx = 0;
        int maxDistSq = 0;

        for (int command : commands) {
            if (command == -2) 
                idx = (idx + 1) % 4;

            else if (command == -1) 
                idx = (idx - 1 + 4) % 4;
                
            else {

                for (int k = 0; k < command; ++k) {
                    int newX = x + delta[idx].first;
                    int newY = y + delta[idx].second;
                    if (m.find({newX, newY}) == m.end()) {
                        x = newX;
                        y = newY;
                        maxDistSq = max(maxDistSq, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxDistSq;
    }
};