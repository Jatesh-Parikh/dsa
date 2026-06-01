// The array must be sorted
// Time Complexity - O(log n)

function binarySearch(arr, val) {
    let start = 0;
    let end = arr.length - 1;
    
    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2);

        if (val === arr[mid]) {
            return mid;
        } else if (val > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}