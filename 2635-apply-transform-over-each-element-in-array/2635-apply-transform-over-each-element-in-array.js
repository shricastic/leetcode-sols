/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const res = []
    arr.forEach(function(index, value){
        res.push(fn(index, value))
    })
    return res 
};