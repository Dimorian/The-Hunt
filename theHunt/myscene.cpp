#include "scenemanager.h"
#include "screenrenderer.h"
#include "controllablecamera.h"
#include "modeltransformation.h"
#include "sunlight.h"
#include "shadermanager.h"
#include "world.h"
#include "trianglemesh.h"
#include "texture.h"
#include "transformation.h"
#include "keyboardtransformation.h"
#include "simplecube.h"
#include "shadertimed.h"
#include <stdio.h>
#include <time.h>
Node *initScene1();

void SceneManager::initScenes()
{

    Camera *cam = new Camera();
    RenderingContext *myContext=new RenderingContext(cam);
    unsigned int myContextNr = SceneManager::instance()->addContext(myContext);
    unsigned int myScene = SceneManager::instance()->addScene(initScene1());
    ScreenRenderer *myRenderer = new ScreenRenderer(myContextNr, myScene);

    //Vorsicht: Die Szene muss initialisiert sein, bevor das Fenster verändert wird (Fullscreen)
    SceneManager::instance()->setActiveScene(myScene);
    SceneManager::instance()->setActiveContext(myContextNr);
//    SceneManager::instance()->setFullScreen();
}

Node *initScene1()
{
	QString path(SRCDIR); //aus .pro-File!

srand(time(NULL));

    SunLight* light1 = new SunLight();
	//Drawable *baum = new Drawable(new TriangleMesh(path+QString("/../Models/Baum.obj")));
	//Drawable *glow = new Drawable(new TriangleMesh(path+QString("/../Models/Bodenblock.obj")));
    Drawable *wind = new Drawable(new TriangleMesh(path+QString("/../Models/Wind.obj")));
    Drawable* leave = new Drawable(new TriangleMesh(path+QString("/../Models/Blatt.obj")));
	Texture *t;
    Transformation* worldLeaning = new Transformation();
    KeyboardTransformation *kTrans = new KeyboardTransformation();
    ModelTransformation *trans;

    Material *m;

//    Node *sNode = new Node(baum);
//    Node *gNode = new Node(glow);
    Node* windNode = new Node(wind);
    Node* leaveNode = new Node(leave);
    Node *light1Node = new Node(light1);
    Node *keyNode = new Node(kTrans);
    Node *worldNode = new Node(worldLeaning);


	//Anzeige der Map:
	World *w = new World();

	QList<TriangleMesh*> meshs;
	meshs.append(new TriangleMesh(path+QString("/../Models/Bodenblock.obj")));
	meshs.append(new TriangleMesh(path+QString("/../Models/Baum.obj")));
	QList<Drawable*> drawables;
	QList<Node*> nodes;


	for (int i = 0; i<WIDTH; i++)
	{
		for (int j = 0; j<HEIGHT; j++)
		{
			switch(  w->getTileAt(i,j)  ){
			case 1:
				drawables.append( new Drawable(meshs.at(0)));
				t = drawables.back()->getProperty<Texture>();
				t->loadPicture(path+QString("/../Textures/BaumTexture.png"));
				drawables.back() ->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
				break;
			case 2:
				drawables.append( new Drawable(meshs.at(1)));
				t = drawables.back()->getProperty<Texture>();
				//ToDo: add block texture
				t->loadPicture(path+QString("/../Textures/BodenblockTexture.png"));
				drawables.back() ->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
				break;
			}
			m = drawables.back()->getProperty<Material>();
			m->setDiffuse(1., 1., 1., 1.);
			m->setAmbient(.5, .5, .5, 1.);
			m->setSpecular(1., 1., 1., 1.);
			m->setShininess(80.);
			trans = drawables.back()->getProperty<ModelTransformation>();

			trans->translate(i*2.0 -14.0, 0.0, j*2.0 - 14.0);
			trans->rotate(90.0 * (double)(rand()%4),0.0,1.0,0.0);
		}
	}
	for( auto n : drawables )
	{
		std::cout << "test"<<std::endl;
		nodes.append( new Node(n) );
		keyNode->addChild(nodes.back());
	}
	//

    kTrans->setRotKeysUpper(KeyboardTransformation::NoKey, 'd', KeyboardTransformation::NoKey);
    kTrans->setRotspeed(2.0);

    worldLeaning->rotate(20.0, 1.0, 0.0, 0.0);
    worldLeaning->rotate(45.0, 0.0, 1.0, 0.0);

    //Object Initialization

    t = leave->getProperty<Texture>();
    t->loadPicture(path+QString("/../Textures/BlattTexture.png"));
    leave->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
    m = leave->getProperty<Material>();
    m->setDiffuse(1., 1., 1., 1.);
    m->setAmbient(.5, .5, .5, 1.);
    m->setSpecular(1., 1., 1., 1.);
    m->setShininess(80.);
    trans = leave->getProperty<ModelTransformation>();
    trans->translate(1.3, 1.8, 0.0);
    trans->scale(0.15, 0.15, 0.15);

//    t = baum->getProperty<Texture>();
//    t->loadPicture(path+QString("/../Textures/BaumTexture.png"));
//    baum->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
//    m = baum->getProperty<Material>();
//    m->setDiffuse(1., 1., 1., 1.);
//    m->setAmbient(.5, .5, .5, 1.);
//    m->setSpecular(1., 1., 1., 1.);
//    m->setShininess(80.);

//    t= glow->getProperty<Texture>();
//    t->loadPicture(path+QString("/../Textures/Bodenblock.png"));
//    glow->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/simpletexture.frag")));
//    trans = glow->getProperty<ModelTransformation>();
//    trans->translate(0.0, 0.4, 0.0);

    ShaderTimed *s = ShaderManager::getShader<ShaderTimed>("://shaders/wind.vert", "://shaders/wind.frag");
    s->setMsecsPerIteration(2000);
    wind->setShader(s);
    m = wind->getProperty<Material>();
    m->setDiffuse(1., 1., 1., 1.);
    m->setAmbient(1., 1., 1., 1.);
    m->setSpecular(1., 1., 1., 1.);
    m->setShininess(80.);
    trans = wind->getProperty<ModelTransformation>();
    trans->translate(1.0, 1.8, 0.0);
	trans->rotate(180.0,0.0,1.0,0.0);
    trans->scale(0.3, 0.3, 0.3);

    light1->setDiffuse(0.7, 0.7, 0.7);
    light1->setSpecular(0.6, 0.6, 0.6);
    light1->setAmbient(0.6, 0.6, 0.6);
    light1->turnOn();

    //Scene Graph

	light1Node->addChild(worldNode);
	worldNode->addChild(keyNode);
//	keyNode->addChild(sNode);
//	keyNode->addChild(gNode);
    keyNode->addChild(windNode);
    keyNode->addChild(leaveNode);

    return(light1Node);
}
