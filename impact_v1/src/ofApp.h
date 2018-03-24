#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

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



	float currentPerformance;

	float currentDepression;

	ofSoundPlayer soundPlayer[AUDIOFILES];
	bool playing[AUDIOFILES];
	int randomNumber;

	float newSelfImage;
	float newDepression;
	float newPerformance;

	int selfImageValue;
	float currentSelfImageValue;
	float newSelfImageValue;


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
