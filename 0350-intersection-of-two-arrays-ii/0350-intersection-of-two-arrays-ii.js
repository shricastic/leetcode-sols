/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let res = nums1
    let tmp = nums2
    
    let final = []
    
    if(nums1.length<nums2.length){
        res = nums2
        tmp = nums1
    }
    
    for(let i=0; i<tmp.length ; i++){
        let cur = tmp[i]
        if(res.includes(cur)){
            final.push(cur)
            res.splice(res.indexOf(cur), 1)
        }
    }
    
    return final
};