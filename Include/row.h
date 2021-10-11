#ifndef ROW_h
#define ROW_h

class Row{
   private: 
      char rowNumber; // номер строки 0 - 7

   public: 
      Row(char number);
      void writeRow(char row);
};

#endif
