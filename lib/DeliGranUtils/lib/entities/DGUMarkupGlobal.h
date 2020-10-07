#ifndef DGU_Markup_GLOBAL_H
#define DGU_Markup_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "DGUString.h"

  typedef struct DGUMDFormats {
    string YAML;
    string JSON;
  } DGUMDFormats;

  typedef struct DGUMDDocument DGUMDDocument;
  typedef struct DGUMDNode DGUMDNode;

#ifdef __cplusplus
}
#endif

#endif //DGU_Markup_GLOBAL_H
