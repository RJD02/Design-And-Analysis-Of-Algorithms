def maxActivities(arr):
    n = len(arr)
    selected = []
    Activity.sort(key = lambda x : x[1])
    i = 0
    selected.append(arr[i])
    for j in range(1, n):
        if arr[j][0] >= arr[i][1]:
            selected.append(arr[j])
            i = j
    return selected

Activity = [[5, 9], [1, 2], [3, 4], [0, 6], [5, 7], [8, 9]]
selected = maxActivities(Activity)
print('Following activities are selected: ')
print(selected)
