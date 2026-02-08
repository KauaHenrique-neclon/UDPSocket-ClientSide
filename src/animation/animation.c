#include "animation.h"
#include <cJSON.h>

AnimationSet* loadAnimations(const char* path)
{
    FILE* f = fopen(path, "rb");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* data = malloc(size + 1);
    fread(data, 1, size, f);
    data[size] = 0;
    fclose(f);

    cJSON* root = cJSON_Parse(data);
    free(data);
    if (!root) return NULL;

    int animCount = cJSON_GetArraySize(root);
    AnimationSet* set = malloc(sizeof(AnimationSet));
    set->animationCount = animCount;
    set->animations = malloc(sizeof(Animation) * animCount);

    for (int i = 0; i < animCount; i++) {
        cJSON* animObj = cJSON_GetArrayItem(root, i);
        cJSON* nameObj = cJSON_GetObjectItem(animObj, "NomeAnimacao");
        cJSON* frameCountObj = cJSON_GetObjectItem(animObj, "QtdSprites");
        cJSON* framesArr = cJSON_GetObjectItem(animObj, "frames");

        Animation* anim = &set->animations[i];
        memset(anim, 0, sizeof(Animation));
        anim->name = strdup(nameObj->valuestring);
        anim->frameCount = frameCountObj->valueint;
        anim->frames = malloc(sizeof(Frame) * anim->frameCount);

        for (int j = 0; j < anim->frameCount; j++) {
            cJSON* fObj = cJSON_GetArrayItem(framesArr, j);
            anim->frames[j].offset_x = cJSON_GetObjectItem(fObj, "offset_x")->valueint;
            anim->frames[j].offset_y = cJSON_GetObjectItem(fObj, "offset_y")->valueint;
            anim->frames[j].width    = cJSON_GetObjectItem(fObj, "width")->valueint;
            anim->frames[j].height   = cJSON_GetObjectItem(fObj, "height")->valueint;
        }
    }

    cJSON_Delete(root);
    return set;
}


Animation* getAnimation(AnimationSet* set, const char* name)
{
    for (int i = 0; i < set->animationCount; i++) {
        if (strcmp(set->animations[i].name, name) == 0)
            return &set->animations[i];
    }
    return NULL;
}

void animation_set_destroy(AnimationSet* set)
{
    if (!set) return;

    for (int i = 0; i < set->animationCount; i++) {
        Animation* anim = &set->animations[i];

        if (anim->name) {
            free(anim->name);
            anim->name = NULL;
        }

        if (anim->frames) {
            free(anim->frames);
            anim->frames = NULL;
        }
    }

    free(set->animations);
    free(set);
}
