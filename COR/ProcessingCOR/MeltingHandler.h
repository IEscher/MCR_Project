//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_MELTINGHANDLER_H
#define MCR_COR_MELTINGHANDLER_H

#include "../Request.h"
#include "../AbstractHandler.h"
#include "../ProcessingRequest.h"
class MeltingHandler : public AbstractHandler<ProcessingRequest>{
public:
   MeltingHandler() = default;
   void handle(ProcessingRequest *request) override;

};


#endif //MCR_COR_MELTINGHANDLER_H
