class Solution:
    """
    ALGORITHM
    1. We are using 2 pointers c and i and will be overwriting on the box list so this is an in-pace approach. 
       c points to an element in the row and i points to a slot in the row which is not an obstacle.
    2. We iterate over each row of the box from the end to the beginning becuase due to
       gravity the stone will slide to the bottom. Thus whenever c points to a slot which is a stone 
       we swap the stone pointed to by c with i. Then we shift/decrement i to the beginning of the row by 1.
    3. IF c points to an obstacle we shift i to a slot before the obstacle.
    4. Finally, we rotate the box. Observation: the box is rotated clockwise so the column becomes the row but in reversed order.
    """
    # Time Complexity: O(mn)
    # Space Complexity: O(mn)
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        ROWS, COLS = len(box), len(box[0])
        STONE = "#"
        OBSTACLE = "*"
        res = []

        for r in range(ROWS):
            i = COLS - 1
            for c in reversed(range(COLS)):
                if box[r][c] == STONE:
                    # SWAP the STONE with the PSITION at 'i'
                    box[r][c], box[r][i] = box[r][i], box[r][c]
                    i -= 1
                elif box[r][c] == OBSTACLE:
                    # Move i to a slot prior to the obstacle.
                    i = c - 1
        # rotate the box
        for c in range(COLS):
            col_to_row = []
            for r in reversed(range(ROWS)):
                col_to_row.append(box[r][c])
            res.append(col_to_row)
        
        return res