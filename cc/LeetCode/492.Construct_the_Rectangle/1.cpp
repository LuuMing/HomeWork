class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        int L = 0;
        for( ; W >= 1; W--)
            if(area % W == 0){
                L = area / W;
                break;
            }
        return {L,W};
    }
};
