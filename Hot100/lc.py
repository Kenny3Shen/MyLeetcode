from collections import defaultdict, Counter, deque, OrderedDict
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right, insort
from math import gcd, inf
import math
from math import isqrt
import functools
from itertools import permutations, combinations, product
from typing import List, Dict, Tuple, Set, Optional
from functools import lru_cache as cache
# Data structures

# Math and functional

# Typing for type hints

# For working with linked lists and trees
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right