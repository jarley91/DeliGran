#ifndef DGU_THREAD_MUTEX_H
#define DGU_THREAD_MUTEX_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>

  #include "DGULog.h"
  #include "DGUThreadMutex.h"
  #include "DGUString.h"

  typedef struct DGUThreadMutexTypes {
    int normal;
    int errorCheck;
    int recursive;
  } DGUThreadMutexTypes;
  
  typedef struct DGUThreadMutex DGUThreadMutex;

  extern struct DGUThreadMutexEntity {
    DGUThreadMutexTypes (*getTypes)(void);
    DGUThreadMutex *(*new)(int type, string source, string function, int line);
    void (*setLogger)(DGUThreadMutex *oDGUThreadMutex, DGULog *oDGULog);
    void (*destroy)(DGUThreadMutex *oDGUThreadMutex, string source, string function, int line);
    bool (*lock)(DGUThreadMutex *oDGUThreadMutex, string source, string function, int line);
    bool (*unlock)(DGUThreadMutex *oDGUThreadMutex, string source, string function, int line);
  } DGUThreadMutexEntity;

#ifdef __cplusplus
}
#endif

#endif //DGU_THREAD_MUTEX_H
