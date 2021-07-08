from threading import Thread
from time import sleep

def sort_worker(arg):
    sleep(arg)
    print str(arg)+ ', ',

if __name__ == "__main__":
    threads = []
    numbers = [1,4,2,5,6,7,8,4,8,10,9]

    for number in numbers:
        new_thread = Thread(target=sort_worker, args=(number,))
        new_thread.start()
        threads.append(new_thread)

    for thread in threads:
        thread.join()