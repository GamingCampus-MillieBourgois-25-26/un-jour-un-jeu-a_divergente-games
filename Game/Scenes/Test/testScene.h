#pragma once
#include "Core/Scene.h"
#include "Test/Player.h"

namespace Test
{
	class TestScene final : public Scene
	{
	public:
		TestScene();
		void CreateBots();
		float minSize = 100.f;
		float maxSize = 300.f;
		//Fonction pour les murs
	private:

	};

}