from collections import deque

class Solution:
    def maxCandies(self, status, candies, keys, containedBoxes, initialBoxes):
        dq = deque()

        for box in initialBoxes:
            for key in keys[box]:
                status[key] = 1
            if status[box] == 0:
                dq.append(box)
            else:
                dq.appendleft(box)

        total = 0

        while dq:
            box = dq.popleft()
            if status[box] == 0:
                continue

            total += candies[box]

            for key in keys[box]:
                status[key] = 1

            for b in containedBoxes[box]:
                if status[b]:
                    dq.appendleft(b)
                else:
                    dq.append(b)

            status[box] = 0

        return total