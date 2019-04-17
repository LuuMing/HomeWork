class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int idx = 0;
        int idxPre = 0;
        vector<string> ret;
        while(idx  < words.size())
        {
            int total = 0;
            int wordsTotal = 0;
            while(idx < words.size() && total  + words[idx].size() <= maxWidth)
            {
                 total += words[idx].size();
                 wordsTotal += words[idx].size();
                 if(total < maxWidth)
                     total += 1;
                 idx++;
            }
            string line;
            int residSpace = maxWidth - wordsTotal;
            vector<string> spaces;
            if(idx - idxPre - 1 != 0){    
                spaces.resize(idx - idxPre - 1, "");
                if(idx != words.size()){         
                    while(residSpace > 0){
                        for(auto &space: spaces){
                            space.push_back(' ');
                            residSpace--;
                            if(residSpace == 0)
                                break;
                        }
                    }
                }
                else{                             // for last line
                    for(auto &space: spaces){
                            space.push_back(' ');
                            residSpace--;
                    }
                    if(residSpace > 0)
                        spaces.push_back(string(residSpace,' '));
                }
            }
            else{                                   //for just two words
                spaces.resize(1,string(residSpace,' '));
            }
            int i = 0;
            while( idxPre < idx ){
                line += words[idxPre];
                if(i < spaces.size()){
                    line += spaces[i];
                    i++;
                }
                idxPre++;
            }
            ret.push_back(line);
        }
        return ret;
    }
};
