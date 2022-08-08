#include "../include/TestDGR.h"

#include "../../DeliGran/include/DeliGranUtils/lib/entities/DGUMemory.h"
#include "../../DeliGran/include/DeliGranRest/lib/DeliGranRest.h"

#include "controllers/include//DefaultController.h"

typedef struct TestDGR TestDGR;

struct TestDGR {
  DGULog *logger;
  DeliGranRest *oDeliGranRest;
};

TestDGR *oTestDGR;

void destroyTestDGR(TestDGR *oTestDGR) {
  if(!oTestDGR) return;

  oTestDGR->logger = NULL;
  DeliGranRestEntity.destroy(oTestDGR->oDeliGranRest);
  DGUMemoryEntity.free((void *)&oTestDGR);
}

bool initTestDGR(void) {
  oTestDGR = DGUMemoryEntity.malloc(sizeof(TestDGR));

  if(!oTestDGR) return false;

  oTestDGR->oDeliGranRest = DeliGranRestEntity.new();

  if(!oTestDGR->oDeliGranRest) {
    destroyTestDGR(oTestDGR);

    return false;
  }

  oTestDGR->logger = NULL;

  return true;
}

int main(int argc, char *argv[]) {
  string configFilePath = DGUStringEntity.new("../config/config.yaml");

  if(argc == 2 ) {
    DGUStringEntity.destroy(&configFilePath);
    configFilePath = DGUStringEntity.new(argv[1]);
  }

  if(!initTestDGR()) {
    DGULogEntity.writeLog(NULL, DGULogEntity.getLeves().ERROR, DGULFile, DGULFunction, DGULLine,
                         "Error creating %s", "TestDGR");

    return EXIT_FAILURE;
  }

  oTestDGR->logger = DeliGranRestEntity.getLogger(oTestDGR->oDeliGranRest);
  bool isConfigFileLoad = DeliGranRestEntity.loadConfigFromFile(oTestDGR->oDeliGranRest, configFilePath);

  if(!isConfigFileLoad) {
    destroyTestDGR(oTestDGR);

    return EXIT_FAILURE;
  }

  DGREndpoint *oDGREndpoint = NULL;

  DefaultController *oDefaultController = DefaultControllerEntity.new();
  DefaultControllerEntity.setLogger(oDefaultController, oTestDGR->logger);

  oDGREndpoint = DGREndpointEntity.new();
  DGREndpointEntity.setHttpMethod(oDGREndpoint, DeliGranRestEntity.getHttp()->getMethods().GET);
  DGREndpointEntity.setUrlPath(oDGREndpoint, "/users");
  DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.addProduce(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.setController(oDGREndpoint, oDefaultController);
  DGREndpointEntity.setCallbackFunction(oDGREndpoint, oDefaultController->usersget);
  DeliGranRestEntity.addEndpoint(oTestDGR->oDeliGranRest, oDGREndpoint);
  DGREndpointEntity.destroy(oDGREndpoint);

  oDGREndpoint = DGREndpointEntity.new();
  DGREndpointEntity.setHttpMethod(oDGREndpoint, DeliGranRestEntity.getHttp()->getMethods().POST);
  DGREndpointEntity.setUrlPath(oDGREndpoint, "/users");
  DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.addProduce(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.setController(oDGREndpoint, oDefaultController);
  DGREndpointEntity.setCallbackFunction(oDGREndpoint, oDefaultController->userspost);
  DeliGranRestEntity.addEndpoint(oTestDGR->oDeliGranRest, oDGREndpoint);
  DGREndpointEntity.destroy(oDGREndpoint);

  oDGREndpoint = DGREndpointEntity.new();
  DGREndpointEntity.setHttpMethod(oDGREndpoint, DeliGranRestEntity.getHttp()->getMethods().GET);
  DGREndpointEntity.setUrlPath(oDGREndpoint, "/users/{userId}");
  DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.addProduce(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
  DGREndpointEntity.setController(oDGREndpoint, oDefaultController);
  DGREndpointEntity.setCallbackFunction(oDGREndpoint, oDefaultController->usersuserIdget);
  DeliGranRestEntity.addEndpoint(oTestDGR->oDeliGranRest, oDGREndpoint);
  DGREndpointEntity.destroy(oDGREndpoint);

  DeliGranRestEntity.start(oTestDGR->oDeliGranRest);

  DGUStringEntity.destroy(&configFilePath);
  destroyTestDGR(oTestDGR);

  return EXIT_SUCCESS;
}
