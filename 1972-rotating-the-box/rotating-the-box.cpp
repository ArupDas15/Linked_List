class Solution {
public:
    /*
    ALGORITHM
    1. We are using 2 pointers c and i and will be overwriting on the box list so this is an in-pace approach. 
       c points to an element in the row and i points to a slot in the row which is not an obstacle.
    2. We iterate over each row of the box from the end to the beginning becuase due to
       gravity the stone will slide to the bottom. Thus whenever c points to a slot which is a stone 
       we swap the stone pointed to by c with i. Then we shift/decrement i to the beginning of the row by 1.
    3. IF c points to an obstacle we shift i to a slot before the obstacle.
    4. Finally, we rotate the box. Observation: the box is rotated clockwise so the column becomes the row but in reversed order.
    */
    // Time Complexity: O(mn)
    // Space Complexity: O(mn)
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int ROWS = box.size();
        int COLS = box[0].size();
        char STONE = '#';
        char OBSTACLE = '*';
        vector<vector<char>> res;

        // Step 1: Process each row from right to left
        for (int r = 0; r < ROWS; ++r) {
            int i = COLS - 1;  // Pointer i points to the empty slot on the row

            for (int c = COLS - 1; c >= 0; --c) {
                if (box[r][c] == STONE) {
                    // Swap the stone with the empty position i
                    swap(box[r][c], box[r][i]);
                    --i;
                } else if (box[r][c] == OBSTACLE) {
                    // Move i to a slot prior to the obstacle
                    i = c - 1;
                }
            }
        }

        // Step 2: Rotate the box to convert rows to columns (clockwise rotation)
        for (int c = 0; c < COLS; ++c) {
            vector<char> col_to_row;
            for (int r = ROWS - 1; r >= 0; --r) {
                col_to_row.push_back(box[r][c]);
            }
            res.push_back(col_to_row);
        }

        return res;
    }
};