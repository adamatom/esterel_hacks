#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
#include "guarded.h"
void GUARDED_I_Bubble(void);
void GUARDED_I_CupBottom(void);
int GUARDED(void);
int GUARDED_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#    ifndef _BUBBLE_ERR_DEFINED
#      ifndef BUBBLE_ERR
extern string BUBBLE_ERR;
#      endif
#    endif
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#    ifndef _LOG_DEFINED
#      ifndef LOG
extern void LOG(string*);
#      endif
#    endif
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int Bubble : 1;
  unsigned int CupBottom : 1;
  unsigned int STOP_Z : 1;
  unsigned int ABORT_Z : 1;
  unsigned int STEP_Z : 1;
  unsigned int zpos : 1;
} _s = {  0,  0,  0,  0,  0,  0 };
#define tick 1
static integer STOP_Z_v;
static integer zpos_v;
static unsigned char _state_5;
static unsigned char _state_9;
static unsigned char _state_1 = 2;
static int _term_18;
static int _counter_0;
void GUARDED_I_Bubble(void) {
  _s.Bubble = 1;
}
void GUARDED_I_CupBottom(void) {
  _s.CupBottom = 1;
}

int GUARDED(void)
{
	_term_18=-1;
  switch (_state_1) {
  case 0:
    goto N15;
  case 1:
    if (0 == (_s.Bubble ? --_counter_0 : _counter_0)) {
      _s.ABORT_Z = 1;
      LOG(&BUBBLE_ERR);
      goto N19;
    } else {
      _state_1 = 1;
      if (_state_9) {
        if (_s.CupBottom) {
          goto N25;
        } else {
          _state_9 = 1;
          _s.STEP_Z = 1;
          _term_18 &= -(1 << 1);
        }
      } else {
      N25:
        _state_9 = 0;
        /* Vacuous terminate */;
      }
      if (_state_5) {
        if (_s.CupBottom) {
          (STOP_Z_v = ( _s.zpos ? zpos_v : (_s.zpos = 1,zpos_v = GUARDED_S_zpos()) )), (_s.STOP_Z = 1);
          goto N28;
        } else {
          _state_5 = 1;
          _term_18 &= -(1 << 1);
        }
      } else {
      N28:
        _state_5 = 0;
        /* Vacuous terminate */;
      }
      if (~_term_18) {
        goto N17;
      } else {
      N19:
        /* Vacuous terminate */;
      N15:
        _state_1 = 0;
      }
    }
    break;
  case 2:
    _s.STEP_Z = 0;;
    _s.ABORT_Z = 0;;
    _s.STOP_Z = 0;;
    _counter_0 = 3;
    _state_1 = 1;
    _state_9 = 1;
    _s.STEP_Z = 1;
    /* Vacuous terminate */;
    _state_5 = 1;
    /* Vacuous terminate */;
  N17:
    /* Vacuous terminate */;
    break;
  default: break;
  }
  if (_s.STOP_Z) { GUARDED_O_STOP_Z(STOP_Z_v); _s.STOP_Z = 0; }
  if (_s.ABORT_Z) { GUARDED_O_ABORT_Z(); _s.ABORT_Z = 0; }
  if (_s.STEP_Z) { GUARDED_O_STEP_Z(); _s.STEP_Z = 0; }
  _s.Bubble = 0;
  _s.CupBottom = 0;
  _s.zpos = 0;
  return (_state_1 != 0);
}

int GUARDED_reset(void)
{
  _s.Bubble = 0;
  _s.CupBottom = 0;
  _s.zpos = 0;
  return 0;
}
