//
// Created by Jarod on 05/06/2023.
//

#include "SellHandler.h"
#include <iostream>
void SellHandler::handle(ProcessingRequest *r) {
   //TODO Sell material depending on value & Quantity (ig)
   std::cout << "Sell handler " << std::endl;
   //Call next handler
   AbstractHandler<ProcessingRequest>::handle(r);
}