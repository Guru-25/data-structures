import numpy as np
import matplotlib.pyplot as plt

algorithms = ["Selection Sort", "Bubble Sort", "Insertion Sort", "Merge Sort", "Shell Sort", "Quick Sort"]

execution_times = [
    [10144, 3102, 5939, 522, 451, 323],
    [35001, 10315, 15694, 578, 512, 376],
    [61569, 16750, 27728, 965, 748, 610],
    [102779, 29746, 52998, 1359, 1030, 801],
    [169443, 48452, 83504, 1799, 1398, 1075],
]

elements = [1000, 2000, 3000, 4000, 5000]

marker_styles = ['o', 's', '^', 'x', 'D', 'P']
line_colors = ['blue', 'green', 'red', 'purple', 'orange', 'cyan']

plt.figure(figsize=(10, 6))

for i, algorithm in enumerate(algorithms):
    execution_times_for_algorithm = [times[i] for times in execution_times]
    plt.plot(elements, execution_times_for_algorithm, marker=marker_styles[i], linestyle='-', color=line_colors[i], label=algorithm)

plt.xlabel('Number of Elements')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time of Sorting Algorithms')
plt.legend()
plt.grid(True)

plt.show()
