#ifndef LED_h
#define LED_h

class Led{
   private: 
      char ledNumber; // номер светодиода 0 - 7
      bool ledState; // false - выключен, true - включен

   public: 
      Led(char number);
      void setLedState(bool state); // управление состоянием светодиода (false - выключен, true - включен)
};

#endif
