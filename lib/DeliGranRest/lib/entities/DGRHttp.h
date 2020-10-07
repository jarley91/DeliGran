#ifndef DGR_HTTP_H
#define DGR_HTTP_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "DGRHttpGlobal.h"

  extern struct DGRHttpEntity {
    DGRHttp *(*new)();
  } DGRHttpEntity;

#ifdef __cplusplus
}
#endif

#endif //DGR_HTTP_H
