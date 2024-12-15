# time complexity: O(nlog n) + O(extraStudents*logn)
# space complexity: O(n)
class Solution:
    def heapPush(self, costs, idx, heap):
        cur_avg = costs[idx][0] / costs[idx][1]
        new_avg = (costs[idx][0] + 1)/ (costs[idx][1] + 1)
        possible_increment = new_avg - cur_avg
        heapq.heappush(heap, (-possible_increment, idx))

    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        heap = []
        final_avg = 0

        for i in range(len(classes)):
            self.heapPush(classes, i, heap)
        while extraStudents > 0:
            extraStudents -= 1
            _, class_id = heapq.heappop(heap)
            classes[class_id][0] += 1
            classes[class_id][1] += 1
            self.heapPush(classes, class_id, heap)
        
        for i in range(len(classes)):
            final_avg += classes[i][0]/classes[i][1]
        
        return final_avg/len(classes)
