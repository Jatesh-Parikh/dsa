// Time complexity - O(N)

function validAnagram(first, second) {
    if(first.length !== second.length) {
        return false;
    }

    const lookup = {};

    for (const char of first) {
        lookup[char] = (lookup[char] || 0) + 1;
    }

    for (const char of second) {
        if(!lookup[char]) {
            return false;
        } else {
            lookup[char] -= 1;
        }
    }
    return true;
}

console.log(validAnagram("hello", "merry")); // false
console.log(validAnagram("cinema", "iceman")); // true