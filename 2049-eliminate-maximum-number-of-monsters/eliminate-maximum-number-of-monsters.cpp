class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> arrival(dist.size(), 0);
        int ans = 0;

        for(int i = 0; i < dist.size(); i++) {
            arrival[i] = ((float) dist[i]) / ((float) speed[i]);
        }
        sort(arrival.begin(), arrival.end());
        if(arrival[0] > 0) {
            ans++;
        }
        for(int i = 1; i < arrival.size(); i++) {
            if(arrival[i] > i) ans++;
            else break;
        }
        return ans;
    }
};