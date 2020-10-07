#ifndef DELIGRAN_REST_H
#define DELIGRAN_REST_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "entities/DeliGranRestGlobal.h"
  
  extern struct DeliGranRestEntity {
    DGRStreamConfigs (*getStreamConfigs)();
    DGRHNetworkTypes (*getNetworkTypes)();
    DGRSslSessions (*getSslSessions)();
    DGRHttp *(*getHttp)();
    
    DeliGranRest *(*new)();
    DGULog *(*getDGULog)(DeliGranRest *oDeliGranRest);
    bool (*loadConfigFromFile)(DeliGranRest *oDeliGranRest, string pathFile);
    bool (*addEndpoint)(DeliGranRest *oDeliGranRest, DGREndpoint *endpoint);
    void (*start)(DeliGranRest *oDeliGranRest);
  } DeliGranRestEntity;

#ifdef __cplusplus
}
#endif

#endif // DELIGRAN_REST_H
