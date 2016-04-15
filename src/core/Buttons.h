
#ifndef BUTTONS_H_
#define BUTTONS_H_

namespace Inputs {

class Buttons {
public:
	Buttons();
	virtual ~Buttons();
  bool isMoistureCalibrationPushed();
};

} /* namespace Inputs */

#endif /* BUTTONS_H_ */
