class Solution:
    #value map
    v_map = {"I":1, "V":5, "X":10, "L": 50, "C":100, "D": 500, "M": 1000}
    def romanToInt(self, s: str) -> int:
        ret = 0
        i = 0
        while i < len(s):
            c = s[i]
            v = self.v_map[c]
            if i + 1 < len(s) and self.v_map[s[i+1]] > v:
                v = self.v_map[s[i+1]] - v
                i+=1
            ret += v
            i+=1
	return ret
