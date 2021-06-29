#include "SendStepInfoEvent.h"

SendStepInfoEvent::SendStepInfoEvent(const StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::STEP_INFO);

  //Typo evento
  //estado_partida --> finalizada
                    // compra/venta
                    // jugando


}

SendStepInfoEvent::~SendStepInfoEvent() {}
