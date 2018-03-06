#include "ofApp.h"


//tabel huishoudens noemen
// klik op 'oke'
// opdracht: deze data visualiseren. data die hierin zit is samenstelling van huishoudens in Nederland
// array met losse jaren (jaartallen niet linear). zelfde zoals we tijdens les gedaan hebben. met muis vertaal je naar 1 van deze jaren
// dit zegt iets over de samenstelling van de gemiddelde huishoudens over de jaren heen. hoe kan ik dat op een zinnige manier weergeven?
// doe onderzoek naar hoe gezinssamenstellingen weergegeven kunnen worden. Taart is simpelst. 
// maak schetsjes van opties, maar ik wil iets bewegends zien



//--------------------------------------------------------------
void ofApp::setup(){

	ofSetCircleResolution(50);
	font.load("JennaSue.ttf", 150);
	ofSetBackgroundColor(ofColor::black);

	string databasePath = ofToDataPath("roslingdb.sqlite", true);
	db = new SQLite::Database(databasePath);


}


void ofApp::update(){


}


void ofApp::draw(){

	SQLite::Statement query(*db, "SELECT * FROM population WHERE year=?");  // query(*db Select * from population where year = 1820);
	
	int year = years[currentYear];

	ofLog() << "year = " << year << endl;

	query.bind(1, year); //1 == eerste vraagteken   ---- vervang 1e vraagteken met 1820
	
	while (query.executeStep()) {
		//		ofLog() << query.getColumn("year") << " " 
		//			<< query.getColumn("nl") 
		//			<< endl;
		

		currentPopulation_NL = ofLerp(currentPopulation_NL, query.getColumn("nl").getInt(), 0.02);
		ofSetColor(ofColor::lightBlue);
		ofDrawCircle(100, 400, currentPopulation_NL * 5);

		currentPopulation_AU = ofLerp(currentPopulation_AU, query.getColumn("au").getInt(), 0.02);
		ofSetColor(ofColor::cadetBlue);
		ofDrawCircle(600, 400, currentPopulation_AU * 5);

		currentPopulation_ZH = ofLerp(currentPopulation_ZH, query.getColumn("zh").getInt(), 0.02);
		ofSetColor(ofColor::darkBlue);
		ofDrawCircle(1100, 400, currentPopulation_ZH * 5);

		ofSetColor(ofColor::lightGoldenRodYellow);
		font.drawString(jaartal, 300, 700);

	}
}

void ofApp::keyPressed(int key){

}


void ofApp::mouseMoved(int x, int y ){
	currentYear = ofMap(x, 0, ofGetWidth(), 0, 5);
	jaartal = ofToString(roundf(ofMap(x, 0, ofGetWidth(), years[0], years[4])));
}


