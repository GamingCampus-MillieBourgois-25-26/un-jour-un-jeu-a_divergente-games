#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/Demo/DemoScene.h"
#include "Scenes/Test/testScene.h"

int main(const int _argc, const char** _argv)
{
    Engine* const engine = Engine::GetInstance();

    engine->Init(_argc, _argv);

    //engine->GetModuleManager()->GetModule<SceneModule>()->SetScene<Demo::DemoScene>();
    engine->GetModuleManager()->GetModule<SceneModule>()->SetScene<Test::TestScene>();

    engine->Run();

    return 0;
}
