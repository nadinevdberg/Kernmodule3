	#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );


private:
	int currentYear = 0;
	int years[5] = { 1820, 1910, 1945, 1968, 2005 };

	float currentPopulation_AU;
	float currentPopulation_NL;
	float currentPopulation_ZH;

	ofTrueTypeFont font;
	string jaartal;

	SQLite::Database* db;
	

};
