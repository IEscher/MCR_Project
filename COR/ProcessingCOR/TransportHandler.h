//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_TRANSPORTHANDLER_H
#define MCR_COR_TRANSPORTHANDLER_H

#include "../AbstractHandler.h"
#include "../Request.h"
#include "../ProcessingRequest.h"
class TransportHandler : public AbstractHandler<ProcessingRequest> {
public:
   TransportHandler() = default;
   void handle(ProcessingRequest *request) override;
};

#endif //MCR_COR_TRANSPORTHANDLER_H
