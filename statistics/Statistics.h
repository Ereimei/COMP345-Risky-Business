/* 
 * File:   Statistics.h
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #3
 * Professor: Dr. Joey Paquet
 *
 * Created on November 4, 2017, 11:13 PM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include "../interfaces/interfaces.h"
#include "../map/map.h"
#include "../player/Player.h"
#include "../dice/Diepool.h"
#include "../mainGame/mainGame.h"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::string;
using std::endl;

class MainGame; //actually necessary because MainGame is a subject and the controller

class GameStatistics : public Observer {
public:
    GameStatistics();
    GameStatistics(MainGame* mg);
    virtual ~GameStatistics();
    virtual void update();
private:
    MainGame* mainGameSubject;
    static const string TURN_START;
    static const string TURN_END;
    static const string STATISTICS;
};

class ObserverDecorator : public Observer {
public:
    ObserverDecorator();
    ObserverDecorator(Observer* o);
    virtual ~ObserverDecorator();
    virtual void update();
    Observer* getDecoratedObserver() const;
private:
    Observer* decoratedObserver;
};

class PlayerDomination : public ObserverDecorator {
public:
    PlayerDomination(Observer* o, World* w, unsigned int nplayers);
    virtual ~PlayerDomination();
    void update();
private:
    World* worldSubject;
    unsigned int numPlayers, numTerritories;
    unsigned int* playerTerritoriesCount;
    static string PLAYER_OWNERSHIP_GRAPH;
    static string PLAYER;
    static string OWNERLESS;
    static string GRAPH_DELIMITER_START;
    static string GRAPH_DELIMITER_END;
    static string GRAPH_ELEMENT;
    static string SPACE;
    static unsigned int GRAPH_MULTIPLIER;
};

class ContinentControl : public Observer {
public:
    ContinentControl(Continent** c, unsigned int cCount);
    virtual ~ContinentControl();
    void update();
private:
    Continent** continentSubjects;
    const unsigned int continentCount;
    static const string CONTINENT_START;
    static const string NOT_OWNED;
    static const string OWNED;
};

#endif /* STATISTICS_H */

