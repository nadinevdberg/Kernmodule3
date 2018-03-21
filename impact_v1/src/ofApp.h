#pragma once

#include "ofMain.h"
#define IMAGES 3
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

	float selfImageValue;
	float currentSelfImageValue;
	float newSelfImageValue;
	float increment;

	float currentPerformance;

	float currentDepression;

	ofSoundPlayer soundPlayer[AUDIOFILES];
	bool playing[AUDIOFILES];
	int randomNumber;

	float newSelfImage;
	float newDepression = 0;
	float newPerformance = 0;


	ofTrueTypeFont titleFont;
	ofTrueTypeFont subtitleFont;
	ofTrueTypeFont baseFont;

	ofImage placeHolder;

	ofImage imageList[IMAGES];

	bool showImage1 = true;
	bool showImage2 = false;
	bool showImage3 = false;

	SQLite::Database* db;

};
