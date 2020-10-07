#ifndef DGR_RESPONSE_H
#define DGR_RESPONSE_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGULog.h"

  #include "DGRResponseGlobal.h"

  extern struct DGRResponseEntity {
    DGRResponse *(*new)();
    //void (*setDGULog)(DGULog *oDGULog);
    void (*destroy)(DGRResponse *oDGRResponse);
    void (*setBody)(DGRResponse *oDGRResponse, string body);
    string (*getBody)(DGRResponse *oDGRResponse);
  } DGRResponseEntity;

#ifdef __cplusplus
}
#endif

#endif //DGR_RESPONSE_H
