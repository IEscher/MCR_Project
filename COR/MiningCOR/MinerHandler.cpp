//
// Created by Jarod on 07/06/2023.
//

#include "MinerHandler.h"
#include <iostream>
void MinerHandler::handle(MiningRequest *request) {
   std::cout << "Miner is mining " << std::endl;
   AbstractHandler::handle(request);
}
