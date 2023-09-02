class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [cc1, cc2] = q.front();
            q.pop();

            if (cc1 + cc2 == targetCapacity) {
                return true;
            }

            // Fill jug 1
            int a = jug1Capacity;
            int b = cc2;
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }

            // Fill jug 2
            a = cc1;
            b = jug2Capacity;
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }

            // Pour 1 to 2
            a = max(0, cc1 - (jug2Capacity - cc2));
            b = min(jug2Capacity, cc1 + cc2);
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }

            // Pour 2 to 1
            a = min(jug1Capacity, cc1 + cc2);
            b = max(0, cc2 - (jug1Capacity - cc1));
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }

            // Empty jug 1
            a = 0;
            b = cc2;
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }

            // Empty jug 2
            a = cc1;
            b = 0;
            if (visited.find({a, b}) == visited.end()) {
                q.push({a, b});
                visited.insert({a, b});
            }
        }

        return false;
    }
};
