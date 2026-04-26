#pragma once
#include <raylib.h>
#include "Misc/CommonInfo.h"
#include "EngineObjects/UI.h"

    const int screenWidth = 800;
    const int screenHeight = 600;


class Scene {
protected:
	GameScreen finishScreen;
	Vector2 mousePosition;
	UI canvas;
	
public:
	Scene();
	virtual void InitScene() = 0;
	virtual void UpdateScreen();
	virtual void DrawScreen() = 0;
	virtual void UnloadScreen() = 0;
	GameScreen FinishScreen() { return finishScreen; };

	virtual void OnMouseDown() = 0;
	virtual void OnKeyPressed(KeyboardKey) = 0;

	void ChangeScene(GameScreen sc){finishScreen = sc;}

private:
	void ManageInterruptions();
	
};

class Logo : public Scene {
	int framesCounter;

	int logoPositionX;
	int logoPositionY;

	int lettersCount;

	int topSideRecWidth;
	int leftSideRecHeight;

	int bottomSideRecWidth;
	int rightSideRecHeight;

	int state;
	float alpha;
public:
	Logo();
	void InitScene();
	void UpdateScreen() override;
	void DrawScreen();
	void UnloadScreen() {};
	void OnMouseDown() {};
	void OnKeyPressed(KeyboardKey) {};
};