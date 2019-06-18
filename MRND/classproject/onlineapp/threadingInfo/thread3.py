import sys
import time
import threading

counter=0

def update():
    global counter
    for i in range(10):
        counter+=1
        #time.sleep(1)

def worker1():
    #activity("worker1")
    update()

def worker2():
    #activity("worker2")
    update()

def activity(tag):
    for i in range(5):
        thread_id=threading.current_thread().ident
        print("hello from tag",tag,"i=",i,"thread_id=",thread_id)
        time.sleep(2)


if __name__=='__main__':
    thread1 = threading.Thread(target=worker1)
    thread2 = threading.Thread(target=worker2)
    thread1.start()
    thread2.start()
    print(counter)