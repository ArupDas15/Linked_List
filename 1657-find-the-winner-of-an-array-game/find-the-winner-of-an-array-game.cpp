class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int getWinner(vector<int>& arr, int k) {
        int maxEle;
        int opponent = 0;     
        int winstreak = 0;
        int currwinner = 0;
        
        currwinner = arr[0];
        maxEle = *max_element(arr.begin(), arr.end());
        for(int i = 1; i < arr.size() and 
            (winstreak < k and currwinner != maxEle); 
            i++) {
                opponent = arr[i];
                if (currwinner > opponent) {
                    winstreak++;
                } else {
                    currwinner = opponent;
                    winstreak = 1;
                }
            }
        return currwinner;
    }
};
// class Solution {
// public:
//     // Time complexity: O(n)
//     // Space complexity: O(n)
//     int getWinner(vector<int>& arr, int k) {
//         queue<int> q;
//         int winstreak = 0 ;
//         int currwinner = 0;
//         int opponent = 0;

//         currwinner = arr[0];
//         for(int i = 1; i < arr.size(); i++) {
//             q.push(arr[i]);
//         }
//         while(q.empty() == false and winstreak < k){
//             opponent = q.front();
//             q.pop();
//             if (currwinner > opponent) {
//                 winstreak++;
//             } else {
//                 currwinner = opponent;
//                 winstreak = 1;
//             }
//         }
//         return currwinner;
//     }
// };