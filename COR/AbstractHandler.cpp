//
// Created by Jarod on 05/06/2023.
//

#include "AbstractHandler.h"
#include "ProcessingRequest.h"

template<typename T>
AbstractHandler<T>::AbstractHandler() = default;

template<typename T>
IHandler<T> *AbstractHandler<T>::setNext(IHandler<T> *handler) {
   this->next_handler = handler;
   return handler;
}
template<typename T>
void AbstractHandler<T>::handle(T *request) {
   if (this->next_handler) {
      return this->next_handler->handle(request);
   }

}



