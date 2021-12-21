#ifndef ANONYMIZER_H
#define ANONYMIZER_H

#include <settings.h>
#include <privateinfo.h>
#include <regex>

class Anonymizer
{
    public:
        Anonymizer();
        ~Anonymizer();
        string anonymize(string input);

    private:
        Settings *settings;
        PrivateInfo *privateInfo;
        string input;
        string hideAbsPaths(string os, string input);
        string hideIps(string input);
        string hideMacs(string input);
};

#endif // ANONYMIZER_H
