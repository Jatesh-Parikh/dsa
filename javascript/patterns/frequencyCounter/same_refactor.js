// Time complexity - O(N)

function same_refactor(arr1, arr2) {
    if(arr1.length !== arr2.length) {
        return false;
    }

    const frequencyCounter1 = {};
    for(const elem of arr1) {
        frequencyCounter1[elem] = (frequencyCounter1[elem] || 0) + 1;
    }
    const frequencyCounter2 = {};
    for (const elem of arr2) {
        frequencyCounter2[elem] = (frequencyCounter2[elem] || 0) + 1;
    }

    for(const key in frequencyCounter1) {
        if(!(key ** 2 in frequencyCounter2)) {
            return false;
        }

        if(frequencyCounter1[key] !== frequencyCounter2[key ** 2]) {
            return false;
        }
    }

    return true;
}

console.log(same_refactor([1, 2, 3], [1, 4, 9])); // true
console.log(same_refactor([1, 2, 3], [1, 1, 9])); // false