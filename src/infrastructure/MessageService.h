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
    MessageService(long, char*);
    ~MessageService();
    virtual int post(char[]);
    virtual char* get(char[]);
    virtual int post(float[]);

  };

}
#endif
