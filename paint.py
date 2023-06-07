import os
import random
import time
import matplotlib.pyplot as plt
import subprocess
import sys

data_sizes = [10000, 50000, 100000, 200000, 300000, 400000,
    500000, 600000, 700000, 800000, 900000, 1000000]
sort_times = {'heap_sort': [], 'merge_sort': [],
    'quick_sort': [], 'shell_sort': []}


def compile_exe(sort_name: str) -> None:
    path = './src/{}.cpp'.format(sort_name)
    os.system('g++ -o ./exe/{} {}'.format(sort_name, path))


def call_exe(sort_name: str, random_data: list[int]) -> float:
    path = './exe/{}.exe'.format(sort_name)

    start_time = time.time()
    out = subprocess.Popen(path, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out = out.communicate(input=' '.join(
        [str(i) for i in random_data]).encode('utf-8'))[0]
    end_time = time.time()

    out = out.decode('utf-8').split()
    out = [int(i) for i in out]
    if not check_sorted(out):
        print('Error: {} is not sorted!'.format(sort_name))
        sys.exit(1)

    return end_time - start_time


def check_sorted(data: list) -> bool:
    for i in range(len(data) - 1):
        if data[i] > data[i + 1]:
            return False
    return True


def generate_random_data(data_size: int) -> list[int]:
    data = [i for i in range(data_size)]
    random.shuffle(data)
    return data


def paint_data() -> None:
    for sort_name in sort_times.keys():
        plt.plot(data_sizes, sort_times[sort_name], label=sort_name)
    plt.xlabel('data size')
    plt.ylabel('running time')
    plt.title('running time of different sorting algorithms')
    plt.legend()
    plt.savefig('running_time.png')

def main() -> None:
    for sort_name in sort_times.keys():
        compile_exe(sort_name)

    for data_size in data_sizes:
        print('data size: {}'.format(data_size))
        random_data = generate_random_data(data_size)
        for sort_name in sort_times.keys():
            sort_times[sort_name].append(call_exe(sort_name, random_data))
            print('{} running time: {:.3f}'.format(sort_name, sort_times[sort_name][-1])) 

    paint_data()


if __name__ == '__main__':  
    main()
