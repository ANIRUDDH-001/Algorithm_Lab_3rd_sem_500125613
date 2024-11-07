import matplotlib.pyplot as plt
import numpy as np

# Data for the Greedy and Dynamic Programming approaches
greedy_items = [
    {'value': 60, 'weight': 10, 'taken': 'entire'},
    {'value': 100, 'weight': 20, 'taken': 'entire'},
    {'value': 120, 'weight': 30, 'taken': 'fractional'}
]

dynamic_items = [
    {'value': 60, 'weight': 10, 'taken': 'entire'},
    {'value': 100, 'weight': 20, 'taken': 'entire'}
]

# Values for total
greedy_total_value = 240.00
dp_total_value = 220

# Create a bar graph for items taken in both approaches
fig, ax = plt.subplots(2, 1, figsize=(10, 10))

# Data for items taken in Greedy Approach
greedy_values = [item['value'] for item in greedy_items]
greedy_labels = ['Item 1 (10kg)', 'Item 2 (20kg)', 'Item 3 (30kg)']

# Bar graph for Greedy Approach
ax[0].bar(greedy_labels, greedy_values, color='blue', alpha=0.7)
ax[0].set_title('Greedy Approach - Values of Items Taken')
ax[0].set_ylabel('Value')
ax[0].axhline(y=greedy_total_value, color='red', linestyle='--', label='Total Value: 240.00')
ax[0].legend()

# Data for items taken in Dynamic Programming Approach
dp_values = [item['value'] for item in dynamic_items]
dp_labels = ['Item 1 (10kg)', 'Item 2 (20kg)']

# Bar graph for Dynamic Programming Approach
ax[1].bar(dp_labels, dp_values, color='orange', alpha=0.7)
ax[1].set_title('Dynamic Programming Approach - Values of Items Taken')
ax[1].set_ylabel('Value')
ax[1].axhline(y=dp_total_value, color='red', linestyle='--', label='Total Value: 220.00')
ax[1].legend()

# Adjust layout
plt.tight_layout()
plt.show()
