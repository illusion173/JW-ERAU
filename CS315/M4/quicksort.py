import pandas as pd
output_dataframe = pd.DataFrame(columns=['Instruction', 'lo', 'j', 'hi'])


# Function to find the partition position
def partition(array, low, high):

    # choose the rightmost element as pivot
    pivot = array[high]

    # pointer for greater element
    i = low - 1

    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:

            # If element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1

            # Swapping element at i with element at j
            print("Swapping " + str(array[j]), str(array[i]))
            (array[i], array[j]) = (array[j], array[i])

    print("Swapping " + str(array[high]), str(array[i+1]))
    # Swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])

    # Return the position from where partition is done
    return i + 1

# function to perform quicksort


def quickSort(array, low, high):
    if low < high:

        # Find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)
        print("I AM PIVOT: " + str(pi))
        # Recursive call on the left of pivot
        quickSort(array, low, pi - 1)

        # Recursive call on the right of pivot
        quickSort(array, pi + 1, high)
        text = "quickSort(arr, {}, {})".format(low, high)
        output_dataframe.loc[len(output_dataframe.index)] = [
            text,
            low,
            pi,
            high
        ]


data = [11, 38, 42, 8, 6, 5]
size = len(data)
quickSort(data, 0, size - 1)
print(output_dataframe)
