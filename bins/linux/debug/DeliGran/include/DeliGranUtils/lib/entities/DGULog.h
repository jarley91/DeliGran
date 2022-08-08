#ifndef DGU_LOG_H
#define DGU_LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "DGUString.h"

  #define DGULFile __FILE__
  #define DGULFunction (string)__FUNCTION__
  #define DGULLine __LINE__

  typedef struct DGULogTypes {
    string CONSOLE;
    string FILE;
    string CONSOLE_AND_FILE;
  } DGULogTypes;

  typedef struct DGULogLeves {
    string INFO;
    string DEBUG;
    string WARNING;
    string ERROR;
    string ALL;
  } DGULogLeves;

  typedef struct DGULog DGULog;

  extern struct DGULogEntity {
    DGULogTypes (*getTypes)(void);
    DGULogLeves (*getLeves)(void);
    
    DGULog *(*new)(void);
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
