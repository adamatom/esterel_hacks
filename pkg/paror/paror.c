#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
#include "paror.h"
void PAROR_I_A(void);
void PAROR_I_B(void);
void PAROR_I_Second(void);
int PAROR(void);
int PAROR_reset(void);
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
  unsigned int X : 1;
  unsigned int A : 1;
  unsigned int B : 1;
  unsigned int Second : 1;
  unsigned int O : 1;
} _s = {  0,  0,  0,  0,  0 };
#define tick 1
static blabla X_v;
static blabla O_v;
static unsigned char _state_4;
static unsigned char _state_9;
static unsigned char _state_14;
static unsigned char _state_1 = 2;
static int _term_33;
static int _counter_0;
void PAROR_I_A(void) {
  _s.A = 1;
}
void PAROR_I_B(void) {
  _s.B = 1;
}
void PAROR_I_Second(void) {
  _s.Second = 1;
}

int PAROR(void)
{
	_term_33=-1;
  switch (_state_1) {
  case 0:
    goto N21;
  case 1:
    _state_1 = 1;
    if (_state_14) {
      if ((_s.A || _s.B)) {
        goto N60;
      } else {
        _state_14 = 1;
        if (0 == (_s.Second ? --_counter_0 : _counter_0)) {
          _counter_0 = 1;
          Log(".");
        }
        _term_33 &= -(1 << 1);
      }
    } else {
    N60:
      _state_14 = 0;
      /* Vacuous terminate */;
    }
    if (_state_9) {
      if (_s.A) {
        goto N47;
      } else {
        _state_9 = 1;
        if (_s.B) {
          Log(" A wins!");
          goto N47;
        } else {
          _term_33 &= -(1 << 1);
        }
      }
    } else {
    N47:
      _state_9 = 0;
      /* Vacuous terminate */;
    }
    if (_state_4) {
      if (_s.B) {
        goto N39;
      } else {
        _state_4 = 1;
        if (_s.A) {
          Log("A wins!");
          goto N39;
        } else {
          _term_33 &= -(1 << 1);
        }
      }
    } else {
    N39:
      _state_4 = 0;
      /* Vacuous terminate */;
    }
    if (~_term_33) {
      goto N23;
    } else {
      (O_v = ( _s.X ? X_v : (_s.X = 1,X_v = PAROR_S_X()) )), (_s.O = 1);
      (O_v = ( _s.X ? X_v : (_s.X = 1,X_v = PAROR_S_X()) )), (_s.O = 1);
      /* Vacuous terminate */;
      Log("press enter to exit.\n");
    N21:
      _state_1 = 0;
    }
    break;
  case 2:
    _s.O = 0;;
    _state_1 = 1;
    _state_14 = 1;
    _counter_0 = 1;
    /* Vacuous terminate */;
    _state_9 = 1;
    /* Vacuous terminate */;
    _state_4 = 1;
    /* Vacuous terminate */;
  N23:
    /* Vacuous terminate */;
    break;
  default: break;
  }
  if (_s.O) { PAROR_O_O(O_v); _s.O = 0; }
  _s.X = 0;
  _s.A = 0;
  _s.B = 0;
  _s.Second = 0;
  return (_state_1 != 0);
}

int PAROR_reset(void)
{
  _s.X = 0;
  _s.A = 0;
  _s.B = 0;
  _s.Second = 0;
  return 0;
}
