/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(Array.isArray(obj)){
        return obj.length === 0
    } else{
        const keys = Object.keys(obj)
        return keys.length === 0
    }
};