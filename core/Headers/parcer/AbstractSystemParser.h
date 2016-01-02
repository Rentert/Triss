//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_SYSTEMPARSERINFO_H
#define TRISS_SYSTEMPARSERINFO_H


class AbstractSystemParser {

public:
    virtual std::string update() = 0;

protected:
    std::string readAll(std::string dir);
    std::string toJson(std::string info);
    std::string* split(std::string info, char splitChar);
    std::string replaceChar(std::string str, char from);
    std::string createValue(std::string buffer, std::string endValue);
    inline std::string getEmptyString();
    std::string addSingleQuotes(std::string str);
    bool check(std::string str);
};


#endif //TRISS_SYSTEMPARSERINFO_H
