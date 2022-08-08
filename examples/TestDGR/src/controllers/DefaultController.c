#include "include/DefaultController.h"

#include "../../../DeliGranUtils/lib/entities/DGUMemory.h"
#include "../../../DeliGranUtils/lib/entities/DGUMarkup.h"

struct DefaultControllerPrivate {
  DGULog *logger;
};

bool isValidStructDefaultController(DefaultController *oDefaultController) {
  if(!oDefaultController) return false;
  if(!oDefaultController->private) return false;

  return true;
}

void setLoggerDefaultController(DefaultController *oDefaultController, DGULog *oDGULog) {
  if(!isValidStructDefaultController(oDefaultController)) return;

  oDefaultController->private->logger = oDGULog;
}

DGULog *getLoggerDefaultController(DefaultController *oDefaultController) {
  if(!isValidStructDefaultController(oDefaultController)) return NULL;

  return oDefaultController->private->logger;
}

void destroyDefaultController(DefaultController *oDefaultController) {
  if(oDefaultController) {
    if(oDefaultController->private) {
      oDefaultController->private->logger = NULL;
      DGUMemoryEntity.free((void *)&oDefaultController->private);
    }

    DGUMemoryEntity.free((void *)&oDefaultController);
  }
}

void usersgetDefaultController(DGRRequest *request, DGRResponse *response, void *userData) {
  DefaultController *oDefaultController = (DefaultController *) userData;

  // Code ...

  //DGUMarkup *oDGUMarkup = DGUMarkupEntity.new();
  //DGUMarkupEntity.setLogger(oDGUMarkup, DefaultControllerEntity.getLogger(oDefaultController));

  //DGUMarkupEntity.setStringDocument(oDGUMarkup, Entity.markup);
  //string entityNodePath = DGUStringEntity.format("/%s", Entity.name);
  //DGUMarkupEntity.setNodeKeyValueByPath(oDGUMarkup, entityNodePath, Entity.properties.nameProperty, "Value propertie");

  //DGUStringEntity.destroy(&entityNodePath);

  //DGRResponseEntity.setBody(response, DGUMarkupEntity.toString(oDGUMarkup, DGUMarkupEntity.getFormats().JSON));

  //DGUMarkupEntity.destroy(oDGUMarkup);

  DGRResponseEntity.setBody(response, "Response from controller DefaultController, method usersgetDefaultController");

}

void userspostDefaultController(DGRRequest *request, DGRResponse *response, void *userData) {
  DefaultController *oDefaultController = (DefaultController *) userData;

  // Code ...

  //DGUMarkup *oDGUMarkup = DGUMarkupEntity.new();
  //DGUMarkupEntity.setLogger(oDGUMarkup, DefaultControllerEntity.getLogger(oDefaultController));

  //DGUMarkupEntity.setStringDocument(oDGUMarkup, Entity.markup);
  //string entityNodePath = DGUStringEntity.format("/%s", Entity.name);
  //DGUMarkupEntity.setNodeKeyValueByPath(oDGUMarkup, entityNodePath, Entity.properties.nameProperty, "Value propertie");

  //DGUStringEntity.destroy(&entityNodePath);

  //DGRResponseEntity.setBody(response, DGUMarkupEntity.toString(oDGUMarkup, DGUMarkupEntity.getFormats().JSON));

  //DGUMarkupEntity.destroy(oDGUMarkup);

  DGRResponseEntity.setBody(response, "Response from controller DefaultController, method userspostDefaultController");

}

void usersuserIdgetDefaultController(DGRRequest *request, DGRResponse *response, void *userData) {
  DefaultController *oDefaultController = (DefaultController *) userData;

  // Code ...

  //DGUMarkup *oDGUMarkup = DGUMarkupEntity.new();
  //DGUMarkupEntity.setLogger(oDGUMarkup, DefaultControllerEntity.getLogger(oDefaultController));

  //DGUMarkupEntity.setStringDocument(oDGUMarkup, Entity.markup);
  //string entityNodePath = DGUStringEntity.format("/%s", Entity.name);
  //DGUMarkupEntity.setNodeKeyValueByPath(oDGUMarkup, entityNodePath, Entity.properties.nameProperty, "Value propertie");

  //DGUStringEntity.destroy(&entityNodePath);

  //DGRResponseEntity.setBody(response, DGUMarkupEntity.toString(oDGUMarkup, DGUMarkupEntity.getFormats().JSON));

  //DGUMarkupEntity.destroy(oDGUMarkup);

  DGRResponseEntity.setBody(response, "Response from controller DefaultController, method usersuserIdgetDefaultController");

}

DefaultController *newDefaultController(void) {
  DefaultController *oDefaultController = DGUMemoryEntity.malloc(sizeof(DefaultController));

  if(!oDefaultController) {
    destroyDefaultController(oDefaultController);

    return NULL;
  }

  oDefaultController->private = DGUMemoryEntity.malloc(sizeof(DefaultControllerPrivate));

  if(!oDefaultController->private) {
    destroyDefaultController(oDefaultController);

    return NULL;
  }

  oDefaultController->private->logger = NULL;
  oDefaultController->usersget = &usersgetDefaultController;
  oDefaultController->userspost = &userspostDefaultController;
  oDefaultController->usersuserIdget = &usersuserIdgetDefaultController;

  return oDefaultController;
}

struct DefaultControllerEntity DefaultControllerEntity = {
  .new = &newDefaultController,
  .destroy = &destroyDefaultController,
  .setLogger = &setLoggerDefaultController,
  .getLogger = &getLoggerDefaultController
};

