import random
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = []
        area = 0
        weight = 0
        for (x1,y1,x2,y2) in rects:
            area +=(x2-x1+1)*(y2-y1+1)
        for (x1,y1,x2,y2) in rects:
            cur_weight = ((x2-x1+1)*(y2-y1+1))/area
            weight+=cur_weight
            self.rects.append((x1,y1,x2,y2,weight))
            

    def pick(self) -> List[int]:
        rand = random.random()
        for (x1,y1,x2,y2,weight) in self.rects:
            if weight > rand:
                return [random.randint(x1,x2),random.randint(y1,y2)]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()