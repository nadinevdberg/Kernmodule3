#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"

//bron https://gist.github.com/rc1/3715e673ef175b5e0c93

class ofApp : public ofBaseApp{



	public:



		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y);
	//	void generatePieMesh(float totaal, float radius, float segments);

private:

	int currentYear = 0;
	int years[9] = { 1995, 2000, 2005, 2010, 2012, 2013, 2014, 2015, 2016 };

	float totaalHuishoudens;  //wordt een groeiende cirkel
	float hh_single;
	float hh_multiple;
	float hh_multiple_nokids;
	float hh_multiple_kids;
	float hh_multiple_notmarried;
	float hh_multiple_married;
	float hh_multiple_singleparrent;
	float hh_multiple_other;

	SQLite::Database* db;
		
};

