/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include "deque.h"     // for DEQUE

struct UserRequest {
   std::string userClass;
   std::string userName;
   unsigned int numMinutes;
   bool emergency;
};

// the interactive nowServing program
void nowServing();

#endif // NOW_SERVING_H

