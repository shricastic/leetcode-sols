class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m = m - 1;
        n = n - 1;

        for (int i = nums1.size() - 1; i >= 0; i--) {
            if (n < 0) {
                break;
            }

            if (m >= 0 && nums1[m] > nums2[n]) {
                nums1[i] = nums1[m];
                m--;
            } else {
                nums1[i] = nums2[n];
                n--;
            }
        }
    }
};