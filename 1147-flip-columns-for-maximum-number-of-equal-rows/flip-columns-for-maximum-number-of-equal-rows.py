class Solution:
    """
    ALGORITHM
    1. Use a default dictionary in python becuase we want it to return 0 if the key doesn't exist.
       The key in this dictionary will be the string representation of the row and value will be the count 
       of every such row. The idea is that if two rows are inverted forms of each other, e.g., 
       1 1 0
       0 0 1
       Here if you flip the last column or the first two columns then both the rows will be equal.
       We need a consistent way of storing 2 equivalent but inverted string. Thus, we have decided to store 
       strings which start with a 0. Thus =, any string if it starts with a 1, we completely invert the string representation of that row.
       Then we increment the count of the occurence of the string (key) in the defulat dictionary by 1. Thus, since we are using
       a defualt dictionary if the key was not encountered before the count of the frequency of key would become 1.
    2. Iterate over every row in matrix:
        2.1. Obtain the string representation of the row: row_lkey = str(row)
        2.1. If row[0] is 1 then invert the string representation row_key.
        2.2. Update the count of row_key: dict[row_key] += 1
    3. Now we will return the maximum frequency count: 
            For that we will iterate over the dictionary: return max(count.values())
    """
    # Time Complexity: O(mn) + O(k) where k is the number of unique row configurations 
    # Space Complexity: O(mn)
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        # Declare a default dictionary count
        count = defaultdict(int)

        for row in matrix:
            # Convert row to its string representation
            row_key = str(row)
            # Check if row[0] is 1
            if row[0] == 1:
                # invert row_key
                row_key = str([0 if n == 1 else 1 for n in row])
            # Update the frequency of row_key in counr.
            count[row_key] += 1

        return max(count.values())