//
//  main.cpp
//  OptionMonitor
//
//  Created by Gavin on 2025/3/15.
//

#include <iostream>
#include "ThostFtdcUserApiStruct.h"
#include "GetMarketInfo.h"
using namespace std;
int main()
{
    std::cout << "hello world!" << std::endl;
    
    CMduserHandler *mduser = new CMduserHandler;
    
    mduser->connect();
    
    mduser->login();
    
    mduser->subscribe();
    
    CThostFtdcDepthMarketDataField pDepthMarketData;
    mduser->OnRtnDepthMarketData(&pDepthMarketData);
    
    
//    Sleep(INFINITE);
    
    return 0;
}


