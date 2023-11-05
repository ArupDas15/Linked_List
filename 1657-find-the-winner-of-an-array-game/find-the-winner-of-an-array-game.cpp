class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        int winstreak = 0 ;
        int currwinner = 0;
        int opponent = 0;

        currwinner = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            q.push(arr[i]);
        }
        while(q.empty() == false and winstreak < k){
            opponent = q.front();
            q.pop();
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