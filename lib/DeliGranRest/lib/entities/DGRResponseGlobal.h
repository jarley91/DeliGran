#ifndef DGR_RESPONSE_GLOBAL_H
#define DGR_RESPONSE_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdio.h>
  #include <stdint.h>

  #include "../../../DeliGranUtils/lib/entities/DGUString.h"

  typedef void (*StreamCallbackDGRRFunction)(void *streamUserData, uint64_t offset, string outBuf, size_t max);
  typedef struct DGRResponse DGRResponse;

#ifdef __cplusplus
}
#endif

#endif //DGR_RESPONSE_GLOBAL_H
