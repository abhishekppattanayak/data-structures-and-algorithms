# 874 Walking Robot Simulation

You can checkout the problem statemment [here](https://leetcode.com/problems/walking-robot-simulation/).

## Thought Process

We are given two inputs 
  1. `commands`: array/list of commands that needs to be executed sequentially
  2. `obstacles`: 2D array/list that indicates where obstacles are present

We are storing all obstacles in a `map` to minimize the lookup time from `O(n)` to `O(log k)`.

Next, we initialize robot's starting position to `(0,0)`, and `delta` to indicate current direction of robot's movement.

Next, we iterate through all the commands
  1. if command is `-2` or `-1`, we appropriately change the direction robot is facing, and
  2. if command is `k`, then we move ahead one at time, and if we encounter a `obstacle` we end the loop and go to the next command
  3. we also store maximum distance reached so far in `maxDistSq`.

Finally, we return `maxDistSq`.

## [🔗Solution File](solution.cpp)

## Code Snippet 
```cpp
// cpp
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
```