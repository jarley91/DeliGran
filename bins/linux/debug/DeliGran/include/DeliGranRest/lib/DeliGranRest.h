#ifndef DELIGRAN_REST_H
#define DELIGRAN_REST_H

#ifdef __cplusplus
extern "C"
{
#endif
  #include <stdbool.h>
  #include <netinet/in.h>

  #include "../../DeliGranDB/lib/entities/DGDBController.h"
  #include "../../DeliGranUtils/lib/entities/DGULog.h"
  #include "entities/DGREndpoint.h"
  #include "entities/DGRHttp.h"

  typedef struct DGRStreamConfigs {
    int BLOCK_SIZE_DEFAULT;
    unsigned long END;
    unsigned long ERROR;
    unsigned long SIZE_UNKOWN;
  } DGRStreamConfigs;

  typedef struct DGRSslSessions {
    unsigned short VERIFY_PEER;
    unsigned short VERIFY_HOSTNAME;
  } DGRSslSessions;

  typedef struct DGRGlobal {
    DGRStreamConfigs (*getStreamConfigs)(void);
    DGRSslSessions (*getSslSessions)(void);
    DGRHttp *(*getHttp)(void);
  } DGRGlobal;

  typedef struct DeliGranRestPrivate DeliGranRestPrivate;

  typedef struct DeliGranRest {
    DeliGranRestPrivate *private;
  } DeliGranRest;
  
  extern struct DeliGranRestEntity {
    DGRStreamConfigs (*getStreamConfigs)(void);
    DGRHNetworkTypes (*getNetworkTypes)(void);
    DGRSslSessions (*getSslSessions)(void);
    DGRHttp *(*getHttp)(void);
    DGDBController *(*getDGDBController)(DeliGranRest *oDeliGranRest);
    
    DeliGranRest *(*new)(void);
    void (*destroy)(DeliGranRest *oDeliGranRest);
    DGULog *(*getLogger)(DeliGranRest *oDeliGranRest);
    bool (*loadConfigFromFile)(DeliGranRest *oDeliGranRest, string pathFile);
    bool (*addEndpoint)(DeliGranRest *oDeliGranRest, DGREndpoint *endpoint);
    void (*start)(DeliGranRest *oDeliGranRest);
  } DeliGranRestEntity;

#ifdef __cplusplus
}
#endif

#endif // DELIGRAN_REST_H
