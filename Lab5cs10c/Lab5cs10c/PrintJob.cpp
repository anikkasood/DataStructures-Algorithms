//
//  PrintJob.cpp
//  Lab5cs10c
//
//  Created by Anika Sood on 2/8/22.
//

#include "PrintJob.h"

PrintJob::PrintJob (int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}
int PrintJob::getPriority ( ){
    return priority;
}

int PrintJob::getJobNumber ( ){
    return jobNumber;
}

int PrintJob::getPages ( ){
    return numPages;
}
