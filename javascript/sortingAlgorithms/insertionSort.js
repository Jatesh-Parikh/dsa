// *Inserting* the element at the current index in the sorted array
// Time Complexity - O(n^2)

function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let currentVal = arr[i];

        let j = i - 1;

        while (j >= 0 && arr[j] > currentVal) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = currentVal;
    }
    return arr;
}