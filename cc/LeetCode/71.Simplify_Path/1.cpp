class Solution {
public:
    string simplifyPath(string path) {
        vector<string> out;
        out.push_back("/");
        string ret;
        int i = 0;
        while( i < path.size())
        {
            if(path[i] == '/' && out.back().back() == '/')
            {
                i++;
            }
            else
            {
                string tmp;
                while(path[i] != '/' && i < path.size())
                {
                    tmp.push_back(path[i++]);
                }
                if(tmp == "..")
                {
                    if(out.size() >= 2)
                        out.pop_back();
                }
                else if(tmp == ".")
                    continue;
                else
                {
                    tmp.push_back('/');
                    out.push_back(tmp);
                }
            }
        }
        for(auto & str:out)
            ret += str;
        if(ret.size() > 1 && ret.back() == '/')
            ret.pop_back();
        return ret;
    }
};
