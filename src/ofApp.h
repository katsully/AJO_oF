#pragma once

#include "ofMain.h"
#include "ofxOsc.h"	
#include "ofxParagraph/src/ofxParagraph.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawScreen();

		ofxOscSender sender;
		ofTrueTypeFont myfont;
		ofTrueTypeFont myfont_bold;
		string mobile_num;
		string email;
		bool typing_num;
		ofxParagraph paragraph;

		// enum classes - enumerator names are local to the enum and their values 
		// do not implicitly convert to other types (like another enum or int)
		enum class Level {
			LEVEL_0a, 
			LEVEL_0b,
			LEVEL_0c,
			LEVEL_1,
			LEVEL_2
		};
		Level myLevel;
		ofFile file;
		ofJson json;
		string copy_text;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
