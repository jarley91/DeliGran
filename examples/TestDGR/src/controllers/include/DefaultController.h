#ifndef DEFAULT_CONTROLLER_H
#define DEFAULT_CONTROLLER_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../../DeliGran/include/DeliGranUtils/lib/entities/DGULog.h"
  #include "../../../../DeliGran/include/DeliGranRest/lib/entities/DGRRequest.h"
  #include "../../../../DeliGran/include/DeliGranRest/lib/entities/DGRResponse.h"

  typedef struct DefaultControllerPrivate DefaultControllerPrivate;

  typedef struct DefaultController {
    DefaultControllerPrivate *private;
    void (*usersget)(DGRRequest *request, DGRResponse *response, void *userData);
    void (*userspost)(DGRRequest *request, DGRResponse *response, void *userData);
    void (*usersuserIdget)(DGRRequest *request, DGRResponse *response, void *userData);
  } DefaultController;

  extern struct DefaultControllerEntity {
    DefaultController *(*new)(void);
    void (*destroy)(DefaultController *oDefaultController);
    void (*setLogger)(DefaultController *oDefaultController, DGULog *oDGULog);
    DGULog *(*getLogger)(DefaultController *oDefaultController);
  } DefaultControllerEntity;

#ifdef __cplusplus
}
#endif

#endif //DEFAULT_CONTROLLER_H
