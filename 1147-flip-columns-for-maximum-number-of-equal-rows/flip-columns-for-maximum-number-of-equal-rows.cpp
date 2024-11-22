class Solution {
public:
    // Time Complexity: O(mn)
    // Space complexity: O(mn)

    // Helper function to convert a vector row to its string representation.
    // Time complexity: O(n)
    // Space complexity: O(n)
    string vectorToString(const vector<int>& row) {
        string row_key = "";
        for(const int& num : row) {
            row_key = row_key + to_string(num) + ",";
        }
        return row_key;
    }
    // Helper function to invert a row vector.
    // Time complexity: O(n)
    // Space complexity: O(n)
    vector<int> flippedRow(const vector<int>& row) {
        vector<int> flippedRow = row;

        for (int& num: flippedRow) {
            num = ((num == 1) ? 0 : 1);
        }
        return flippedRow;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        int maxCount = 1;

        // This for-loop will run m times thus the time complexity is O(m*n)
        for (vector<int> row: matrix) {
            // Convert the row to its string representation.
            string row_key = vectorToString(row);
            // Check if row[0] == 1 and invert if true.
            if (row[0] == 1) {
                row_key = vectorToString(flippedRow(row));
            }
            count[row_key]++;
        }
        // Iterate over the dictionary.
        for (const auto& row_key : count) {
            maxCount = max(maxCount, row_key.second);
        }
        return maxCount;
    }
};