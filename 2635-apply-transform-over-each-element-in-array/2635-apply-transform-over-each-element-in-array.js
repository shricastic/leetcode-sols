/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    arr.forEach(function(val, idx, arr){
        arr[idx] = fn(arr[idx], idx)
    })

    return arr;
};