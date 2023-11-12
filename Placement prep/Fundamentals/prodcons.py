# Shared buffer of fixed size
buffer = []
buffer_size = 5

# Semaphores for synchronization
mutex = Semaphore(1)  # Controls access to the buffer
empty = Semaphore(buffer_size)  # Counts empty slots in the buffer
full = Semaphore(0)  # Counts filled slots in the buffer

# Producer function
def producer():
    while True:
        item = produce_item()
        empty.wait()  # Wait if the buffer is full
        mutex.wait()  # Enter critical section
        buffer.append(item)  # Add item to the buffer
        mutex.signal()  # Exit critical section
        full.signal()  # Signal that the buffer is no longer empty

# Consumer function
def consumer():
    while True:
        full.wait()  # Wait if the buffer is empty
        mutex.wait()  # Enter critical section
        item = buffer.pop(0)  # Remove item from the buffer
        mutex.signal()  # Exit critical section
        empty.signal()  # Signal that the buffer is no longer full
        consume_item(item)

# Start producer and consumer threads
create_thread(producer)
create_thread(consumer)
