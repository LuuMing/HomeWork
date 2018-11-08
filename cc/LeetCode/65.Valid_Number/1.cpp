class Solution {
public:
    bool isNumber(string s) {
        regex number_pattern{"^\\s*[+-]?(?:[0-9]+[.][0-9]*|[0-9]+|[.][0-9]+)(e[+-]?[0-9]+)?\\s*$"};
        return regex_match(s,number_pattern);
    }
};
