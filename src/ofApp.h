
#pragma once

#include "ofMain.h"
#if (defined(__APPLE__) && defined(__MACH__))
#include "ofxSyphon.h"
#endif
#include "ofxHapPlayer.h"
#include "ofxOsc.h"
#include "ofxPostGlitch.h"
#include "ofxXmlSettings.h"
#include "ofxAssimpModelLoader.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofxDomemaster.h"

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
    void drawScene();
    void drawFbo();
    void drawBlur();
    
    ofxHapPlayer videoLC[LIM];
    ofxDomemaster domemaster;
    // retroalimentación
    
    float position;
    ofTexture screenImage;
    bool feedback;
    
#if (defined(__APPLE__) && defined(__MACH__))
    ofxSyphonClient client;
    bool syphonON;
#endif
    ofxXmlSettings XML;
    ofxOscReceiver reciever;
    ofxOscSender sender;

    float retroVel;
    int retroX;
    int retroY;
    int retroON;
    int domeON;
    int domeDistance;
    
    //ofBoxPrimitive caja;
    ofIcoSpherePrimitive icoSphere;
    ofIcoSpherePrimitive icoSphere2;
    ofIcoSpherePrimitive icoSphere3;


    int winSizeW;
    int winSizeH;
    
    int portIn;
    int portOut;
    
    float vSpeed [LIM];
    int vOpacity[LIM];
    int vX[LIM];
    int vY[LIM];
    int vZ[LIM];
    float vScaleX[LIM];
    float vScaleY[LIM];
    int vW [LIM];
    int vH [LIM];
    float vRotX [LIM];
    float vRotY [LIM];
    float vRotZ [LIM];
    int canonGenerator;
    ofPath path[LIM];
    
    int feedbackON;         

    ofShader shaderFish;
    
    ofFbo fbo; 
    
    ofPlanePrimitive plane;
    ofxPostGlitch myGlitch;
    
    int icoIntON;
    int icoOutON;

    //
    string clientTyping;
    ofTrueTypeFont titleFont; // font for some info in the title line
    //
    
    ofColor colorLight1;
    ofColor colorLight2;
    ofColor colorLight3;
    
    ofShader shaderBlurX;
    ofShader shaderBlurY;
    
    ofFbo fboBlurOnePass;
    ofFbo fboBlurTwoPass;
    
    float blur;
    int blurON;

    float fbox;
    float fboy;
    float fboz;
    float fboscaleX;
    float fboscaleY;
    float fboSpeed;
    float lightON;
    float namesON;
    float fixText;
    float autoOrbit;
    float orbitX;
    float orbitY;
    int distanceLockON;
    int malandroModeON;
    float timeElapsedON;
    
    ofFbo fboText;

    bool convergence;
    bool glow;
    bool shaker;
    bool cutslider;
    bool twist;
    bool outline;
    bool noise;
    bool slitscan;
    bool swell;
    bool invert;

    bool highcontrast;
    bool blueraise;
    bool redraise;
    bool greenraise;
    bool blueinvert;
    bool redinvert;
    bool greeninvert;
    float onScreen;
    
    float textRotX;
    float textRotY;
    float textRotZ;
    int ofxglitch;
    float tempo;
    float depth;
        
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
    ofMaterial material;
    ofColor lightColor;
    int modelON;
    ofPlanePrimitive planeMatrix;

    ofxCenteredTrueTypeFont font;
    ofxCenteredTrueTypeFont font2;
    
    string texto;
    string nombre;
    string text;
    
    /*
    
    ofShader shaderBlurX;
    ofShader shaderBlurY;
    
    ofFbo fboBlurOnePass;
    ofFbo fboBlurTwoPass;
    
     
     */
    ofxCenteredTrueTypeFont fontOrb [LIM];
    ofRectangle rectOrb [LIM];
    
    string textOrb[LIM];
    string textOrbPrima[LIM];
    float noiseX[LIM];
    float noiseY[LIM];
    float msgRotX[LIM];
    float msgRotY[LIM];
    float msgRotZ[LIM];
    
    float lcneON;
    float multiMsg;
    float stars;
    ofTexture asteroid;
    int multiModelON;
    int multiModelX[LIM];
    int multiModelY[LIM];
    int multiModelZ[LIM];
    int multiModelRotX[LIM];
    int multiModelRotY[LIM];
    int multiModelRotZ[LIM];

    ofxAssimpModelLoader multiModel[LIM];
    ofxAssimpModelLoader model3D;
    int textON;
    int fontSize;
        
    ofEasyCam camera;
    
    string wrapString(string text, int width) {
        
        string typeWrapped = "";
        string tempString = "";
        vector <string> words = ofSplitString(text, " ");
        
        for(int i=0; i<words.size(); i++) {
            
            string wrd = words[i];
            cout << wrd << endl;
            
            tempString += wrd + " ";
            int stringwidth = font.stringWidth(tempString);
            if(stringwidth >= width) {
                tempString = "";
                typeWrapped += "\n";
            }
            
            typeWrapped += wrd + " ";
        }
        
        return typeWrapped;
        
    }

};
