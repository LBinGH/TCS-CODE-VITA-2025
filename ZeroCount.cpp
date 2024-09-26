def find_min_swaps(arr):
    size = len(arr)

    # Count swaps for both ascending and descending order
    swaps_ascending = count_no_swaps(arr, "asc")
    swaps_descending = count_no_swaps(arr, "desc")

    # Return minimum swaps
    return min(swaps_ascending, swaps_descending)

def count_no_swaps(array, order_type):
    n = len(array)
    
    # Create a sorted version of the array based on the order type
    if order_type == "asc":
        sorted_array = sorted((value, index) for index, value in enumerate(array))
    else:
        sorted_array = sorted((value, index) for index, value in enumerate(array), reverse=True)

    # Create a mapping from element to its original index
    index_mapping = {index: i for i, (value, index) in enumerate(sorted_array)}

    visited = [False] * n
    swaps = 0

    for i in range(n):
        # If already visited or already in correct position, skip
        if visited[i] or index_mapping[i] == i:
            continue

        cycle_size = 0
        x = i

        # Count the size of the cycle
        while not visited[x]:
            visited[x] = True
            # Move to the index of the next element
            x = index_mapping[x]
            cycle_size += 1

        # If there is a cycle of size `cycle_size`, it takes `cycle_size - 1` swaps to arrange them
        if cycle_size > 0:
            swaps += (cycle_size - 1)

    return swaps

# Input
number_of_elements = int(input())
array = list(map(int, input().split()))

# Output
result = find_min_swaps(array)
print(result)
