#ifndef EMPRESAS_CONTROLLER_H
#define EMPRESAS_CONTROLLER_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../../DeliGranUtils/lib/entities/DGULog.h"

  #include "../../../../DeliGranRest/lib/entities/DGRRequest.h"
  #include "../../../../DeliGranRest/lib/entities/DGRResponse.h"

  typedef struct EmpresasController {
    void (*listarEmpresas)(DGRRequest *request, DGRResponse *response);
  } EmpresasController;

  extern struct EmpresasControllerEntity {
    EmpresasController *(*new)();
    void (*setDGULog)(DGULog *oDGULog);
  } EmpresasControllerEntity;

#ifdef __cplusplus
}
#endif

#endif // EMPRESAS_CONTROLLER_H
