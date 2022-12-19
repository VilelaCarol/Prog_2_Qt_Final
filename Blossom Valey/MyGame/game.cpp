#include<QGraphicsTextItem>
#include<QTimer>
#include<QImage>
#include<QBrush>
#include "game.hpp"
#include "enemy.hpp"
#include "boss.hpp"

Game::Game(QWidget *parent)
{
    //criarscene
    scene=new QGraphicsScene();

    //fixarotamanhoem800x600,queéinfinitopordefinição
    scene->setSceneRect(0,0,1849,1040);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagens/Fundo_casa.png"))); 

    //visualizaroobjetoscene(cenario)
    setScene(scene);

    //desabilitarasbarrasderolagem
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //fixarotamanho
    setFixedSize(1849,1040);

    //tentaticaDeFullScreen


    //criarojogador
    player=new Player();
    //definirotamanhodojogador100x100
    //player->setRect(0,0,100,100);
    //definiraposiçãopadrãodojogadorparaserembaixodatela
    //pordefiniçãoavisualizaçãoécentralizadaparapegartodososobjetos
    player->setPos(370,350);
    //colocarofoconojogador
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //adicionarojogadornocenario
    scene->addItem(player);

    //adicionarcontagemdepontosevidadojogador
    score=new Score();
    scene->addItem(score);
    health=new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    score->increase();

    //criarinimigos

        QTimer*timer1=new QTimer();
        QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(spawn()));
        timer1->start(3500);

    //criarBoss
        QTimer*timer2=new QTimer();
        QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawnBoss()));
        timer2->start(15000);
    show();
}
