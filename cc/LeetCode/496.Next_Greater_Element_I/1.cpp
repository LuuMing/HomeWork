class Solution {
public:
    unordered_map<int,int> m;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int idx = 0;
        for(int i = 0; i < nums1.size() ; i++){
            if(m.count(nums1[i])){
                ret.push_back( m[nums1[i]] );
            }
            else{
                while(idx < nums2.size()){
                    bool flag = true;
                    for(int _i = idx + 1; _i < nums2.size(); _i++){
                        if(nums2[_i] > nums2[idx]){
                            flag = false;
                            m[nums2[idx]]  = nums2[_i];
                            break;
                        }
                    }
                    if(flag)
                        m[nums2[idx]] = -1;
                    if(nums2[idx] == nums1[i]){
                        ret.push_back(m[nums2[idx]]);
                        break;
                    }
                    idx++;
                }
            }
        }
        return ret;
    }
};