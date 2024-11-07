import matplotlib.pyplot as plt

# Example output values for minimum number of multiplications and time taken (in seconds)
cases = [1, 2, 3, 4, 5]
min_multiplications = [121500000000, 156000000000, 28000000000, 12500000000, 145000000000]
time_taken = [0.005489, 0.005698, 0.004129, 0.004238, 0.006451]

# Create a figure with two subplots
fig, ax1 = plt.subplots()

# Plotting the minimum number of multiplications on the primary y-axis
color = 'tab:blue'
ax1.set_xlabel('Cases')
ax1.set_ylabel('Min Multiplications', color=color)
ax1.plot(cases, min_multiplications, color=color, marker='o', label='Min Multiplications')
ax1.tick_params(axis='y', labelcolor=color)

# Creating a secondary y-axis to plot time taken
ax2 = ax1.twinx()  
color = 'tab:red'
ax2.set_ylabel('Time Taken (s)', color=color)
ax2.plot(cases, time_taken, color=color, marker='x', label='Time Taken (s)')
ax2.tick_params(axis='y', labelcolor=color)

# Title and layout adjustments
plt.title('Matrix Chain Multiplication: Min Multiplications vs Time Taken')
fig.tight_layout()

# Show the plot
plt.show()
