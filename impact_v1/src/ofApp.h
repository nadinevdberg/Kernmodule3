#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

#define IMAGES 10
#define AUDIOFILES 13

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

private:
	int maxBarLength;
	int minBarLength;
	int totalImpact;

	float currentPerformance;
	float currentSelfImageValue;
	float currentDepression;

	float newSelfImage;
	float newDepression;
	float newPerformance;

	int selfImageValue;
	int depressionValue;
	int performanceValue;

	ofSoundPlayer soundPlayer;

	ofTrueTypeFont titleFont;
	ofTrueTypeFont subtitleFont;
	ofTrueTypeFont baseFont;

	ofImage imageList[IMAGES];

	bool showImage1 = true;
	bool showImage2 = false;
	bool showImage3 = false;

	SQLite::Database* db;

};
