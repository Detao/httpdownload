#ifndef _OAL_REGISTRY_H_
#define _OAL_REGISTRY_H_

OAL_RESULT OAL_RegistryInit();
OAL_RESULT OAL_RegistrySetStringValue(char *name, char *value);
OAL_RESULT OAL_RegistryGetStringValue(char *name, char *value, int valueLen);


#endif


