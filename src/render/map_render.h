#ifndef UDPSOCKETCLIENT_MAP_RENDER_H
#define UDPSOCKETCLIENT_MAP_RENDER_H
#include "../map/map.h"

Texture* getTextureForTile(Map* map, Texture* textures, int tileId);
void map_render(Map* map, Texture* textures);
#endif //UDPSOCKETCLIENT_MAP_RENDER_H