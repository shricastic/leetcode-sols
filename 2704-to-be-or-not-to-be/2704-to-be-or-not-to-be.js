/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe:  function (val2) { 
            return val2 === val ? true : function() {throw new Error('Not Equal')}()},
        notToBe: function (val2) {
            return val2 !== val ? true : function() {throw new Error('Equal')}()},
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */