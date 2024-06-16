#include <iostream>
#include "Logs/debugLogs.h"

int main() {
  LOGS::DebugLog debugLog("logs.txt");

  // example:
  debugLog.print(LOGS::messageType::INFO, "My age is :", 21);
  debugLog.print(LOGS::messageType::INFO, "counting goes like: ", 1, 2, 3, 4, 5);
}