#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		int maxBarLength; 
		int minBarLength;

		float selfImageValue;
		float currentSelfImageValue;
		float newSelfImageValue;
		float increment;


private:
	ofTrueTypeFont titleFont;
	ofTrueTypeFont subtitleFont;
	ofTrueTypeFont baseFont;

	ofImage placeHolder;


		
};
