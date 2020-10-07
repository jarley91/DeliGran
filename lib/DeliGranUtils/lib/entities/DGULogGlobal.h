#ifndef DGU_LOG_GLOBAL_H
#define DGU_LOG_GLOBAL_H

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

#ifdef __cplusplus
}
#endif

#endif //DGU_LOG_GLOBAL_H
