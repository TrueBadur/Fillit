import datetime
import time
import os

t1 = 0;
for i in xrange(1000):
    os.system("./generator test 26")
    t0 = int(round(time.time() * 1000))
    os.system("./fillit test > /dev/null")
    t1 += int(round(time.time() * 1000)) - t0
print t1 / 1000
