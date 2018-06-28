#pragma once

#include "ofMain.h"
#if (defined(__APPLE__) && defined(__MACH__))
#include "ofxSyphon.h"
#endif
#include "ofxHapPlayer.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

#define LIM 10

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
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
    
    ofxHapPlayer videoLC[LIM]; // para volver al estado anterior
    ofxHapPlayer player;
    void load(std::string movie);
#if (defined(__APPLE__) && defined(__MACH__))
    ofxSyphonClient client;
    bool syphonON;
#endif
    ofxXmlSettings XML;
    ofxOscReceiver reciever;
    ofxOscSender sender;
    int portIn;
    int portOut;
    
    float vSpeed [LIM];
    int vOpacity[LIM];
    int vX[LIM];
    int vY[LIM];
    float vScaleX[LIM];
    float vScaleY[LIM];
    int vW [LIM];
    int vH [LIM];

};
