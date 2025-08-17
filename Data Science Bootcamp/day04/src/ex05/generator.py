import sys
import resource
import time

def read_file_generator(filename):
    with open(filename, 'r') as file:
        for line in file:
            yield line

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Error args! Usage: python3 generator.py <filename>")
        sys.exit(1)
    
    start_time = time.time()
    data_gen = read_file_generator(sys.argv[1])
    
    for line in data_gen:
        pass
    
    end_time = time.time()
    peak_mem = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / (1024 ** 3)
    
    print(f"Peak Memory Usage = {peak_mem:.3f} GB")
    print(f"User Mode Time + System Mode Time = {end_time - start_time:.2f}s")