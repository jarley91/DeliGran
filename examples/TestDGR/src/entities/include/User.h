#ifndef USER_H
#define USER_H

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct UserStruct UserType;
  typedef struct propertiesUser propertiesUser;
  typedef struct requiredUser requiredUser;
  typedef struct exampleUser exampleUser;

  struct propertiesUser {
    char id[3];
    char name[5];
    char lastName[9];
  };

  struct requiredUser {
    char id[3];
    char name[5];
  };

  struct exampleUser {
    char id[2];
    char name[12];
    char lastName[12];
  };

  struct UserStruct {
    char name[5];
    char markup[112];
    char markupOrigin[381];
    propertiesUser properties;
    requiredUser required;
    exampleUser example;
  };

  UserType User = (UserType) {
    .name = "User",
    .markup = "\
      User:\n\
        id : 4\n\
        name : Arthur Dent\n\
        lastName : Vargas Haya\n\
      ",
    .markupOrigin = "\
      User:\n\
        type: object\n\
        properties:\n\
          id:\n\
            type: integer\n\
            example: 4\n\
          name:\n\
            type: string\n\
            example: Arthur Dent\n\
          lastName:\n\
            type: string\n\
            example: Vargas Haya\n\
        required:\n\
          - id\n\
          - name\n\
      ",
    .properties = (propertiesUser) {
      .id = "id",
      .name = "name",
      .lastName = "lastName"
    },
    .required = (requiredUser) {
      .id = "id",
      .name = "name"
    },
    .example = (exampleUser) {
      .id = "4",
      .name = "Arthur Dent",
      .lastName = "Vargas Haya"
    }
  };

#ifdef __cplusplus
}
#endif

#endif //USER_H
