#ifndef DGDB_CONTROLLER_H
#define DGDB_CONTROLLER_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGUString.h"

  #include "DGDBQuery.h"

  #define EndParameters NULL
  
  typedef struct DGDBDataSourceDrivers {
    string PostgreSQL;
    string MySQL;
    string MariaDB;
    string SQLite;
    string Redis;
    string MongoDB;
  } DGDBDataSourceDrivers;

  typedef struct DGDBController DGDBController;

  extern struct DGDBControllerEntity {
    DGDBDataSourceDrivers (*getDrivers)(void);
    DGDBQuery *(*execQuery)(DGDBController *oDGDBController, string nameDataSource, string query, ...);
    DGDBQuery *(*execQueryByPath)(DGDBController *oDGDBController, string nameDataSource, string queryPath, ...);
    void (*destroyQuery)(DGDBController *oDGDBController, DGDBQuery *oDGDBQuery);
    int (*getTotalColumns)(DGDBController *oDGDBController, DGDBQuery *oDGDBQuery);
    int (*getTotalRows)(DGDBController *oDGDBController, DGDBQuery *oDGDBQuery);
  } DGDBControllerEntity;

#ifdef __cplusplus
}
#endif

#endif //DGDB_CONTROLLER_H
