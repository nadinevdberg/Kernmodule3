#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {



	//ofSetBackgroundColor(ofColor::white);
	titleFont.load("SinkinSans-700Bold.otf", 30);
	subtitleFont.load("SinkinSans-300Light.otf", 15);
	baseFont.load("SinkinSans-200XLight.otf", 12);
	baseFont.setLineHeight(25);
	maxBarLength = 467;
	minBarLength = 1;
	currentSelfImageValue = 1;
	currentDepression = 1;
	currentPerformance = 1;

	newSelfImage = 0;

	//images inladen
	for (int i = 0; i < 3; i++) {
		ofLog() << "L O A D I N G    I M A G E " << i << endl;
		imageList[i].load(ofToString(i) + ".jpg");
	}

	//audio inladen
	for (int i = 0; i < AUDIOFILES; i++) {
		soundPlayer[i].load(ofToDataPath(ofToString(i + 1) + ".mp3"));
		soundPlayer[i].setLoop(true);

		soundPlayer[i].play();
		soundPlayer[i].setPaused(true);
	}

	ofSoundSetVolume(0.5);
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	totalImpact = currentSelfImageValue + currentDepression + currentPerformance;
	//ofLog() << "Total Impact = " << totalImpact << endl;

	if (showImage1 == true) {
		ofSetBackgroundColor(ofColor::lightGray);
	}
	if (showImage2 == true) {
		ofSetBackgroundColor(ofColor::gray);
	}
	if (showImage3 == true) {
		ofSetBackgroundColor(ofColor::black);
	}
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
	currentSelfImageValue = ofLerp(currentSelfImageValue, newSelfImage, 0.2);
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 291, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Self image", 87, 337);
	ofNoFill();
	ofDrawRectangle(87, 357, 475, 30); // outline progressbar
	ofFill();
	ofDrawRectangle(90, 359.5, currentSelfImageValue, 25); //dit zou de maximale grootte van de balk zijn, waarbij '470' van waarde gaat veranderen en bij 1 zal beginnen
	baseFont.drawString("Positive", 87, 412);
	baseFont.drawString("Negative", 487, 412);

	//Depression	
	currentDepression = ofLerp(currentDepression, newDepression, 0.2);
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 483, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Depression", 87, 529);
	ofNoFill();
	ofDrawRectangle(87, 549, 475, 30); // outline progressbar
	ofFill();
	ofDrawRectangle(90, 551.5, currentDepression, 25);
	baseFont.drawString("Low", 87, 604);
	baseFont.drawString("High", 500, 604);

	//Performance
	currentPerformance = ofLerp(currentPerformance, newPerformance, 0.2);
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 675, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Performace", 87, 721);
	ofNoFill();
	ofDrawRectangle(87, 741, 475, 30); // outline progressbar
	ofFill();
	ofDrawRectangle(90, 743.5, currentPerformance, 25);
	baseFont.drawString("Low", 87, 796);
	baseFont.drawString("High", 500, 796);

	if (showImage1 == true) {

		imageList[0].draw(640, 70);
	}

	if (showImage2 == true) {
		imageList[1].draw(640, 70);
	}

	if (showImage3 == true) {

		imageList[2].draw(640, 70);
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == ' ') {
		randomNumber = ofRandom(AUDIOFILES);
		playing[randomNumber] = !playing[randomNumber];
		soundPlayer[randomNumber].setPaused(playing[randomNumber]);
		ofLog() << "soundPLayer should now be playing: " << randomNumber << endl;

		if (currentSelfImageValue <= maxBarLength) {
			newSelfImage = currentSelfImageValue + ofRandom(0, 20);
		}
		if (currentDepression <= maxBarLength) {
			newDepression =	currentDepression += ofRandom(0, 20);
		}
		if (currentPerformance <= maxBarLength) {
			newPerformance = currentPerformance += ofRandom(0, 20);
		}
	}


	if (key == '1') {
		showImage1 = true;
		showImage2 = false;
		showImage3 = false;
		ofLog() << "D R A W I N G" << endl;
	}

	if (key == '2') {
		showImage2 = true;
		showImage1 = false;
		showImage3 = false;
	}

	if (key == '3') {
		showImage1 = false;
		showImage2 = false;
		showImage3 = true;
	}


}
