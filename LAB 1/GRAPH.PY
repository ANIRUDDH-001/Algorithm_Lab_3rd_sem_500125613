import matplotlib.pyplot as plt

# Updated data for Array Size, Iterative Time, and Recursive Time
array_size = [5000, 10000, 50000, 100000, 1000000]
iterative_time = [0.000000, 0.001000, 0.006000, 0.012000, 0.110000]
recursive_time = [0.000000, 0.001000, 0.008000, 0.014000, 0.140000]

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the Iterative Time vs Array Size
plt.plot(array_size, iterative_time, label='Iterative Time', marker='o', color='blue', linestyle='-', linewidth=2)

# Plot the Recursive Time vs Array Size
plt.plot(array_size, recursive_time, label='Recursive Time', marker='o', color='red', linestyle='-', linewidth=2)

# Add labels and title
plt.xlabel('Array Size')
plt.ylabel('Time (seconds)')
plt.title('Performance Comparison: Iterative vs Recursive BST Insertion')

# Set logarithmic scale for both axes for better visualization
plt.xscale('log')
plt.yscale('log')

# Add a legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Display the plot
plt.show()
