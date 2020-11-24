#x = [1,2,3,4,5, 100]
from typing import List

y = [4,5,7,8,9, 100, 1,2,3]

def find(ls: List[int], x: int) -> int:
  l = 0
  r = len(y) - 1

  while (l <= r):
    mid = (l + r) // 2

    if x == y[mid]:
      return mid

    if y[l] <= y[mid]:
      if x >= y[l] and x <= y[mid]:
        r = mid - 1
      else:
        l = mid + 1

    if x >= y[mid] and x <= y[r]:
      l = mid + 1
    else:
      r = mid - 1

  return -1



assert find(y, 4) == 0
assert find(y, 5878) == -1
