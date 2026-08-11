// Time complexity - O(N)

// The arr must be sorted
function sumZeroRefactor(arr) {
    let left = 0;
    let right = arr.length - 1;
    while (left < right) {
        let sum = arr[left] + arr[right];
        if(sum === 0) {
            return [arr[left], arr[right]];
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    } 
}

console.log(sumZeroRefactor([-4, -2, -6, -5, 2, 8, 5, 6, 7, 8,]));