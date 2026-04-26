#pragma once
#include "ProgramFlow/Scene.h"

class Tittle : public Scene {
	int framesCounter;
	Font font;
	int click;
	
public:
	Tittle(Font f);
	void InitScene() override {finishScreen = UNKNOWN;};
	void UpdateScreen() override;
	void DrawScreen() override;
	void UnloadScreen() override {finishScreen = UNKNOWN;};
	void OnMouseDown() override;
	void OnKeyPressed(KeyboardKey) override {};
	private:
};