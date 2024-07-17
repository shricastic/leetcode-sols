/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let called = false
    let res = 0
    
    return function(...args){
        if(called){
            return undefined;
        } else{
            res = fn(...args)
            called = true
            return res
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
