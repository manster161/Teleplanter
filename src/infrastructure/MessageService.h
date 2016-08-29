/*
 * MessageService.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef MESSAGESERVICE_H_
#define MESSAGESERVICE_H_

namespace  Infrastructure {

  class MessageService {
  public:
    MessageService();
    ~MessageService();
    int Post(char[]);
    char* Get(char[]);


  };

}
#endif
