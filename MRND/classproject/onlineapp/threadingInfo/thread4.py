import threading
import sys
import time

counter=0

def worker1():
    global counter
    for i in range(5):
       counter += 1
       print("in worker1 i =", i, 'counter = ', counter)
       time.sleep(1)


def worker2():
    global counter
    for i in range(5):
       counter += 1
       print("in worker2 i =", i, 'counter = ', counter)
       time.sleep(1)


def worker3():
    global counter
    print("in worker3 counter = ",counter)


def main():
    thread1=threading.Thread(target=worker1)
    thread2 = threading.Thread(target=worker2)
    thread3 = threading.Thread(target=worker3)
    thread1.start()
    thread2.start()
    thread3.start()

    thread1.join()
    thread2.join()
    thread3.join()

    print("final counter ",counter)

if __name__=='__main__':
    main()