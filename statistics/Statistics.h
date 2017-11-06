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

class Statistics : public Observer {
public:
    Statistics();
    Statistics(const Statistics& orig);
    virtual ~Statistics();
    void update();
private:

};

#endif /* STATISTICS_H */

