//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_SELLHANDLER_H
#define MCR_COR_SELLHANDLER_H
#include "../Request.h"
#include "../AbstractHandler.h"
#include "../ProcessingRequest.h"
class SellHandler : public AbstractHandler<ProcessingRequest> {
public:
   SellHandler() = default;
   void handle(ProcessingRequest *request) override;
};


#endif //MCR_COR_SELLHANDLER_H
