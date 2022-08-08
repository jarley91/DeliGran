#ifndef DGR_REQUEST_H
#define DGR_REQUEST_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGUHashTable.h"

  typedef struct DGRRequest DGRRequest;

  extern struct DGRRequestEntity {
    string (*getIdRequest)(DGRRequest *oDGRRequest);
    string (*getHttpVersion)(DGRRequest *oDGRRequest);
    string (*getHttpMethod)(DGRRequest *oDGRRequest);
    string (*getUrl)(DGRRequest *oDGRRequest);
    string (*getUrlPath)(DGRRequest *oDGRRequest);
    unsigned short (*getNetworkType)(DGRRequest *oDGRRequest);
    DGUHashTable *(*getParameters)(DGRRequest *oDGRRequest);
    DGUHashTable *(*getHeaders)(DGRRequest *oDGRRequest);
    string (*getBody)(DGRRequest *oDGRRequest);
  } DGRRequestEntity;

#ifdef __cplusplus
}
#endif

#endif //DGR_REQUEST_H
