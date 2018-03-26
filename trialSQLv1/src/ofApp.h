#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

private:
	float currentSelfImage;
	SQLite::Database* db;
	

	string currentKey;
	string keys[13] = {"r","t", "y", "u", "i", "o", "g", "h", "j", "k", "b", "n", "m"};
};
