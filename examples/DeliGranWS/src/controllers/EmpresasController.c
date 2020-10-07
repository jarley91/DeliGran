#include "include/EmpresasController.h"

#include "../../../DeliGranUtils/lib/entities/DGUHashTable.h"
#include "../../../DeliGranUtils/lib/entities/DGUMarkup.h"
#include "../../../DeliGranUtils/lib/entities/DGUString.h"
#include "../../../DeliGranUtils/lib/entities/DGUMemory.h"

DGULog *logger;

void setDGULogEmpresasController(DGULog *oDGULog) {
  logger = oDGULog;
}

void listHeaders(int index, string key, void *value) {
  DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                        "Header -> Index: %i Key: %s Value: %s", index, key, value);
}

void listarEmpresas(DGRRequest *request, DGRResponse *response) {
  DGULogEntity.writeLog(logger, DGULogEntity.getLeves().DEBUG, DGULFile, DGULFunction, DGULLine,
                        "Invocando listarEmpresas");
  
  DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                        "------------------------------------------------");

  DGUHashTableEntity.forEach(DGRRequestEntity.getHeaders(request), listHeaders);
  
  DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                        "------------------------------------------------");
  
  DGUMarkup *oDGUMarkup = DGUMarkupEntity.new();
  
  DGUMarkupEntity.setStringDocument(oDGUMarkup, DGRRequestEntity.getBody(request));
  
  string idTest = DGUMarkupEntity.getStringValue(oDGUMarkup, "/id");
  string nameTest = DGUMarkupEntity.getStringValue(oDGUMarkup, "/name");
  string dateTimeString = DGUStringEntity.getDateTime2String("%d/%m/%Y %H:%M:%S.%MCS");
  
  DGUMDDocument *document = DGUMarkupEntity.newDocument();
  DGUMarkupEntity.addPropertyToDocument(document, "nombre", "DeliGranREST");
  DGUMarkupEntity.addPropertyToDocument(document, "descripcion", "C Framework para aplicaciones REST");
  DGUMarkupEntity.addPropertyToDocument(document, "fecha-hora", dateTimeString);
  DGUMarkupEntity.addPropertyToDocument(document, "id-test", idTest);
  DGUMarkupEntity.addPropertyToDocument(document, "name-test", nameTest);
  
  DGUMDNode *detalles = DGUMarkupEntity.addNodeToDocument(document, "Detalles");
  DGUMarkupEntity.addPropertyToNode(detalles, "totalFuncionesImplementadas", "6");

  DGUMDNode *funcionesArray = DGUMarkupEntity.addArrayToNode("funciones", "funcion", detalles);

  DGUMDNode *itemFuncion1 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion1, "descripcion", "Configuración en base a un archivo o texto YAML/JSON");

  DGUMDNode *itemFuncion2 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion2, "descripcion", "Servidor HTTP y HTTPS");
  
  DGUMDNode *itemFuncion3 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion3, "descripcion", "Manejo de logs");
  
  DGUMDNode *itemFuncion4 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion4, "descripcion", "Endpoints");
  
  DGUMDNode *itemFuncion5 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion5, "descripcion", "Implementación de Controlador");
  
  DGUMDNode *itemFuncion6 = DGUMarkupEntity.newNodeItemArray();
  DGUMarkupEntity.addPropertyToNode(itemFuncion6, "descripcion", "Integración YAML/JSON");

  DGUMarkupEntity.addNodeToNode(itemFuncion1, funcionesArray);
  DGUMarkupEntity.addNodeToNode(itemFuncion2, funcionesArray);
  DGUMarkupEntity.addNodeToNode(itemFuncion3, funcionesArray);
  DGUMarkupEntity.addNodeToNode(itemFuncion4, funcionesArray);
  DGUMarkupEntity.addNodeToNode(itemFuncion5, funcionesArray);
  DGUMarkupEntity.addNodeToNode(itemFuncion6, funcionesArray);

  DGRResponseEntity.setBody(response, DGUMarkupEntity.documentToString(document, DGUMarkupEntity.getFormats().JSON));
  
  DGUStringEntity.destroy(idTest);
  DGUStringEntity.destroy(nameTest);
  DGUStringEntity.destroy(dateTimeString);
  DGUMarkupEntity.destroy(oDGUMarkup);
  DGUMarkupEntity.destroyDcoument(document);
}

EmpresasController *newEmpresasController() {
  EmpresasController *oEmpresasController = DGUMemoryEntity.malloc(sizeof(EmpresasController));
  oEmpresasController->listarEmpresas = &listarEmpresas;

  return oEmpresasController;
}

struct EmpresasControllerEntity EmpresasControllerEntity = {
  .new = &newEmpresasController,
  .setDGULog = &setDGULogEmpresasController
};
