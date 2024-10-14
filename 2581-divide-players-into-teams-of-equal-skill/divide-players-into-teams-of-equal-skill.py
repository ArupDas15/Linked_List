class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        tot_sum=sum(skill)
        target = tot_sum//(len(skill)//2)
        i,j = 0, len(skill) - 1
        ans = 0
        while i < j:
            if skill[i] + skill[j] == target:
                ans = ans + skill[i] * skill[j] 
            else:
                return -1
            i += 1
            j -= 1

        return ans;        