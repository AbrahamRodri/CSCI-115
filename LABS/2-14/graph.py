import matplotlib.pyplot as plt

# Data for the sorting algorithm performance
data = {
    "Random Array": {
        "Selection Sort": [0, 1993, 133630, 13133262],
        "Insertion Sort": [0, 0, 995, 0],
        "Bubble Sort": [0, 996, 136474, 12562607]
    },
    "Sorted Array": {
        "Selection Sort": [0, 1995, 133143, 12833453],
        "Insertion Sort": [0, 0, 0, 997],
        "Bubble Sort": [0, 996, 139629, 12770630]
    },
    "90% Sorted Array": {
        "Selection Sort": [0, 2439, 133200, 12803707],
        "Insertion Sort": [0, 0, 0, 0],
        "Bubble Sort": [0, 997, 124973, 13146670]
    },
    "50% Sorted Array": {
        "Selection Sort": [0, 1993, 129133, 13475973],
        "Insertion Sort": [0, 0, 0, 503],
        "Bubble Sort": [0, 1993, 130053, 13103083]
    }
}

# Array sizes
sizes = [100, 1000, 10000, 100000]

# Plotting the data
for array_type, algorithms in data.items():
    plt.figure()
    for algorithm, times in algorithms.items():
        plt.plot(sizes, times, marker='o', label=algorithm)
    plt.title(f"{array_type} Sorting Algorithm Performance")
    plt.xlabel("Array Size (n)")
    plt.ylabel("Time (microseconds)")
    plt.legend()
    plt.grid()
    plt.tight_layout()

# Displaying the plots
plt.show()