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
    virtual bool reset();
    virtual bool httpPost(int , int , int );
    virtual bool connectWiFi();
    virtual bool init();
    virtual int post(float, float, float);

  };

}
#endif
