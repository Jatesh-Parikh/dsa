// Time Complexity - O(N)

// Only works for sorted array
function count_unique_values(arr) {
    let i = 0;
    for(let j = 1; j < arr.length; j++) {
        if(arr[i] !== arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}

console.log(count_unique_values([1, 1, 1, 2, 2, 3, 4, 5, 6, 6, 7]));