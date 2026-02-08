#ifndef UDPSOCKETCLIENT_TEXTURE_H
#define UDPSOCKETCLIENT_TEXTURE_H
#include "../map/map.h"
Texture texture_load(const char* path);
void texture_destroy(Texture* tex);
#endif //UDPSOCKETCLIENT_TEXTURE_H