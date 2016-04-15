/*
 * Logger.h
 *
 *  Created on: 4 Apr 2016
 *      Author: manshaegert
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "WString.h"
class Logger {
public:
	Logger();
	virtual ~Logger();
	void logMessage(String message);
};

#endif /* LOGGER_H_ */
