#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//set up the database
	string databasePath = ofToDataPath("pesten.db", true);
	db = new SQLite::Database(databasePath);

	//Load in all fonts
	titleFont.load("SinkinSans-700Bold.otf", 30);
	subtitleFont.load("SinkinSans-300Light.otf", 15);
	baseFont.load("SinkinSans-200XLight.otf", 12);
	baseFont.setLineHeight(25);

	// set sizes for bars
	maxBarLength = 467;
	minBarLength = 1;

	// set start variables for bars and values
	currentSelfImageValue = 1;
	currentDepression = 1;
	currentPerformance = 1;

	newSelfImage = 0;
	newDepression = 0;
	newPerformance = 0;

	//load images
	for (int i = 0; i < IMAGES; i++) {
		//ofLog() << "L O A D I N G    I M A G E " << i << endl;
		imageList[i].load("bg" + ofToString(i + 1) + ".jpg");
	}
	
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	totalImpact = currentSelfImageValue + currentDepression + currentPerformance;
	//ofLog() << "Total Impact = " << totalImpact << endl;




}

//--------------------------------------------------------------
void ofApp::draw() {

	//pas de achtergrond afbeelding aan aan de hand van de totale waardes. 
	if (totalImpact <= 20) {
		imageList[0].draw(0, 0);
	}
	else if (totalImpact > 20 && totalImpact <= 40) {
		imageList[1].draw(0, 0);
	}
	else if (totalImpact > 40 && totalImpact <= 60) {
		imageList[2].draw(0, 0);
	}
	else if (totalImpact > 60 && totalImpact <= 80) {
		imageList[3].draw(0, 0);
	}
	else if (totalImpact > 80 && totalImpact <= 100) {
		imageList[4].draw(0, 0);
	}
	else if (totalImpact > 100 && totalImpact <= 120) {
		imageList[5].draw(0, 0);
	}
	else if (totalImpact > 120 && totalImpact <= 140) {
		imageList[6].draw(0, 0);
	}
	else if (totalImpact > 140 && totalImpact <= 160) {
		imageList[7].draw(0, 0);
	}
	else if (totalImpact > 160 && totalImpact <= 180) {
		imageList[8].draw(0, 0);
	}
	else if (totalImpact > 180 && totalImpact <= 300) {
		imageList[9].draw(0, 0);
	}

	//Healthmonitor visuals
	// kiest de kleur voor de achtergrond van het blok, tekent het blok, kiest vervolgens kleur voor de tekst en tekent de tekst
	ofSetColor(20, 20, 20);
	ofFill();
	ofDrawRectangle(50, 70, 550, 190);
	ofSetColor(191, 191, 191);
	titleFont.drawString("HEALTH MONITOR", 87, 140);
	baseFont.drawString("While we may not see what the impact of our words \nis on the outside,\
 this monitor will show you what \nhappens on the inside.", 87, 165);

	//Self Image
	//bereken de huidige waarde, zet de kleur voor de achtergrond goed, teken de achtergrondblokken, balken en tekst. dit pas ik ook toe bij depression en performance
	currentSelfImageValue = ofLerp(currentSelfImageValue, newSelfImage, 0.2);
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 291, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Self image", 87, 337);
	ofNoFill();
	ofDrawRectangle(87, 357, 475, 30); // outline progressbar
	ofFill();
	ofDrawRectangle(90, 359.5, ofMap(currentSelfImageValue, 0, 100, 1, maxBarLength, true), 25);
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
	ofDrawRectangle(90, 551.5, ofMap(currentDepression, 0, 100, 1, maxBarLength, true), 25);
	baseFont.drawString("Low", 87, 604);
	baseFont.drawString("High", 500, 604);

	//Performance
	currentPerformance = ofLerp(currentPerformance, newPerformance, 0.2);
	ofFill();
	ofSetColor(20, 20, 20);
	ofDrawRectangle(50, 675, 550, 160); //BG
	ofSetColor(191, 191, 191);
	subtitleFont.drawString("Performance", 87, 721);
	ofNoFill();
	ofDrawRectangle(87, 741, 475, 30); // outline progressbar
	ofFill();
	ofDrawRectangle(90, 743.5, ofMap(currentPerformance, 0, 100, 1, maxBarLength, true), 25);
	baseFont.drawString("High", 87, 796);
	baseFont.drawString("Low", 500, 796);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	//ga naar mijn database en selecteer alles van mijn tabel 'impact' waarbij de key nog onbekend is
	SQLite::Statement query(*db, "SELECT * FROM impact WHERE key=?");
	

	//vervang het '?' in de query met de ingevoerde key
	query.bind(1, key);
	while (query.executeStep()) {
		
		//ofLog() << "current keypressed == " << key << endl;
		//geef me de waardes per opmerking -- gelinkt aan de key
		selfImageValue = query.getColumn("Zelfbeeld").getInt();
		performanceValue = query.getColumn("Prestaties").getInt();
		depressionValue = query.getColumn("Depressiviteit").getInt();

		//bereken wat de nieuwe waarde wordt 
		newSelfImage = currentSelfImageValue + selfImageValue;
		newDepression = currentDepression += depressionValue;
		newPerformance = currentPerformance += performanceValue;

		//speel geluid af, gelinkt aan de key
		soundPlayer.load(query.getColumn("Soundfile").getText());
		ofLog() << "current soundfile is " << query.getColumn("Soundfile") << endl;
		soundPlayer.play();
	}


}
