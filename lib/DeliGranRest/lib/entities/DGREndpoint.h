#ifndef DGR_ENDPOINT_H
#define DGR_ENDPOINT_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGULog.h"

  #include "DGREndpointGlobal.h"

  extern struct DGREndpointEntity {
    void (*destroy)(DGREndpoint *oDGREndpoint);
    DGREndpoint *(*new)();
    void (*setCallbackFunction)(DGREndpoint *oDGREndpoint, CallbackFunctionDGRE callbackFunction);
    void (*setDGULog)(DGULog *oDGULog);
    bool (*isValid)(DGREndpoint *oDGREndpoint);
    bool (*isValidConsume)(DGREndpoint *oDGREndpoint, string contentType);
    void (*setHttpMethod)(DGREndpoint *oDGREndpoint, string httpMethod);
    string (*getHttpMethod)(DGREndpoint *oDGREndpoint);
    void (*setUrlPath)(DGREndpoint *oDGREndpoint, string urlPath);
    string (*getUrlPath)(DGREndpoint *oDGREndpoint);
    DGREndpoint *(*copy)(DGREndpoint *oDGREndpoint);
    void (*addConsume)(DGREndpoint *oDGREndpoint, string consume);
    void (*addProduce)(DGREndpoint *oDGREndpoint, string produce);
  } DGREndpointEntity;

#ifdef __cplusplus
}
#endif

#endif //DGR_ENDPOINT_H
