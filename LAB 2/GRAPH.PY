import matplotlib.pyplot as plt

# Data for Set Size, Merge Sort Time, and Quick Sort Time
set_size = [1000, 5000, 10000, 50000, 100000]
merge_sort_time = [0.001000, 0.001000, 0.002000, 0.015000, 0.031000]
quick_sort_time = [0.000000, 0.001000, 0.002000, 0.011000, 0.018000]

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the Merge Sort Time vs Set Size
plt.plot(set_size, merge_sort_time, label='Merge Sort Time', marker='o', color='blue', linestyle='-', linewidth=2)

# Plot the Quick Sort Time vs Set Size
plt.plot(set_size, quick_sort_time, label='Quick Sort Time', marker='o', color='red', linestyle='-', linewidth=2)

# Add labels and title
plt.xlabel('Set Size')
plt.ylabel('Time (seconds)')
plt.title('Performance Comparison: Merge Sort vs Quick Sort')

# Add a legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Display the plot
plt.show()
