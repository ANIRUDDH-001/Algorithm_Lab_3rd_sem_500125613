import matplotlib.pyplot as plt
import numpy as np

# Example output values for distances from the source
bellman_ford_distances = [0, -1, 2, -2, 1]  # Distances for Bellman-Ford
dijkstra_distances = [0, 8, 9, 7, 5]         # Distances for Dijkstra

# Example times taken for each algorithm
bellman_ford_time = 0.000024  # Time taken by Bellman-Ford
dijkstra_time = 0.000013       # Time taken by Dijkstra

# Bar graph for distances
labels = ['Node 1', 'Node 2', 'Node 3', 'Node 4', 'Node 5']
x = np.arange(len(labels))

fig, ax = plt.subplots(2, 1, figsize=(10, 10))

# Distances Bar Plot
ax[0].bar(x - 0.2, bellman_ford_distances, width=0.4, label='Bellman-Ford', color='blue')
ax[0].bar(x + 0.2, dijkstra_distances, width=0.4, label='Dijkstra', color='orange')

ax[0].set_xlabel('Nodes')
ax[0].set_ylabel('Distance from Source')
ax[0].set_title('Distances from Source Node')
ax[0].set_xticks(x)
ax[0].set_xticklabels(labels)
ax[0].legend()

# Bar graph for time taken
algorithms = ['Bellman-Ford', 'Dijkstra']
time_taken = [bellman_ford_time, dijkstra_time]

ax[1].bar(algorithms, time_taken, color=['blue', 'orange'])
ax[1].set_ylabel('Time Taken (seconds)')
ax[1].set_title('Time Taken by Algorithms')

# Display the plot
plt.tight_layout()
plt.show()
