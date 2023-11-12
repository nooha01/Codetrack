from threading import Thread, Lock

N = 5  # Number of philosophers

# Initialize a mutex for each fork and a global mutex
forks = [Lock() for _ in range(N)]
mutex = Lock()

# Philosopher function
def philosopher(id):
    while True:
        think()
        with mutex:
            forks[id].acquire()  # Pick up left fork
            forks[(id + 1) % N].acquire()  # Pick up right fork
        eat()
        forks[id].release()  # Release left fork
        forks[(id + 1) % N].release()  # Release right fork

# Create philosopher threads
philosopher_threads = [Thread(target=philosopher, args=(i,)) for i in range(N)]

# Start philosopher threads
for thread in philosopher_threads:
    thread.start()

# Wait for philosopher threads to finish
for thread in philosopher_threads:
    thread.join()
