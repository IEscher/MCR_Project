//
// Created by Jarod on 05/06/2023.
//

#include "TransportHandler.h"
#include <iostream>
void TransportHandler::handle(ProcessingRequest *r) {

   //TODO Transport the material
   std::cout << "Transport handler " << std::endl;
   //Call next handler
   AbstractHandler<ProcessingRequest>::handle(r);
}
