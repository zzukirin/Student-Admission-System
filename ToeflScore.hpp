#ifndef TOEFLSCORE_H
#define TOEFLSCORE_H
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class ToeflScore
{
  private:
    //Declarations
    int reading, listening, speaking, writing, toefl_total;

  public:
    //Constructors
    ToeflScore(int reading, int listening, int speaking, int writing, int toefl_total);
    ToeflScore(); //Default

    //Destructor
    ~ToeflScore();

    //Overloaded Operator
    friend ostream& operator<<(ostream& out, ToeflScore& myStudent);

    //Functions
    bool ToeflCondition();
    
    //Mutators
    int get_reading();
    int get_listening();
    int get_speaking();
    int get_writing();
    int get_toefl_total();

    //Accessors
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);
    void set_toefl_total(int toefl_total);
};
#endif