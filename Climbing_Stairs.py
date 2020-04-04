class Solution(object):
    def __init__(self):
        self.cache = {};  
        
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n in self.cache.keys():
          return(self.cache[n])
          
        if(n==1 or n == 0):
          return(1)
        output = self.climbStairs(n-1) + self.climbStairs(n-2) 
        self.cache[n] = output;
        return(output)
