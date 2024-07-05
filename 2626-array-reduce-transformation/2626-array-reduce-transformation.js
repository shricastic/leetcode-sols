/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    nums.forEach(function(val, idx){
        init = fn(init, val)
    })
    
    return init;
};