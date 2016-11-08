#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
void Unbounded_I_A(void);
void Unbounded_I_B(void);
int Unbounded(void);
int Unbounded_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int A : 1;
  unsigned int B : 1;
  unsigned int O : 1;
} _s = {  0,  0,  0 };
#define tick 1
static unsigned char _state_1 = 2;
void Unbounded_I_A(void) {
  _s.A = 1;
}
void Unbounded_I_B(void) {
  _s.B = 1;
}

int Unbounded(void)
{
  switch (_state_1) {
  case 0:
    goto N6;
  case 1:
    _s.O = 1;
    if (_s.A) {
      _state_1 = 1;
      goto N8;
    } else {
      goto N11;
    }
    break;
  case 2:
    _s.O = 0;;
    if (_s.A) {
      _state_1 = 1;
    N8:
      /* Vacuous terminate */;
    } else {
    N11:
      /* Vacuous terminate */;
    N6:
      _state_1 = 0;
    }
    break;
  default: break;
  }
  if (_s.O) { Unbounded_O_O(); _s.O = 0; }
  _s.A = 0;
  _s.B = 0;
  return (_state_1 != 0);
}

int Unbounded_reset(void)
{
  _s.A = 0;
  _s.B = 0;
  return 0;
}
