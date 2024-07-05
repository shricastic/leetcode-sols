/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const res = []
    
    arr.forEach(function(val, idx){
        if(fn(val, idx)){
            res.push(val)
        }
    })
    
    return res
};