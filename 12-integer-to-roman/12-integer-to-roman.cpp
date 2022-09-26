
// Reference: (Techdose) https://www.youtube.com/watch?v=Rsq1ObYg6ak
class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> values {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans;
        int div;
        while(num>0){
            for(int i=values.size()-1;i>=0;i--){
                if(num>=values[i]){
                    div = num/values[i];
                    num=num%values[i];
                    while(div>0){
                        ans = ans + symbol[i];
                        div--;
                    }
                }
            }  
        }
        return ans;
    }
};
