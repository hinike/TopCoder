import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class ApplesAndOrangesEasy:
    def maximumApples(self, N, K, info):
        
        return

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, p1, p2, hasAnswer, p3):
	obj = ApplesAndOrangesEasy()
	startTime = time.clock()
	answer = obj.maximumApples(p0, p1, p2)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		res = answer == p3
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		print(str("\t") + str(p3))
		sys.stdout.write(str("received: "))
		print(str("\t") + str(answer))
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
p0 = 3
p1 = 2
p2 = ()
p3 = 2
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, p2, True, p3) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = 10
p1 = 3
p2 = (3,8)
p3 = 2
all_right = (disabled or KawigiEdit_RunTest(1, p0, p1, p2, True, p3) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = 9
p1 = 4
p2 = (1,4)
p3 = 5
all_right = (disabled or KawigiEdit_RunTest(2, p0, p1, p2, True, p3) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = 9
p1 = 4
p2 = (2,4)
p3 = 4
all_right = (disabled or KawigiEdit_RunTest(3, p0, p1, p2, True, p3) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = 23
p1 = 7
p2 = (3,2,9,1,15,23,20,19)
p3 = 10
all_right = (disabled or KawigiEdit_RunTest(4, p0, p1, p2, True, p3) ) and all_right
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