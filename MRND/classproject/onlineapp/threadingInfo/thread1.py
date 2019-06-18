import sys
import time
import threading

def worker1():
    for i in range(5):
        print("hello from worker1")
        time.sleep(1)

def worker2():
    for i in range(5):
        print("hello from worker2")
        time.sleep(1)

def activity():
    thread1=threading.Thread(target=worker1)
    thread2 = threading.Thread(target=worker2)
    thread1.start()
    thread2.start()

if __name__=='__main__':
    activity()