#ifndef ANONYMIZER_H
#define ANONYMIZER_H

#include <settings.h>
#include <privateinfo.h>
#include <regex>

/*!
 * \class Anonymizer
 * \brief The Anonymizer is implements methods to anonymize input logs
 * \since v 0.0.1
 */
class Anonymizer
{
    public:
        /*!
        \fn Anonymizer()
        Default Constructs
        */
        Anonymizer();
        /*!
        \fn ~Anonymizer()
        Default Deconstructs
        delete settings and privateInfo pointers
        */
        ~Anonymizer();
        /*!
          \fn string anonymize(string input, string projectName)
          Takes logs to be anonymized as \a input and specified project directory name as \a projectDirName
          and anonymize the input logs according to
          * user settings
          * whether the project name is empty or not
          and Returns a anonymized string
         */
        string anonymize(string input, string projectDirName);

    private:
        /*!
        Pointer to a instance of Settings class
        which is used retrieve user settings
        */
        Settings *settings;
        /*!
        Pointer to a instance of PrivateInfo class
        which is used retrieve user private information
        like OS, home directory
        */
        PrivateInfo *privateInfo;
        /*!
          \fn string hideAbsPaths(string input)
          Takes logs to be anonymized as \a input and anonymize the input logs by
          hiding the absolute paths
          in Windows this will be Drive Letter ex: D:,
          in Linux this will be users home directory ex: /home/username/
          and Returns a anonymized string
         */
        string hideAbsPaths(string input);
        /*!
          \fn string hideIps(string input)
          Takes logs to be anonymized as \a input and anonymize the input logs by
          hiding the IPv4 and IPv6 addresses
          and Returns a anonymized string
         */
        string hideIps(string input);
        /*!
          \fn string hideMacs(string input)
          Takes logs to be anonymized as \a input and anonymize the input logs by
          hiding the MAC addresses addresses where sections separated by
          hyphens (-) or colons(:)
          and Returns a anonymized string
         */
        string hideMacs(string input);
        /*!
          \fn  string hideProjectDirName(string projectName, string input)
          Takes project directory name as \a projectDirName,
          logs to be anonymized as \a input and anonymize the input logs by
          hiding project directory names and files containing project directory names
          and Returns a anonymized string
         */
        string hideProjectDirName(string projectDirName, string input);
};

#endif // ANONYMIZER_H
