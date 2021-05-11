#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1440, 1024);
	sender.setup("localhost", 12345);
	myfont.load("Roboto/Roboto-Regular.ttf", 18);
	myfont_bold.load("Roboto/Roboto-Bold.ttf", 36);
	mobile_num = "";
	email = "";	
	typing_num = true;

	file.open(ofToDataPath("copy_text.json"), ofFile::ReadWrite, false);
	if (file.exists()) {
		json = ofLoadJson(file);
	}

	myLevel = Level::LEVEL_0a;
	copy_text = json["level0a"].get<std::string>();
	ofBackground(0xE2E1DD);

	paragraph = ofxParagraph(copy_text, 1150);
	paragraph.setFont("Roboto/Roboto-Regular.ttf", 18);
	paragraph.setLeading(10);

}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::drawScreen() {
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0xE2E1DD);

	switch (myLevel)
	{
	case Level::LEVEL_0a:
		ofSetColor(ofColor::black);
		myfont_bold.drawString("AJO Journalism Game", 150, 200);
		paragraph.draw(150, 300);
		//ofSetColor(255, 0, 0);
		//ofDrawRectangle(600, 600, 100, 100);
		break;
	case Level::LEVEL_0b:
		myfont_bold.drawString("Welcome to the AJO Journalism Game", 150, 200);
		paragraph.draw(150, 300);
		myfont.drawString("Mobile # " + mobile_num, 150, 700);
		myfont.drawString("NYU email " + email, 150, 800);
		break;
	case Level::LEVEL_2:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		ofxOscMessage message;
		message.setAddress("/email");
		message.addStringArg(email + "@nyu.edu");
		message.addStringArg(mobile_num);
		sender.sendMessage(message);
	}
	else if (key == OF_KEY_TAB) {
		typing_num = false;
	}
	else if (key == 8 && email.size() > 0) { // backspace
		if (typing_num) {
			mobile_num = mobile_num.substr(0, mobile_num.size() - 1); // delete last character 
		}
		else {
			email = email.substr(0, email.size() - 1); // delete last character 
		}
	}
	else {
		if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key >= 48 && key <= 57)) {
			if (typing_num) {
				mobile_num.append(1, char(key));
			}
			else {
				email.append(1, char(key));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	switch (myLevel)
	{
		case Level::LEVEL_0a:
			// if user clicked next button
			//if (x >= 600 && x < 700 && y >= 600 && y < 700) {
				myLevel = Level::LEVEL_0b;
				copy_text = json["level0b"].get<std::string>();
				cout << copy_text;
				paragraph.setText(copy_text);
				paragraph.setLeading(10);
			//}
			break;
		case Level::LEVEL_1:
			break;
		case Level::LEVEL_2:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
