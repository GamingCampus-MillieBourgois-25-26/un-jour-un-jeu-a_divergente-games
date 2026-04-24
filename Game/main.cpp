#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/Demo/DemoScene.h"
#include "Scenes/TopDownShooter/TopDownScene.h"
#include "Scenes/Touhou/TouhouScene.h"

#include "Touhou/QueueGlobal.h"   

int main(const int _argc, const char** _argv)
{
    
    GCreateQueue = nullptr;

    Engine* const engine = Engine::GetInstance();

    engine->Init(_argc, _argv);

    
    engine->GetModuleManager()
        ->GetModule<SceneModule>()
        ->SetScene<TouhouScene>();

    engine->Run();

    return 0;
}
