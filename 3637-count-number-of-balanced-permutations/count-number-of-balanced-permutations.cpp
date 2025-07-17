class Solution {
public:
    // Global vairables
    using ll = long long;
    int mod=1e9+7;
    int tot_way_to_permute;

    vector<int> fact;
    vector<int> inverse_fact;
    vector<int> freq;
    int mem[10][40+2][42*9];//Digits:[0:9]...Length[2,80]...MaxSumOfDigits:[80*9]

    int modMul(int& a, int& b) {
        return ((ll)(a%mod)*(b%mod))%mod;
    }
    // precompute ftorials to answer each query in o(!)
    void computeFactorial(int n) {
        fact[0]=1;
        for(int i=1; i <= n; i++) {
            fact[i] = modMul(fact[i-1],i);
        }
    }
    // calculating module multiplicative inverse using Fermat's Little theorem.
    int binary_exponentiation(int a, int b) {
        int res = 1;
        while(b) {
            if (b&1)
                res = modMul(res,a);
            b /= 2;
            a = modMul(a,a);
        }
        return res;
    }
    void computeInverseFactorial(int n) {
        for(int i=0;i<=n;i++)
            inverse_fact[i] = binary_exponentiation(fact[i], mod-2);
    }
    // calculate the number of unqiue arrangements
    // equal sum permutation (LC 416) + Fermat's Little Theorem.
    // GOAL: Count the number of arrangements where the "Odd Index Sum" = "Even Index Sum"
    // Since permuation has the flexibility to place any digit at any index and odd index sum = even idx sum = sum of all digits
    // if odd idx sum = even idx sum
    //      then odd idx sum = even idx sum = sum of all digits/2 = (S/2)
    // Therefore, the new goal is to find a unqiue subset of digits with sum = (S/2) - CONSTRAINT 1
    // Number of digits in each set:  - CONSTRAINT 2
    //      if N is even we have N/2 numbers on each set.
    //      if N is odd we have floor(N/2) and ceil(N/2) numbers on both the sets. 
    // The total number of arragements = no. of unique arragements in odd set * no. of unique arrangements in even set.
    // digit: which digit we are currently assigning. 
    //      Digits we can try at any position will be i:
    //          0 <= i <= min(leftover, freq[digit], target/digit)
    // leftover: how many more digits do we need to pick in the first half
    // target: how much sum is left to reach the half sum.
    // Stopping condition in recursion: when target is 0 (we have reached S/2) and leftover is 0 (that means we have included n/2 digits in our set)
    // We will build a 3d memoization table: int mem[digit(ranging from 0-9)][leftover(0-40 digits)][target(maximum sum is 40*9)];
    // int mem[10][40+2][42*9] = {-1};
    //      Space complexity: 10 * (N/2) * (N/2) [Total no. of states possible] = O(N^2)
    //      Time complexity: O(N^3)
    //          The depth of the rcursion tree is at most 10.
    //          At every level we can have N/2 branches since in every state we try max leftover no. of digits.
    int countPermutation(int digit, int leftover, int target) {
        if (digit==10) {
            if(leftover==0) return target==0?tot_way_to_permute:0;
            else return 0;
        }
        if(mem[digit][leftover][target]!=-1) return mem[digit][leftover][target];
        int include_count=min({leftover,freq[digit],digit>0?target/digit:INT_MAX});

        ll ans=0;
        for(int i=0;i<=include_count;i++){
            ll ways_for_current_digit = modMul(inverse_fact[i],inverse_fact[freq[digit]-i]);
            ans += (ways_for_current_digit * countPermutation(digit+1,leftover-i,target-digit*i))%mod;
            ans = ans%mod;
        }
        return mem[digit][leftover][target] = ans;
    }
    int countBalancedPermutations(string num) {
        int n=num.size();
        int sum=0;
        freq = vector<int>(10);
        // iterate through all the digits, find the sum and frequenchy of all the digits.
        for(int i=0;num[i]!='\0';i++){
            sum+=num[i]-'0';
            freq[num[i]-'0']++;
        }
        // if sum is odd return 0
        if(sum&1) return 0;
        int target = sum/2;
        fact = vector<int>(n+1);
        computeFactorial(n);
        
        inverse_fact = vector<int>(n+1);
        computeInverseFactorial(n);

        tot_way_to_permute = modMul(fact[floor((double)n/2)],fact[ceil((double)n/2)]);//Overcounts for duplicates
        memset(mem,-1,sizeof(mem));
        return countPermutation(0,n/2,target);
    }
};