import matplotlib.pyplot as plt

# Data for Matrix Size, Traditional Time, and Strassen Time
matrix_size = ['64x64', '128x128', '256x256', '512x512', '1024x1024', '2048x2048']
traditional_time = [0.002000, 0.018000, 0.114000, 1.085000, 12.260000, 104.087000]
strassen_time = [0.003000, 0.012000, 0.097000, 0.695000, 5.342000, 31.159000]

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the Traditional Time vs Matrix Size
plt.plot(matrix_size, traditional_time, label='Traditional Time', marker='o', color='blue', linestyle='-', linewidth=2)

# Plot the Strassen Time vs Matrix Size
plt.plot(matrix_size, strassen_time, label='Strassen Time', marker='o', color='red', linestyle='-', linewidth=2)

# Add labels and title
plt.xlabel('Matrix Size')
plt.ylabel('Time (seconds)')
plt.title('Performance Comparison: Traditional vs Strassen Matrix Multiplication')

# Add a legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Display the plot
plt.show()
