#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
#include "abro.h"
void ABRO_I_A(void);
void ABRO_I_B(void);
void ABRO_I_R(void);
int ABRO(void);
int ABRO_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#    ifndef _SOME_STRING_DEFINED
#      ifndef SOME_STRING
extern string SOME_STRING;
#      endif
#    endif
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#    ifndef _print_hello_DEFINED
#      ifndef print_hello
extern void print_hello(string*);
#      endif
#    endif
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int A : 1;
  unsigned int B : 1;
  unsigned int R : 1;
  unsigned int O : 1;
} _s = {  0,  0,  0,  0 };
#define tick 1
static unsigned char _state_3;
static unsigned char _state_6;
static unsigned char _state_10;
static unsigned char _state_1 = 1;
static int _term_31;
void ABRO_I_A(void) {
  _s.A = 1;
}
void ABRO_I_B(void) {
  _s.B = 1;
}
void ABRO_I_R(void) {
  _s.R = 1;
}

int ABRO(void)
{
	_term_31=-1;
  /* Vacuous terminate */;
  if (_state_1) {
    _s.O = 0;;
    _state_1 = 0;
    _state_3 = 1;
    _state_10 = 1;
    /* Vacuous terminate */;
    _state_6 = 1;
    /* Vacuous terminate */;
  } else {
    if (_s.R) {
      _state_1 = 0;
      _state_3 = 1;
      _state_10 = 1;
      /* Vacuous terminate */;
      _state_6 = 1;
      /* Vacuous terminate */;
    } else {
      _state_1 = 0;
      if (_state_3) {
        _state_3 = 1;
        if (_state_10) {
          if (_s.B) {
            goto N39;
          } else {
            _state_10 = 1;
            _term_31 &= -(1 << 1);
          }
        } else {
        N39:
          _state_10 = 0;
          /* Vacuous terminate */;
        }
        if (_state_6) {
          if (_s.A) {
            goto N35;
          } else {
            _state_6 = 1;
            _term_31 &= -(1 << 1);
          }
        } else {
        N35:
          _state_6 = 0;
          /* Vacuous terminate */;
        }
        if (~_term_31) {
        } else {
          _s.O = 1;
          print_hello(&SOME_STRING);
          _state_3 = 0;
        }
      } else {
        _state_3 = 0;
      }
    }
  }
  if (_s.O) { ABRO_O_O(); _s.O = 0; }
  _s.A = 0;
  _s.B = 0;
  _s.R = 0;
  return 1;
}

int ABRO_reset(void)
{
  _s.A = 0;
  _s.B = 0;
  _s.R = 0;
  return 0;
}
