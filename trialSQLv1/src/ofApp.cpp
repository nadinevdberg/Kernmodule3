#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetCircleResolution(50);
	ofSetBackgroundColor(ofColor::black);

	string databasePath = ofToDataPath("pesten.db", true);
	db = new SQLite::Database(databasePath);

	SQLite::Statement query(*db, "SELECT * FROM impact");
	while (query.executeStep()) {
		ofLog() << query.getColumn("opmerking") << endl;
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

