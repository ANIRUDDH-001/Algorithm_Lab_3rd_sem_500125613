import matplotlib.pyplot as plt

# Sample data from your output
algorithms = ['Naive', 'KMP', 'Rabin-Karp']
matches_found = [499998, 499998, 1]
time_taken = [0.004, 0.004, 0.000]  # Time in seconds

# Create a bar chart for matches found
plt.figure(figsize=(12, 6))

# Create a bar for matches found
plt.subplot(1, 2, 1)
plt.bar(algorithms, matches_found, color=['blue', 'orange', 'green'])
plt.title('Number of Matches Found')
plt.xlabel('Algorithms')
plt.ylabel('Matches Found')
plt.ylim(0, 500000)  # Set y-axis limit for better visualization

# Create a bar for time taken
plt.subplot(1, 2, 2)
plt.bar(algorithms, time_taken, color=['red', 'purple', 'cyan'])
plt.title('Time Taken (in seconds)')
plt.xlabel('Algorithms')
plt.ylabel('Time (s)')
plt.ylim(0, 0.01)  # Set y-axis limit for better visualization

# Show the plot
plt.tight_layout()
plt.show()
