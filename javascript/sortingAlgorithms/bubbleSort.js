// Bubbles the largest value to the end
// Time Complexity - O(n^2)
// Space Complexity - O(1)

function bubbleSort(arr) {
    for (let i = arr.length - 1; i > 0; i--) {
        let swap = false;

        for(let j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }

        if(!swap) break;
    }

    return arr;
}