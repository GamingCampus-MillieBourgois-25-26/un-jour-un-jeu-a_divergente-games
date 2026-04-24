#pragma once
#include "Scene.h"
#include "Touhou/QueueSystem.h"

class TouhouScene : public Scene
{
public:
    TouhouScene();

    
    GameObject* CreateObjectSafe(const std::string& name);
    void FlushCreateQueue();

private:
    QueueSystem createQueue;
};
