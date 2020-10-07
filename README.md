# DeliGranREST
C Framework para aplicaciones REST

DeliGran se basa y usa lo siguiente:

- [GNU Libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/)
- [The GnuTLS Transport Layer Security Library](https://www.gnutls.org/)
- [SDS - Simple Dynamic Strings](https://github.com/antirez/sds)
- [libfyaml](https://github.com/pantoniou/libfyaml)
- [hashdict.c](https://github.com/exebook/hashdict.c)
- [ulfius](https://github.com/babelouest/ulfius)

Cada implementación siempre está hecha simple y sencilla dentro de un ecosistema puro en **C**, esto con el fin de que sea un producto fácil de implementar, pero sin perder la solidez y robustez que brinda **C**

En este repositorio iré publicando los binarios y librerías con el fin de que las personas interesadas puedan ir haciendo sus pruebas.

## Lo implementado:
- Configuración en base a un archivo o texto YAML/JSON
- Servidor HTTP y HTTPS
- Logger
- Endpoints
- Implementación de Controlador
- Integración YAML/JSON

## A implementar:
- Integración con un servidor de configuración
- Niveles de logs, control de archivos generados
- Encriptar datos sensibles
- OAuth 2.0
- Integración con Kubernetes
- Integración con REDIS
- Integración con PostgreSQL
- Generador de proyectos con OpenAPI
- Iré agregando más ...

## Empecemos:

Para iniciar el servidor web, es necesario tener la siguiente configuración en un archivo o texto YAML/JSON:

```yaml
deligran-rest:
  config:
    # THIS_FILE or CONFIG_SERVER
    type: THIS_FILE
  server:
    port: 8081
    # IPV4, IPV6 or ALL
    network-type: IPV4
    # HTTP or HTTPS
    protocol: HTTPS
    root-ca-private-key:
      -----BEGIN ENCRYPTED PRIVATE KEY-----
      .
      .
      .
      -----END ENCRYPTED PRIVATE KEY-----
    root-ca-private-key-password: password
    root-ca-certificate:
      -----BEGIN CERTIFICATE-----
      .
      .
      .
      -----END CERTIFICATE-----
  application:
    # "type-channel-name-version" used for name base path and file log
    type: business
    channel: sales
    name: products
    version: v1
    description:
      Inicios de DeliGran REST C Framework

deligran-utils-log:
  config:
    # CONSOLE, FILE or CONSOLE_AND_FILE
    type: CONSOLE_AND_FILE
    level: ALL
    # format sys/time was added %MCS = Microseconds and %MLS = Milliseconds
    format-date-time: "%d/%m/%Y %H:%M:%S.%MCS"
    file:
      path: /path/to/log/file
```

Usando la configuración con **libDeliGranRest** y **libDeliGranUtils**

### Principal:

Archivo fuente:

```c
#include "DeliGranRest.h"

#include "controllers/include/EmpresasController.h"

DGULog *logger;
DeliGranRest *oDeliGranRest;

int main(void) {
  oDeliGranRest = DeliGranRestEntity.new();

  if(oDeliGranRest) {
    bool isLoadConfig = oDeliGranRest.loadConfigFromFile("/path/to/log/file/DeliGranRestConfig.yaml");

    if(isLoadConfig) {
      logger = DeliGranRestEntity.getDGULog(oDeliGranRest);
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
      oDGULog = DGULogEntity.new();
      oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                      "Error al cargar configuración desde archivo Yaml");
    }
  } else {
    logger = DGULogEntity.new();
    DGULogEntity.writeLog(logger, DGULogEntity.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                          "Error al crear DeliGranRest");
  }
  
  return 0;
}
```
### Controlador:

Archivo cabecera:

```c
#ifndef EMPRESAS_CONTROLLER_H
#define EMPRESAS_CONTROLLER_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "DGULog.h"

  #include "DGRRequest.h"
  #include "DGRResponse.h"

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
```
Archivo fuente:

```c
#include "include/EmpresasController.h"

#include "DGUHashTable.h"
#include "DGUMarkup.h"
#include "DGUString.h"
#include "DGUMemory"

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

```

Consola o archivo el log:

![initial-log-1, Initial log 1](images/initial-log-1.png)

Prueba con Postman:

![initial-log-1, Initial log 1](images/postman-get-1.png)

Consola o archivo el log:

![initial-log-1, Initial log 1](images/initial-log-2.png)