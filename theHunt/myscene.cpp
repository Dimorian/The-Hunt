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
#include "animatedmodel.h"
#include <stdio.h>
#include <time.h>
#include "animal.h"
#include "controller.h"
#include "wind.h"
#include "player.h"
#include "smellpool.h"

Node *initScene1();

Camera *cam;

void SceneManager::initScenes()
{


	cam = new Camera();
	cam->setPosition(QVector3D(0.66666, -16.35, 35.0));
	cam->rotate(0.0,-30.0,0.0);


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

    Drawable* leave = new Drawable(new TriangleMesh(path+QString("/../Models/Blatt.obj")));
	Texture *t;
    Transformation* worldLeaning = new Transformation();
    KeyboardTransformation *kTrans = new KeyboardTransformation();
    ModelTransformation *trans;

    Material *m;


    Node* leaveNode = new Node(leave);
    Node *light1Node = new Node(light1);
    Node *keyNode = new Node(kTrans);
    Node *worldNode = new Node(worldLeaning);


	World *w = new World();

	Shader* ss;
	ss=ShaderManager::getShader(QString("/../Skybox/texture.vert"), QString("/../Skybox/texture.frag"));

	// ===Skybox===

	//Später als eigene Klasse implementieren mit bewegenden Wolken etc.

	Drawable *Back = new Drawable(new TriangleMesh(path + QString("/../Skybox/Back.obj") ));
	Drawable *Backsky = new Drawable(new TriangleMesh(path + QString("/../Skybox/Backsky.obj") ));
	Drawable *Bottom = new Drawable(new TriangleMesh(path + QString("/../Skybox/Bottom.obj") ));
	Drawable *Front = new Drawable(new TriangleMesh(path + QString("/../Skybox/Front.obj") ));
	Drawable *Frontbottom = new Drawable(new TriangleMesh(path + QString("/../Skybox/Frontbottom.obj") ));
	Drawable *Mist = new Drawable(new TriangleMesh(path + QString("/../Skybox/Mist.obj") ));
	Drawable *TopSky= new Drawable(new TriangleMesh(path + QString("/../Skybox/TopSky.obj") ));



	Node *BackNode = new Node(Back);
	Node *BackskyNode = new Node(Backsky);
	Node *BottomNode = new Node(Bottom);
	Node *FrontNode = new Node(Front);
	Node *FrontbottomNode = new Node(Frontbottom);
	Node *MistNode = new Node(Mist);
	Node *TopSkyNode = new Node(TopSky);


	Transformation *SkyBoxScale = new Transformation();
	SkyBoxScale->translate(0.0,-25.0,0.0);
	SkyBoxScale->scale(0.7,0.7,0.7);
	Node *SkyBoxScaleNode = new Node(SkyBoxScale);



	keyNode->addChild(SkyBoxScaleNode);

	SkyBoxScaleNode->addChild(BackNode);
	SkyBoxScaleNode->addChild(BackskyNode);
	SkyBoxScaleNode->addChild(BottomNode);
	SkyBoxScaleNode->addChild(FrontNode);
	SkyBoxScaleNode->addChild(FrontbottomNode);
	SkyBoxScaleNode->addChild(MistNode);
	SkyBoxScaleNode->addChild(TopSkyNode);

	t = Back->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/back.png"));
	Back->setShader(ss);
	Back->setTransparent(true);

	t = Backsky->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/backsky.png"));
	Backsky->setShader(ss);
	Backsky->setTransparent(true);

	t = Bottom->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/bottom.png"));
	Bottom->setShader(ss);
	Bottom->setTransparent(true);

	t = Front->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/front.png"));
	Front->setShader(ss);
	Front->setTransparent(true);

	t = Frontbottom->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/frontbottom.png"));
	Frontbottom->setShader(ss);
	Frontbottom->setTransparent(true);

	t = Mist->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/mist.png"));
	Mist->setShader(ss);
	Mist->setTransparent(true);

	t = TopSky->getProperty<Texture>();
	t->loadPicture(path + QString("/../Skybox/topsky.png"));
	TopSky->setShader(ss);
	TopSky->setTransparent(true);
	// ===Skybox===


	//Wind:
	TriangleMesh *windMesh = new TriangleMesh(path+QString("/../Models/Wind.obj"));
	QList<Node*> WindNodes;
	QList<Drawable*> WindDrawables;
	ShaderTimed *s= ShaderManager::getShader<ShaderTimed>("://shaders/wind.vert", "://shaders/wind.frag");
	s->setMsecsPerIteration(2000);

	for(int i = 0; i < 10; i++){

		WindDrawables.append(new Drawable(windMesh));
		WindDrawables.back()->setShader(s);



		m = WindDrawables.back()->getProperty<Material>();
		m->setDiffuse(1., 1., 1., 1.);
		m->setAmbient(1., 1., 1., 1.);
		m->setSpecular(1., 1., 1., 1.);
		m->setShininess(80.);
		trans =  WindDrawables.back()->getProperty<ModelTransformation>();
		trans->translate(rand()%14, 2.0, rand()%14);
		trans->rotate(180.0,0.0,1.0,0.0);
		trans->scale(0.3, 0.3, 0.3);


		std::cout << WindDrawables.size()<<std::endl;
		//WindNodes.append(new Node(WindDrawables.back()));
		//keyNode->addChild(WindNodes.back());
	}
	for( auto n : WindDrawables )
	{
		//std::cout << "test"<<std::endl;
		WindNodes.append( new Node(n) );
		keyNode->addChild(WindNodes.back());
	}
	Wind *wind = new Wind(&WindDrawables);
	//
	//Anzeige der Map:


	QList<TriangleMesh*> meshs;
	meshs.append(new TriangleMesh(path+QString("/../Models/Bodenblock.obj")));
    meshs.append(new TriangleMesh(path+QString("/../Models/Baum.obj")));
    meshs.append(new TriangleMesh(path+QString("/../Models/Tanne.obj")));
    meshs.append(new TriangleMesh(path+QString("/../Models/Stein.obj")));
	QList<Drawable*> drawables;
	QList<Node*> nodes;

    Texture* bodenblock = new Texture(path+QString("/../Textures/BodenblockTexture.png"));
    Texture* baum = new Texture(path+QString("/../Textures/BaumTexture.png"));
    Texture* tanne = new Texture(path+QString("/../Textures/TanneTexture.png"));
    Texture* stein = new Texture(path+QString("/../Textures/SteinTexture.png"));

	for (int i = 0; i<WIDTH; i++)
	{
		for (int j = 0; j<HEIGHT; j++)
		{
			switch(  w->getTileAt(i,j)  ){
			case 1:
				drawables.append( new Drawable(meshs.at(0)));
                drawables.back()->setProperty<Texture>(bodenblock);
				drawables.back() ->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
				break;
			case 2:
                drawables.append( new Drawable(meshs.at(1)));
                drawables.back()->setProperty<Texture>(baum);
				drawables.back() ->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
				break;
            case 3:
                drawables.append( new Drawable(meshs.at(2)));
                drawables.back()->setProperty<Texture>(tanne);
                drawables.back() ->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
                break;
            case 4:
                drawables.append( new Drawable(meshs.at(3)));
                drawables.back()->setProperty<Texture>(stein);
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
        //std::cout << "test"<<std::endl;
		nodes.append( new Node(n) );
		keyNode->addChild(nodes.back());
	}
	//

    //Anzeige des Tiers

	AnimatedModel* AnimalModel = new AnimatedModel(path+QString("/../Models/Elch"), 1);
	t = AnimalModel->getProperty<Texture>();
	t->loadPicture(path + QString("/../Textures/Elch.png"));
	AnimalModel->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
	m = AnimalModel->getProperty<Material>();
	AnimalModel->setScale(0.5,0.5,0.5);
	trans=AnimalModel->getProperty<ModelTransformation>();
	trans->rotate(-90.0 ,0.0, 1.0, 0.0);

	m->setDiffuse(1., 1., 1., 1.);
    m->setAmbient(.5, .5, .5, 1.);
    m->setSpecular(1., 1., 1., 1.);
    m->setShininess(80.);


	keyNode->addChild(new Node(AnimalModel));

    //Player Inistialisierung


	AnimatedModel* PlayerModel = new AnimatedModel(path+QString("/../Models/Baer"), 1);
	t = PlayerModel->getProperty<Texture>();
	t->loadPicture(path + QString("/../Textures/Baer.png"));
	PlayerModel->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));
	m = PlayerModel->getProperty<Material>();
	m->setDiffuse(1., 1., 1., 1.);
	m->setAmbient(.5, .5, .5, 1.);
	m->setSpecular(1., 1., 1., 1.);
	m->setShininess(80.);
	AnimalModel->setScale(0.6,0.6,0.6);
	trans=PlayerModel->getProperty<ModelTransformation>();
	trans->rotate(-90.0 ,0.0, 1.0, 0.0);

	keyNode->addChild(new Node(PlayerModel));
	//


	Player *player = new Player(PlayerModel);
    int xBuf, yBuf;
    do{
        xBuf = rand()%8;
        yBuf = rand()%8;
    }while(!w->getTile(xBuf, yBuf)->getBegehbar());
    QVector3D* position = new QVector3D(xBuf*2-14, 0.4f, yBuf*2-14);
    player->setPosition(position);

	Animal *animal = new Animal(AnimalModel);
    SmellPool *smellpool = new SmellPool();
    Controller *controller = new Controller(cam,animal,smellpool,w,player,wind);

    kTrans->setRotKeysUpper(KeyboardTransformation::NoKey, 'e', KeyboardTransformation::NoKey);
    kTrans->setRotspeed(2.0);

    worldLeaning->rotate(45.0, 1.0, 0.0, 0.0);
    worldLeaning->rotate(45.0, 0.0, 1.0, 0.0);

    light1->setDiffuse(0.7, 0.7, 0.7);
    light1->setSpecular(0.6, 0.6, 0.6);
    light1->setAmbient(0.6, 0.6, 0.6);
    light1->turnOn();

    //Scene Graph

	light1Node->addChild(worldNode);
    worldNode->addChild(keyNode);


    return(light1Node);
}
