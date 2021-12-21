#include "anonymizer.h"

Anonymizer::Anonymizer()
{

}

Anonymizer::~Anonymizer(){

}

string Anonymizer::anonymize(string input){
    array<bool,4> savedSettings = settings -> loadSettings();
    string os = privateInfo -> getOS();

    string anonymizedOutput = "";
    if(savedSettings[1] && savedSettings[2] && savedSettings[3]){
        anonymizedOutput = hideAbsPaths(os, input);
        anonymizedOutput = hideIps(anonymizedOutput);
        anonymizedOutput = hideMacs(anonymizedOutput);
    }
    else if(savedSettings[1] == false && savedSettings[2] && savedSettings[3]){
        anonymizedOutput = hideIps(input);
        anonymizedOutput = hideMacs(anonymizedOutput);
    }
     else if(savedSettings[1] && savedSettings[2] == false && savedSettings[3]){
        anonymizedOutput = hideAbsPaths(os, input);
        anonymizedOutput = hideMacs(anonymizedOutput);
    }
    else if (savedSettings[1] && savedSettings[2] && savedSettings[3] == false){
        anonymizedOutput = hideAbsPaths(os, input);
        anonymizedOutput = hideIps(anonymizedOutput);
    }
    else if (savedSettings[1] && savedSettings[2]== false && savedSettings[3] == false){
        anonymizedOutput = hideAbsPaths(os, input);
    }
    else if (savedSettings[1]==false && savedSettings[2] && savedSettings[3] == false){
        anonymizedOutput = hideIps(input);
    }
    else if (savedSettings[1]==false && savedSettings[2]==false && savedSettings[3] ){
        anonymizedOutput = hideMacs(input);
    }

    qDebug("Anonymized String :\n %s", anonymizedOutput.c_str());
    return anonymizedOutput;
}

string Anonymizer::hideIps(string input){
    regex regIpV4("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");
    string output = regex_replace(input, regIpV4, "[IP_V4_ADDR]");
    regex regIpV6("(([0-9a-fA-F]{1,4}:){7,7}[0-9a-fA-F]{1,4}|([0-9a-fA-F]{1,4}:){1,7}:|([0-9a-fA-F]{1,4}:){1,6}:[0-9a-fA-F]{1,4}|([0-9a-fA-F]{1,4}:){1,5}(:[0-9a-fA-F]{1,4}){1,2}|([0-9a-fA-F]{1,4}:){1,4}(:[0-9a-fA-F]{1,4}){1,3}|([0-9a-fA-F]{1,4}:){1,3}(:[0-9a-fA-F]{1,4}){1,4}|([0-9a-fA-F]{1,4}:){1,2}(:[0-9a-fA-F]{1,4}){1,5}|[0-9a-fA-F]{1,4}:((:[0-9a-fA-F]{1,4}){1,6})|:((:[0-9a-fA-F]{1,4}){1,7}|:)|fe80:(:[0-9a-fA-F]{0,4}){0,4}%[0-9a-zA-Z]{1,}|::(ffff(:0{1,4}){0,1}:){0,1}((25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])\.){3,3}(25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])|([0-9a-fA-F]{1,4}:){1,4}:((25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])\.){3,3}(25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9]))");
    output = regex_replace(output, regIpV6, "[IP_V6_ADDR]");
    return output;
}

string Anonymizer::hideMacs(string input){
    regex regMac("([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})");
    string output = regex_replace(input, regMac, "[MAC_ADDR]");
    return output;
}

string Anonymizer::hideAbsPaths(string os, string input){
    string output = "";
    if(os=="windows"){
        regex regDriveLetter("[C-Z]:\\");
        output = regex_replace(input, regDriveLetter, "[DriveLetter]:/");
    }
    else if(os =="linux"){
        string homeDir = privateInfo ->getHomeDirectory();
        regex regHomeDir(homeDir);
        output = regex_replace(input, regHomeDir, "[HOME_DIR]");
    }
    else{
        qDebug("Probably MacOS or something else");
    }
    return output;
}
