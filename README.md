# DeliGranREST
C Framework para aplicaciones REST

Desligran se basa y uso lo siguiente:

- [GNU Libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/)
- [The GnuTLS Transport Layer Security Library](https://www.gnutls.org/)
- [SDS - Simple Dynamic Strings](https://github.com/antirez/sds)
- [libfyaml](https://github.com/pantoniou/libfyaml)
- [hashdict.c](https://github.com/exebook/hashdict.c)

Cada implementación siempre está en hacerlo lo más simple y sencillo posible dentro de un ecosistema puro en **Lenguaje C**, esto con el fin de que sea un producto facil de implementar pero sin perder la solidez y robustes que proporciona el **Lenguaje C**

En este repositorio iré publicando los binarios con el fin que las personas interesadas en lo descrito líneas arriba puedan ir haciendo sus pruebas.

## Lo implementado:
- Configuración en base a un archivo o texto YAML
- Servidor HTTP
- Manejo de logs
- Agregar Endpoints
- Implementación de Controlador

## A implementar:
- Integración con un servidor de configuración
- Servidor HTTPS
- Niveles de logs control de archivos generados
- Encriptar datos sensibles
- OAuth 2.0
- Integración con JSON
- Integración con Kubernetes
- Integración con REDIS
- Integración con PostgreSQL
- Generador de proyectos con OpenAPI
- Iré agregando más ...

## Empecemos con lo ya implementado:

Para iniciar el servidor web, es necesario tener la siguiente configuración en un archivo o texto:

```yaml
deligran-rest:
  config:
    # THIS_FILE or CONFIG_SERVER
    type: THIS_FILE
application:
    port: 8081
    # IPV4, IPV6 or IPV4_AND_IPV6
    network-type: IPV4 # Por confirmar si se mantiene
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
    format-date-time: "%d/%m/%Y %H:%M:%S.%MCS"
    file:
      path: /path/to/log/file
```

Usando la configuración con **libDeliGranRest** y **libDeliGranUtils**

### Principal:

Archivo fuente:

```c
DeliGranRest oDeliGranRest;
DGULog oDGULog;

int main(void) {
  oDeliGranRest = DeliGranRestEntity.new();
  bool isLoadConfig = oDeliGranRest.loadConfigFromFile("/path/to/log/file/DeliGranRestConfig.yaml");

  oDGULog = oDeliGranRest.getDGULog();

  if(isLoadConfig) {
    oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                     "Configuración cargada con éxito");

    EmpresasController oEmpresasController = EmpresasControllerEntity.new();
    DGREndpoint *oDGREndpoint = DGREndpointEntity.new();
    DGREndpointEntity.setHttpMethod(oDGREndpoint, oDeliGranRest.getHttp()->getMethods().GET);
    DGREndpointEntity.setUrlPath(oDGREndpoint, "/test/list/business");
    DGREndpointEntity.addConsume(oDGREndpoint, oDeliGranRest.getHttp()->getMediaTypes().APPLICATION_JSON);
    DGREndpointEntity.addConsume(oDGREndpoint, oDeliGranRest.getHttp()->getMediaTypes().APPLICATION_XML);
    DGREndpointEntity.addConsume(oDGREndpoint, oDeliGranRest.getHttp()->getMediaTypes().TEXT_PLAIN);
    DGREndpointEntity.addProduce(oDGREndpoint, oDeliGranRest.getHttp()->getMediaTypes().APPLICATION_JSON);
    oDGREndpoint->callbackFunction = oEmpresasController.listarEmpresas;
    oDeliGranRest.addEndpoint(oDGREndpoint);
    
    DGREndpointEntity.destroy(oDGREndpoint);

    oDeliGranRest.start();

  } else {
    oDGULog = DGULogEntity.new();
    oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                     "Error al cargar configuración desde archivo Yaml");
  }
  
  return 0;
}
```
### Controlador:

Archivo cabecera:

```c
#ifndef EMPRESAS_CONTROLLER_H
#define EMPRESAS_CONTROLLER_H

#include "DGRRequestUser.h"
#include "DGRResponseUser.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct EmpresasController {
    void (*listarEmpresas)(DGRRequest *request, DGRResponse *response);
  } EmpresasController;

  extern struct EmpresasControllerClass {
    EmpresasController (*new)();
  } EmpresasControllerEntity;

#ifdef __cplusplus
}
#endif

#endif // EMPRESAS_CONTROLLER_H

```
Archivo fuente:

```c
#include "include/EmpresasController.h"

#include "DGUHashTableUser.h"

DGULog oDGULog;

void listHeaders(int index, string key, void *value) {
  oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                   "Header -> Index: %i Key: %s Value: %s", index, key, value);
}

void listarEmpresas(DGRRequest *request, DGRResponse *response) {
  oDGULog.writeLog(oDGULog.getLeves().DEBUG, DGULFile, DGULFunction, DGULLine,
                   "Invocando listarEmpresas");
  
  oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                   "------------------------------------------------");

  DGUHashTableUserEntity.forEach(DGRRequestUserEntity.getHeaders(request), listHeaders);
  
  oDGULog.writeLog(oDGULog.getLeves().INFO, DGULFile, DGULFunction, DGULLine,
                   "------------------------------------------------");
  
  puts(DGRRequestUserEntity.getUrl(request));
}

static EmpresasController new() {
  EmpresasController oEmpresasController = {
      .listarEmpresas = &listarEmpresas,
  };

  return oEmpresasController;
}

struct EmpresasControllerClass EmpresasControllerEntity = {.new = &new};
```

Consola o archivo el log:

![initial-log-1, Initial log 1](images/initial-log-1.png)

Prueba con Postman:

![initial-log-1, Initial log 1](images/postman-get-1.png)

Consola o archivo el log:

![initial-log-1, Initial log 1](images/initial-log-2.png)