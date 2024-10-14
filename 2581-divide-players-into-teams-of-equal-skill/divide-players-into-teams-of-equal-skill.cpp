class Solution {
public:
    /*
    Time complexity: (n⋅logn)
    Sorting the array takes O(n⋅logn) time. The algorithm iterates through half of the array, which takes O(n/2)=O(n) time. All operations within the loop are constant time operations.
    Thus, the overall time complexity of the algorithm is O(n⋅logn)+O(n)=(n⋅logn).

    Space complexity: O(S)
    The only additional space used is for the sorting algorithm. The space taken by the sorting algorithm (S) depends on the language of implementation:
    In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logn).
    In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worst-case space complexity of O(logn).
    In Python, the sort() method sorts a list using the Timsort algorithm which is a combination of Merge Sort and Insertion Sort and has a space complexity of O(n).
    */
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long int sum = accumulate(skill.begin(),skill.end(),0);
        long long int ans = 0;
        long long int target = sum/(skill.size()/2);

        for(int i = 0, j = skill.size()-1; i<j; i++, j--) {
            if ((long long int )skill[i] + (long long int )skill[j] == target) {
                ans = ans + (skill[i]*skill[j]);
            } else {
                return -1;
            }
        }
        return ans;
    }
};