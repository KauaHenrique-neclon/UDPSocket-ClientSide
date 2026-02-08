#ifndef UDPSOCKETCLIENT_ANIMATION_H
#define UDPSOCKETCLIENT_ANIMATION_H
#include <SDL_stdinc.h>

typedef struct {
    int offset_x;
    int offset_y;
    int width;
    int height;
} Frame;

typedef struct {
    char* name;
    int frameCount;
    int lastFrame;
    Frame* frames;
    double delay;
    Uint32 lastTick;
} Animation;

typedef struct {
    int animationCount;
    Animation* animations;
} AnimationSet;

AnimationSet* loadAnimations(const char* path);
Animation* getAnimation(AnimationSet* set, const char* name);
void animation_set_destroy(AnimationSet* set);

#endif //UDPSOCKETCLIENT_ANIMATION_H