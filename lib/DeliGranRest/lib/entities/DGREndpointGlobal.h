#ifndef DGR_ENDPOINT_GLOBAL_H
#define DGR_ENDPOINT_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif
  #include "DGRRequest.h"
  #include "DGRResponse.h"

  typedef struct DGREndpointPrivate DGREndpointPrivate;
  typedef struct DGREndpoint DGREndpoint;

  typedef void (*CallbackFunctionDGRE)(DGRRequest *request, DGRResponse *response);

#ifdef __cplusplus
}
#endif

#endif //DGR_ENDPOINT_GLOBAL_H
