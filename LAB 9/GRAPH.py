import time
import random
import matplotlib.pyplot as plt

# Define an Item class to hold weight and value
class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value

# Utility function to return the maximum of two integers
def max_value(a, b):
    return a if a > b else b

# Backtracking Approach
def knapsack_backtracking(i, current_weight, current_value, max_value, W, items):
    if current_weight > W:
        return
    if i == len(items):
        max_value[0] = max(max_value[0], current_value)
        return
    knapsack_backtracking(i + 1, current_weight + items[i].weight, current_value + items[i].value, max_value, W, items)
    knapsack_backtracking(i + 1, current_weight, current_value, max_value, W, items)

# Branch & Bound Approach
class Node:
    def __init__(self, level, value, weight, bound):
        self.level = level
        self.value = value
        self.weight = weight
        self.bound = bound

def bound(u, n, W, items):
    if u.weight >= W:
        return 0
    bound_value = u.value
    total_weight = u.weight
    for i in range(u.level, n):
        if total_weight + items[i].weight <= W:
            total_weight += items[i].weight
            bound_value += items[i].value
        else:
            bound_value += (W - total_weight) * items[i].value / items[i].weight
            break
    return bound_value

def knapsack_branch_and_bound(W, items):
    items.sort(key=lambda x: x.value / x.weight, reverse=True)
    Q = []
    n = len(items)
    max_value = 0
    u = Node(0, 0, 0, 0)
    u.bound = bound(u, n, W, items)
    Q.append(u)
    while Q:
        u = Q.pop(0)
        if u.level == n:
            continue
        v = Node(u.level + 1, u.value + items[u.level].value, u.weight + items[u.level].weight, 0)
        if v.weight <= W and v.value > max_value:
            max_value = v.value
        v.bound = bound(v, n, W, items)
        if v.bound > max_value:
            Q.append(v)
        v = Node(u.level + 1, u.value, u.weight, 0)
        v.bound = bound(v, n, W, items)
        if v.bound > max_value:
            Q.append(v)
    return max_value

# Dynamic Programming Approach
def knapsack_dynamic(W, items):
    n = len(items)
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(W + 1):
            if items[i - 1].weight <= w:
                dp[i][w] = max_value(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    return dp[n][W]

# Function to generate random items
def generate_random_items(n):
    items = []
    for _ in range(n):
        weight = random.randint(1, 20)
        value = random.randint(10, 100)
        items.append(Item(weight, value))
    return items

# Function to compare performance of different approaches
def compare_algorithms():
    W = 50  # Knapsack capacity
    item_counts = [5, 10, 15, 20, 25]  # Different numbers of items
    backtracking_times = []
    branch_and_bound_times = []
    dynamic_times = []

    for n in item_counts:
        items = generate_random_items(n)

        # Backtracking
        start_time = time.time()
        max_value_backtracking = [0]
        knapsack_backtracking(0, 0, 0, max_value_backtracking, W, items)
        backtracking_times.append(time.time() - start_time)

        # Branch & Bound
        start_time = time.time()
        knapsack_branch_and_bound(W, items)
        branch_and_bound_times.append(time.time() - start_time)

        # Dynamic Programming
        start_time = time.time()
        knapsack_dynamic(W, items)
        dynamic_times.append(time.time() - start_time)

    # Plotting results
    plt.plot(item_counts, backtracking_times, label='Backtracking')
    plt.plot(item_counts, branch_and_bound_times, label='Branch & Bound')
    plt.plot(item_counts, dynamic_times, label='Dynamic Programming')

    plt.xlabel('Number of Items')
    plt.ylabel('Execution Time (seconds)')
    plt.title('Performance Comparison of 0/1 Knapsack Algorithms')
    plt.legend()
    plt.show()

# Run the comparison
compare_algorithms()
