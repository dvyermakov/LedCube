#ifndef LED_h
#define LED_h

class Led{
   private: 
      char ledNumber; // ����� ���������� 0 - 7
      bool ledState; // false - ��������, true - �������

   public: 
      Led(char number);
      void setLedState(bool state); // ���������� ���������� ���������� (false - ��������, true - �������)
};

#endif
