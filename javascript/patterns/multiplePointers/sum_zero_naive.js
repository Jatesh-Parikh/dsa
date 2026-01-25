// Time complexity - O(N)

function sum_zero_naive(arr) {
    for(let i = 0; i < arr.length; i++) {
        for(let j = i + 1; j < arr.length; j++) {
            if(arr[i] + arr[j] === 0) {
                return [arr[i], arr[j]]
            }
        }
    }
}

console.log(sum_zero_naive([-4, -2, -6, -5, 2, 8, 5, 6, 7, 8,]))