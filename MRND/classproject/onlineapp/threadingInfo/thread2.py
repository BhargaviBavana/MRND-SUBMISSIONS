import sys
import time
import threading

def worker1():
    activity("worker1")

def worker2():
    activity("worker2")

def activity(tag):
    for i in range(5):
        thread_id=threading.current_thread().ident
        print("hello from tag",tag,"i=",i,"thread_id=",thread_id)
        time.sleep(1)


if __name__=='__main__':
    thread1 = threading.Thread(target=worker1)
    thread2 = threading.Thread(target=worker2)
    thread1.start()
    thread2.start()