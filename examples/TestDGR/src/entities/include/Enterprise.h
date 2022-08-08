#ifndef ENTERPRISE_H
#define ENTERPRISE_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct EnterpriseStruct EnterpriseType;
  typedef struct propertiesEnterprise propertiesEnterprise;
  typedef struct requiredEnterprise requiredEnterprise;
  typedef struct exampleEnterprise exampleEnterprise;

  struct propertiesEnterprise {
    char id[3];
    char name[5];
  };

  struct requiredEnterprise {
    char id[3];
    char name[5];
  };

  struct exampleEnterprise {
    char id[2];
  };

  struct EnterpriseStruct {
    char name[11];
    char markup[78];
    char markupOrigin[258];
    propertiesEnterprise properties;
    requiredEnterprise required;
    exampleEnterprise example;
  };

  EnterpriseType Enterprise = (EnterpriseType) {
    .name = "Enterprise",
    .markup = "\
      Enterprise:\n\
        id : 4\n\
        name : name\n\
      ",
    .markupOrigin = "\
      Enterprise:\n\
        type: object\n\
        properties:\n\
          id:\n\
            type: integer\n\
            example: 4\n\
          name:\n\
            type: string\n\
        required:\n\
          - id\n\
          - name\n\
      ",
    .properties = (propertiesEnterprise) {
      .id = "id",
      .name = "name"
    },
    .required = (requiredEnterprise) {
      .id = "id",
      .name = "name"
    },
    .example = (exampleEnterprise) {
      .id = "4",
    }
  };

#ifdef __cplusplus
}
#endif

#endif //ENTERPRISE_H
