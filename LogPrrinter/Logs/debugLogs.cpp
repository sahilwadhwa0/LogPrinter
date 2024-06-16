#include "debugLogs.h"

namespace LOGS
{

  DebugLog::DebugLog(const std::string& filePath): _filePath(filePath) {}

  std::string DebugLog::messageTypeToString(messageType type)
  {
    switch(type)
    {
      case messageType::DEBUG: return "DEBUG:";
      case messageType::ERROR: return "ERROR:";
      case messageType::WARNING: return "WARNING:";
      case messageType::INFO: return "INFO:";
      default: return "UNKNOWN:";
    }
  }

  void DebugLog::logMessage(std::ostream& stream)
  {
    stream << std::endl;
  }

  DebugLog::~DebugLog(){}

}
