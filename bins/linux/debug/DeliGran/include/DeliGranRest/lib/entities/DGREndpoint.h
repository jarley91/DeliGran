#ifndef DGR_ENDPOINT_H
#define DGR_ENDPOINT_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGULog.h"

  #include "DGRRequest.h"
  #include "DGRResponse.h"

  typedef struct DGREndpointPrivate DGREndpointPrivate;
  typedef struct DGREndpoint DGREndpoint;

  typedef void (*CallbackFunctionDGRE)(DGRRequest *request, DGRResponse *response, void *userData);

  extern struct DGREndpointEntity {
    void (*destroy)(DGREndpoint *oDGREndpoint);
    DGREndpoint *(*new)(void);
    void (*setController)(DGREndpoint *oDGREndpoint, void *controller);
    void (*setCallbackFunction)(DGREndpoint *oDGREndpoint, CallbackFunctionDGRE callbackFunction);
    void (*setLogger)(DGREndpoint *oDGREndpoint, DGULog *oDGULog);
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
