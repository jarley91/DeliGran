#include "../include/DeliGranWS.h"

#include "../../DeliGranRest/lib/DeliGranRest.h"

#include "controllers/include/EmpresasController.h"

DGULog *logger;
DeliGranRest *oDeliGranRest;


void callbackHelloWorld(DGRRequest *request, DGRResponse *response) {
  puts("callbackHelloWorld");
}

int main(void) {
  oDeliGranRest = DeliGranRestEntity.new();
  
  if(oDeliGranRest) {
    logger = DeliGranRestEntity.getDGULog(oDeliGranRest);
    bool isLoadConfig = DeliGranRestEntity.loadConfigFromFile(oDeliGranRest, "/Users/jarley/Desktop/fuentes/qt/deligranrest/DeliGran/config/yaml/DeliGranRestConfig.yaml");

    if(isLoadConfig) {
      DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                            "Configuración cargada con éxito");
      
      EmpresasControllerEntity.setDGULog(logger);
      EmpresasController *oEmpresasController = EmpresasControllerEntity.new();
      DGREndpoint *oDGREndpoint = DGREndpointEntity.new();
      DGREndpointEntity.setHttpMethod(oDGREndpoint, DeliGranRestEntity.getHttp()->getMethods().GET);
      DGREndpointEntity.setUrlPath(oDGREndpoint, "/test/list/business");
      DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
      DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_XML);
      DGREndpointEntity.addConsume(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().TEXT_PLAIN);
      DGREndpointEntity.addProduce(oDGREndpoint, DeliGranRestEntity.getHttp()->getMediaTypes().APPLICATION_JSON);
      DGREndpointEntity.setCallbackFunction(oDGREndpoint, oEmpresasController->listarEmpresas);
      DeliGranRestEntity.addEndpoint(oDeliGranRest, oDGREndpoint);
      
      DGREndpointEntity.destroy(oDGREndpoint);
      DeliGranRestEntity.start(oDeliGranRest);

    } else {
      logger = DGULogEntity.new();
      DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                            "Error al cargar configuración desde archivo Yaml");
    }
  } else {
    logger = DGULogEntity.new();
    DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                          "Error al crear DeliGranRest");
  }
  
  return 0;
}
