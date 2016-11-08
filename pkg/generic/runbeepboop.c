#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
#include "runbeepboop.h"
void RUNBEEPBOOP_I_ms(void);
int RUNBEEPBOOP(void);
int RUNBEEPBOOP_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#    ifndef _Log_DEFINED
#      ifndef Log
extern void Log(string);
#      endif
#    endif
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int ms : 1;
} _s = {  0 };
#define tick 1
static unsigned char _state_1 = 1;
static int _counter_0;
static int _counter_1;
static int _counter_2;
static int _counter_3;
static int _counter_4;
static int _counter_5;
static int _counter_6;
static int _counter_7;
static int _counter_8;
void RUNBEEPBOOP_I_ms(void) {
  _s.ms = 1;
}

int RUNBEEPBOOP(void)
{
  if (_state_1) {
    _state_1 = 0;
    _counter_8 = (1010 + 1234);
    /* Vacuous terminate */;
    _counter_7 = 1010;
    /* Vacuous terminate */;
    _counter_6 = 1234;
    /* Vacuous terminate */;
    /* Vacuous terminate */;
    _counter_5 = (500 + 500);
    /* Vacuous terminate */;
    _counter_4 = 500;
    /* Vacuous terminate */;
    _counter_3 = 500;
    /* Vacuous terminate */;
    /* Vacuous terminate */;
    _counter_2 = (5000 + 2000);
    /* Vacuous terminate */;
    _counter_1 = 5000;
    /* Vacuous terminate */;
    _counter_0 = 2000;
    /* Vacuous terminate */;
    /* Vacuous terminate */;
  } else {
    _state_1 = 0;
    if (0 == (_s.ms ? --_counter_8 : _counter_8)) {
      _counter_8 = (1010 + 1234);
      Log("[BOOM]\n ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_7 : _counter_7)) {
      _counter_7 = 1010;
      Log("[bloop] ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_6 : _counter_6)) {
      _counter_6 = 1234;
      Log("[bleep] ");
    }
    /* Vacuous terminate */;
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_5 : _counter_5)) {
      _counter_5 = (500 + 500);
      Log("pop! ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_4 : _counter_4)) {
      _counter_4 = 500;
      Log("boop ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_3 : _counter_3)) {
      _counter_3 = 500;
      Log("beep ");
    }
    /* Vacuous terminate */;
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_2 : _counter_2)) {
      _counter_2 = (5000 + 2000);
      Log("BANG!!! ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_1 : _counter_1)) {
      _counter_1 = 5000;
      Log("BOOP ");
    }
    /* Vacuous terminate */;
    if (0 == (_s.ms ? --_counter_0 : _counter_0)) {
      _counter_0 = 2000;
      Log("BEEP ");
    }
    /* Vacuous terminate */;
    /* Vacuous terminate */;
  }
  /* Vacuous terminate */;
  _s.ms = 0;
  return 1;
}

int RUNBEEPBOOP_reset(void)
{
  _s.ms = 0;
  return 0;
}
