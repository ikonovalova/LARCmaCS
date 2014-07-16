#ifndef MLDATA_H
#define MLDATA_H

#include <iostream>
#include "engine.h"
#include "matrix.h"

typedef struct {
    std::string	name;
    const char* file_of_matlab;
    int         RULE_AMOUNT;
    int     	RULE_LENGTH;
    int 		BACK_AMOUNT;
    int         BACK_LENGTH;
} RCConfig;

class MlData
{
public:
    MlData(){}
    MlData(RCConfig conf);
    MlData(const MlData &data);
//    virtual ~MlData(){
//        mxDestroyArray(Ball);
//        mxDestroyArray(Blue);
//        mxDestroyArray(Yellow);
//        mxDestroyArray(Rules_length);
//        mxDestroyArray(Rules_count);
//        mxDestroyArray(Rule);
//        mxDestroyArray(Back_Params);
//        mxDestroyArray(Back_Amount);
//        mxDestroyArray(Back_Length);
//    }

    RCConfig config;

    Engine  *ep;
//    mxArray *Rules_length;
//    mxArray *Rules_count;
//    mxArray *Ball;
//    mxArray *Blue;
//    mxArray *Yellow;
//    mxArray *Rule;
//    mxArray *Back_Params;
//    mxArray *Back_Amount;
//    mxArray *Back_Length;
};

#endif // MLDATA_H
