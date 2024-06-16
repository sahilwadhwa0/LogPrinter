#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

namespace LOGS
{
  enum class messageType
  {
    DEBUG,
    ERROR,
    WARNING,
    INFO,
    MAX
  };

  class DebugLog
  {
    std::string _filePath;

    void logMessage(std::ostream& stream);

    template<typename T, typename ...Args>
    void logMessage(std::ostream& stream,
        const T& value, const Args& ...args)
    {
      stream << value << " "; // process the first argument
      logMessage(stream, args...); // recurse with rest of arguments
    }

    std::string messageTypeToString(messageType type);

    public:

      DebugLog(const std::string& filePath=""); 

      template<typename ...Args>
      void print(messageType type, const Args& ...args)
      {
        std::ostringstream stream;
        stream << messageTypeToString(type);

        logMessage(stream, args...);

        // appending to log file if exist
        if(!_filePath.empty())
        {
          std::ofstream logFile(_filePath, std::ios::app); // Append mode
          if(!logFile)
          {
            std::cout << "ERROR: opening log file" << std::endl;
          }
          else
          {
            logFile << stream.str();
          }
        }

        // also printing in console
        std::cout << stream.str();
      }

      ~DebugLog();
  };

}

#endif // DEBUGLOG_H