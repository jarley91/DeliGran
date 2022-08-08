#ifndef DGR_RESPONSE_H
#define DGR_RESPONSE_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdio.h>
  #include <stdint.h>

  #include "../../../DeliGranUtils/lib/entities/DGULog.h"
  #include "../../../DeliGranUtils/lib/entities/DGUString.h"

  typedef void (*StreamCallbackDGRRFunction)(void *streamUserData, uint64_t offset, string outBuf, size_t max);
  typedef struct DGRResponse DGRResponse;

  extern struct DGRResponseEntity {
    DGRResponse *(*new)(void);
    void (*destroy)(DGRResponse *oDGRResponse);
    void (*setBody)(DGRResponse *oDGRResponse, string body);
    string (*getBody)(DGRResponse *oDGRResponse);
  } DGRResponseEntity;

#ifdef __cplusplus
}
#endif

#endif //DGR_RESPONSE_H
