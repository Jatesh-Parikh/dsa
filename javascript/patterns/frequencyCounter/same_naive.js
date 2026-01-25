// Time complexity - O(N^2)

function same_naive(arr1, arr2) {
    if(arr1.length !== arr2.length) {
        return false;
    }

    for(i = 0; i < arr1.length; i++) {
        const correctIndex = arr2.indexOf(arr1[i] ** 2);
        if(correctIndex === -1) {
            return false;
        }
        arr2.splice(correctIndex, 1);
    }
    return true;
}

console.log(same_naive([1, 2, 3], [1, 4, 9])); // true
console.log(same_naive([1, 2, 3], [1, 1, 9])); // false