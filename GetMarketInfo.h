//
//  GetMarketInfo.h
//  OptionMonitor
//
//  Created by Gavin on 2025/3/7.
//

#include "ThostFtdcMdApi.h"
#include "ThostFtdcUserApiDataType.h"
#include "ThostFtdcUserApiStruct.h"
//#include <Windows.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class CMduserHandler : public CThostFtdcMdSpi
 {
 private:
   CThostFtdcMdApi *m_mdApi;
 public:
   void connect()
   {
 //创建并初始化API
       m_mdApi = CThostFtdcMdApi::CreateFtdcMdApi("/Users/gavin/Code/OptionMonitor/OptionMonitor/flow_md/", true, true);

       m_mdApi->RegisterSpi(this);
       
       string IPAddress = "tcp://180.169.50.131:42213";
       char* buffer = new char[IPAddress.size() + 1]; // 分配足够的内存
       std::strcpy(buffer, IPAddress.c_str());       // 复制字符串内容
       m_mdApi->RegisterFront(buffer);
       // 使用完后释放内存
       delete[] buffer;
       
       m_mdApi->Init();

   }

 //登陆
   void login()
   {
       CThostFtdcReqUserLoginField t = {0};
       // init t
       strcpy(t.BrokerID, "2071");
       strcpy(t.UserID, "10000258");
       strcpy(t.Password, "10000258");
       int ret = m_mdApi->ReqUserLogin(&t, 1);
       cout << "login: "<< ret <<endl;
//       while (m_mdApi->ReqUserLogin(&t, 1)!=0) Sleep(1000);

   }



 // 订阅行情

   void subscribe()

   {

       char **ppInstrument=new char * [50];

//       ppInstrument[0] = "IH2503";
       strcpy(ppInstrument[0], "IH2503");
       int ret = m_mdApi->SubscribeMarketData(ppInstrument, 1);
       cout << "subscribe: "<< ret <<endl;
//       while (m_mdApi->SubscribeMarketData(ppInstrument, 1)!=0) Sleep(1000);

   }



   //接收行情

   void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)

   {

           printf("OnRtnDepthMarketData\n");

   }

 };

