#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	titleFont.load("SinkinSans-700Bold.otf", 30);
	subtitleFont.load("SinkinSans-300Light.otf", 15);
	baseFont.load("SinkinSans-200XLight.otf", 12);
	baseFont.setLineHeight(25);
	maxBarLength = 467;
	minBarLength = 1;
	currentSelfImageValue = 1;

	placeHolder.load("placeholder.jpg");	
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {


	//Healthmonitor
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 70, 550, 190); //BG
	ofSetColor(191, 191, 191);
	titleFont.drawString("HEALTH MONITOR", 87, 140);
	baseFont.drawString("While we may not see what the impact of our words \nis on the outside,\
 this monitor will show you what \nhappens on the inside.", 87, 165);

	//Self Image
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 291, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Self image", 87, 337);
	ofNoFill();
	ofDrawRectangle(87, 357, 475, 30); // placeholder progressbar
	ofFill();
	ofDrawRectangle(90, 359.5, currentSelfImageValue, 25); //dit zou de maximale grootte van de balk zijn, waarbij '470' van waarde gaat veranderen en bij 1 zal beginnen
	baseFont.drawString("Positive", 87, 412);
	baseFont.drawString("Negative", 487, 412);

	//Depression
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 483, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Depression", 87, 529);
	ofNoFill();
	ofDrawRectangle(87, 549, 475, 30); // placeholder progressbar
	baseFont.drawString("Low", 87, 604);
	baseFont.drawString("High", 500, 604);

	//Performance
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 675, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Performace", 87, 721);
	ofNoFill();
	ofDrawRectangle(87, 741, 475, 30); // placeholder progressbar
	baseFont.drawString("Low", 87, 796);
	baseFont.drawString("High", 500, 796);

	//Image placeholder

	placeHolder.draw(640, 70);

//	ofFill();
	//ofSetColor(20, 20, 20);
	
	//ofDrawRectangle(640, 70, 1000, 765);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (currentSelfImageValue <= maxBarLength) {
		if (key == ' ') {
			currentSelfImageValue += 10;
			//currentSelfImageValue = ofLerp(currentSelfImageValue, currentSelfImageValue + 20, 0.1);
		}
	}
}
