import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class InfiniteString:
    def equal(self, s, t):
        ls = len(s)
        lt = len(t)
        rs = ""
        rt = ""
        for i in range(1, ls + 1):
            rs = s[:i]
            rep = ls // i
            if rs * rep == s:
                break

        for i in range(1, lt + 1):
            rt = t[:i]
            rep = lt // i
            if rt * rep == t:
                break

        print(rs, rt)
        if rs == rt:
            return "Equal"
        else:
            return "Not equal"


# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, p1, hasAnswer, p2):
	obj = InfiniteString()
	startTime = time.clock()
	answer = obj.equal(p0, p1)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		res = answer == p2
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		print(str("\t") + str("\"") + str(p2) + str("\""))
		sys.stdout.write(str("received: "))
		print(str("\t") + str("\"") + str(answer) + str("\""))
		print(str(""))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		sys.stdout.write(str("passed.      "))
		sys.stdout.write(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
		print(str(""))
	else:
		print(str("OK, but is it right?"))
	
	return res

all_right = True
tests_disabled = False


# ----- test 0 -----
disabled = False
p0 = "ab"
p1 = "abab"
p2 = "Equal"
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = "abc"
p1 = "bca"
p2 = "Not equal"
all_right = (disabled or KawigiEdit_RunTest(1, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = "abab"
p1 = "aba"
p2 = "Not equal"
all_right = (disabled or KawigiEdit_RunTest(2, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = "aaaaa"
p1 = "aaaaaa"
p2 = "Equal"
all_right = (disabled or KawigiEdit_RunTest(3, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = "ababab"
p1 = "abab"
p2 = "Equal"
all_right = (disabled or KawigiEdit_RunTest(4, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 5 -----
disabled = False
p0 = "a"
p1 = "z"
p2 = "Not equal"
all_right = (disabled or KawigiEdit_RunTest(5, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	print(str(""))
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!