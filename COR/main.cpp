#include <iostream>
#include "ProcessingCOR/MakeToolsHandler.h"
#include "ProcessingCOR/MeltingHandler.h"
#include "ProcessingCOR/SellHandler.h"
#include "ProcessingCOR/SortingHandler.h"
#include "ProcessingCOR/TransportHandler.h"
#include "ProcessingRequest.h"
#include "MiningCOR/MinerHandler.h"
int main() {
   TransportHandler transport;
   SortingHandler sorting;
   MeltingHandler melting;
   MakeToolsHandler makeTools;
   SellHandler selling;
   ProcessingRequest test;
   MiningRequest miningRequest;
   transport.setNext(&sorting);

   sorting.setNext(&melting);
   melting.setNext(&makeTools);
   makeTools.setNext(&selling);

   transport.handle(&test);

   MinerHandler miner1;
   MinerHandler miner2;
   MinerHandler miner3;

   miner1.setNext(&miner2);
   miner2.setNext(&miner3);

   miner1.handle(&miningRequest);

   return 0;

}
