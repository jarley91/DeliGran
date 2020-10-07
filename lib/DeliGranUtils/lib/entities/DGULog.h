#ifndef DGU_LOG_H
#define DGU_LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "DGULogGlobal.h"

  typedef struct DGULog DGULog;

  extern struct DGULogEntity {
    DGULogTypes (*getTypes)();
    DGULogLeves (*getLeves)();
    
    DGULog *(*new)();
    void (*setFormatDateTime)(DGULog *oDGULog, string formatDateTime);
    void (*setFilePath)(DGULog *oDGULog, string filePath);
    void (*setType)(DGULog *oDGULog, string type);
    void (*setLevel)(DGULog *oDGULog, string level);
    void (*writeLog)(DGULog *oDGULog, string level, string source, string function, int line, string message, ...);
    void (*writeLogMessage)(DGULog *oDGULog, string message);
  } DGULogEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_LOG_H
