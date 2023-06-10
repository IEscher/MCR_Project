//
// Created by Jarod on 05/06/2023.
//

#ifndef MCR_COR_BASEHANDLER_H
#define MCR_COR_BASEHANDLER_H

#include "IHandler.h"
#include "ProcessingRequest.h"
#include "MiningRequest.h"
template <typename T>
class AbstractHandler : public IHandler<T> {
public:
   AbstractHandler<T>();

   /**
    * Set the next handler of a specified handler
    * @param handler
    * @return return a handler so we can use it like this handlerA->setNext
    * (handlerB)->setNext(handlerC);
    */
   IHandler<T> *setNext(IHandler<T> *handler) override;
   void handle(T *request) override;
   ~AbstractHandler() override = default;
private:
   IHandler<T>* next_handler = nullptr;
};
//Needed because C++
template class  AbstractHandler<ProcessingRequest>;
template class  AbstractHandler<MiningRequest>;

#endif //MCR_COR_BASEHANDLER_H
