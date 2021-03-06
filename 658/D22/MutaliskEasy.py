import math,string,itertools,fractions,heapq,collections,re,array,bisect,random,copy

base = 61

class MutaliskEasy:
    def encode(self, x, y, z):
        return x + y * base + z * base * base;

    def minimalAttacks(self, x):
        for i in range(len(x), 3):
            x = x + (0,)
        res = 10000000
        q = []
        q.append( self.encode(x[0], x[1], x[2]) )

        cnt = 1
        cnt2 = 0
        curr = 1

        hows = []
        for how in itertools.permutations((9, 3, 1), 3):
            hows.append(how)
        d = [False for i in range(base * base * base + 5)]
        while len(q) > 0:
            t = q.pop(0)
            t0 = t % base
            t /= base
            t1 = t % base
            t /= base
            t2 = t

            cnt -= 1
            for how in hows:
                m0 = t0 - how[0]
                m1 = t1 - how[1]
                m2 = t2 - how[2]
                if m0 <= 0 and m1 <= 0 and m2 <= 0:
                    res = min(res, curr)
                else:
                    m = self.encode( max(0, m0), max(0, m1), max(0, m2) )
                    if not d[m]:
                        d[m] = True
                        q.append(m)
                        cnt2 += 1

            if cnt == 0:
                cnt = cnt2
                cnt2 = 0
                curr += 1
        return res

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, hasAnswer, p1):
	obj = MutaliskEasy()
	startTime = time.clock()
	answer = obj.minimalAttacks(p0)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		res = answer == p1
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		print(str("\t") + str(p1))
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
p0 = (12,10,4)
p1 = 2
all_right = (disabled or KawigiEdit_RunTest(0, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = (54,18,6)
p1 = 6
all_right = (disabled or KawigiEdit_RunTest(1, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = (55,60,53)
p1 = 13
all_right = (disabled or KawigiEdit_RunTest(2, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled = False
p0 = (60,60,60)
p1 = 14
all_right = (disabled or KawigiEdit_RunTest(3, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = (60,40)
p1 = 9
all_right = (disabled or KawigiEdit_RunTest(4, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 5 -----
disabled = False
p0 = (60,)
p1 = 7
all_right = (disabled or KawigiEdit_RunTest(5, p0, True, p1) ) and all_right
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
