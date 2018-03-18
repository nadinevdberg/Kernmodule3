#pragma once

#include "ofMain.h"
#define IMAGES 3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		int maxBarLength; 
		int minBarLength;
		int totalImpact;

		float selfImageValue;
		float currentSelfImageValue;
		float newSelfImageValue;
		float increment;

		float currentPerformance;

		float currentDepression;

private:
	ofTrueTypeFont titleFont;
	ofTrueTypeFont subtitleFont;
	ofTrueTypeFont baseFont;

	ofImage placeHolder;

	ofImage imageList[IMAGES];

	bool showImage1 = false;
	bool showImage2 = false;
	bool showImage3 = false;

		
};
