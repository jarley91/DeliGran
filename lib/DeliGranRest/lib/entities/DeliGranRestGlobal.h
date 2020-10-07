#ifndef DELIGRAN_REST_GLOBAL_H
#define DELIGRAN_REST_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include <stdbool.h>
  #include <netinet/in.h>

  #include <microhttpd.h>

  #include "../../../DeliGranUtils/lib/entities/DGULog.h"
  #include "../../lib/entities/DGREndpoint.h"
  #include "DGRHttpGlobal.h"

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
    DGRStreamConfigs (*getStreamConfigs)();
    DGRSslSessions (*getSslSessions)();
    DGRHttp *(*getHttp)();
  } DGRGlobal;

  extern struct DeliGranRESTGlobalEntity {
    DGRGlobal (*new)();
  } DeliGranRESTGlobalEntity;

  typedef struct DeliGranRestPrivate DeliGranRestPrivate;

  typedef struct DeliGranRest {
    DeliGranRestPrivate *private;
  } DeliGranRest;

#ifdef __cplusplus
}
#endif

#endif //DELIGRAN_REST_GLOBAL_H
