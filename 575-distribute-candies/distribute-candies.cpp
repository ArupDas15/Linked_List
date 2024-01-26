class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        map<int,int>m;
        for(int i=0;i<candyType.size();i++)
        {
            m[candyType[i]]++;
        }
        int eat = candyType.size()/2;
        //return eat;
        int type = m.size();
        cout<<type<<endl;
        if(eat>=type)
        {
            return type;
        }
        else
        {
            return eat;
        }
    }
};