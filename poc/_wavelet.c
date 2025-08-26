#line 1 "wavelet-cpp.c"
#line 1 "<built-in>"
#line 1 "<command-line>"
#line 1 "/usr/include/stdc-predef.h"
#line 1 "<command-line>"
#line 1 "wavelet-cpp.c"
#if 700 < 700
  #undef 700
  #define 700 700
#endif
#if _GNU_SOURCE
#include <stdint.h>
#include <string.h>
#include <fenv.h>
#endif


#line 1 "/home/lisergey/basilisk/src/common.h"
typedef double number; 






number macro_min (number a, number b) { return a < b ? a : b; } 
number macro_sq (number x) { return x*x; } 
number macro_cube (number x) { return x*x*x; } 
int macro_sign (number x) { return (int)(x > 0 ? 1 : -1); } 
int macro_sign2 (number x) { return (int)(x > 0 ? 1 : x < 0 ? -1 : 0); } 
number macro_clamp (number x, number a, number b) {
  return x < a ? a : x > b ? b : x;
} 



#line 1 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stdlib.h"
#include <stdlib.h>
#line 2 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stdio.h"
#include <stdio.h>
#line 3 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stddef.h"
#include <stddef.h>
#line 4 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stdint.h"
#include <stdint.h>
#line 5 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stdbool.h"
#include <stdbool.h>
#line 6 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/stdarg.h"
#include <stdarg.h>
#line 7 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/string.h"
#include <string.h>
#line 8 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/float.h"
#include <float.h>
#line 9 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/limits.h"
#include <limits.h>
#line 10 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/math.h"
#include <math.h>
#line 11 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/time.h"
#include <time.h>
#line 12 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/sys/time.h"
#include <sys/time.h>
#line 13 "/home/lisergey/basilisk/src/grid/config.h"
#line 1 "/home/lisergey/basilisk/src/ast/std/sys/resource.h"
#include <sys/resource.h>
#line 14 "/home/lisergey/basilisk/src/grid/config.h"




#define unmap(x,y)
#define trash(x)


void macro_BEGIN_FOREACH() {;}
#line 52 "/home/lisergey/basilisk/src/grid/config.h"
# define OMP(x)
void macro_OMP_SERIAL() {;}
#line 69 "/home/lisergey/basilisk/src/grid/config.h"
#define _NVARMAX 65536
#define is_constant(v) ((v).i >= _NVARMAX)
#define constant(v) (is_constant(v) ? _constant[(v).i - _NVARMAX] : 1e30f)

#define systderr stderr
#define systdout stdout
#line 89 "/home/lisergey/basilisk/src/grid/config.h"
# define qstderr() stderr
# define qstdout() stdout
# define ferr stderr
# define fout stdout
# define not_mpi_compatible()



static inline void qassert (const char * file, int line, const char * cond) {
  fprintf (ferr, "%s:%d: Assertion `%s' failed.\n", file, line, cond);
  abort();
}







#define sysmalloc malloc
#define syscalloc calloc
#define sysrealloc realloc
#define sysfree free
#define systrdup strdup




# define pmalloc(s,func,file,line) malloc(s)
# define pcalloc(n,s,func,file,line) calloc(n,s)
# define prealloc(p,s,func,file,line) realloc(p,s)
# define pfree(p,func,file,line) free(p)
# define pstrdup(s,func,file,line) strdup(s)






#line 1 "/home/lisergey/basilisk/src/grid/array.h"


typedef struct {
  void * p;
  long max, len;
} Array;

Array * array_new()
{
  Array * a = ((Array *) pmalloc ((1)*sizeof(Array),__func__,__FILE__,__LINE__));
  a->p = NULL;
  a->max = a->len = 0;
  return a;
}

void array_free (Array * a)
{
  pfree (a->p,__func__,__FILE__,__LINE__);
  pfree (a,__func__,__FILE__,__LINE__);
}

void * array_append (Array * a, void * elem, size_t size)
{
  if (a->len + size >= a->max) {
    a->max += ( size > 4096 ? size : 4096);
    a->p = prealloc (a->p, a->max,__func__,__FILE__,__LINE__);
  }
  memcpy (((char *)a->p) + a->len, elem, size);
  a->len += size;
  return (void *)(((char *)a->p) + a->len - size);
}

void * array_shrink (Array * a)
{
  void * p = prealloc (a->p, a->len,__func__,__FILE__,__LINE__);
  pfree (a,__func__,__FILE__,__LINE__);
  return p;
}
#line 129 "/home/lisergey/basilisk/src/grid/config.h"
#line 372 "/home/lisergey/basilisk/src/grid/config.h"
# define tracing(...)
# define end_tracing(...)
#line 524 "/home/lisergey/basilisk/src/grid/config.h"
#define tid() 0
#define pid() 0
#define npe() 1
#define mpi_all_reduce(v,type,op)
#define mpi_all_reduce_array(v,type,op,elem)



void macro_OMP_PARALLEL() {;}
#define OMP_PARALLEL(...) OMP(omp parallel __VA_ARGS__)

#define NOT_UNUSED(x) (void)(x)

void macro1_VARIABLES() { ; }
#define _index(a,m) (a.i)
#define val(a,k,l,m) data(k,l,m)[_index(a,m)]

double _val_higher_dimension = 0.;
#line 550 "/home/lisergey/basilisk/src/grid/config.h"
#if (_GNU_SOURCE || __APPLE__) && !_OPENMP && !_CADNA
double undefined;
# if __APPLE__
# include <stdint.h>
# include "fp_osx.h"
# endif
#if _GPU
# define enable_fpe(flags)
#else
# define enable_fpe(flags) feenableexcept (flags)
#endif
# define disable_fpe(flags) fedisableexcept (flags)
static void set_fpe (void) {
  int64_t lnan = 0x7ff0000000000001;
  if (!(sizeof (int64_t) == sizeof (double))) qassert ("/home/lisergey/basilisk/src/grid/config.h", 564, "sizeof (int64_t) == sizeof (double)");
  memcpy (&undefined, &lnan, sizeof (double));
  enable_fpe (FE_DIVBYZERO|FE_INVALID);
}
#else
# define undefined ((double) DBL_MAX)
# define enable_fpe(flags)
# define disable_fpe(flags)
static void set_fpe (void) {}
#endif



static FILE ** qpopen_pipes = NULL;

FILE * qpopen (const char * command, const char * type)
{
  if (pid() > 0)
    return fopen ("/dev/null", type);
  FILE * fp = popen (command, type);
  if (fp) {
    FILE ** i = qpopen_pipes;
    int n = 0;
    while (i && *i) { n++; i++; }
    qpopen_pipes = (FILE * *) prealloc (qpopen_pipes, (n + 2)*sizeof(FILE *),__func__,__FILE__,__LINE__);
    qpopen_pipes[n] = fp;
    qpopen_pipes[n+1] = NULL;
  }
  return fp;
}

int qpclose (FILE * fp)
{
  if (pid() > 0)
    return fclose (fp);
  FILE ** i = qpopen_pipes;
  while (i && *i) {
    if (*i == fp)
      *i = (FILE *) 1;
    i++;
  }
  return pclose (fp);
}

static void qpclose_all()
{
  FILE ** i = qpopen_pipes;
  while (i && *i) {
    if (*i != (FILE *) 1)
      pclose (*i);
    i++;
  }
  pfree (qpopen_pipes,__func__,__FILE__,__LINE__);
  qpopen_pipes = NULL;
}






FILE * lfopen (const char * name, const char * mode)
{
  char fname[80];
  sprintf (fname, "%s-%d", name, pid());
  return fopen (fname, mode);
}

#line 1 "/home/lisergey/basilisk/src/grid/../ast/symbols.h"

const char * symbol_name (int sym);
int token_symbol (int token);
enum yysymbol_kind_t
{
  sym_YYEMPTY = -2,
  sym_YYEOF = 0,
  sym_YYerror = 1,
  sym_YYUNDEF = 2,
  sym_IDENTIFIER = 3,
  sym_I_CONSTANT = 4,
  sym_F_CONSTANT = 5,
  sym_STRING_LITERAL = 6,
  sym_FUNC_NAME = 7,
  sym_SIZEOF = 8,
  sym_PTR_OP = 9,
  sym_INC_OP = 10,
  sym_DEC_OP = 11,
  sym_LEFT_OP = 12,
  sym_RIGHT_OP = 13,
  sym_LE_OP = 14,
  sym_GE_OP = 15,
  sym_EQ_OP = 16,
  sym_NE_OP = 17,
  sym_AND_OP = 18,
  sym_OR_OP = 19,
  sym_MUL_ASSIGN = 20,
  sym_DIV_ASSIGN = 21,
  sym_MOD_ASSIGN = 22,
  sym_ADD_ASSIGN = 23,
  sym_SUB_ASSIGN = 24,
  sym_LEFT_ASSIGN = 25,
  sym_RIGHT_ASSIGN = 26,
  sym_AND_ASSIGN = 27,
  sym_XOR_ASSIGN = 28,
  sym_OR_ASSIGN = 29,
  sym_TYPEDEF_NAME = 30,
  sym_ENUMERATION_CONSTANT = 31,
  sym_TYPEDEF = 32,
  sym_EXTERN = 33,
  sym_STATIC = 34,
  sym_AUTO = 35,
  sym_REGISTER = 36,
  sym_INLINE = 37,
  sym_CONST = 38,
  sym_RESTRICT = 39,
  sym_VOLATILE = 40,
  sym_BOOL = 41,
  sym_CHAR = 42,
  sym_SHORT = 43,
  sym_INT = 44,
  sym_LONG = 45,
  sym_SIGNED = 46,
  sym_UNSIGNED = 47,
  sym_FLOAT = 48,
  sym_DOUBLE = 49,
  sym_VOID = 50,
  sym_COMPLEX = 51,
  sym_IMAGINARY = 52,
  sym_STRUCT = 53,
  sym_UNION = 54,
  sym_ENUM = 55,
  sym_ELLIPSIS = 56,
  sym_CASE = 57,
  sym_DEFAULT = 58,
  sym_IF = 59,
  sym_ELSE = 60,
  sym_SWITCH = 61,
  sym_WHILE = 62,
  sym_DO = 63,
  sym_FOR = 64,
  sym_GOTO = 65,
  sym_CONTINUE = 66,
  sym_BREAK = 67,
  sym_RETURN = 68,
  sym_ALIGNAS = 69,
  sym_ALIGNOF = 70,
  sym_ATOMIC = 71,
  sym_GENERIC = 72,
  sym_NORETURN = 73,
  sym_STATIC_ASSERT = 74,
  sym_THREAD_LOCAL = 75,
  sym_MAYBECONST = 76,
  sym_NEW_FIELD = 77,
  sym_TRACE = 78,
  sym_FOREACH_DIMENSION = 79,
  sym_REDUCTION = 80,
  sym_MACRO = 81,
  sym_ELLIPSIS_MACRO = 82,
  sym_MACRODEF = 83,
  sym_foreach_statement = 84,
  sym_85_ = 85,
  sym_86_ = 86,
  sym_87_ = 87,
  sym_88_ = 88,
  sym_89_ = 89,
  sym_90_ = 90,
  sym_91_ = 91,
  sym_92_ = 92,
  sym_93_ = 93,
  sym_94_ = 94,
  sym_95_ = 95,
  sym_96_ = 96,
  sym_97_ = 97,
  sym_98_ = 98,
  sym_99_ = 99,
  sym_100_ = 100,
  sym_101_ = 101,
  sym_102_ = 102,
  sym_103_ = 103,
  sym_104_ = 104,
  sym_105_ = 105,
  sym_106_ = 106,
  sym_107_ = 107,
  sym_108_ = 108,
  sym_YYACCEPT = 109,
  sym_translation_unit = 110,
  sym_primary_expression = 111,
  sym_expression_error = 112,
  sym_constant = 113,
  sym_enumeration_constant = 114,
  sym_string = 115,
  sym_generic_selection = 116,
  sym_generic_assoc_list = 117,
  sym_generic_association = 118,
  sym_postfix_expression = 119,
  sym_postfix_initializer = 120,
  sym_array_access = 121,
  sym_function_call = 122,
  sym_member_identifier = 123,
  sym_argument_expression_list = 124,
  sym_argument_expression_list_item = 125,
  sym_unary_expression = 126,
  sym_unary_operator = 127,
  sym_cast_expression = 128,
  sym_multiplicative_expression = 129,
  sym_additive_expression = 130,
  sym_shift_expression = 131,
  sym_relational_expression = 132,
  sym_equality_expression = 133,
  sym_and_expression = 134,
  sym_exclusive_or_expression = 135,
  sym_inclusive_or_expression = 136,
  sym_logical_and_expression = 137,
  sym_logical_or_expression = 138,
  sym_conditional_expression = 139,
  sym_assignment_expression = 140,
  sym_assignment_operator = 141,
  sym_expression = 142,
  sym_constant_expression = 143,
  sym_declaration = 144,
  sym_declaration_specifiers = 145,
  sym_init_declarator_list = 146,
  sym_init_declarator = 147,
  sym_storage_class_specifier = 148,
  sym_type_specifier = 149,
  sym_types = 150,
  sym_struct_or_union_specifier = 151,
  sym_struct_or_union = 152,
  sym_struct_declaration_list = 153,
  sym_struct_declaration = 154,
  sym_specifier_qualifier_list = 155,
  sym_struct_declarator_list = 156,
  sym_struct_declarator = 157,
  sym_enum_specifier = 158,
  sym_enumerator_list = 159,
  sym_enumerator = 160,
  sym_atomic_type_specifier = 161,
  sym_type_qualifier = 162,
  sym_function_specifier = 163,
  sym_alignment_specifier = 164,
  sym_declarator = 165,
  sym_direct_declarator = 166,
  sym_generic_identifier = 167,
  sym_pointer = 168,
  sym_type_qualifier_list = 169,
  sym_parameter_type_list = 170,
  sym_parameter_list = 171,
  sym_parameter_declaration = 172,
  sym_identifier_list = 173,
  sym_type_name = 174,
  sym_abstract_declarator = 175,
  sym_direct_abstract_declarator = 176,
  sym_type_not_specified = 177,
  sym_initializer = 178,
  sym_initializer_list = 179,
  sym_designation = 180,
  sym_designator_list = 181,
  sym_designator = 182,
  sym_static_assert_declaration = 183,
  sym_statement = 184,
  sym_labeled_statement = 185,
  sym_compound_statement = 186,
  sym_187_1 = 187,
  sym_block_item_list = 188,
  sym_block_item = 189,
  sym_expression_statement = 190,
  sym_selection_statement = 191,
  sym_for_scope = 192,
  sym_iteration_statement = 193,
  sym_for_declaration_statement = 194,
  sym_jump_statement = 195,
  sym_external_declaration = 196,
  sym_function_declaration = 197,
  sym_function_definition = 198,
  sym_declaration_list = 199,
  sym_basilisk_statements = 200,
  sym_macro_statement = 201,
  sym_reduction_list = 202,
  sym_reduction = 203,
  sym_reduction_operator = 204,
  sym_reduction_array = 205,
  sym_foreach_dimension_statement = 206,
  sym_forin_declaration_statement = 207,
  sym_forin_statement = 208,
  sym_forin_arguments = 209,
  sym_event_definition = 210,
  sym_event_parameters = 211,
  sym_event_parameter = 212,
  sym_boundary_definition = 213,
  sym_external_foreach_dimension = 214,
  sym_attribute = 215,
  sym_new_field = 216,
  sym_root = 217
};
#line 633 "/home/lisergey/basilisk/src/grid/config.h"

enum typedef_kind_t {
  sym_SCALAR = sym_root + 1,
  sym_VECTOR,
  sym_TENSOR,
  sym_COORD,
  sym__COORD,
  sym_VEC4,
  sym_IVEC
};

#define attroffset(x) (offsetof(_Attributes,x))




typedef int Reduce;

void macro_foreach_face (char flags, Reduce reductions,
   const char * order)
{;}
void macro_einstein_sum() {;}
void macro_diagonalize (int a) {;}




#define dimensional(...)

#define show_dimension_internal(...)
#define display_value(...)
#define interpreter_verbosity(...)
#line 20 "/home/lisergey/basilisk/src/common.h"

static inline double noise() { return 1. - 2.*rand()/(double)RAND_MAX; }


typedef struct {
  long n;
  long tn;
  int depth;
  int maxdepth;
} Grid;
Grid * grid = NULL;

double X0 = 0., Y0 = 0., Z0 = 0.;

double L0 = 1.;


int N = 64;




typedef struct { int i; } scalar;

typedef struct {
  scalar x;






} vector;

typedef struct {
  scalar * x;






} vectorl;

typedef struct {
  vector x;






} tensor;

struct { int x, y, z; } Period = {false, false, false};

typedef struct {
  double x, y, z;
} coord;

OMP(omp declare reduction (+ : coord :
      omp_out.x += omp_in.x,
      omp_out.y += omp_in.y,
      omp_out.z += omp_in.z))
#line 96 "/home/lisergey/basilisk/src/common.h"
void normalize (coord * n)
{
  double norm = 0.;
  
    norm += ( (n->x)*(n->x));
  norm = sqrt(norm);
  
    n->x /= norm;
}

void origin (double x, double y, double z) {
  X0 = x; Y0 = y; Z0 = z;
}

void size (double L) {
  L0 = L;
}

double zero (double s0, double s1, double s2) { return 0.; }




  enum { right, left };





int nboundary = 2*1;



double * _constant = NULL;
size_t datasize = 0;
typedef struct _Point Point;

#line 1 "/home/lisergey/basilisk/src/grid/boundaries.h"


typedef struct _Boundary Boundary;

struct _Boundary {
  void (* destroy) (Boundary * b);
  void (* level) (const Boundary * b, scalar * list, int l);

  void (* restriction) (const Boundary * b, scalar * list, int l);
};

static Boundary ** boundaries = NULL;

void add_boundary (Boundary * b) {
  int len = 0;
  if (boundaries) {
    Boundary ** i = boundaries;
    while (*i++) len++;
  }
  boundaries = (Boundary * *) prealloc (boundaries, (len + 2)*sizeof(Boundary *),__func__,__FILE__,__LINE__);
  boundaries[len] = b;
  boundaries[len+1] = NULL;
}

void free_boundaries() {
  if (!boundaries)
    return;
  Boundary ** i = boundaries, * b;
  while ((b = *i++))
    if (b->destroy)
      b->destroy (b);
    else
      pfree (b,__func__,__FILE__,__LINE__);
  pfree (boundaries,__func__,__FILE__,__LINE__);
  boundaries = NULL;
}
#line 47 "/home/lisergey/basilisk/src/grid/boundaries.h"
typedef struct {
  Boundary parent;
  int d;
} BoxBoundary;
#line 134 "/home/lisergey/basilisk/src/common.h"



typedef struct {
  int x;






} ivec;
typedef double (* BoundaryFunc) (Point, Point, scalar, bool *);
typedef struct {
  BoundaryFunc * boundary;
  BoundaryFunc * boundary_homogeneous;
  double (* gradient) (double, double, double);
  void (* delete) (scalar);
  char * name;
  ivec d;
  vector v;
  int face;
  bool nodump, freed;
  int block;
  scalar * depends;  
#line 19 "/home/lisergey/basilisk/src/grid/stencils.h"
bool input, output, nowarning;
  int width;
  int dirty;  
#line 21 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
void (* prolongation) (Point, scalar);
  void (* restriction) (Point, scalar);  
#line 9 "/home/lisergey/basilisk/src/grid/tree-common.h"
void (* refine) (Point, scalar);
  
#line 97
void (* coarsen) (Point, scalar);

#line 159 "/home/lisergey/basilisk/src/common.h"
} _Attributes;

static _Attributes * _attribute = NULL;





ivec Dimensions = {1};
#line 176 "/home/lisergey/basilisk/src/common.h"
int list_len (scalar * list)
{
  if (!list) return 0;
  int ns = 0;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ ns++;}}
  return ns;
}

scalar * list_append (scalar * list, scalar s)
{
  int len = list_len (list);
  list = (scalar *) prealloc (list, (len + 2)*sizeof(scalar),__func__,__FILE__,__LINE__);
  list[len] = s;
  list[len + 1].i = -1;
  return list;
}

scalar * list_prepend (scalar * list, scalar s)
{
  int len = list_len (list);
  list = (scalar *) prealloc (list, (len + 2)*sizeof(scalar),__func__,__FILE__,__LINE__);
  for (int i = len; i >= 1; i--)
    list[i] = list[i-1];
  list[0] = s;
  list[len + 1].i = -1;
  return list;
}

scalar * list_add (scalar * list, scalar s)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar t=*_i;(&t)->i>=0;t=*++_i){
    if (t.i == s.i)
      return list;}}
  return list_append (list, s);
}

int list_lookup (scalar * l, scalar s)
{
  if (l != NULL)
    {scalar*_i=(scalar*)( l);if(_i)for(scalar s1=*_i;(&s1)->i>=0;s1=*++_i){
      if (s1.i == s.i)
 return true;}}
  return false;
}

scalar * list_copy (scalar * l)
{
  scalar * list = NULL;
  if (l != NULL)
    {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      list = list_append (list, s);}}
  return list;
}

scalar * list_concat (scalar * l1, scalar * l2)
{
  scalar * l3 = list_copy (l1);
  {scalar*_i=(scalar*)( l2);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    l3 = list_append (l3, s);}}
  return l3;
}

void list_print (scalar * l, FILE * fp)
{
  int i = 0;
  {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    fprintf (fp, "%s%s", i++ == 0 ? "{" : ",", _attribute[s.i].name);}}
  fputs (i > 0 ? "}\n" : "{}\n", fp);
}

int vectors_len (vector * list)
{
  if (!list) return 0;
  int nv = 0;
  {vector*_i=(vector*)( list);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){ nv++;}}
  return nv;
}

vector * vectors_append (vector * list, vector v)
{
  int len = vectors_len (list);
  list = (vector *) prealloc (list, (len + 2)*sizeof(vector),__func__,__FILE__,__LINE__);
  list[len] = v;
  list[len + 1] = (vector){{-1}};
  return list;
}

vector * vectors_add (vector * list, vector v)
{
  {vector*_i=(vector*)( list);if(_i)for(vector w=*_i;(&w)->x.i>=0;w=*++_i){ {
    bool id = true;
    
      if (w.x.i != v.x.i)
 id = false;
    if (id)
      return list;
  }}}
  return vectors_append (list, v);
}

vector * vectors_copy (vector * l)
{
  vector * list = NULL;
  if (l != NULL)
    {vector*_i=(vector*)( l);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
      list = vectors_append (list, v);}}
  return list;
}

vector * vectors_from_scalars (scalar * s)
{
  vector * list = NULL;
  while (s->i >= 0) {
    vector v;
     {
      if (!(s->i >= 0)) qassert ("/home/lisergey/basilisk/src/common.h", 291, "s->i >= 0");
      v.x = *s++;
    }
    list = vectors_append (list, v);
  }
  return list;
}

int tensors_len (tensor * list)
{
  if (!list) return 0;
  int nt = 0;
  {tensor*_i=(tensor*)( list);if(_i)for(tensor t=*_i;(&t)->x.x.i>=0;t=*++_i){ nt++;}}
  return nt;
}

tensor * tensors_append (tensor * list, tensor t)
{
  int len = tensors_len (list);
  list = (tensor *) prealloc (list, (len + 2)*sizeof(tensor),__func__,__FILE__,__LINE__);
  list[len] = t;
  list[len + 1] = (tensor){{{-1}}};
  return list;
}

tensor * tensors_from_vectors (vector * v)
{
  tensor * list = NULL;
  while (v->x.i >= 0) {
    tensor t;
     {
      if (!(v->x.i >= 0)) qassert ("/home/lisergey/basilisk/src/common.h", 322, "v->x.i >= 0");
      t.x = *v++;
    }
    list = tensors_append (list, t);
  }
  return list;
}

static inline bool is_vertex_scalar (scalar s)
{
  
    if (_attribute[s.i].d.x != -1)
      return false;
  return true;
}

scalar * all = NULL;
scalar * baseblock = NULL;



scalar (* init_scalar) (scalar, const char *);
scalar (* init_vertex_scalar) (scalar, const char *);
vector (* init_vector) (vector, const char *);
vector (* init_face_vector) (vector, const char *);
tensor (* init_tensor) (tensor, const char *);
void (* scalar_clone) (scalar, scalar);
#line 358 "/home/lisergey/basilisk/src/common.h"
typedef struct {
  clock_t c;
  struct timeval tv;
  double tm;
} timer;

timer timer_start (void)
{
  timer t;
  t.c = clock();
  gettimeofday (&t.tv, NULL);



  return t;
}

double timer_elapsed (timer t)
{
  struct timeval tvend;
  gettimeofday (&tvend, NULL);
  return ((tvend.tv_sec - t.tv.tv_sec) +
   (tvend.tv_usec - t.tv.tv_usec)/1e6);
}



const vector zerof = {{_NVARMAX+0}};
const vector unityf = {{_NVARMAX+1}};
const scalar unity = {_NVARMAX+2};
const scalar zeroc = {_NVARMAX+3};



        vector fm = {{_NVARMAX+4}};
        scalar cm = {_NVARMAX+5};
#line 407 "/home/lisergey/basilisk/src/common.h"
void * matrix_new (int n, int p, size_t size)
{
  void ** m = ((void * *) pmalloc ((n)*sizeof(void *),__func__,__FILE__,__LINE__));
  char * a = ((char *) pmalloc ((n*p*size)*sizeof(char),__func__,__FILE__,__LINE__));
  for (int i = 0; i < n; i++)
    m[i] = a + i*p*size;
  return m;
}

double matrix_inverse (double ** m, int n, double pivmin)
{
  int indxc[n], indxr[n], ipiv[n];
  int i, icol = 0, irow = 0, j, k, l, ll;
  double big, dum, pivinv, minpiv = 1e30f;

  for (j = 0; j < n; j++)
    ipiv[j] = -1;

  for (i = 0; i < n; i++) {
    big = 0.0;
    for (j = 0; j < n; j++)
      if (ipiv[j] != 0)
 for (k = 0; k < n; k++) {
   if (ipiv[k] == -1) {
     if (fabs (m[j][k]) >= big) {
       big = fabs (m[j][k]);
       irow = j;
       icol = k;
     }
   }
 }
    ipiv[icol]++;
    if (irow != icol)
      for (l = 0; l < n; l++)
 do { double _tmp_ = m[irow][l]; m[irow][l] = m[icol][l]; m[icol][l] = _tmp_; } while(false);
    indxr[i] = irow;
    indxc[i] = icol;
    if (fabs (m[icol][icol]) <= pivmin)
      return 0.;
    if (fabs (m[icol][icol]) < minpiv)
      minpiv = fabs (m[icol][icol]);
    pivinv = 1.0/m[icol][icol];
    m[icol][icol] = 1.0;
    for (l = 0; l < n; l++) m[icol][l] *= pivinv;
    for (ll = 0; ll < n; ll++)
      if (ll != icol) {
 dum = m[ll][icol];
 m[ll][icol] = 0.0;
 for (l = 0; l < n; l++)
   m[ll][l] -= m[icol][l]*dum;
      }
  }
  for (l = n - 1; l >= 0; l--) {
    if (indxr[l] != indxc[l])
      for (k = 0; k < n; k++)
 do { double _tmp_ = m[k][indxr[l]]; m[k][indxr[l]] = m[k][indxc[l]]; m[k][indxc[l]] = _tmp_; } while(false);
  }
  return minpiv;
}

void matrix_free (void * m)
{
  pfree (((void **) m)[0],__func__,__FILE__,__LINE__);
  pfree (m,__func__,__FILE__,__LINE__);
}



typedef void (* free_solver_func) (void);

static Array * free_solver_funcs = NULL;

void free_solver_func_add (free_solver_func func)
{
  if (!free_solver_funcs)
    free_solver_funcs = array_new();
  array_append (free_solver_funcs, &func, sizeof(free_solver_func));
}



static char * display_defaults = NULL;

static void free_display_defaults() {
  pfree (display_defaults,__func__,__FILE__,__LINE__);
}

void display (const char * commands, bool overwrite)
{
  if (display_defaults == NULL)
    free_solver_func_add (free_display_defaults);
  if (overwrite) {
    pfree (display_defaults,__func__,__FILE__,__LINE__);
    display_defaults = pmalloc (strlen(commands) + 2,__func__,__FILE__,__LINE__);
    strcpy (display_defaults, "@");
    strcat (display_defaults, commands);
  }
  else {
    if (!display_defaults)
      display_defaults = pstrdup ("@",__func__,__FILE__,__LINE__);
    display_defaults =
      prealloc (display_defaults,
        strlen(display_defaults) + strlen(commands) + 1,__func__,__FILE__,__LINE__);
    strcat (display_defaults, commands);
  }
}



typedef struct {
  double x;






} _coord;



typedef struct {
  float r, g, b, a;
} vec4;
#line 540 "/home/lisergey/basilisk/src/common.h"
typedef struct {
  coord x, y, z;
} mat3;

OMP(omp declare reduction (+ : mat3 :
      omp_out.x.x += omp_in.x.x,
      omp_out.x.y += omp_in.x.y,
      omp_out.x.z += omp_in.x.z,
      omp_out.y.x += omp_in.y.x,
      omp_out.y.y += omp_in.y.y,
      omp_out.y.z += omp_in.y.z,
      omp_out.z.x += omp_in.z.x,
      omp_out.z.y += omp_in.z.y,
      omp_out.z.z += omp_in.z.z
      ))

typedef struct {
  uint32_t s;
} Adler32Hash;

static
inline void a32_hash_init (Adler32Hash * hash)
{
  hash->s = 0;
}

static
inline void a32_hash_add (Adler32Hash * hash, const void * data, size_t size)
{
  const uint8_t * buffer = (const uint8_t*) data;
  for (size_t n = 0; n < size; n++, buffer++)
    hash->s = *buffer + (hash->s << 6) + (hash->s << 16) - hash->s;
}

static
inline uint32_t a32_hash (const Adler32Hash * hash)
{
  return hash->s;
}
#line 13 "wavelet-cpp.c"
#line 1 "wavelet.c"
#line 1 "grid/bitree.h"
#line 1 "/home/lisergey/basilisk/src/grid/bitree.h"


#line 1 "grid/tree.h"
#line 1 "/home/lisergey/basilisk/src/grid/tree.h"
typedef double real;

#line 1 "grid/mempool.h"
#line 1 "/home/lisergey/basilisk/src/grid/mempool.h"





typedef struct _Pool Pool;

struct _Pool {
  Pool * next;
};

typedef struct {
  char * first, * lastb;
  size_t size;
  size_t poolsize;
  Pool * pool, * last;
} Mempool;

typedef struct {
  char * next;
} FreeBlock;

Mempool * mempool_new (size_t poolsize, size_t size)
{

  if (!(poolsize % 8 == 0)) qassert ("/home/lisergey/basilisk/src/grid/mempool.h", 26, "poolsize % 8 == 0");
  if (!(size >= sizeof(FreeBlock))) qassert ("/home/lisergey/basilisk/src/grid/mempool.h", 27, "size >= sizeof(FreeBlock)");


  poolsize = ( (1 << 20) < (poolsize + sizeof(Pool)) ? (1 << 20) : (poolsize + sizeof(Pool)));
  Mempool * m = ((Mempool *) pcalloc (1, sizeof(Mempool),__func__,__FILE__,__LINE__));
  m->poolsize = poolsize;
  m->size = size;
  return m;
}

void mempool_destroy (Mempool * m)
{
  Pool * p = m->pool;
  while (p) {
    Pool * next = p->next;
    pfree (p,__func__,__FILE__,__LINE__);
    p = next;
  }
  pfree (m,__func__,__FILE__,__LINE__);
}

void * mempool_alloc (Mempool * m)
{
  if (!m->first) {

    Pool * p = (Pool *) pmalloc (m->poolsize,__func__,__FILE__,__LINE__);
    p->next = NULL;
    if (m->last)
      m->last->next = p;
    else
      m->pool = p;
    m->last = p;
    m->first = m->lastb = ((char *)m->last) + sizeof(Pool);
    FreeBlock * b = (FreeBlock *) m->first;
    b->next = NULL;
  }
  void * ret = m->first;
  FreeBlock * b = (FreeBlock *) ret;
  char * next = b->next;
  if (!next) {
    m->lastb += m->size;
    next = m->lastb;
    if (next + m->size > ((char *) m->last) + m->poolsize)
      next = NULL;
    else {
      FreeBlock * b = (FreeBlock *) next;
      b->next = NULL;
    }
  }
  m->first = next;
#if TRASH
  double * v = (double *) ret;
  for (int i = 0; i < m->size/sizeof(real); i++)
    v[i] = undefined;
#endif
  return ret;
}

void * mempool_alloc0 (Mempool * m)
{
  void * ret = mempool_alloc (m);
  memset (ret, 0, m->size);
  return ret;
}

void mempool_free (Mempool * m, void * p)
{
#if TRASH
  double * v = (double *) p;
  for (int i = 0; i < m->size/sizeof(real); i++)
    v[i] = undefined;
#endif
  FreeBlock * b = (FreeBlock *) p;
  b->next = m->first;
  m->first = (char *) p;
}
#line 4 "/home/lisergey/basilisk/src/grid/tree.h"




struct _Point {

  int i;






  int level;




  #define _BLOCK_INDEX

};

#line 1 "grid/memindex/range.h"
#line 1 "/home/lisergey/basilisk/src/grid/memindex/range.h"
#line 15 "/home/lisergey/basilisk/src/grid/memindex/range.h"
typedef struct {
  void ** p;
  int size;
} Memalloc;

typedef struct {
  int start, end;
} Memrange;
#line 34 "/home/lisergey/basilisk/src/grid/memindex/range.h"
void memrange_alloc (Memrange * r, Memalloc * mem, int i)
{
  if (r->start == r->end) {
    r->start = i;
    r->end = i + 1;
    for (Memalloc * m = mem; m->p; m++) {
      *m->p = pcalloc (1, m->size,__func__,__FILE__,__LINE__);
      *m->p = (char *)(*m->p) - i*m->size;
    }
  }
  else if (i >= r->end) {
    for (Memalloc * m = mem; m->p; m++) {
      *m->p = prealloc ((char *)(*m->p) + r->start*m->size,
         m->size*(i + 1 - r->start),__func__,__FILE__,__LINE__);
      *m->p = (char *)(*m->p) - r->start*m->size;
      memset ((char *)(*m->p) + r->end*m->size, 0, (i - r->end + 1)*m->size);
    }
    r->end = i + 1;
  }
  else if (i < r->start) {
    for (Memalloc * m = mem; m->p; m++) {
      *m->p = prealloc ((char *)(*m->p) + r->start*m->size, m->size*(r->end - i),__func__,__FILE__,__LINE__);
      memmove ((char *)(*m->p) + (r->start - i)*m->size, *m->p,
        m->size*(r->end - r->start));
      memset ((char *)(*m->p), 0, (r->start - i)*m->size);
      *m->p = (char *)(*m->p) - i*m->size;
    }
    r->start = i;
  }
}
#line 73 "/home/lisergey/basilisk/src/grid/memindex/range.h"
bool memrange_free (Memrange * r, Memalloc * mem, int i)
{
  if (i == r->start) {
    if (i == r->end - 1) {
      for (Memalloc * m = mem; m->p; m++) {
 pfree ((char *)(*m->p) + r->start*m->size,__func__,__FILE__,__LINE__);
 *m->p = NULL;
      }
      r->start = r->end = 0;
      return true;
    }
    else {
      for (i = i + 1; i < r->end &&
      !*(void **)((char *)(*mem->p) + i*mem->size); i++);
      for (Memalloc * m = mem; m->p; m++) {
 memmove ((char *)(*m->p) + r->start*m->size,
   (char *)(*m->p) + i*m->size, m->size*(r->end - i));
 *m->p = prealloc ((char *)(*m->p) + r->start*m->size,
    m->size*(r->end - i),__func__,__FILE__,__LINE__);
 *m->p = (char *)(*m->p) - i*m->size;
      }
      r->start = i;
    }
  }
  else if (i == r->end - 1) {
    for (i = i - 1; i >= r->start &&
    !*(void **)((char *)(*mem->p) + i*mem->size); i--);
    r->end = i + 1;
    for (Memalloc * m = mem; m->p; m++) {
      *m->p = prealloc ((char *)(*m->p) + r->start*m->size,
         m->size*(r->end - r->start),__func__,__FILE__,__LINE__);
      *m->p = (char *)(*m->p) - r->start*m->size;
    }
  }
  else {
    if (!(i > r->start && i < r->end)) qassert ("/home/lisergey/basilisk/src/grid/memindex/range.h", 108, "i > r->start && i < r->end");
    for (Memalloc * m = mem; m->p; m++)
      memset ((char *)(*m->p) + i*m->size, 0, m->size);
  }
  return false;
}







struct _Memindex {
  Memrange r1;







  char ** b;





};
#line 171 "/home/lisergey/basilisk/src/grid/memindex/range.h"
struct _Memindex * mem_new (int len)
{
  struct _Memindex * m = pcalloc (1, sizeof (struct _Memindex),__func__,__FILE__,__LINE__);
  return m;
}





void mem_destroy (struct _Memindex * m, int len)
{
#line 201 "/home/lisergey/basilisk/src/grid/memindex/range.h"
  if (m->b)
    pfree (m->b + m->r1.start,__func__,__FILE__,__LINE__);
  pfree (m,__func__,__FILE__,__LINE__);
}





void mem_assign (struct _Memindex * m, int i, int len, void * b)
{
  Memalloc mem[] = {{(void **)&m->b, sizeof(char *)},
      {NULL}};
  memrange_alloc (&m->r1, mem, i);
  ((m)->b[i]) = b;
}
#line 252 "/home/lisergey/basilisk/src/grid/memindex/range.h"
void mem_free (struct _Memindex * m, int i, int len, void * b)
{
  Memalloc mem[] = {{(void **)&m->b, sizeof(char *)},
      {NULL}};
  memrange_free (&m->r1, mem, i);
}
#line 296 "/home/lisergey/basilisk/src/grid/memindex/range.h"
void macro_foreach_mem (struct _Memindex * index, int len, int _i) {
  struct _Memindex * _m = index;
  int _len = len;
  Point point = {0};
  for (point.i = ( (Period.x*2) > (_m->r1.start) ? (Period.x*2) : (_m->r1.start));
       point.i < ( (_len - Period.x*2) < (_m->r1.end) ? (_len - Period.x*2) : (_m->r1.end));
       point.i += _i)
    if (_m->b[point.i])
      ;
}
#line 27 "/home/lisergey/basilisk/src/grid/tree.h"
#line 36 "/home/lisergey/basilisk/src/grid/tree.h"
# define BGHOSTS 1
#line 48 "/home/lisergey/basilisk/src/grid/tree.h"
typedef struct {
  unsigned short flags;

  unsigned short neighbors;
  int pid;
} Cell;

enum {
  active = 1 << 0,
  leaf = 1 << 1,
  border = 1 << 2,
  vertex = 1 << 3,
  user = 4,

  face_x = 1 << 0






};

#define is_active(cell) ((cell).flags & active)
#define is_leaf(cell) ((cell).flags & leaf)
#define is_coarse() ((cell).neighbors > 0)
#define is_border(cell) ((cell).flags & border)
#define is_local(cell) ((cell).pid == pid())
#define is_vertex(cell) ((cell).flags & vertex)



typedef struct {
  int i;






} IndexLevel;

typedef struct {
  IndexLevel * p;
  int n, nm;
} CacheLevel;

typedef struct {
  int i;






  int level, flags;
} Index;

typedef struct {
  Index * p;
  int n, nm;
} Cache;



typedef struct {
  struct _Memindex * m;
  Mempool * pool;
  long nc;
  int len;
} Layer;

static size_t _size (size_t depth)
{
  return (1 << depth) + 2*2;
}

static size_t poolsize (size_t depth, size_t size)
{


  return _size(depth)*size;





}

static Layer * new_layer (int depth)
{
  Layer * l = ((Layer *) pmalloc ((1)*sizeof(Layer),__func__,__FILE__,__LINE__));
  l->len = _size (depth);
  if (depth == 0)
    l->pool = NULL;
  else {
    size_t size = sizeof(Cell) + datasize;


    l->pool = mempool_new (poolsize (depth, size), (1 << 1)*size);
  }
  l->m = mem_new (l->len);
  l->nc = 0;
  return l;
}

static void destroy_layer (Layer * l)
{
  if (l->pool)
    mempool_destroy (l->pool);
  mem_destroy (l->m, l->len);
  pfree (l,__func__,__FILE__,__LINE__);
}



typedef struct {
  Grid g;
  Layer ** L;

  Cache leaves;
  Cache faces;
  Cache vertices;
  Cache refined;
  CacheLevel * active;
  CacheLevel * prolongation;
  CacheLevel * boundary;

  CacheLevel * restriction;

  bool dirty;
} Tree;



static Point last_point;



static void cache_level_append (CacheLevel * c, Point p)
{
  if (c->n >= c->nm) {
    c->nm += 128;
    c->p = (IndexLevel *) prealloc (c->p, (c->nm)*sizeof(IndexLevel),__func__,__FILE__,__LINE__);
  }
  c->p[c->n].i = p.i;






  c->n++;
}

static void cache_level_shrink (CacheLevel * c)
{
  if (c->nm > (c->n/128 + 1)*128) {
    c->nm = (c->n/128 + 1)*128;
    if (!(c->nm > c->n)) qassert ("/home/lisergey/basilisk/src/grid/tree.h", 207, "c->nm > c->n");
    c->p = (IndexLevel *) prealloc (c->p, sizeof (Index)*c->nm,__func__,__FILE__,__LINE__);
  }
}

static void cache_append (Cache * c, Point p, unsigned short flags)
{
  if (c->n >= c->nm) {
    c->nm += 128;
    c->p = (Index *) prealloc (c->p, (c->nm)*sizeof(Index),__func__,__FILE__,__LINE__);
  }
  c->p[c->n].i = p.i;






  c->p[c->n].level = p.level;
  c->p[c->n].flags = flags;
  c->n++;
}

void cache_shrink (Cache * c)
{
  cache_level_shrink ((CacheLevel *)c);
}





#define allocated(k,l,n) (((point.i+k) >= (((Tree *)grid)->L[point.level]->m)->r1.start && (point.i+k) < (((Tree *)grid)->L[point.level]->m->r1.end) && (((Tree *)grid)->L[point.level]->m)->b[point.i+k]))
#define NEIGHBOR(k,l,n) (((((Tree *)grid)->L[point.level]->m)->b[point.i+k]))
#define PARENT(k,l,n) (((((Tree *)grid)->L[point.level-1]->m)->b[(point.i+2)/2+k])\
                              )\

#line 243

#define allocated_child(k,l,n) (level < depth() &&\
        ((2*point.i-2 +k) >= (((Tree *)grid)->L[point.level+1]->m)->r1.start && (2*point.i-2 +k) < (((Tree *)grid)->L[point.level+1]->m->r1.end) && (((Tree *)grid)->L[point.level+1]->m)->b[2*point.i-2 +k])\
                           )\

#line 247

#define CHILD(k,l,n) (((((Tree *)grid)->L[point.level+1]->m)->b[2*point.i-2 +k]))
#line 291 "/home/lisergey/basilisk/src/grid/tree.h"
#define CELL(m) (*((Cell *)(m)))


#define depth() (grid->depth)
#define aparent(k,l,n) CELL(PARENT(k,l,n))
#define child(k,l,n) CELL(CHILD(k,l,n))


#define cell CELL(NEIGHBOR(0,0,0))
#define neighbor(k,l,n) CELL(NEIGHBOR(k,l,n))
#define neighborp(l,m,n) (Point) {\
    point.i + l,\
\
\
\
\
\
\
    point.level\
    _BLOCK_INDEX\
}\

#line 312



#define data(k,l,n) ((double *) (NEIGHBOR(k,l,n) + sizeof(Cell)))
#define fine(a,k,p,n) ((double *) (CHILD(k,p,n) + sizeof(Cell)))[_index(a,n)]
#define coarse(a,k,p,n) ((double *) (PARENT(k,p,n) + sizeof(Cell)))[_index(a,n)]

void macro_POINT_VARIABLES (Point point) { 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 348 "/home/lisergey/basilisk/src/grid/tree.h"
}

#line 1 "grid/foreach_cell.h"
#line 1 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
#line 66 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
void macro_foreach_cell_root (Point root)
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {

 ;

 if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}

void macro_foreach_cell()
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
      
#line 136
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 136 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
;} 
#line 91
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

void macro_foreach_cell_all() {
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
     
#line 151
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 151 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
;} 
#line 91
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}

void macro_foreach_cell_post_root (bool condition, Point root)
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:
 ;

      }
    }
  }
}

void macro_foreach_cell_post (bool condition)
{
  {

    Point root = {2,0};
#line 156
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:
      
#line 265
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 265 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
;}      
#line 249
}
    }
  }
}
  
#line 266
}
}

void macro_foreach_cell_post_all (bool condition)
{
  {
    Point root = {0};
    for (root.i = 0; root.i <= 2*2; root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 156 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if (condition)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if (condition)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:
     
#line 281
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 281 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
;}      
#line 249
}
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 282 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}

void macro_foreach_leaf()
{
#line 126
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 288
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 288 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (is_leaf (cell)) {
      if (is_active(cell) && is_local(cell))
 ;
      continue;
    }} 
#line 91
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 293
}
#line 351 "/home/lisergey/basilisk/src/grid/tree.h"


void macro_foreach_child (Point point) {
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
      
#line 360
;
    }
    point.i = (_i + 2)/2;
    point.level--;
  }
}
#line 411 "/home/lisergey/basilisk/src/grid/tree.h"
#define is_refined_check() ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) &&\
    point.i > 0 && point.i < (1 << level) + 2*2 - 1\
\
\
\
\
\
\
    )\

#line 420


void macro_foreach_cache (Cache cache, Reduce reductions)
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < cache.n; _k++) {
 point.i = cache.p[_k].i;






 point.level = cache.p[_k].level;
 _flags = cache.p[_k].flags;
 ;
      }
  }
}

void macro_foreach_cache_level (Cache cache, int _l, Reduce reductions)
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < cache.n; _k++) {
 point.i = cache.p[_k].i;






 ;
      }
  }
}

static void update_cache_f (void);

void macro_foreach_boundary_level (int _l, Reduce reductions)
{
  if (_l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _boundary = ((Tree *)grid)->boundary[_l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _boundary.n; _k++) {
 point.i = _boundary.p[_k].i;
      
#line 487
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 487
;}      
#line 475
}
  }
}
  









}
}



void macro_foreach_halo_prolongation (int _l)
{
  if (_l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->prolongation[_l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i;
      
#line 499
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 499
;}      
#line 475
}
  }
}
  
#line 500
}
}

void macro_foreach_halo_restriction (int _l)
{
  if (_l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->restriction[_l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i;
      
#line 509
{ 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 509
;}      
#line 475
}
  }
}
  
#line 510
}
}



#line 1 "grid/neighbors.h"
#line 1 "/home/lisergey/basilisk/src/grid/neighbors.h"

void macro_foreach_neighbor (int _s,
    Point point) {
  {
    const int _nn = _s;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;      
#line 10 "/home/lisergey/basilisk/src/grid/neighbors.h"
;
    }
    point.i = _i;
  }
}
#line 516 "/home/lisergey/basilisk/src/grid/tree.h"

static inline bool has_local_children (Point point)
{int ig=0;NOT_UNUSED(ig); 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 520
if (is_local(cell))
      return true;    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 522
return false;
}

static inline void cache_append_face (Point point, unsigned short flags)
{int ig=0;NOT_UNUSED(ig); 
  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 527
Tree * q = ((Tree *)grid);
  cache_append (&q->faces, point, flags);
#line 549 "/home/lisergey/basilisk/src/grid/tree.h"
}



static void update_cache_f (void)
{
  Tree * q = ((Tree *)grid);
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 557
q->vertices
#line 436
).n; _k++) {
 point.i = (
#line 557
q->vertices
#line 437
).p[_k].i;






 point.level = (
#line 557
q->vertices
#line 444
).p[_k].level;
 _flags = (
#line 557
q->vertices
#line 445
).p[_k].flags;
    
#line 558
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 558
if (level <= depth() && allocated(0,0,0))
      cell.flags &= ~vertex;}      
#line 447
}
  }
}


  
#line 562
q->leaves.n = q->faces.n = q->vertices.n = 0;
  for (int l = 0; l <= depth(); l++)
    q->active[l].n = q->prolongation[l].n =
      q->boundary[l].n = q->restriction[l].n = 0;

  const unsigned short fboundary = 1 << user;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 568 "/home/lisergey/basilisk/src/grid/tree.h"
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 568
{



    if (is_local(cell) && is_active(cell)) {


      cache_level_append (&q->active[level], point);
    }
#line 593 "/home/lisergey/basilisk/src/grid/tree.h"
    if (!(cell.pid < 0)) {      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = BGHOSTS;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 596
if (allocated(0,0,0) && (cell.pid < 0) && !(cell.flags & fboundary)) {
   cache_level_append (&q->boundary[level], point);
   cell.flags |= fboundary;
 }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
    
#line 600 "/home/lisergey/basilisk/src/grid/tree.h"
}

    else if (level > 0 && is_local(aparent(0,0,0)))
      cache_level_append (&q->restriction[level], point);

    if (is_leaf (cell)) {
      if (is_local(cell)) {
 cache_append (&q->leaves, point, 0);

 unsigned short flags = 0;
 
   if ((neighbor(-1,0,0).pid < 0) || (!is_leaf(neighbor(-1,0,0)) && !neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0) ||
       is_leaf(neighbor(-1,0,0)))
     flags |= face_x;
 if (flags)
   cache_append (&q->faces, point, flags);
 
   if ((neighbor(1,0,0).pid < 0) || (!is_leaf(neighbor(1,0,0)) && !neighbor(1,0,0).neighbors && neighbor(1,0,0).pid >= 0) ||
       (!is_local(neighbor(1,0,0)) && is_leaf(neighbor(1,0,0))))
     cache_append (&q->faces, neighborp(1,0,0), face_x);

 for (int i = 0; i <= 1; i++)






       if (!is_vertex(neighbor(i,j,k))) {
  cache_append (&q->vertices, neighborp(i,j,k), 0);
  neighbor(i,j,k).flags |= vertex;
       }

        if (cell.neighbors > 0)
   cache_level_append (&q->prolongation[level], point);
      }
      else if (!(cell.pid < 0) || is_local(aparent(0,0,0))) {

 unsigned short flags = 0;
 
   if (allocated(-1,0,0) &&
       is_local(neighbor(-1,0,0)) && (!is_leaf(neighbor(-1,0,0)) && !neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0))
     flags |= face_x;
 if (flags)
   cache_append_face (point, flags);
 
   if (allocated(1,0,0) && is_local(neighbor(1,0,0)) &&
       (!is_leaf(neighbor(1,0,0)) && !neighbor(1,0,0).neighbors && neighbor(1,0,0).pid >= 0))
     cache_append_face (neighborp(1,0,0), face_x);
      }

      continue;

    }
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}


  
#line 657 "/home/lisergey/basilisk/src/grid/tree.h"
cache_shrink (&q->leaves);
  cache_shrink (&q->faces);
  cache_shrink (&q->vertices);
  for (int l = 0; l <= depth(); l++) {
    cache_level_shrink (&q->active[l]);
    cache_level_shrink (&q->prolongation[l]);
    cache_level_shrink (&q->boundary[l]);
    cache_level_shrink (&q->restriction[l]);
}

  q->dirty = false;


  for (int l = depth(); l >= 0; l--) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 482 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _boundary = ((Tree *)grid)->boundary[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _boundary.n; _k++) {
 point.i = _boundary.p[_k].i;
      
#line 672
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 672
cell.flags &= ~fboundary;}      
#line 475
}
  }
}
  









}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}



  
#line 676 "/home/lisergey/basilisk/src/grid/tree.h"
grid->n = q->leaves.n;

#if !_MPI
  grid->tn = grid->n;
  grid->maxdepth = grid->depth;
#endif
}

void macro_foreach (char flags, Reduce reductions) {
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags;
    
#line 687
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 687
;}      
#line 447
}
  }
}

#line 688
}

void macro_foreach_face_generic (char flags, Reduce reductions,
    const char * order)
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 694
((Tree *)grid)->faces
#line 436
).n; _k++) {
 point.i = (
#line 694
((Tree *)grid)->faces
#line 437
).p[_k].i;






 point.level = (
#line 694
((Tree *)grid)->faces
#line 444
).p[_k].level;
 _flags = (
#line 694
((Tree *)grid)->faces
#line 445
).p[_k].flags;
    
#line 695
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 695
;}      
#line 447
}
  }
}

#line 696
}

void macro_is_face_x (unsigned short _f) {
  if (_f & face_x) {
    int ig = -1; NOT_UNUSED(ig);
    ;
  }
}
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
void macro_foreach_level (int l, char flags, Reduce reductions) {
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
      
#line 736
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 736
;}      
#line 475
}
  }
}
  
#line 737
}
}

void macro1_foreach_coarse_level (int l, char flags, Reduce reductions) { 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 742
if (!is_leaf(cell))
      ;}      
#line 475
}
  }
}
  
#line 737
}
}





}

void macro1_foreach_level_or_leaf (int l, char flags, Reduce reductions) {
  for (int _l1 = l; _l1 >= 0; _l1--) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{ 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (_l1 <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[_l1];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l1;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
      
#line 749
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 749
if (_l1 == l || is_leaf (cell))
 ;}      
#line 475
}
  }
}
  
#line 737
}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}

#line 751 "/home/lisergey/basilisk/src/grid/tree.h"
}

#if TRASH
# undef trash
# define trash(list) reset(list, undefined)
#endif

void reset (void * alist, double val)
{
  scalar * list = (scalar *) alist;
  Tree * q = ((Tree *)grid);

  for (int l = 0; l <= depth(); l++) {
    Layer * L = q->L[l];    
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
struct _Memindex * _m = (
#line 765 "/home/lisergey/basilisk/src/grid/tree.h"
L->m
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  int _len = (
#line 765 "/home/lisergey/basilisk/src/grid/tree.h"
L->len
#line 298 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  Point point = {0};
  for (point.i = ( (Period.x*2) > (_m->r1.start) ? (Period.x*2) : (_m->r1.start));
       point.i < ( (_len - Period.x*2) < (_m->r1.end) ? (_len - Period.x*2) : (_m->r1.end));
       point.i += 1)
    if (_m->b[point.i]) 
#line 765 "/home/lisergey/basilisk/src/grid/tree.h"
{
      point.level = l;
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
 if (!is_constant(s))
   for (int b = 0; b < _attribute[s.i].block; b++)
     data(0,0,0)[s.i + b] = val;
      }}}
    }
  }
}

static CacheLevel * cache_level_resize (CacheLevel * name, int a)
{
  for (int i = 0; i <= depth() - a; i++)
    pfree (name[i].p,__func__,__FILE__,__LINE__);
  pfree (name,__func__,__FILE__,__LINE__);
  return ((CacheLevel *) pcalloc (depth() + 1, sizeof(CacheLevel),__func__,__FILE__,__LINE__));
}

static void update_depth (int inc)
{
  Tree * q = ((Tree *)grid);
  grid->depth += inc;
  q->L = &(q->L[-1]);
  q->L = (Layer * *) prealloc (q->L, (grid->depth + 2)*sizeof(Layer *),__func__,__FILE__,__LINE__);
  q->L = &(q->L[1]);
  if (inc > 0)
    q->L[grid->depth] = new_layer (grid->depth);
  q->active = cache_level_resize (q->active, inc);
  q->prolongation = cache_level_resize (q->prolongation, inc);
  q->boundary = cache_level_resize (q->boundary, inc);
  q->restriction = cache_level_resize (q->restriction, inc);
}


typedef void (* PeriodicFunction) (struct _Memindex *, int, int, void *);

static void periodic_function (struct _Memindex * m, int i, int len, void * b,
          PeriodicFunction f)
{
  f(m, i, len, b);
  if (Period.x) {
    int nl = len - 2*2;
    for (int l = - 1; l <= 1; l += 2)
      for (int n = i + l*nl; n >= 0 && n < len; n += l*nl)
 f(m, n, len, b);
  }
}

static void assign_periodic (struct _Memindex * m, int i, int len, void * b)
{
  periodic_function (m, i, len, b, mem_assign);
}

static void free_periodic (struct _Memindex * m, int i, int len)
{
  periodic_function (m, i, len, NULL, (PeriodicFunction) mem_free);
}
#line 939 "/home/lisergey/basilisk/src/grid/tree.h"
static void alloc_children (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 941
if (point.level == grid->depth)
    update_depth (+1);
  else if (allocated_child(0,0,0))
    return;


  Layer * L = ((Tree *)grid)->L[point.level + 1];
  L->nc++;
  size_t len = sizeof(Cell) + datasize;
  char * b = (char *) mempool_alloc0 (L->pool);
  int i = 2*point.i - 2;
  for (int k = 0; k < 2; k++, i++) {

    assign_periodic (L->m, i, L->len, b);
    b += len;
#line 972 "/home/lisergey/basilisk/src/grid/tree.h"
  }

  int pid = cell.pid;  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 975
{
    cell.pid = pid;
#if TRASH
    {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      val(s,0,0,0) = undefined;}}
#endif
  }    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }

#line 982
}


static void free_children (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;

  
#line 988
Layer * L = ((Tree *)grid)->L[point.level + 1];
  int i = 2*point.i - 2;
  if (!(((L->m)->b[i]))) qassert ("/home/lisergey/basilisk/src/grid/tree.h", 990, "mem_data (L->m,i)");
  mempool_free (L->pool, ((L->m)->b[i]));
  for (int k = 0; k < 2; k++, i++)
    free_periodic (L->m, i, L->len);
  if (--L->nc == 0) {
    destroy_layer (L);
    if (!(point.level + 1 == grid->depth)) qassert ("/home/lisergey/basilisk/src/grid/tree.h", 996, "point.level + 1 == grid->depth");
    update_depth (-1);
  }
}
#line 1042 "/home/lisergey/basilisk/src/grid/tree.h"
void increment_neighbors (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1044
((Tree *)grid)->dirty = true;
  if (cell.neighbors++ == 0)
    alloc_children (point);  
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = (
#line 1047 "/home/lisergey/basilisk/src/grid/tree.h"
2/2
#line 5 "/home/lisergey/basilisk/src/grid/neighbors.h"
);
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 1048
if (cell.neighbors++ == 0)
      alloc_children (point);    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
  
#line 1050 "/home/lisergey/basilisk/src/grid/tree.h"
cell.neighbors--;
}

void decrement_neighbors (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1055
((Tree *)grid)->dirty = true;  
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = (
#line 1056 "/home/lisergey/basilisk/src/grid/tree.h"
2/2
#line 5 "/home/lisergey/basilisk/src/grid/neighbors.h"
);
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 1057
if (allocated(0,0,0)) {
      cell.neighbors--;
      if (cell.neighbors == 0)
 free_children (point);
    }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
  
#line 1062 "/home/lisergey/basilisk/src/grid/tree.h"
if (cell.neighbors) {
    int pid = cell.pid;    
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 1064
{
      cell.flags = 0;
      cell.pid = pid;
    }    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 1068
}
}

void realloc_scalar (int size)
{

  Tree * q = ((Tree *)grid);
  size_t oldlen = sizeof(Cell) + datasize;
  size_t newlen = oldlen + size;
  datasize += size;

  Layer * L = q->L[0];  
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
struct _Memindex * _m = (
#line 1080 "/home/lisergey/basilisk/src/grid/tree.h"
L->m
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  int _len = (
#line 1080 "/home/lisergey/basilisk/src/grid/tree.h"
L->len
#line 298 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  Point point = {0};
  for (point.i = ( (Period.x*2) > (_m->r1.start) ? (Period.x*2) : (_m->r1.start));
       point.i < ( (_len - Period.x*2) < (_m->r1.end) ? (_len - Period.x*2) : (_m->r1.end));
       point.i += 1)
    if (_m->b[point.i]) 
#line 1080 "/home/lisergey/basilisk/src/grid/tree.h"
{

    char * p = (char *) prealloc (((L->m)->b[point.i]), newlen*sizeof(char),__func__,__FILE__,__LINE__);
    assign_periodic (L->m, point.i, L->len, p);
#line 1093 "/home/lisergey/basilisk/src/grid/tree.h"
  }

  for (int l = 1; l <= depth(); l++) {
    Layer * L = q->L[l];
    Mempool * oldpool = L->pool;
    L->pool = mempool_new (poolsize (l, newlen), (1 << 1)*newlen);    
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
struct _Memindex * _m = (
#line 1099 "/home/lisergey/basilisk/src/grid/tree.h"
L->m
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  int _len = (
#line 1099 "/home/lisergey/basilisk/src/grid/tree.h"
L->len
#line 298 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  Point point = {0};
  for (point.i = ( (Period.x*2) > (_m->r1.start) ? (Period.x*2) : (_m->r1.start));
       point.i < ( (_len - Period.x*2) < (_m->r1.end) ? (_len - Period.x*2) : (_m->r1.end));
       point.i += 2)
    if (_m->b[point.i]) 
#line 1099 "/home/lisergey/basilisk/src/grid/tree.h"
{
      char * new = (char *) mempool_alloc (L->pool);

      for (int k = 0; k < 2; k++) {
 memcpy (new, ((L->m)->b[point.i + k]), oldlen);
 assign_periodic (L->m, point.i + k, L->len, new);
 new += newlen;
      }
#line 1125 "/home/lisergey/basilisk/src/grid/tree.h"
    }
    mempool_destroy (oldpool);
  }
}



#define VN v.x
#define VT v.y
#define VR v.z




#if _MPI
# define disable_fpe_for_mpi() disable_fpe (FE_DIVBYZERO|FE_INVALID)
# define enable_fpe_for_mpi() enable_fpe (FE_DIVBYZERO|FE_INVALID)
#else
# define disable_fpe_for_mpi()
# define enable_fpe_for_mpi()
#endif

static inline void no_restriction (Point point, scalar s);

static bool normal_neighbor (Point point, scalar * scalars, vector * vectors)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1151
for (int k = 1; k <= BGHOSTS; k++)
    {
      for (int i = -k; i <= k; i += 2*k)
 if ((allocated(i,0,0) && !(neighbor(i,0,0).pid < 0))) {
   Point neighbor = neighborp(i,0,0);
   int id = (- cell.pid - 1);
   {scalar*_i=(scalar*)( scalars);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    
       val(s,0,0,0) = _attribute[s.i].boundary[id](neighbor, point, s, NULL);}}
   {vector*_i=(vector*)( vectors);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
     {
       scalar vn = VN;
       val(v.x,0,0,0) = _attribute[vn.i].boundary[id](neighbor, point, v.x, NULL);
#line 1172 "/home/lisergey/basilisk/src/grid/tree.h"
     }}}
   return true;
 }}
  return false;
}

static bool diagonal_neighbor_2D (Point point,
      scalar * scalars, vector * vectors)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1218 "/home/lisergey/basilisk/src/grid/tree.h"
  return false;
}

static bool diagonal_neighbor_3D (Point point,
      scalar * scalars, vector * vectors)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1267 "/home/lisergey/basilisk/src/grid/tree.h"
  return false;
}
#line 1292 "/home/lisergey/basilisk/src/grid/tree.h"
static inline bool is_boundary_point (Point point) {int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1293
return (cell.pid < 0);
}

static void box_boundary_level (const Boundary * b, scalar * list, int l)
{
  disable_fpe_for_mpi();
  scalar * scalars = NULL;
  vector * vectors = NULL, * faces = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].refine != no_restriction) {
      if (_attribute[s.i].v.x.i == s.i) {
 if (_attribute[s.i].face)
   faces = vectors_add (faces, _attribute[s.i].v);
 else
   vectors = vectors_add (vectors, _attribute[s.i].v);
      }
      else if (_attribute[s.i].v.x.i < 0 && _attribute[s.i].boundary[0])
 scalars = list_add (scalars, s);
    }}}
#line 482
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _boundary = ((Tree *)grid)->boundary[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _boundary.n; _k++) {
 point.i = _boundary.p[_k].i; 
#line 1313
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1313
{
    if (!normal_neighbor (point, scalars, vectors) &&
 !diagonal_neighbor_2D (point, scalars, vectors) &&
 !diagonal_neighbor_3D (point, scalars, vectors)) {

      {scalar*_i=(scalar*)( scalars);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){

   val(s,0,0,0) = undefined;}}
      {vector*_i=(vector*)( vectors);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){

   {
     val(v.x,0,0,0) = undefined;}}}
    }
    if (faces) {
      int id = (- cell.pid - 1);
      
 for (int i = -1; i <= 1; i += 2) {

   if ((allocated(i,0,0) && !(neighbor(i,0,0).pid < 0))) {
     Point neighbor = neighborp(i,0,0);
     {vector*_i=(vector*)( faces);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){ {
       scalar vn = VN;
       if (_attribute[vn.i].boundary[id])
 
    val(v.x,(i + 1)/2,0,0) = _attribute[vn.i].boundary[id](neighbor, point, v.x, NULL);
     }}}
   }
#line 1365 "/home/lisergey/basilisk/src/grid/tree.h"
 }
    }
  }}      
#line 475
}
  }
}
  









}
}

  
#line 1369
pfree (scalars,__func__,__FILE__,__LINE__);
  pfree (vectors,__func__,__FILE__,__LINE__);
  pfree (faces,__func__,__FILE__,__LINE__);
  enable_fpe_for_mpi();
}



#undef VN
#undef VT
#define VN _attribute[s.i].v.x
#define VT _attribute[s.i].v.y

static double masked_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1384
double sum = 0., n = 0.;  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 1386
if (!(cell.pid < 0) && val(s,0,0,0) != 1e30f)
      sum += val(s,0,0,0), n++;    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 1388
return n ? sum/n : 1e30f;
}


static double masked_average_x (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1394
double sum = 0., n = 0.;  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 1396
if (child.x < 0 && (!(cell.pid < 0) || !(neighbor(1,0,0).pid < 0)) &&
 val(s,1,0,0) != 1e30f)
      sum += val(s,1,0,0), n++;    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 1399
return n ? sum/n : 1e30f;
}

static void masked_boundary_restriction (const Boundary * b,
      scalar * list, int l)
{
  scalar * scalars = NULL;
  vector * faces = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].refine != no_restriction) {
      if (_attribute[s.i].v.x.i == s.i && _attribute[s.i].face)
 faces = vectors_add (faces, _attribute[s.i].v);
      else
 scalars = list_add (scalars, s);
    }}}
#line 504
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->restriction[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i; 
#line 1415
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1415
{
    {scalar*_i=(scalar*)( scalars);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      val(s,0,0,0) = masked_average (parent, s);}}
    {vector*_i=(vector*)( faces);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
      { {
 double average = masked_average_x (parent, v.x);
 if ((neighbor(-1,0,0).pid < 0))
   val(v.x,0,0,0) = average;
 if ((neighbor(1,0,0).pid < 0))
   val(v.x,1,0,0) = average;
      }}}}
  }}      
#line 475
}
  }
}
  
#line 510
}
}

  
#line 1428
pfree (scalars,__func__,__FILE__,__LINE__);
  pfree (faces,__func__,__FILE__,__LINE__);
}

void macro_mask (double func) {
#line 255 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 156
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if ((
#line 264
(
#line 1433 "/home/lisergey/basilisk/src/grid/tree.h"
!is_leaf(cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 182
))
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if ((
#line 264
(
#line 1433 "/home/lisergey/basilisk/src/grid/tree.h"
!is_leaf(cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 190
))
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default: 
#line 1433 "/home/lisergey/basilisk/src/grid/tree.h"
{  
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1433
{
    if (is_leaf(cell)) {
      int bid = (func);
      if (bid >= 0)
 cell.pid = - bid - 1;
    }
    else {
      int pid = -1;      
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k; 
  
      
#line 537 "/home/lisergey/basilisk/src/grid/config.h"
;  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 1442
if (cell.pid >= 0 || pid < 0)
   pid = cell.pid;    
#line 361
}
    point.i = (_i + 2)/2;
    point.level--;
  }
      
#line 1444
cell.pid = pid;
      if (pid < 0) {

 cell.flags |= leaf;
 decrement_neighbors (point);
      }
    }
  }}      
#line 249 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
    }
  }
}
  
#line 266
}
}
  
#line 1452 "/home/lisergey/basilisk/src/grid/tree.h"
((Tree *)grid)->dirty = true;
}

static void free_cache (CacheLevel * c)
{
  for (int l = 0; l <= depth(); l++)
    pfree (c[l].p,__func__,__FILE__,__LINE__);
  pfree (c,__func__,__FILE__,__LINE__);
}

void free_grid (void)
{
  if (!grid)
    return;
  free_boundaries();
  Tree * q = ((Tree *)grid);
  pfree (q->leaves.p,__func__,__FILE__,__LINE__);
  pfree (q->faces.p,__func__,__FILE__,__LINE__);
  pfree (q->vertices.p,__func__,__FILE__,__LINE__);
  pfree (q->refined.p,__func__,__FILE__,__LINE__);


  Layer * L = q->L[0];  
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
struct _Memindex * _m = (
#line 1475 "/home/lisergey/basilisk/src/grid/tree.h"
L->m
#line 297 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  int _len = (
#line 1475 "/home/lisergey/basilisk/src/grid/tree.h"
L->len
#line 298 "/home/lisergey/basilisk/src/grid/memindex/range.h"
);
  Point point = {0};
  for (point.i = ( (Period.x*2) > (_m->r1.start) ? (Period.x*2) : (_m->r1.start));
       point.i < ( (_len - Period.x*2) < (_m->r1.end) ? (_len - Period.x*2) : (_m->r1.end));
       point.i += 1)
    if (_m->b[point.i]) 
#line 1475 "/home/lisergey/basilisk/src/grid/tree.h"
{

    pfree (((L->m)->b[point.i]),__func__,__FILE__,__LINE__);





  }
  for (int l = 0; l <= depth(); l++)
    destroy_layer (q->L[l]);
  q->L = &(q->L[-1]);
  pfree (q->L,__func__,__FILE__,__LINE__);
  free_cache (q->active);
  free_cache (q->prolongation);
  free_cache (q->boundary);
  free_cache (q->restriction);
  pfree (q,__func__,__FILE__,__LINE__);
  grid = NULL;
}

static void refine_level (int depth);

     
void init_grid (int n)
{tracing("init_grid","/home/lisergey/basilisk/src/grid/tree.h",1499);

  if (!(sizeof(Cell) % 8 == 0)) qassert ("/home/lisergey/basilisk/src/grid/tree.h", 1502, "sizeof(Cell) % 8 == 0");

  free_grid();
  int depth = 0;
  while (n > 1) {
    if (n % 2) {
      fprintf (ferr, "tree: N must be a power-of-two\n");
      exit (1);
    }
    n /= 2;
    depth++;
  }
  Tree * q = ((Tree *) pcalloc (1, sizeof(Tree),__func__,__FILE__,__LINE__));
  grid = (Grid *) q;
  grid->depth = 0;


  q->L = ((Layer * *) pmalloc ((2)*sizeof(Layer *),__func__,__FILE__,__LINE__));

  q->L[0] = NULL; q->L = &(q->L[1]);

  Layer * L = new_layer (0);
  q->L[0] = L;

  for (int i = Period.x*2; i < L->len - Period.x*2; i++)
    assign_periodic (L->m, i, L->len,
       (char *) pcalloc (1, sizeof(Cell) + datasize,__func__,__FILE__,__LINE__));
  CELL(((L->m)->b[2])).flags |= leaf;
  if (pid() == 0)
    CELL(((L->m)->b[2])).flags |= active;
  for (int k = -2*(1 - Period.x); k <= 2*(1 - Period.x); k++)
    CELL(((L->m)->b[2 +k])).pid = (k < 0 ? -1 - left :
       k > 0 ? -1 - right :
       0);
  CELL(((L->m)->b[2])).pid = 0;
#line 1576 "/home/lisergey/basilisk/src/grid/tree.h"
  q->active = ((CacheLevel *) pcalloc (1, sizeof(CacheLevel),__func__,__FILE__,__LINE__));
  q->prolongation = ((CacheLevel *) pcalloc (1, sizeof(CacheLevel),__func__,__FILE__,__LINE__));
  q->boundary = ((CacheLevel *) pcalloc (1, sizeof(CacheLevel),__func__,__FILE__,__LINE__));
  q->restriction = ((CacheLevel *) pcalloc (1, sizeof(CacheLevel),__func__,__FILE__,__LINE__));
  q->dirty = true;
  N = 1 << depth;
#if _MPI
  void mpi_boundary_new();
  mpi_boundary_new();
#endif

  Boundary * b = ((Boundary *) pcalloc (1, sizeof(Boundary),__func__,__FILE__,__LINE__));
  b->level = box_boundary_level;
  b->restriction = masked_boundary_restriction;
  add_boundary (b);
  refine_level (depth);
  reset (all, 0.);
  { if (((Tree *)grid)->dirty) update_cache_f(); };
end_tracing("init_grid","/home/lisergey/basilisk/src/grid/tree.h",1594);}
#line 1631 "/home/lisergey/basilisk/src/grid/tree.h"
Point locate (double xp, double yp, double zp)
{
  for (int l = depth(); l >= 0; l--) {
    Point point = {0};
    point.level = l;
    int n = 1 << point.level;
    point.i = (xp - X0)/L0*n + 2;






    if (point.i >= 0 && point.i < n + 2*2






 ) {
      if (allocated(0,0,0) && is_local(cell) && is_leaf(cell))
 return point;
    }
    else
      break;
  }
  Point point = {0};
  point.level = -1;
  return point;
}



bool tree_is_full()
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
  return (grid->tn == 1L << grid->maxdepth*1);
}

#line 1 "grid/variables.h"
#line 1 "/home/lisergey/basilisk/src/grid/variables.h"
void macro2_VARIABLES (Point point, int _ig, int _jg, int _kg)
{
  double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((_ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
}
#line 1672 "/home/lisergey/basilisk/src/grid/tree.h"

void macro_foreach_boundary (int _b, Reduce reductions) {
  for (int _l = depth(); _l >= 0; _l--) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 482 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (_l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _boundary = ((Tree *)grid)->boundary[_l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = _l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _boundary.n; _k++) {
 point.i = _boundary.p[_k].i; 
#line 1675
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1675
{      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
      
#line 1677
if ((- cell.pid - 1) == _b)
 for (int _d = 0; _d < 1; _d++) {
   for (int _i = -1; _i <= 1; _i += 2) {
     if (_d == 0) ig = _i; else if (_d == 1) jg = _i; else kg = _i;
     if (allocated(-ig,-jg,-kg) &&
  is_leaf (neighbor(-ig,-jg,-kg)) &&
  !(neighbor(-ig,-jg,-kg).pid < 0) &&
  is_local(neighbor(-ig,-jg,-kg))) {
       point.i -= ig; x -= ig*Delta/2.;






       ;
       point.i += ig; x += ig*Delta/2.;






            }
   }
   ig = jg = kg = 0;
 }
    }}      
#line 475
}
  }
}
  









}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}

#line 1705 "/home/lisergey/basilisk/src/grid/tree.h"
}

void macro_foreach_vertex (char flags, Reduce reductions)
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 1710
((Tree *)grid)->vertices
#line 436
).n; _k++) {
 point.i = (
#line 1710
((Tree *)grid)->vertices
#line 437
).p[_k].i;






 point.level = (
#line 1710
((Tree *)grid)->vertices
#line 444
).p[_k].level;
 _flags = (
#line 1710
((Tree *)grid)->vertices
#line 445
).p[_k].flags; 
#line 1710
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1710
{
    int ig = -1; NOT_UNUSED (ig);






    ;
  }}      
#line 447
}
  }
}

#line 1720
}

#line 1 "grid/tree-common.h"
#line 1 "/home/lisergey/basilisk/src/grid/tree-common.h"



#line 1 "grid/multigrid-common.h"
#line 1 "/home/lisergey/basilisk/src/grid/multigrid-common.h"



#line 1 "grid/cartesian-common.h"
#line 1 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
#line 1 "grid/events.h"
#line 1 "/home/lisergey/basilisk/src/grid/events.h"
typedef struct _Event Event;
typedef int (* Expr) (int *, double *, Event *);

struct _Event {
  int last, nexpr;
  int (* action) (const int, const double, Event *);
  Expr expr[3];
  int * arrayi;
  double * arrayt;
  char * file;
  int line;
  char * name;
  double t;
  int i, a;
  void * data;
  Event * next;
};

static Event * Events = NULL;

int iter = 0, inext = 0;
double t = 0, tnext = 0;
void init_events (void);
void event_register (Event event);
static void _init_solver (void);





static int END_EVENT = 1234567890;
static double TEND_EVENT = 1234567890;
static double TEPS = 1e-9;

static void event_error (Event * ev, const char * s)
{
  fprintf (ferr, "%s:%d: error: %s\n", ev->file, ev->line, s);
  exit (1);
}

static void init_event (Event * ev)
{
  if (ev->arrayi || ev->arrayt) {
    ev->i = -1; ev->t = - TEND_EVENT;
    if (ev->arrayi)
      ev->i = ev->arrayi[0];
    else
      ev->t = ev->arrayt[0];
    ev->a = 1;
    ev->expr[1] = NULL;
  }
  else {
    if (ev->nexpr > 0) {
      Expr init = NULL, cond = NULL, inc = NULL;
      for (int j = 0; j < ev->nexpr; j++) {
 int i = -123456; double t = - TEND_EVENT;
 (* ev->expr[j]) (&i, &t, ev);
 if (i == -123456 && t == - TEND_EVENT) {

   if (cond)
     event_error (ev, "events can only use a single condition");
   cond = ev->expr[j];
 }
 else {

   int i1 = i; double t1 = t;
   (* ev->expr[j]) (&i1, &t1, ev);
   if (i1 == i && t1 == t) {


     if (init)
       event_error (ev, "events can only use a single initialisation");
     init = ev->expr[j];
   }
   else {

     if (inc)
       event_error (ev, "events can only use a single increment");
     inc = ev->expr[j];
   }
 }
      }
      ev->expr[0] = init;
      ev->expr[1] = cond;
      ev->expr[2] = inc;
      ev->nexpr = 0;
    }
    ev->i = -1; ev->t = - TEND_EVENT;
    if (ev->expr[0]) {
      (* ev->expr[0]) (&ev->i, &ev->t, ev);
      if (ev->i == END_EVENT || ev->t == TEND_EVENT) {
 ev->i = END_EVENT; ev->t = - TEND_EVENT;
      }
    }
    else if (ev->expr[2]) {
      (* ev->expr[2]) (&ev->i, &ev->t, ev);
      if (ev->i != -1)
 ev->i = 0;
      if (ev->t != - TEND_EVENT)
 ev->t = 0;
    }
  }
}

enum { event_done, event_alive, event_stop };

static int event_finished (Event * ev)
{
  ev->i = -1; ev->t = - TEND_EVENT;
  return event_done;
}

void event_register (Event event) {
  if (!(Events)) qassert ("/home/lisergey/basilisk/src/grid/events.h", 114, "Events");
  if (!(!event.last)) qassert ("/home/lisergey/basilisk/src/grid/events.h", 115, "!event.last");
  int n = 0, parent = -1;
  for (Event * ev = Events; !ev->last; ev++) {
    if (!strcmp (event.name, ev->name)) {
      if (!(parent < 0)) qassert ("/home/lisergey/basilisk/src/grid/events.h", 119, "parent < 0");
      parent = n;
    }
    n++;
  }
  if (parent < 0) {
    Events = (Event *) prealloc (Events, (n + 2)*sizeof(Event),__func__,__FILE__,__LINE__);
    Events[n] = event;
    Events[n].next = NULL;
    Events[n + 1].last = true;
    init_event (&Events[n]);
  }
  else {
    Event * ev = ((Event *) pcalloc (1, sizeof(Event),__func__,__FILE__,__LINE__));
    *ev = Events[parent];
    Events[parent] = event;
    Events[parent].next = ev;
    init_event (&Events[parent]);
  }
}

static int event_cond (Event * ev, int i, double t)
{
  if (!ev->expr[1])
    return true;
  return (* ev->expr[1]) (&i, &t, ev);
}
#line 162 "/home/lisergey/basilisk/src/grid/events.h"
static bool overload_event() { return true; }

static int event_do (Event * ev, bool action)
{
  if ((iter > ev->i && t > ev->t) || !event_cond (ev, iter, t))
    return event_finished (ev);
  if (!overload_event() || iter == ev->i || fabs (t - ev->t) <= TEPS*t) {
    if (action) {
      bool finished = false;
      for (Event * e = ev; e; e = e->next) {



 if ((* e->action) (iter, t, e))
   finished = true;
      }
      if (finished) {
 event_finished (ev);
 return event_stop;
      }
    }
    if (ev->arrayi) {
      ev->i = ev->arrayi[ev->a++];
      if (ev->i < 0)
 return event_finished (ev);
    }
    if (ev->arrayt) {
      ev->t = ev->arrayt[ev->a++];
      if (ev->t < 0)
 return event_finished (ev);
    }
    else if (ev->expr[2]) {
      int i0 = ev->i;
      (* ev->expr[2]) (&ev->i, &ev->t, ev);
      if (i0 == -1 && ev->i != i0)
 ev->i += iter + 1;
      if (!event_cond (ev, iter + 1, ev->t))
 return event_finished (ev);
    }
    else if (ev->expr[0] && !ev->expr[1])
      return event_finished (ev);
  }
  return event_alive;
}

static void end_event_do (bool action)
{




  for (Event * ev = Events; !ev->last; ev++)
    if (ev->i == END_EVENT && action)
      for (Event * e = ev; e; e = e->next) {



 e->action (iter, t, e);
      }
}

int events (bool action)
{





  if (iter == 0)
    for (Event * ev = Events; !ev->last; ev++)
      init_event (ev);

  int cond = 0, cond1 = 0;
  inext = END_EVENT; tnext = 1e30f;
  for (Event * ev = Events; !ev->last && !cond; ev++)
    if (ev->i != END_EVENT &&
 (ev->expr[1] || (ev->expr[0] && !ev->expr[1] && !ev->expr[2]) || ev->arrayi || ev->arrayt))
      cond = 1;
  for (Event * ev = Events; !ev->last; ev++) {
    int status = event_do (ev, action);
    if (status == event_stop) {
      end_event_do (action);
      return 0;
    }
    if (status == event_alive && ev->i != END_EVENT &&
 (ev->expr[1] || (ev->expr[0] && !ev->expr[1] && !ev->expr[2]) || ev->arrayi || ev->arrayt))
      cond1 = 1;
    if (ev->t > t && ev->t < tnext)
      tnext = ev->t;
    if (ev->i > iter && ev->i < inext)
      inext = ev->i;
  }
  if (overload_event() && (!cond || cond1) && (tnext != 1e30f || inext != END_EVENT)) {
    inext = iter + 1;
    return 1;
  }
  end_event_do (action);
  return 0;
}

void event (const char * name)
{
  for (Event * ev = Events; !ev->last; ev++)
    if (!strcmp (ev->name, name))
      for (Event * e = ev; e; e = e->next) {



 (* e->action) (0, 0, e);
      }
}

double dtnext (double dt)
{
  if (tnext != 1e30f && tnext > t) {
    if (!(dt > 0.)) qassert ("/home/lisergey/basilisk/src/grid/events.h", 277, "dt > 0.");
    unsigned int n = (tnext - t)/dt;
    if (!(n < INT_MAX)) qassert ("/home/lisergey/basilisk/src/grid/events.h", 279, "n < INT_MAX");
    if (n == 0)
      dt = tnext - t;
    else {
      double dt1 = (tnext - t)/n;
      if (dt1 > dt*(1. + TEPS))
 dt = (tnext - t)/(n + 1);
      else if (dt1 < dt)
 dt = dt1;
      tnext = t + dt;
    }
  }
  else
    tnext = t + dt;
  return dt;
}

void init_solver()
{
  Events = pmalloc (sizeof (Event),__func__,__FILE__,__LINE__);
  Events[0].last = 1;
  _attribute = pcalloc (datasize/sizeof(real), sizeof (_Attributes),__func__,__FILE__,__LINE__);
  int n = datasize/sizeof(real);
  all = (scalar *) pmalloc (sizeof (scalar)*(n + 1),__func__,__FILE__,__LINE__);
  baseblock = (scalar *) pmalloc (sizeof (scalar)*(n + 1),__func__,__FILE__,__LINE__);
  for (int i = 0; i < n; i++)
    baseblock[i].i = all[i].i = i;
  baseblock[n].i = all[n].i = -1;
#line 317 "/home/lisergey/basilisk/src/grid/events.h"
}
#line 2 "/home/lisergey/basilisk/src/grid/cartesian-common.h"

void (* debug) (Point);

#define _val_constant(a,k,l,m) ((const double) _constant[a.i -_NVARMAX])
#define val_diagonal(a,k,l,m) ((k) == 0 && (l) == 0 && (m) == 0)

#line 1 "grid/fpe.h"
#line 1 "/home/lisergey/basilisk/src/grid/fpe.h"


#include <signal.h>
#include <unistd.h>

static int gdb()
{
  if (last_point.level >= 0) {
    debug (last_point);
    fputc ('\n', ferr);
    fflush (ferr);
  }
  char command[80];
  sprintf (command, "exec xterm -e 'gdb -p %d' & xterm -e 'gnuplot plot -'",
    getpid());
  return system (command);
}

static void caught_abort (int sig)
{
  fprintf (ferr, "Caught signal %d (Aborted)\n", sig);
  gdb();
}

static void caught_fpe (int sig)
{
  fprintf (ferr, "Caught signal %d (Floating Point Exception)\n", sig);
  gdb();
  exit (1);
}

static void caught_segfault (int sig)
{
  fprintf (ferr, "Caught signal %d (Segmentation Fault)\n", sig);
  gdb();
  exit (2);
}

void catch_fpe (void)
{
  struct sigaction act;
  act.sa_handler = caught_fpe;
  sigemptyset (&act.sa_mask);
  act.sa_flags = 0;
  last_point.level = -1;
  sigaction (8, &act, NULL);
  act.sa_handler = caught_segfault;
  sigaction (11, &act, NULL);
  act.sa_handler = caught_abort;
  act.sa_flags = SA_RESETHAND;
  sigaction (6, &act, NULL);
}
#line 9 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
#line 1 "grid/stencils.h"
#line 1 "/home/lisergey/basilisk/src/grid/stencils.h"
#line 17 "/home/lisergey/basilisk/src/grid/stencils.h"










typedef struct _External External;

struct _External {
  char * name;
  void * pointer;
  int type;
  int nd;
  char reduct;
  char global;
  void * data;
  scalar s;
  External * externals, * next;
  int used;
};

typedef struct {
  const char * fname;
  int line;
  int first;
  int face;
  bool vertex;
  int parallel;
  scalar * listc;
  vectorl listf;
  scalar * dirty;
  void * data;
} ForeachData;







static inline bool scalar_is_dirty (scalar s)
{
  if (_attribute[s.i].dirty)
    return true;
  scalar * depends = _attribute[s.i].depends;
  {scalar*_i=(scalar*)( depends);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
    if (_attribute[d.i].dirty)
      return true;}}
  return false;
}




static inline bool scalar_depends_from (scalar a, scalar b)
{
  scalar * depends = _attribute[a.i].depends;
  {scalar*_i=(scalar*)( depends);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (s.i == b.i)
      return true;}}
  return false;
}







void boundary_internal (scalar * list, const char * fname, int line);
void (* boundary_face) (vectorl);







void check_stencil (ForeachData * loop)
{
  loop->listf = (vectorl){NULL};




  {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    bool write = _attribute[s.i].output, read = _attribute[s.i].input;




    {





      if (read && scalar_is_dirty (s)) {





 if (_attribute[s.i].face) {
   if (_attribute[s.i].width > 0)
     loop->listc = list_append (loop->listc, s);
   else if (!write) {
     scalar sn = _attribute[s.i].v.x.i >= 0 ? _attribute[s.i].v.x : s;
     
       if (_attribute[s.i].v.x.i == s.i) {




  if (_attribute[sn.i].boundary[left] || _attribute[sn.i].boundary[right])
    loop->listc = list_append (loop->listc, s);
  else if (_attribute[s.i].dirty != 2)
    loop->listf.x = list_append (loop->listf.x, s);
       }
   }
 }





 else if (_attribute[s.i].width > 0)
   loop->listc = list_append (loop->listc, s);
      }





      if (write) {
 if (1 > 1 && !loop->vertex && loop->first && !_attribute[s.i].nowarning) {
   bool vertex = true;
   
     if (_attribute[s.i].d.x != -1)
       vertex = false;
   if (vertex)
     fprintf (ferr,
       "%s:%d: warning: vertex scalar '%s' should be assigned with"
       " a foreach_vertex() loop\n",
       loop->fname, loop->line, _attribute[s.i].name);
 }
 if (_attribute[s.i].face) {
   if (loop->face == 0 && loop->first && !_attribute[s.i].nowarning)
     fprintf (ferr,
       "%s:%d: warning: face vector '%s' should be assigned with"
       " a foreach_face() loop\n",
       loop->fname, loop->line, _attribute[s.i].name);
 }
 else if (loop->face) {
   if (_attribute[s.i].v.x.i < 0) {
     int d = 1, i = 0;
      {
       if (loop->face == d) {
  _attribute[s.i].face = 2, _attribute[s.i].v.x.i = s.i;
  _attribute[s.i].boundary[left] = _attribute[s.i].boundary[right] = NULL;





       }
       d *= 2, i++;
     }
     if (!_attribute[s.i].face && loop->first && !_attribute[s.i].nowarning)
       fprintf (ferr,
         "%s:%d: warning: scalar '%s' should be assigned with "
         "a foreach_face(x|y|z) loop\n",
         loop->fname, loop->line, _attribute[s.i].name);
   }
   else {
     char * name = NULL;
     if (_attribute[s.i].name) {
       name = pstrdup (_attribute[s.i].name,__func__,__FILE__,__LINE__);
       char * s = name + strlen(name) - 1;
       while (s != name && *s != '.') s--;
       if (s != name) *s = '\0';
     }
     struct { int x, y, z; } input, output;
     vector v = _attribute[s.i].v;

     
       input.x = _attribute[v.x.i].input, output.x = _attribute[v.x.i].output;

     init_face_vector (v, name);


     
       _attribute[v.x.i].input = input.x, _attribute[v.x.i].output = output.x;





     pfree (name,__func__,__FILE__,__LINE__);
   }
 }
 else if (loop->vertex) {
   bool vertex = true;
   
     if (_attribute[s.i].d.x != -1)
       vertex = false;
   if (!vertex) {
     char * name = NULL;
     if (_attribute[s.i].name) name = pstrdup (_attribute[s.i].name,__func__,__FILE__,__LINE__);
     init_vertex_scalar (s, name);
     
       _attribute[s.i].v.x.i = -1;




     pfree (name,__func__,__FILE__,__LINE__);
   }
 }





 loop->dirty = list_append (loop->dirty, s);
 {scalar*_i=(scalar*)( baseblock);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
   if (scalar_depends_from (d, s))
     loop->dirty = list_append (loop->dirty, d);}}
      }
    }
  }}}
}




void boundary_stencil (ForeachData * loop)
{
  bool flux = false;
  
    if (loop->listf.x)
      flux = true;
  if (flux) {
#line 276 "/home/lisergey/basilisk/src/grid/stencils.h"
    boundary_face (loop->listf);
    
      pfree (loop->listf.x,__func__,__FILE__,__LINE__), loop->listf.x = NULL;
  }




  if (loop->listc) {






    boundary_internal (loop->listc, loop->fname, loop->line);
    pfree (loop->listc,__func__,__FILE__,__LINE__), loop->listc = NULL;
  }





  if (loop->dirty) {






    {scalar*_i=(scalar*)( loop->dirty);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].dirty = true;}}
    pfree (loop->dirty,__func__,__FILE__,__LINE__), loop->dirty = NULL;
  }
}

void macro_foreach_stencil (char flags, Reduce reductions)
{
  {
    static int _first = 1.;
    ForeachData _loop = {
      .fname = __FILE__, .line = __LINE__, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);

    ;

    check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }
}

void macro_foreach_vertex_stencil (char flags, Reduce reductions) {  
#line 314
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/stencils.h", .line = 335, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 335
{
    _loop.vertex = true;
    ;
  }    
#line 328
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }







}

void macro_foreach_face_stencil (char flags, Reduce reductions, const char * order) {  
#line 314
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/stencils.h", .line = 342, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 343
;    
#line 328
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 344
}

void macro_foreach_level_stencil (int l, char flags, Reduce reductions) {
  if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    ;
  }
}

void macro_foreach_coarse_level_stencil (int l, char flags, Reduce reductions) {  
#line 347
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    





;  
#line 352
}





}

void macro_foreach_level_or_leaf_stencil (int l, char flags, Reduce reductions) {  
#line 347
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 362
;  
#line 352
}










}

void macro_foreach_point_stencil (double xp, double yp, double zp, char flags, Reduce reductions)
{  
#line 314
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/stencils.h", .line = 367, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 368
;    
#line 328
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 369
}

void macro_foreach_region_stencil (coord p, coord box[2], coord n, char flags, Reduce reductions)
{  
#line 314
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/stencils.h", .line = 373, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 374
;    
#line 328
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }

#line 375
}

void macro__stencil_is_face_x (ForeachData l) { l.face |= (1 << 0); ; }
void macro__stencil_is_face_y (ForeachData l) { l.face |= (1 << 1); ; }
void macro__stencil_is_face_z (ForeachData l) { l.face |= (1 << 2); ; }

void stencil_val (Point p, scalar s, int i, int j, int k,
    const char * file, int line, bool overflow);
void stencil_val_a (Point p, scalar s, int i, int j, int k, bool input,
      const char * file, int line);

#define _stencil_val(a,_i,_j,_k)\
  stencil_val (point, a, _i, _j, _k, __FILE__, __LINE__, false)\

#line 508

#define _stencil_val_o(a,_i,_j,_k)\
  stencil_val (point, a, _i, _j, _k, __FILE__, __LINE__, true)\

#line 511

#define _stencil_val_a(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, false, __FILE__, __LINE__)\

#line 514

#define _stencil_val_r(a,_i,_j,_k)\
  stencil_val_a (point, a, _i, _j, _k, true, __FILE__, __LINE__)\

#line 517


#define _stencil_fine(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_fine(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_fine_a(a,_i,_j,_k) _stencil_val_a(a,_i,_j,_k)
#define _stencil_fine_r(a,_i,_j,_k) _stencil_val_r(a,_i,_j,_k)

#define _stencil_coarse(a,_i,_j,_k) _stencil_val(a,_i,_j,_k)
#define _stencil_coarse_a(a,_i,_j,_k) _stencil_val_a(a,_i,_j,_k)
#define _stencil_coarse_r(a,_i,_j,_k) _stencil_val_r(a,_i,_j,_k)

#define r_assign(x)
#define _assign(x)

#define _stencil_neighbor(i,j,k)
#define _stencil_child(i,j,k)
#define _stencil_aparent(i,j,k)
#define _stencil_aparent_a(i,j,k)
#define _stencil_aparent_r(i,j,k)

#define _stencil_allocated(i,j,k) true

#define _stencil_neighborp(i,j,k) neighborp(i,j,k)

int _stencil_nop;
#define _stencil_val_higher_dimension (_stencil_nop = 1)
#define _stencil__val_constant(a,_i,_j,_k) (_stencil_nop = 1)
#define _stencil_val_diagonal(a,_i,_j,_k) (_stencil_nop = 1)

typedef void _stencil_undefined;

#define o_stencil -3
#line 10 "/home/lisergey/basilisk/src/grid/cartesian-common.h"

void macro_foreach_point (double _x, double _y, double _z,
        char flags, Reduce reductions)
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { _x, _y, _z };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
      ;
  }
}

void macro_foreach_region (coord p, coord box[2], coord n,
         char flags, Reduce reductions)
{
  {
    if (n.x < 1) n.x = 1;
    if (n.y < 1) n.y = 1;
    if (n.z < 1) n.z = 1;

    for (int _i = 0; _i < (int) n.x; _i++) {
      p.x = box[0].x + (box[1].x - box[0].x)/n.x*(_i + 0.5);
      for (int _j = 0; _j < (int) n.y; _j++) {
 p.y = box[0].y + (box[1].y - box[0].y)/n.y*(_j + 0.5);
 for (int _k = 0; _k < (int) n.z; _k++) {
   p.z = box[0].z + (box[1].z - box[0].z)/n.z*(_k + 0.5);
   Point point = locate (p.x, p.y, p.z);
   if (point.level >= 0) {
     int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
     ;
   }
 }
      }
    }
  }
}




static inline
double dirichlet (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 54 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return 2.*expr - val(s,0,0,0);
}

static inline
double dirichlet_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 60 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return - val(s,0,0,0);
}

static inline
double dirichlet_face (double expr)
{
  return expr;
}

static inline
double dirichlet_face_homogeneous (double expr)
{
  return 0.;
}

static inline
double neumann (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 78 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return Delta*expr + val(s,0,0,0);
}

static inline
double neumann_homogeneous (double expr, Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 84 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return val(s,0,0,0);
}
#line 145 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
static void init_block_scalar (scalar sb, const char * name, const char * ext,
          int n, int block)
{
  char bname[strlen(name) + strlen(ext) + 10];
  if (n == 0) {
    strcat (strcpy (bname, name), ext);
    _attribute[sb.i].block = block;
    baseblock = list_append (baseblock, sb);
  }
  else {
    sprintf (bname, "%s%d%s", name, n, ext);
    _attribute[sb.i].block = - n;
  }
  _attribute[sb.i].name = pstrdup (bname,__func__,__FILE__,__LINE__);
  all = list_append (all, sb);
}

#define interpreter_set_int(...)
#define interpreter_reset_scalar(...)

scalar alloc_block_scalar (const char * name, const char * ext, int block)
{
  interpreter_set_int (&block);
  int nvar = datasize/sizeof(real);

  scalar s = {0};
  while (s.i < nvar) {
    int n = 0;
    scalar sb = s;
    while (sb.i < nvar && n < block && _attribute[sb.i].freed)
      n++, sb.i++;
    if (n >= block) {
      memset (&_attribute[s.i], 0, block*sizeof (_Attributes));
      for (sb.i = s.i, n = 0; n < block; n++, sb.i++) {
 init_block_scalar (sb, name, ext, n, block);
 interpreter_reset_scalar (sb);
      }
      trash (((scalar []){s, {-1}}));
      return s;
    }
    s.i = sb.i + 1;
  }


  s = (scalar){nvar};
  if (!(nvar + block <= _NVARMAX)) qassert ("/home/lisergey/basilisk/src/grid/cartesian-common.h", 190, "nvar + block <= _NVARMAX");

  if (_attribute == NULL)
    _attribute = (_Attributes *) pcalloc (nvar + block + 1, sizeof (_Attributes),__func__,__FILE__,__LINE__);
  else
    _attribute = (_Attributes *)
      prealloc (_attribute, (nvar + block + 1)*sizeof (_Attributes),__func__,__FILE__,__LINE__);
  memset (&_attribute[nvar], 0, block*sizeof (_Attributes));
  for (int n = 0; n < block; n++, nvar++) {
    scalar sb = (scalar){nvar};
    init_block_scalar (sb, name, ext, n, block);
  }

  realloc_scalar (block*sizeof(real));
  trash (((scalar []){s, {-1}}));
  return s;
}

scalar new_block_scalar (const char * name, const char * ext, int block)
{
  scalar s = alloc_block_scalar (name, ext, block), sb;
  int n = 0;
  for (sb.i = s.i, n = 0; n < block; n++, sb.i++)
    init_scalar (sb, NULL);
  return s;
}

scalar new_scalar (const char * name)
{
  return init_scalar (alloc_block_scalar (name, "", 1), NULL);
}

scalar new_vertex_scalar (const char * name)
{
  return init_vertex_scalar (alloc_block_scalar (name, "", 1), NULL);
}

static vector alloc_block_vector (const char * name, int block)
{
  vector v;
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
  
    v.x = alloc_block_scalar (name, ext.x, block);
  return v;
}

vector new_vector (const char * name)
{
  vector v = alloc_block_vector (name, 1);
  init_vector (v, NULL);
  return v;
}

vector new_face_vector (const char * name)
{
  vector v = alloc_block_vector (name, 1);
  init_face_vector (v, NULL);
  return v;
}

vector new_block_vector (const char * name, int block)
{
  vector v = alloc_block_vector (name, block);
  for (int i = 0; i < block; i++) {
    vector vb;
    
      vb.x.i = v.x.i + i;
    init_vector (vb, NULL);
    
      _attribute[vb.x.i].block = - i;
  }
  
    _attribute[v.x.i].block = block;
  return v;
}

vector new_block_face_vector (const char * name, int block)
{
  vector v = alloc_block_vector (name, block);
  for (int i = 0; i < block; i++) {
    vector vb;
    
      vb.x.i = v.x.i + i;
    init_face_vector (vb, NULL);
    
      _attribute[vb.x.i].block = - i;
  }
  
    _attribute[v.x.i].block = block;
  return v;
}

tensor new_tensor (const char * name)
{
  char cname[strlen(name) + 3];
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
  tensor t;
   {
    strcat (strcpy (cname, name), ext.x);
    t.x = alloc_block_vector (cname, 1);
  }
  init_tensor (t, NULL);
  return t;
}

tensor new_symmetric_tensor (const char * name)
{
  struct { char * x, * y, * z; } ext = {".x.x", ".y.y", ".z.z"};
  tensor t;
  
    t.x.x = alloc_block_scalar (name, ext.x, 1);
#line 314 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
  init_tensor (t, NULL);
  return t;
}

static int nconst = 0;

void init_const_scalar (scalar s, const char * name, double val)
{
  if (s.i - _NVARMAX >= nconst) {
    _constant = (double *) prealloc (_constant, (s.i - _NVARMAX + 1)*sizeof(double),__func__,__FILE__,__LINE__);
    for (int i = nconst; i < s.i - _NVARMAX; i++)
      _constant[i] = 0.;
    nconst = s.i - _NVARMAX + 1;
  }
  _constant[s.i - _NVARMAX] = val;
}

scalar new_const_scalar (const char * name, int i, double val)
{
  scalar s = (scalar){i + _NVARMAX};
  init_const_scalar (s, name, val);
  return s;
}

void init_const_vector (vector v, const char * name, double * val)
{
  
    init_const_scalar (v.x, name, *val++);
}

vector new_const_vector (const char * name, int i, double * val)
{
  vector v;
  
    v.x.i = _NVARMAX + i++;
  init_const_vector (v, name, val);
  return v;
}

static void cartesian_scalar_clone (scalar clone, scalar src)
{
  char * cname = _attribute[clone.i].name;
  BoundaryFunc * boundary = _attribute[clone.i].boundary;
  BoundaryFunc * boundary_homogeneous = _attribute[clone.i].boundary_homogeneous;
  if (!(_attribute[src.i].block > 0 && _attribute[clone.i].block == _attribute[src.i].block)) qassert ("/home/lisergey/basilisk/src/grid/cartesian-common.h", 358, "src.block > 0 && clone.block == src.block");
  pfree (_attribute[clone.i].depends,__func__,__FILE__,__LINE__);
  _attribute[clone.i] = _attribute[src.i];
  _attribute[clone.i].name = cname;
  _attribute[clone.i].boundary = boundary;
  _attribute[clone.i].boundary_homogeneous = boundary_homogeneous;
  for (int i = 0; i < nboundary; i++) {
    _attribute[clone.i].boundary[i] = _attribute[src.i].boundary[i];
    _attribute[clone.i].boundary_homogeneous[i] = _attribute[src.i].boundary_homogeneous[i];
  }
  _attribute[clone.i].depends = list_copy (_attribute[src.i].depends);
}

scalar * list_clone (scalar * l)
{
  scalar * list = NULL;
  int nvar = datasize/sizeof(real), map[nvar];
  for (int i = 0; i < nvar; i++)
    map[i] = -1;
  {scalar*_i=(scalar*)( l);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    scalar c = _attribute[s.i].block > 1 ? new_block_scalar("c", "", _attribute[s.i].block) : new_scalar("c");
    scalar_clone (c, s);
    map[s.i] = c.i;
    list = list_append (list, c);
  }}}
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    {
      if (_attribute[s.i].v.x.i >= 0 && map[_attribute[s.i].v.x.i] >= 0)
 _attribute[s.i].v.x.i = map[_attribute[s.i].v.x.i];}}}
  return list;
}

void delete (scalar * list)
{
  if (all == NULL)
    return;

  {scalar*_i=(scalar*)( list);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){ {
    for (int i = 0; i < _attribute[f.i].block; i++) {
      scalar fb = {f.i + i};
      if (_attribute[f.i].delete)
 _attribute[f.i].delete (fb);
      pfree (_attribute[fb.i].name,__func__,__FILE__,__LINE__); _attribute[fb.i].name = NULL;
      pfree (_attribute[fb.i].boundary,__func__,__FILE__,__LINE__); _attribute[fb.i].boundary = NULL;
      pfree (_attribute[fb.i].boundary_homogeneous,__func__,__FILE__,__LINE__); _attribute[fb.i].boundary_homogeneous = NULL;
      pfree (_attribute[fb.i].depends,__func__,__FILE__,__LINE__); _attribute[fb.i].depends = NULL;
      _attribute[fb.i].freed = true;
    }
  }}}

  if (list == all) {
    all[0].i = -1;
    baseblock[0].i = -1;
    return;
  }

  trash (list);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar f=*_i;(&f)->i>=0;f=*++_i){ {
    if (_attribute[f.i].block > 0) {
      scalar * s;
      for (s = all; s->i >= 0 && s->i != f.i; s++);
      if (s->i == f.i) {
 for (; s[_attribute[f.i].block].i >= 0; s++)
   s[0] = s[_attribute[f.i].block];
 s->i = -1;
      }
      for (s = baseblock; s->i >= 0 && s->i != f.i; s++);
      if (s->i == f.i) {
 for (; s[1].i >= 0; s++)
   s[0] = s[1];
 s->i = -1;
      }
    }
  }}}
}

void free_solver()
{
  if (!(_val_higher_dimension == 0.)) qassert ("/home/lisergey/basilisk/src/grid/cartesian-common.h", 436, "_val_higher_dimension == 0.");

  if (free_solver_funcs) {
    free_solver_func * a = (free_solver_func *) free_solver_funcs->p;
    for (int i = 0; i < free_solver_funcs->len/sizeof(free_solver_func); i++)
      a[i] ();
    array_free (free_solver_funcs);
  }

  delete (all);
  pfree (all,__func__,__FILE__,__LINE__); all = NULL;
  pfree (baseblock,__func__,__FILE__,__LINE__); baseblock = NULL;
  for (Event * ev = Events; !ev->last; ev++) {
    Event * e = ev->next;
    while (e) {
      Event * next = e->next;
      pfree (e,__func__,__FILE__,__LINE__);
      e = next;
    }
  }

  pfree (Events,__func__,__FILE__,__LINE__); Events = NULL;
  pfree (_attribute,__func__,__FILE__,__LINE__); _attribute = NULL;
  pfree (_constant,__func__,__FILE__,__LINE__); _constant = NULL;




  free_grid();
  qpclose_all();
#if TRACE
  trace_off();
#endif
#if MTRACE
  pmuntrace();
#endif
#if _CADNA
  cadna_end();
#endif
}



void (* boundary_level) (scalar *, int l);
void (* boundary_face) (vectorl);




void boundary_flux (vector * list) __attribute__ ((deprecated));

void boundary_flux (vector * list)
{
  vectorl list1 = {NULL};
  {vector*_i=(vector*)( list);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
    {
      list1.x = list_append (list1.x, v.x);}}}
  boundary_face (list1);
  
    pfree (list1.x,__func__,__FILE__,__LINE__);
}

static scalar * list_add_depends (scalar * list, scalar s)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar t=*_i;(&t)->i>=0;t=*++_i){
    if (t.i == s.i)
      return list;}}
  scalar * list1 = list;
  {scalar*_i=(scalar*)( _attribute[s.i].depends);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
    if (_attribute[d.i].dirty)
      list1 = list_add_depends (list1, d);}}
  return list_append (list1, s);
}

     
void boundary_internal (scalar * list, const char * fname, int line)
{tracing("boundary_internal","/home/lisergey/basilisk/src/grid/cartesian-common.h",511);
  if (list == NULL)
    {end_tracing("boundary_internal","/home/lisergey/basilisk/src/grid/cartesian-common.h",514);return;}
  scalar * listc = NULL;
  vectorl listf = {NULL};
  bool flux = false;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].block > 0) {
      if (scalar_is_dirty (s)) {
 if (_attribute[s.i].face && _attribute[s.i].dirty != 2)
   {
     if (_attribute[s.i].v.x.i == s.i)
       listf.x = list_add (listf.x, s), flux = true;}
 if (!is_constant(cm) && _attribute[cm.i].dirty)
   listc = list_add_depends (listc, cm);
 if (_attribute[s.i].face != 2)
   listc = list_add_depends (listc, s);
      }




    }}}
  if (flux) {
    boundary_face (listf);
    
      pfree (listf.x,__func__,__FILE__,__LINE__);
  }
  if (listc) {






    boundary_level (listc, -1);
    {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].dirty = false;}}
    pfree (listc,__func__,__FILE__,__LINE__);
  }
end_tracing("boundary_internal","/home/lisergey/basilisk/src/grid/cartesian-common.h",552);}

void cartesian_boundary_level (scalar * list, int l)
{
  { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list, l); };
}

void cartesian_boundary_face (vectorl list)
{
  
    {scalar*_i=(scalar*)( list.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].dirty = 2;}}
}

static double symmetry (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 568 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return val(s,0,0,0);
}

static double antisymmetry (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 573 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return -val(s,0,0,0);
}

BoundaryFunc default_scalar_bc[] = {
  symmetry, symmetry, symmetry, symmetry, symmetry, symmetry
};

scalar cartesian_init_scalar (scalar s, const char * name)
{

  char * pname;
  if (name) {
    pfree (_attribute[s.i].name,__func__,__FILE__,__LINE__);
    pname = pstrdup (name,__func__,__FILE__,__LINE__);
  }
  else
    pname = _attribute[s.i].name;
  int block = _attribute[s.i].block;
  BoundaryFunc * boundary = _attribute[s.i].boundary;
  BoundaryFunc * boundary_homogeneous = _attribute[s.i].boundary_homogeneous;
  _attribute[s.i].name = pname;
  if (block < 0)
    _attribute[s.i].block = block;
  else
    _attribute[s.i].block = block > 0 ? block : 1;

  _attribute[s.i].boundary = boundary ? boundary : (BoundaryFunc *) pmalloc (nboundary*sizeof (BoundaryFunc),__func__,__FILE__,__LINE__);
  _attribute[s.i].boundary_homogeneous = boundary_homogeneous ? boundary_homogeneous :
    (BoundaryFunc *) pmalloc (nboundary*sizeof (BoundaryFunc),__func__,__FILE__,__LINE__);
  for (int b = 0; b < nboundary; b++)
    _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b] =
      b < 2*1 ? default_scalar_bc[b] : symmetry;
  _attribute[s.i].gradient = NULL;
   {
    _attribute[s.i].d.x = 0;
    _attribute[s.i].v.x.i = -1;
  }
  _attribute[s.i].face = false;
  return s;
}

scalar cartesian_init_vertex_scalar (scalar s, const char * name)
{
  cartesian_init_scalar (s, name);
  
    _attribute[s.i].d.x = -1;
  for (int d = 0; d < nboundary; d++)
    _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = NULL;
  return s;
}

BoundaryFunc default_vector_bc[] = {
  antisymmetry, antisymmetry,
  antisymmetry, antisymmetry,
  antisymmetry, antisymmetry
};

vector cartesian_init_vector (vector v, const char * name)
{
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
   {
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.x);
      cartesian_init_scalar (v.x, cname);
    }
    else
      cartesian_init_scalar (v.x, NULL);
    _attribute[v.x.i].v = v;
  }

  for (int d = 0; d < nboundary; d++)
    _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] =
      d < 2*1 ? default_vector_bc[d] : antisymmetry;
  return v;
}

vector cartesian_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_vector (v, name);
   {
    _attribute[v.x.i].d.x = -1;
    _attribute[v.x.i].face = true;
  }
  for (int d = 0; d < nboundary; d++)
    _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] = NULL;
  return v;
}

tensor cartesian_init_tensor (tensor t, const char * name)
{
  struct { char * x, * y, * z; } ext = {".x", ".y", ".z"};
   {
    if (name) {
      char cname[strlen(name) + 3];
      strcat (strcpy (cname, name), ext.x);
      cartesian_init_vector (t.x, cname);
    }
    else
      cartesian_init_vector (t.x, NULL);
  }


    for (int b = 0; b < nboundary; b++)
      _attribute[t.x.x.i].boundary[b] = _attribute[t.x.x.i].boundary_homogeneous[b] =
 b < 2*1 ? default_scalar_bc[b] : symmetry;
#line 691 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
  return t;
}

void output_cells (FILE * fp, coord c, double size)
{ 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags; 
#line 696 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 696 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{
    bool inside = true;
    coord o = {x,y,z};
    
      if (inside && size > 0. &&
   (o.x > c.x + size || o.x < c.x - size))
 inside = false;
    if (inside) {
      Delta /= 2.;

      fprintf (fp, "%g 0\n%g 0\n\n", x - Delta, x + Delta);
#line 728 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
    }
  }}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}
  
#line 730 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
fflush (fp);
}
#line 740 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
static char * replace_ (const char * vname)
{
  char * name = pstrdup (vname,__func__,__FILE__,__LINE__), * c = name;
  while (*c != '\0') {
    if (*c == '.')
      *c = '_';
    c++;
  }
  return name;
}

static void debug_plot (FILE * fp, const char * name, const char * cells,
   const char * stencil)
{
  char * vname = replace_ (name);
  fprintf (fp,
    "  load 'debug.plot'\n"
    "  v=%s\n"

    "  plot '%s' w l lc 0, "
    "'%s' u 1+2*v:(0):2+2*v w labels tc lt 1 title columnhead(2+2*v)",
#line 769 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
    vname, cells, stencil);
  pfree (vname,__func__,__FILE__,__LINE__);
}

void cartesian_debug (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 775 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
char name[80] = "cells";
  if (pid() > 0)
    sprintf (name, "cells-%d", pid());
  FILE * fp = fopen (name, "w");
  output_cells (fp, (coord){x,y,z}, 4.*Delta);
  fclose (fp);

  char stencil[80] = "stencil";
  if (pid() > 0)
    sprintf (stencil, "stencil-%d", pid());
  fp = fopen (stencil, "w");
  {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){

    fprintf (fp, "x %s ", _attribute[v.i].name);}}





  fputc ('\n', fp);

    for (int k = -2; k <= 2; k++) {
      {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){ {
 fprintf (fp, "%g ", x + k*Delta + _attribute[v.i].d.x*Delta/2.);
 if (allocated(k,0,0))
   fprintf (fp, "%g ", val(v,k,0,0));
 else
   fputs ("n/a ", fp);
      }}}
      fputc ('\n', fp);
    }
#line 837 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
  fclose (fp);

  fp = fopen ("debug.plot", "w");
  fprintf (fp,
    "set term x11\n"
    "set size ratio -1\n"
    "set key outside\n");
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    char * name = replace_ (_attribute[s.i].name);
    fprintf (fp, "%s = %d\n", name, s.i);
    pfree (name,__func__,__FILE__,__LINE__);
  }}}
  fclose (fp);

  fprintf (ferr, "Last point stencils can be displayed using (in gnuplot)\n");
  debug_plot (ferr, _attribute[0].name, name, stencil);
  fflush (ferr);

  fp = fopen ("plot", "w");
  debug_plot (fp, _attribute[0].name, name, stencil);
  fclose (fp);
}

void cartesian_methods()
{
  init_scalar = cartesian_init_scalar;
  init_vertex_scalar = cartesian_init_vertex_scalar;
  init_vector = cartesian_init_vector;
  init_face_vector = cartesian_init_face_vector;
  init_tensor = cartesian_init_tensor;
  boundary_level = cartesian_boundary_level;
  boundary_face = cartesian_boundary_face;
  scalar_clone = cartesian_scalar_clone;
  debug = cartesian_debug;
}

tensor init_symmetric_tensor (tensor t, const char * name)
{
  return init_tensor (t, name);
}

static double interpolate_linear (Point point, scalar v,
      double xp, double yp, double zp)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;

  
#line 882 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
x = (xp - x)/Delta - _attribute[v.i].d.x/2.;
  int i = ( (int)(x > 0 ? 1 : -1));
  x = fabs(x);

  return val(v,0,0,0)*(1. - x) + val(v,i,0,0)*x;
#line 907 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
}
#line 878
static void _stencil_interpolate_linear (Point point, scalar v,
_stencil_undefined * xp,_stencil_undefined * yp,_stencil_undefined * zp)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;          

        
  
     
#line 886 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
_stencil_val(v,0,0,0);_stencil_val(v, o_stencil,0,0);  return   ;
#line 907 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
}

     
double interpolate (scalar v, double xp, double yp, double zp,
      bool linear)
{tracing("interpolate","/home/lisergey/basilisk/src/grid/cartesian-common.h",910);
  double val = 1e30f;  
#line 314 "/home/lisergey/basilisk/src/grid/stencils.h"
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/cartesian-common.h", .line = 914, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 915 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{ _stencil_interpolate_linear (point, v, NULL, NULL, NULL); _stencil_val(v,0,0,0);    }    
#line 328 "/home/lisergey/basilisk/src/grid/stencils.h"
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }
#line 13 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { xp, yp, zp };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0)
    
#line 915
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 915 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
val = linear ? interpolate_linear (point, v, xp, yp, zp) : val(v,0,0,0);}  
#line 20
}
}
#line 915
{mpi_all_reduce_array(&val,MPI_DOUBLE,MPI_MIN,1);}
  {end_tracing("interpolate","/home/lisergey/basilisk/src/grid/cartesian-common.h",916);return val;}
end_tracing("interpolate","/home/lisergey/basilisk/src/grid/cartesian-common.h",917);}

     
void interpolate_array (scalar * list, coord * a, int n, double * v,
   bool linear)
{tracing("interpolate_array","/home/lisergey/basilisk/src/grid/cartesian-common.h",920);
  int len = 0;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    len++;}}
  for (int i = 0; i < n; i++) {
    double * w = v;
#line 937 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      *(w++) = 1e30f;}}    
#line 314 "/home/lisergey/basilisk/src/grid/stencils.h"
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/cartesian-common.h", .line = 939, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 939 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{   
      
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 { _stencil_val(s,0,0,0); _stencil_interpolate_linear (point, s, NULL, NULL, NULL);    }}}
    }    
#line 328 "/home/lisergey/basilisk/src/grid/stencils.h"
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  }
#line 13 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{
  {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    coord _p = { (
#line 939
a[i].x
#line 16
), (
#line 939
a[i].y
#line 16
), (
#line 939
a[i].z
#line 16
) };
    Point point = locate (_p.x, _p.y, _p.z);
    if (point.level >= 0) 
#line 939
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 939 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
{
      int j = 0;
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 v[j++] = !linear ? val(s,0,0,0) : interpolate_linear (point, s, a[i].x, a[i].y, a[i].z);}}
    }}  
#line 20
}
}
#line 943
{mpi_all_reduce_array(v,MPI_DOUBLE,MPI_MIN,len);}

    v = w;
  }
end_tracing("interpolate_array","/home/lisergey/basilisk/src/grid/cartesian-common.h",947);}



typedef int bid;

bid new_bid()
{
  int b = nboundary++;
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    _attribute[s.i].boundary = (BoundaryFunc *) prealloc (_attribute[s.i].boundary, nboundary*sizeof (BoundaryFunc),__func__,__FILE__,__LINE__);
    _attribute[s.i].boundary_homogeneous = (BoundaryFunc *)
      prealloc (_attribute[s.i].boundary_homogeneous, nboundary*sizeof (BoundaryFunc),__func__,__FILE__,__LINE__);
  }}}
  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    if (_attribute[s.i].v.x.i < 0)
      _attribute[s.i].boundary[b] = _attribute[s.i].boundary_homogeneous[b] = symmetry;
    else if (_attribute[s.i].v.x.i == s.i) {
      vector v = _attribute[s.i].v;
      
 _attribute[v.x.i].boundary[b] = _attribute[v.x.i].boundary_homogeneous[b] = symmetry;
      _attribute[v.x.i].boundary[b] = _attribute[v.x.i].boundary_homogeneous[b] =
 _attribute[v.x.i].face ? NULL : antisymmetry;
    }
  }}}
  return b;
}



static double periodic_bc (Point point, Point neighbor, scalar s, bool * data)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 979 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return val(s,0,0,0);
}

static void periodic_boundary (int d)
{

  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (is_vertex_scalar (s))
      _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = NULL;
    else
      _attribute[s.i].boundary[d] = _attribute[s.i].boundary_homogeneous[d] = periodic_bc;}}

  {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (_attribute[s.i].face) {
      vector v = _attribute[s.i].v;
      _attribute[v.x.i].boundary[d] = _attribute[v.x.i].boundary_homogeneous[d] = NULL;
    }}}

  default_scalar_bc[d] = periodic_bc;
  default_vector_bc[d] = periodic_bc;
}

void periodic (int dir)
{

    if (!(dir <= left)) qassert ("/home/lisergey/basilisk/src/grid/cartesian-common.h", 1004, "dir <= left");






  int c = dir/2;
  periodic_boundary (2*c);
  periodic_boundary (2*c + 1);
  (&Period.x)[c] = true;
}


double getvalue (Point point, scalar s, int i, int j, int k)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 1020 "/home/lisergey/basilisk/src/grid/cartesian-common.h"
return val(s,i,j,k);
}

void default_stencil (Point p, scalar * list)
{
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    if (_attribute[s.i].v.x.i != -1) {
      vector v = _attribute[s.i].v;
      {scalar*_i=(scalar*)(((vector[]) {v,{{-1}}}));if(_i)for(scalar c=*_i;(&c)->i>=0;c=*++_i){
 _attribute[c.i].input = _attribute[c.i].output = _attribute[c.i].nowarning = true, _attribute[c.i].width = 2;}}
    }
    else
      _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = true, _attribute[s.i].width = 2;
  }}}
}




static void write_stencil_index (int * index)
{
  fprintf (qstderr(), "[%d", index[0]);
  for (int d = 1; d < 1; d++)
    fprintf (qstderr(), ",%d", index[d]);
  fputs ("]", qstderr());
}

void stencil_val (Point p, scalar s, int i, int j, int k,
    const char * file, int line, bool overflow)
{
  if (is_constant(s) || s.i < 0)
    return;
  if (_attribute[s.i].block < 0)
    s.i += _attribute[s.i].block;
  if (!_attribute[s.i].name) {
    fprintf (ferr, "%s:%d: error: trying to access a deleted field\n",
      file, line);
    exit (1);
  }
  int index[] = {i, j, k};
  for (int d = 0; d < 1; d++) {
    if (index[d] == o_stencil)
      index[d] = 2;
    else
      index[d] += (&p.i)[d];
  }
  bool central = true;
  for (int d = 0; d < 1; d++) {
    if (!overflow && (index[d] > 2 || index[d] < - 2)) {
      fprintf (qstderr(), "%s:%d: error: stencil overflow: %s",
        file, line, _attribute[s.i].name);
      write_stencil_index (index);
      fprintf (qstderr(), "\n");
      fflush (qstderr());
      abort();
    }
    if (index[d] != 0)
      central = false;
  }
  if (central) {
    if (!_attribute[s.i].output)
      _attribute[s.i].input = true;
  }
  else {
    _attribute[s.i].input = true;
    int d = 0;
     {
      if ((!_attribute[s.i].face || _attribute[s.i].v.x.i != s.i) && abs(index[d]) > _attribute[s.i].width)
 _attribute[s.i].width = abs(index[d]);
      d++;
    }
  }
}

void stencil_val_a (Point p, scalar s, int i, int j, int k, bool input,
      const char * file, int line)
{
  if (is_constant(s) || s.i < 0) {
    fprintf (ferr, "%s:%d: error: trying to modify a%s field\n",
      file, line, s.i < 0 ? "n undefined" : " constant");
    exit (1);
  }
  if (_attribute[s.i].block < 0)
    s.i += _attribute[s.i].block;
  if (!_attribute[s.i].name) {
    fprintf (ferr, "%s:%d: error: trying to access a deleted field\n",
      file, line);
    exit (1);
  }
  int index[] = {i, j, k};
  for (int d = 0; d < 1; d++)
    index[d] += (&p.i)[d];
  for (int d = 0; d < 1; d++)
    if (index[d] != 0) {
      fprintf (qstderr(), "%s:%d: error: illegal write: %s",
        file, line, _attribute[s.i].name);
      write_stencil_index (index);
      fprintf (qstderr(), "\n");
      fflush (qstderr());
      abort();
    }
  if (input && !_attribute[s.i].output)
    _attribute[s.i].input = true;
  _attribute[s.i].output = true;
} 
#line 5 "/home/lisergey/basilisk/src/grid/multigrid-common.h"

void macro2_foreach_level_or_leaf (int l, char flags, Reduce reductions)
{ 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;    
#line 9 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 9 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
;}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}
#line 10 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
} 

void macro2_foreach_coarse_level (int l, char flags, Reduce reductions)
{ 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;    
#line 15 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 15 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
;}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}
#line 16 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}










void (* restriction) (scalar *);

static inline void restriction_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 31 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
double sum = 0.;
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 33 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
sum += val(s,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 34 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = sum/(1 << 1);
}
#line 29
static void _stencil_restriction_average (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 33 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(s,0,0,0); }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 34 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
_stencil_val_a(s,0,0,0);    
}

static inline void restriction_volume_average (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 39 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
double sum = 0.;
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 41 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
sum += val(cm,0,0,0)*val(s,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 42 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = sum/(1 << 1)/(val(cm,0,0,0) + 1e-30);
}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
#line 38
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 39 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
double sum = 0.;
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 41 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
sum += _const_cm*val(s,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 42 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = sum/(1 << 1)/(_const_cm + 1e-30);
}}}

static inline void face_average (Point point, vector v)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;   
#line 47 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{

      val(v.x,0,0,0) = fine(v.x,0,0,0);
      val(v.x,1,0,0) = fine(v.x,2,0,0);
#line 60 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
  }
}

static inline void restriction_face (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 65 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
face_average (point, _attribute[s.i].v);
}

static inline void restriction_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 70 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
for (int i = 0; i <= 1; i++) {
    val(s,i,0,0) = fine(s,2*i,0,0);







  }
}

static inline void no_restriction (Point point, scalar s) {}

static inline void no_data (Point point, scalar s) {int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 86 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = 1e30f;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 87 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

void wavelet (scalar s, scalar w)
{
  restriction (((scalar[]){s,{-1}}));
  for (int l = grid->maxdepth - 1; l >= 0; l--) {
  
  
    
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 93 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;        
#line 95 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 96 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
default_stencil (      point,((scalar[]){ s,{-1}}));
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 97 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
         _stencil_val(s,0,0,0); 
_stencil_val(w,0,0,0);        _stencil_val_a(s,0,0,0); 

        _stencil_val_r(w,0,0,0);  
      }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }    
#line 103 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 740 "/home/lisergey/basilisk/src/grid/tree.h"
{ 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
if (!is_leaf(cell)) 
#line 93 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 93 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;        
#line 95 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(w,0,0,0) = val(s,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }      
#line 96 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
_attribute[s.i].prolongation (point, s);
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 97 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
        double sp = val(s,0,0,0);
        val(s,0,0,0) = val(w,0,0,0);

        val(w,0,0,0) -= sp;
      }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }    
#line 103 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}





}    
#line 104 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
boundary_level (((scalar[]){w,{-1}}), l + 1);
  }
  

  
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    
#line 108 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(s,0,0,0);_stencil_val_a(w,0,0,0); }
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (0 <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[0];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = 0;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;    
#line 108 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 108 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(w,0,0,0) = val(s,0,0,0);}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}  
#line 109 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
boundary_level (((scalar[]){w,{-1}}), 0);
}

void inverse_wavelet (scalar s, scalar w)
{
  
  
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    
#line 115 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(w,0,0,0);_stencil_val_a(s,0,0,0); }
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (0 <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[0];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = 0;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;    
#line 115 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 115 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = val(w,0,0,0);}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}  
#line 116 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
boundary_level (((scalar[]){s,{-1}}), 0);
  for (int l = 0; l <= grid->maxdepth - 1; l++) {
  
  
    
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 118 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
default_stencil (      point,((scalar[]){ s,{-1}}));
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;        
#line 121 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(w,0,0,0);_stencil_val_r(s,0,0,0); }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }    
#line 122 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 740 "/home/lisergey/basilisk/src/grid/tree.h"
{ 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
if (!is_leaf(cell)) 
#line 118 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 118 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
      _attribute[s.i].prolongation (point, s);
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;        
#line 121 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) += val(w,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }    
#line 122 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}





}    
#line 123 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
boundary_level (((scalar[]){s,{-1}}), l + 1);
  }
}

static inline double bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 130 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
return (3.*coarse(s,0,0,0) + coarse(s,child.x,0,0))/4.;
#line 143 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static inline void refine_bilinear (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 148 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = bilinear (point, s);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 149 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static inline double quadratic (double a, double b, double c)
{
  return (30.*a + 5.*b - 3.*c)/32.;
}

static inline double biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 159 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
return quadratic (coarse(s,0,0,0), coarse(s,child.x,0,0), coarse(s,-child.x,0,0));
#line 175 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static inline double biquadratic_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 180 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
return (6.*val(s,0,0,0) + 3.*val(s,-1,0,0) - val(s,1,0,0))/8.;







}

static inline void refine_biquadratic (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 193 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(s,0,0,0) = biquadratic (point, s);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 194 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static inline void refine_linear (Point point, scalar s)
{if(!is_constant(cm)){{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 198 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*val(cm,0,0,0), sum = val(cm,0,0,0)*(1 << 1);
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 207 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*val(cm,-child.x,0,0)/cmc;
    sum -= val(cm,0,0,0);
  }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 213 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
if (!(fabs(sum) < 1e-10)) qassert ("/home/lisergey/basilisk/src/grid/multigrid-common.h", 213, "fabs(sum) < 1e-10");
}}else {double _const_cm=_constant[cm.i-_NVARMAX];NOT_UNUSED(_const_cm);
#line 197
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 198 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
coord g;
  if (_attribute[s.i].gradient)
    {
      g.x = _attribute[s.i].gradient (val(s,-1,0,0), val(s,0,0,0), val(s,1,0,0));}
  else
    {
      g.x = (val(s,1,0,0) - val(s,-1,0,0))/2.;}

  double sc = val(s,0,0,0), cmc = 4.*_const_cm, sum = _const_cm*(1 << 1);
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 207 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
    val(s,0,0,0) = sc;
    
      val(s,0,0,0) += child.x*g.x*_const_cm/cmc;
    sum -= _const_cm;
  }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 213 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
if (!(fabs(sum) < 1e-10)) qassert ("/home/lisergey/basilisk/src/grid/multigrid-common.h", 213, "fabs(sum) < 1e-10");
}}}

static inline void refine_reset (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 219 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(v,0,0,0) = 0.;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 220 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static inline void refine_injection (Point point, scalar v)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 224 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
double val = val(v,0,0,0);
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 226 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(v,0,0,0) = val;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 227 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
}

static scalar multigrid_init_scalar (scalar s, const char * name)
{
  s = cartesian_init_scalar (s, name);
  _attribute[s.i].prolongation = refine_bilinear;
  _attribute[s.i].restriction = restriction_average;
  return s;
}

static scalar multigrid_init_vertex_scalar (scalar s, const char * name)
{
  s = cartesian_init_vertex_scalar (s, name);
  _attribute[s.i].restriction = restriction_vertex;
  return s;
}

static void multigrid_setup_vector (vector v)
{
   {
    _attribute[v.x.i].prolongation = refine_bilinear;
    _attribute[v.x.i].restriction = restriction_average;
  }
}

static vector multigrid_init_vector (vector v, const char * name)
{
  v = cartesian_init_vector (v, name);
  multigrid_setup_vector (v);
  return v;
}

static vector multigrid_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_face_vector (v, name);
  
    _attribute[v.x.i].restriction = no_restriction;
  _attribute[v.x.i].restriction = restriction_face;
  return v;
}

static tensor multigrid_init_tensor (tensor t, const char * name)
{
  t = cartesian_init_tensor (t, name);
  
    multigrid_setup_vector (t.x);
  return t;
}

void multigrid_debug (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 278 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
cartesian_debug (point);

  FILE * plot = fopen ("plot", "a");
  if (point.level > 0) {
    char name[80] = "coarse";
    if (pid() > 0)
      sprintf (name, "coarse-%d", pid());
    FILE * fp = fopen (name, "w");

      double xc = x - child.x*Delta/2.;
      for (int k = 0; k <= 1; k++)
 {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){
   fprintf (fp, "%g %g ",
     xc + k*child.x*Delta*2. + _attribute[v.i].d.x*Delta,
     coarse(v,k*child.x,0,0));}}
      fputc ('\n', fp);
      fprintf (ferr, ", '%s' u 1+2*v:(0):2+2*v w labels tc lt 3 t ''", name);
      fprintf (plot, ", '%s' u 1+2*v:(0):2+2*v w labels tc lt 3 t ''", name);
#line 328 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
    fclose (fp);
  }

  if (is_coarse()) {
    char name[80] = "fine";
    if (pid() > 0)
      sprintf (name, "fine-%d", pid());
    FILE * fp = fopen (name, "w");

      double xf = x - Delta/4.;
      for (int k = -2; k <= 3; k++)
 {scalar*_i=(scalar*)( all);if(_i)for(scalar v=*_i;(&v)->i>=0;v=*++_i){ {
   fprintf (fp, "%g ", xf + k*Delta/2. + _attribute[v.i].d.x*Delta/4.);
   if (allocated_child(k,0,0))
     fprintf (fp, "%g ", fine(v,k,0,0));
   else
     fputs ("n/a ", fp);
 }}}
      fputc ('\n', fp);
      fprintf (ferr, ", '%s' u 1+2*v:(0):2+2*v w labels tc lt 2 t ''", name);
      fprintf (plot, ", '%s' u 1+2*v:(0):2+2*v w labels tc lt 2 t ''", name);
#line 388 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
    fclose (fp);
  }
  fflush (ferr);
  fclose (plot);
}

static void multigrid_restriction (scalar * list)
{
  scalar * listdef = NULL, * listc = NULL, * list2 = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant (s) && _attribute[s.i].block > 0) {
      if (_attribute[s.i].restriction == restriction_average) {
 listdef = list_add (listdef, s);
 list2 = list_add (list2, s);
      }
      else if (_attribute[s.i].restriction != no_restriction) {
 listc = list_add (listc, s);
 if (_attribute[s.i].face)
   {
     list2 = list_add (list2, _attribute[s.i].v.x);}
 else
   list2 = list_add (list2, s);
      }
    }}}

  if (listdef || listc) {
    for (int l = depth() - 1; l >= 0; l--) {      
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 415 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     _stencil_restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {

default_stencil (     point,((scalar[]){ s,{-1}}));
 }}}
      }  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 740 "/home/lisergey/basilisk/src/grid/tree.h"
{ 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
if (!is_leaf(cell)) 
#line 415 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 415 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
  
     restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
  
     _attribute[s.i].restriction (point, s);
 }}}
      }}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}





}      
#line 424 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list2, l); };
    }
    pfree (listdef,__func__,__FILE__,__LINE__);
    pfree (listc,__func__,__FILE__,__LINE__);
    pfree (list2,__func__,__FILE__,__LINE__);
  }
}

void multigrid_methods()
{
  cartesian_methods();
  init_scalar = multigrid_init_scalar;
  init_vertex_scalar = multigrid_init_vertex_scalar;
  init_vector = multigrid_init_vector;
  init_face_vector = multigrid_init_face_vector;
  init_tensor = multigrid_init_tensor;
  restriction = multigrid_restriction;
  debug = multigrid_debug;
}







void subtree_size (scalar size, bool leaves)
{  
#line 314 "/home/lisergey/basilisk/src/grid/stencils.h"
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "/home/lisergey/basilisk/src/grid/multigrid-common.h", .line = 456, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 457 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{_stencil_val_a(size,0,0,0);  }    
#line 328 "/home/lisergey/basilisk/src/grid/stencils.h"
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags;
    
#line 457 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 457 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(size,0,0,0) = 1;}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}  
#line 463 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), depth()); };
  for (int l = depth() - 1; l >= 0; l--) {    
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 465 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 468 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ _stencil_val(size,0,0,0); }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
      
#line 469 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
_stencil_val_a(size,0,0,0);  
    }  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 740 "/home/lisergey/basilisk/src/grid/tree.h"
{ 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
if (!is_leaf(cell)) 
#line 465 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 465 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{
      double sum = !leaves;      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 468 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
sum += val(size,0,0,0);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
      
#line 469 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
val(size,0,0,0) = sum;
    }}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}





}    
#line 471 "/home/lisergey/basilisk/src/grid/multigrid-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {size,{-1}}), l); };
  }
}
#line 5 "/home/lisergey/basilisk/src/grid/tree-common.h"




#line 21 "/home/lisergey/basilisk/src/grid/tree-common.h"
int refine_cell (Point point, scalar * list, int flag, Cache * refined)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 23 "/home/lisergey/basilisk/src/grid/tree-common.h"
int nr = 0;


  if (level > 0)
    for (int k = 0; k != 2*child.x; k += child.x)






   if (aparent(k,l,m).pid >= 0 && is_leaf(aparent(k,l,m))) {
     Point p = point;


     p.level = point.level - 1;
     p.i = (point.i + 2)/2 + k;
     do { if (p.i < 2) p.i += 1 << p.level; else if (p.i >= 2 + (1 << p.level)) p.i -= 1 << p.level; } while(0);
#line 49 "/home/lisergey/basilisk/src/grid/tree-common.h"
     nr += refine_cell (p, list, flag, refined);
     aparent(k,l,m).flags |= flag;
   }



  increment_neighbors (point);

  int cflag = is_active(cell) ? (active|leaf) : leaf;
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 59 "/home/lisergey/basilisk/src/grid/tree-common.h"
cell.flags |= cflag;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 62 "/home/lisergey/basilisk/src/grid/tree-common.h"
{scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (is_local(cell) || _attribute[s.i].face)
      _attribute[s.i].refine (point, s);}}


  cell.flags &= ~leaf;

#if _MPI
  if (is_border(cell)) {
  
    
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 71 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
      bool bord = false;      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 73 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 if (!is_local(cell) || (level > 0 && !is_local(aparent(0,0,0)))) {
   bord = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 75 "/home/lisergey/basilisk/src/grid/tree-common.h"
;
 }
 if (is_refined_check())
    
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;     
#line 79 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!is_local(cell)) {
       bord = true;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 80 "/home/lisergey/basilisk/src/grid/tree-common.h"
;
     }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
} 
#line 82 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (bord)   
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 83 "/home/lisergey/basilisk/src/grid/tree-common.h"
;
      }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
      
#line 85 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (bord)
 cell.flags |= border;
    }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }    
#line 88 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (refined)
      cache_append (refined, point, cell.flags);
    nr++;
  }
#endif
  return nr;
}





bool coarsen_cell (Point point, scalar * list)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 105 "/home/lisergey/basilisk/src/grid/tree-common.h"
int pid = cell.pid;
  
  
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 107 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (cell.neighbors || (cell.pid < 0 && cell.pid != pid))
      return false;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 112 "/home/lisergey/basilisk/src/grid/tree-common.h"
{scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
    _attribute[s.i].restriction (point, s);
    if (_attribute[s.i].coarsen)
      _attribute[s.i].coarsen (point, s);
  }}}


  cell.flags |= leaf;


  decrement_neighbors (point);

#if _MPI
  if (!is_local(cell)) {
    cell.flags &= ~(active|border);    
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;      
#line 128 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (cell.neighbors)
  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;   
#line 130 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (allocated(0,0,0) && is_local(cell) && !is_border(cell))
     cell.flags |= border;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
  
#line 132 "/home/lisergey/basilisk/src/grid/tree-common.h"
}
#endif

  return true;
}

void coarsen_cell_recursive (Point point, scalar * list)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  


  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;    
#line 143 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (cell.neighbors)       
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
  {
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 145 "/home/lisergey/basilisk/src/grid/tree-common.h"
if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0))
   coarsen_cell_recursive (point, list);    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
}
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }  
#line 148 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!(coarsen_cell (point, list))) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 148, "coarsen_cell (point, list)");
}

void mpi_boundary_refine (scalar *);
void mpi_boundary_coarsen (int, int);
void mpi_boundary_update (scalar *);

static
scalar * list_add_depend (scalar * list, scalar s)
{
  if (is_constant(s) || _attribute[s.i].restriction == no_restriction)
    return list;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar t=*_i;(&t)->i>=0;t=*++_i){
    if (t.i == s.i)
      return list;}}
  {scalar*_i=(scalar*)( _attribute[s.i].depends);if(_i)for(scalar d=*_i;(&d)->i>=0;d=*++_i){
    list = list_add_depend (list, d);}}
  return list_append (list, s);
}

typedef struct {
  int nc, nf;
} astats;

     
astats adapt_wavelet (scalar * slist,
        double * max,
        int maxlevel,
        int minlevel,
        scalar * list)
{tracing("adapt_wavelet","/home/lisergey/basilisk/src/grid/tree-common.h",173);
  scalar * ilist = list;

  if (is_constant(cm)) {
    if (list == NULL || list == all)
      list = list_copy (all);
    boundary_internal ((scalar *)list, "/home/lisergey/basilisk/src/grid/tree-common.h", 184);
    restriction (slist);
  }
  else {
    if (list == NULL || list == all) {
      list = list_copy (((scalar[]){cm, fm.x,{-1}}));
      {scalar*_i=(scalar*)( all);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
 list = list_add (list, s);}}
    }
    boundary_internal ((scalar *)list, "/home/lisergey/basilisk/src/grid/tree-common.h", 193);
    scalar * listr = list_concat (slist,((scalar[]) {cm,{-1}}));
    restriction (listr);
    pfree (listr,__func__,__FILE__,__LINE__);
  }

  astats st = {0, 0};
  scalar * listc = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    listc = list_add_depend (listc, s);}}


  if (minlevel < 1)
    minlevel = 1;
  ((Tree *)grid)->refined.n = 0;
  static const int refined = 1 << user, too_fine = 1 << (user + 1);
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 209 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 209 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
    if (is_active(cell)) {
      static const int too_coarse = 1 << (user + 2);
      if (is_leaf (cell)) {
 if (cell.flags & too_coarse) {
   cell.flags &= ~too_coarse;
   refine_cell (point, listc, refined, &((Tree *)grid)->refined);
   st.nf++;
 }
 continue;
      }
      else {
 if (cell.flags & refined) {

   cell.flags &= ~too_coarse;
   continue;
 }

 bool local = is_local(cell);
 if (!local)
    
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;     
#line 230 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (is_local(cell)) {
       local = true;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 231 "/home/lisergey/basilisk/src/grid/tree-common.h"
;
     }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
} 
#line 233 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (local) {
   int i = 0;
   static const int just_fine = 1 << (user + 3);
   {scalar*_i=(scalar*)( slist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
     double emax = max[i++], sc[1 << 1];
     int c = 0;
  
     
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;       
#line 240 "/home/lisergey/basilisk/src/grid/tree-common.h"
sc[c++] = val(s,0,0,0);
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }     
#line 241 "/home/lisergey/basilisk/src/grid/tree-common.h"
_attribute[s.i].prolongation (point, s);
     c = 0;
  
     
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 243 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
       double e = fabs(sc[c] - val(s,0,0,0));
       if (e > emax && level < maxlevel) {
  cell.flags &= ~too_fine;
  cell.flags |= too_coarse;
       }
       else if ((e <= emax/1.5 || level > maxlevel) &&
         !(cell.flags & (too_coarse|just_fine))) {
  if (level >= minlevel)
    cell.flags |= too_fine;
       }
       else if (!(cell.flags & too_coarse)) {
  cell.flags &= ~too_fine;
  cell.flags |= just_fine;
       }
       val(s,0,0,0) = sc[c++];
     }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }   
#line 260 "/home/lisergey/basilisk/src/grid/tree-common.h"
}}}
  
   
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 261 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
     cell.flags &= ~just_fine;
     if (!is_leaf(cell)) {
       cell.flags &= ~too_coarse;
       if (level >= maxlevel)
  cell.flags |= too_fine;
     }
     else if (!is_active(cell))
       cell.flags &= ~too_coarse;
   }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  } 
#line 271 "/home/lisergey/basilisk/src/grid/tree-common.h"
}
      }
    }
    else
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 277 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_boundary_refine (listc);



  for (int l = depth(); l >= 0; l--) {
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
      
#line 283 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 283 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!(cell.pid < 0)) {
 if (level == l) {
   if (!is_leaf(cell)) {
     if (cell.flags & refined)

       cell.flags &= ~(refined|too_fine);
     else if (cell.flags & too_fine) {
       if (is_local(cell) && coarsen_cell (point, listc))
  st.nc++;
       cell.flags &= ~too_fine;
     }
   }
   if (cell.flags & too_fine)
     cell.flags &= ~too_fine;
   else if (level > 0 && (aparent(0,0,0).flags & too_fine))
     aparent(0,0,0).flags &= ~too_fine;
   continue;
 }
 else if (is_leaf(cell))
   continue;
      }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
    
#line 304 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_boundary_coarsen (l, too_fine);
  }
  pfree (listc,__func__,__FILE__,__LINE__);

  mpi_all_reduce (st.nf, MPI_INT, MPI_SUM);
  mpi_all_reduce (st.nc, MPI_INT, MPI_SUM);
  if (st.nc || st.nf)
    mpi_boundary_update (list);

  if (list != ilist)
    pfree (list,__func__,__FILE__,__LINE__);

  {end_tracing("adapt_wavelet","/home/lisergey/basilisk/src/grid/tree-common.h",316);return st;}
end_tracing("adapt_wavelet","/home/lisergey/basilisk/src/grid/tree-common.h",317);}

void macro_refine (bool cond)
{
  {
    int refined;
    do {
      boundary_internal ((scalar *)all, "/home/lisergey/basilisk/src/grid/tree-common.h", 324);
      refined = 0;
      ((Tree *)grid)->refined.n = 0;
#line 286 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
#line 126
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 288
if (is_leaf (cell)) {
      if (is_active(cell) && is_local(cell))
 
#line 328 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 328 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (cond) {
   refine_cell (point, all, 0, &((Tree *)grid)->refined);
   refined++;
   continue;
 }}      
#line 291 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
continue;
    } 
#line 91
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 293
}
      
#line 333 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_all_reduce (refined, MPI_INT, MPI_SUM);
      if (refined) {
 mpi_boundary_refine (all);
 mpi_boundary_update (all);
      }
    } while (refined);
  }
}

static void refine_level (int depth)
{
  int refined;
  do {
    refined = 0;
    ((Tree *)grid)->refined.n = 0;
#line 286 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
#line 126
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 288
if (is_leaf (cell)) {
      if (is_active(cell) && is_local(cell))
      
#line 349 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 349 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (level < depth) {
 refine_cell (point, NULL, 0, &((Tree *)grid)->refined);
 refined++;
 continue;
      }}      
#line 291 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
continue;
    } 
#line 91
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 293
}
    
#line 354 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_all_reduce (refined, MPI_INT, MPI_SUM);
    if (refined) {
      mpi_boundary_refine (NULL);
      mpi_boundary_update (NULL);
    }
  } while (refined);
}

void macro_unrefine (bool cond)
{
  {
    static const int too_fine = 1 << user;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 366 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 366 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
      if (is_leaf(cell))
 continue;
      if (is_local(cell) && (cond))
 cell.flags |= too_fine;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
    
#line 372 "/home/lisergey/basilisk/src/grid/tree-common.h"
for (int _l = depth(); _l >= 0; _l--) {
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 373 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 373 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 if (is_leaf(cell))
   continue;
 if (level == _l) {
   if (is_local(cell) && (cell.flags & too_fine)) {
     coarsen_cell (point, all);
     cell.flags &= ~too_fine;
   }
   continue;
 }
      }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
      
#line 384 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_boundary_coarsen (_l, too_fine);
    }
    mpi_boundary_update (all);
  }
}

     
static void halo_face (vectorl vl)
{tracing("halo_face","/home/lisergey/basilisk/src/grid/tree-common.h",391);
  
    {scalar*_i=(scalar*)( vl.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
      _attribute[s.i].dirty = 2;}}

  for (int l = depth() - 1; l >= 0; l--) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 494 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->prolongation[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i;      
#line 399 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 399 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
        if (vl.x) {

   if ((!is_leaf (neighbor(-1,0,0)) && neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0))
     {scalar*_i=(scalar*)( vl.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
       val(s,0,0,0) = fine(s,0,0,0);}}
   if ((!is_leaf (neighbor(1,0,0)) && neighbor(1,0,0).neighbors && neighbor(1,0,0).pid >= 0))
     {scalar*_i=(scalar*)( vl.x);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
       val(s,1,0,0) = fine(s,2,0,0);}}
#line 425 "/home/lisergey/basilisk/src/grid/tree-common.h"
 }}}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 500
}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
end_tracing("halo_face","/home/lisergey/basilisk/src/grid/tree-common.h",426);
#line 426 "/home/lisergey/basilisk/src/grid/tree-common.h"
}



static scalar tree_init_scalar (scalar s, const char * name)
{
  s = multigrid_init_scalar (s, name);
  _attribute[s.i].refine = _attribute[s.i].prolongation;
  return s;
}

static void prolongation_vertex (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;



  
#line 442 "/home/lisergey/basilisk/src/grid/tree-common.h"
fine(s,1,1,1) = (val(s,0,0,0) + val(s,1,0,0) + val(s,0,1,0) + val(s,1,1,0) +
     val(s,0,0,1) + val(s,1,0,1) + val(s,0,1,1) + val(s,1,1,1))/8.;


  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++)





      if (allocated_child(2*i,2*j,0))
 fine(s,2*i,2*j,0) = val(s,i,j,0);


    
      if (neighbor(i,0,0).neighbors) {
#line 470 "/home/lisergey/basilisk/src/grid/tree-common.h"
      }
  }
}

static scalar tree_init_vertex_scalar (scalar s, const char * name)
{
  s = multigrid_init_vertex_scalar (s, name);
  _attribute[s.i].refine = _attribute[s.i].prolongation = prolongation_vertex;
  return s;
}

static void tree_setup_vector (vector v)
{
  
    _attribute[v.x.i].refine = _attribute[v.x.i].prolongation;
}

static vector tree_init_vector (vector v, const char * name)
{
  v = multigrid_init_vector (v, name);
  tree_setup_vector (v);
  return v;
}


static void refine_face_x (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 497 "/home/lisergey/basilisk/src/grid/tree-common.h"
vector v = _attribute[s.i].v;

  if (!(!is_leaf (neighbor(-1,0,0)) && neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0) &&
      (is_local(cell) || is_local(neighbor(-1,0,0)))) {
    double g1 = (val(v.x,0,+1,0) - val(v.x,0,-1,0))/8.;
    for (int j = 0; j <= 1; j++)
      fine(v.x,0,j,0) = val(v.x,0,0,0) + (2*j - 1)*g1;
  }
  if (!(!is_leaf (neighbor(1,0,0)) && neighbor(1,0,0).neighbors && neighbor(1,0,0).pid >= 0) && neighbor(1,0,0).neighbors &&
      (is_local(cell) || is_local(neighbor(1,0,0)))) {
    double g1 = (val(v.x,1,+1,0) - val(v.x,1,-1,0))/8.;
    for (int j = 0; j <= 1; j++)
      fine(v.x,2,j,0) = val(v.x,1,0,0) + (2*j - 1)*g1;
  }
  if (is_local(cell)) {
    double g1 = (val(v.x,0,+1,0) - val(v.x,0,-1,0) + val(v.x,1,+1,0) - val(v.x,1,-1,0))/16.;
    for (int j = 0; j <= 1; j++)
      fine(v.x,1,j,0) = (val(v.x,0,0,0) + val(v.x,1,0,0))/2. + (2*j - 1)*g1;
  }
#line 541 "/home/lisergey/basilisk/src/grid/tree-common.h"
}

void refine_face (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 545 "/home/lisergey/basilisk/src/grid/tree-common.h"
vector v = _attribute[s.i].v;
  
    _attribute[v.x.i].prolongation (point, v.x);
}

void refine_face_solenoidal (Point point, scalar s)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 552 "/home/lisergey/basilisk/src/grid/tree-common.h"
refine_face (point, s);
#line 603 "/home/lisergey/basilisk/src/grid/tree-common.h"
}

static vector tree_init_face_vector (vector v, const char * name)
{
  v = cartesian_init_face_vector (v, name);
  
    _attribute[v.x.i].restriction = _attribute[v.x.i].refine = no_restriction;
  _attribute[v.x.i].restriction = restriction_face;
  _attribute[v.x.i].refine = refine_face;
  
    _attribute[v.x.i].prolongation = refine_face_x;
  return v;
}

static tensor tree_init_tensor (tensor t, const char * name)
{
  t = multigrid_init_tensor (t, name);
  
    tree_setup_vector (t.x);
  return t;
}

     
static void tree_boundary_level (scalar * list, int l)
{tracing("tree_boundary_level","/home/lisergey/basilisk/src/grid/tree-common.h",626);
  int depth = l < 0 ? depth() : l;

  if (tree_is_full()) {
    { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list, depth); };
    {end_tracing("tree_boundary_level","/home/lisergey/basilisk/src/grid/tree-common.h",632);return;}
  }

  scalar * listdef = NULL, * listc = NULL, * list2 = NULL, * vlist = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant (s)) {
      if (_attribute[s.i].restriction == restriction_average) {
 listdef = list_add (listdef, s);
 list2 = list_add (list2, s);
      }
      else if (_attribute[s.i].restriction != no_restriction) {
 listc = list_add (listc, s);
 if (_attribute[s.i].face)
   {
     list2 = list_add (list2, _attribute[s.i].v.x);}
 else {
   list2 = list_add (list2, s);
   if (_attribute[s.i].restriction == restriction_vertex)
     vlist = list_add (vlist, s);
 }
      }
    }}}

  if (vlist) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 1708 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 1710
((Tree *)grid)->vertices
#line 436
).n; _k++) {
 point.i = (
#line 1710
((Tree *)grid)->vertices
#line 437
).p[_k].i;






 point.level = (
#line 1710
((Tree *)grid)->vertices
#line 444
).p[_k].level;
 _flags = (
#line 1710
((Tree *)grid)->vertices
#line 445
).p[_k].flags; 
#line 1710
{
    int ig = -1; NOT_UNUSED (ig);      
#line 658 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 658 "/home/lisergey/basilisk/src/grid/tree-common.h"
if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) || (!is_leaf (neighbor(-1,0,0)) && neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0))
 {scalar*_i=(scalar*)( vlist);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   val(s,0,0,0) = is_vertex (child(0,0,0)) ? fine(s,0,0,0) : 1e30f;}}}
  
#line 1719 "/home/lisergey/basilisk/src/grid/tree.h"
}      
#line 447
}
  }
}

#line 1720
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
#line 711 "/home/lisergey/basilisk/src/grid/tree-common.h"
  pfree (vlist,__func__,__FILE__,__LINE__);

  if (listdef || listc) {
    { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b, list2, depth); };
    for (int l = depth - 1; l >= 0; l--) {      
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 716 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _stencil_restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
default_stencil (   point,((scalar[]){ s,{-1}}));}}
      }  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 740 "/home/lisergey/basilisk/src/grid/tree.h"
{ 
#line 731
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 742
if (!is_leaf(cell)) 
#line 716 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 716 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 {scalar*_i=(scalar*)( listdef);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   restriction_average (point, s);}}
 {scalar*_i=(scalar*)( listc);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
   _attribute[s.i].restriction (point, s);}}
      }}      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}





}      
#line 722 "/home/lisergey/basilisk/src/grid/tree-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b, list2, l); };
    }
    pfree (listdef,__func__,__FILE__,__LINE__);
    pfree (listc,__func__,__FILE__,__LINE__);
    pfree (list2,__func__,__FILE__,__LINE__);
  }

  scalar * listr = NULL;
  vector * listf = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant (s) && _attribute[s.i].refine != no_restriction) {
      if (_attribute[s.i].face)
 listf = vectors_add (listf, _attribute[s.i].v);
      else
 listr = list_add (listr, s);
    }}}

  if (listr || listf) {
    { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list, 0); };
    for (int i = 0; i < depth; i++) {
#line 494 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (i <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->prolongation[i];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = i;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i; 
#line 742 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 742 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 {scalar*_i=(scalar*)( listr);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
          _attribute[s.i].prolongation (point, s);}}
 {vector*_i=(vector*)( listf);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
   {
     _attribute[v.x.i].prolongation (point, v.x);}}}
      }}      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 500
}
}
      
#line 749 "/home/lisergey/basilisk/src/grid/tree-common.h"
{ Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b, list, i + 1); };
    }
    pfree (listr,__func__,__FILE__,__LINE__);
    pfree (listf,__func__,__FILE__,__LINE__);
  }
end_tracing("tree_boundary_level","/home/lisergey/basilisk/src/grid/tree-common.h",754);}

double treex (Point point) {int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 757 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (level == 0)
    return 0;




  if (!(false)) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 763, "false");
  double i = 0;

  return treex(parent) + i/(1 << 2*(level - 1));
}

double treey (Point point) {int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 770 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (level == 0)
    return 0;
  return treey(parent) + 4./(1 << 2*(level - 1));
}

void output_tree (FILE * fp)
{
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 778 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 778 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (cell.neighbors)       
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 780 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (is_local(cell))
   fprintf (fp, "%g %g\n%g %g\n\n",
     treex(parent), treey(parent), treex(point), treey(point));    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
#line 782 "/home/lisergey/basilisk/src/grid/tree-common.h"
} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 783 "/home/lisergey/basilisk/src/grid/tree-common.h"
}

     
void tree_check()
{tracing("tree_check","/home/lisergey/basilisk/src/grid/tree-common.h",786);


  long nleaves = 0, nactive = 0; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 791 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 791 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
    if (is_leaf(cell)) {
      if (!(cell.pid >= 0)) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 793, "cell.pid >= 0");
      nleaves++;
    }
    if (is_local(cell))
      if (!(is_active(cell) || (!is_leaf(cell) && !cell.neighbors && cell.pid >= 0))) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 797, "is_active(cell) || is_prolongation(cell)");
    if (is_active(cell))
      nactive++;

    int neighbors = 0;    
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
      
#line 803 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (allocated(0,0,0) && (!is_leaf (cell) && cell.neighbors && cell.pid >= 0))
 neighbors++;    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
    
#line 805 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!(cell.neighbors == neighbors)) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 805, "cell.neighbors == neighbors");


    if (!cell.neighbors)
      if (!(!allocated_child(0,0,0))) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 809, "!allocated_child(0)");
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}


  
#line 813 "/home/lisergey/basilisk/src/grid/tree-common.h"
long reachable = 0;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 814 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 814 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
    if (is_active(cell))
      reachable++;
    else
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 820 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!(nactive == reachable)) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 820, "nactive == reachable");


  reachable = 0;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 825 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 825 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (is_leaf(cell)) {
      reachable++;
      continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 829 "/home/lisergey/basilisk/src/grid/tree-common.h"
if (!(nleaves == reachable)) qassert ("/home/lisergey/basilisk/src/grid/tree-common.h", 829, "nleaves == reachable");
end_tracing("tree_check","/home/lisergey/basilisk/src/grid/tree-common.h",830);}

     
static void tree_restriction (scalar * list) {tracing("tree_restriction","/home/lisergey/basilisk/src/grid/tree-common.h",833);
  boundary_internal ((scalar *)list, "/home/lisergey/basilisk/src/grid/tree-common.h", 834);
  if (tree_is_full())
    multigrid_restriction (list);
end_tracing("tree_restriction","/home/lisergey/basilisk/src/grid/tree-common.h",837);}

void tree_methods()
{
  multigrid_methods();
  init_scalar = tree_init_scalar;
  init_vertex_scalar = tree_init_vertex_scalar;
  init_vector = tree_init_vector;
  init_face_vector = tree_init_face_vector;
  init_tensor = tree_init_tensor;
  boundary_level = tree_boundary_level;
  boundary_face = halo_face;
  restriction = tree_restriction;
}
#line 1723 "/home/lisergey/basilisk/src/grid/tree.h"


void tree_periodic (int dir)
{
  int depth = grid ? depth() : -1;
  if (grid)
    free_grid();
  periodic (dir);
  if (depth >= 0)
    init_grid (1 << depth);
}


#if _MPI
#line 1 "grid/tree-mpi.h"
#line 1 "/home/lisergey/basilisk/src/grid/tree-mpi.h"

int debug_iteration = -1;

void debug_mpi (FILE * fp1);

typedef struct {
  CacheLevel * halo;
  void * buf;
  MPI_Request r;
  int depth;
  int pid;
  int maxdepth;
} Rcv;

typedef struct {
  Rcv * rcv;
  char * name;
  int npid;
} RcvPid;

typedef struct {
  RcvPid * rcv, * snd;
} SndRcv;

typedef struct {
  Boundary parent;

  SndRcv mpi_level, mpi_level_root, restriction;
  Array * send, * receive;
} MpiBoundary;

static void cache_level_init (CacheLevel * c)
{
  c->p = NULL;
  c->n = c->nm = 0;
}

static void rcv_append (Point point, Rcv * rcv)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 40 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (level > rcv->depth) {
    rcv->halo = (CacheLevel *) prealloc (rcv->halo, (level + 1)*sizeof(CacheLevel),__func__,__FILE__,__LINE__);
    for (int j = rcv->depth + 1; j <= level; j++)
      cache_level_init (&rcv->halo[j]);
    rcv->depth = level;
  }
  cache_level_append (&rcv->halo[level], point);
  if (level > rcv->maxdepth)
    rcv->maxdepth = level;
}

void rcv_print (Rcv * rcv, FILE * fp, const char * prefix)
{
  for (int l = 0; l <= rcv->depth; l++)
    if (rcv->halo[l].n > 0) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 452 "/home/lisergey/basilisk/src/grid/tree.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 55 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 466 "/home/lisergey/basilisk/src/grid/tree.h"
).n; _k++) {
 point.i = (
#line 55 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 467 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].i; 
#line 56 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 56 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d %d\n", prefix, x, y, z, rcv->pid, level);}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}

#line 57 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}

static void rcv_free_buf (Rcv * rcv)
{
  if (rcv->buf) {
    prof_start ("rcv_pid_receive");
    MPI_Wait (&rcv->r, MPI_STATUS_IGNORE);
    pfree (rcv->buf,__func__,__FILE__,__LINE__);
    rcv->buf = NULL;
    prof_stop();
  }
}

static void rcv_destroy (Rcv * rcv)
{
  rcv_free_buf (rcv);
  for (int i = 0; i <= rcv->depth; i++)
    if (rcv->halo[i].n > 0)
      pfree (rcv->halo[i].p,__func__,__FILE__,__LINE__);
  pfree (rcv->halo,__func__,__FILE__,__LINE__);
}

static RcvPid * rcv_pid_new (const char * name)
{
  RcvPid * r = ((RcvPid *) pcalloc (1, sizeof(RcvPid),__func__,__FILE__,__LINE__));
  r->name = pstrdup (name,__func__,__FILE__,__LINE__);
  return r;
}

static Rcv * rcv_pid_pointer (RcvPid * p, int pid)
{
  if (!(pid >= 0 && pid < npe())) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 88, "pid >= 0 && pid < npe()");

  int i;
  for (i = 0; i < p->npid; i++)
    if (pid == p->rcv[i].pid)
      break;

  if (i == p->npid) {
    p->rcv = (Rcv *) prealloc (p->rcv, (++p->npid)*sizeof(Rcv),__func__,__FILE__,__LINE__);
    Rcv * rcv = &p->rcv[p->npid-1];
    rcv->pid = pid;
    rcv->depth = rcv->maxdepth = 0;
    rcv->halo = ((CacheLevel *) pmalloc ((1)*sizeof(CacheLevel),__func__,__FILE__,__LINE__));
    rcv->buf = NULL;
    cache_level_init (&rcv->halo[0]);
  }
  return &p->rcv[i];
}

static void rcv_pid_append (RcvPid * p, int pid, Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;  
#line 109 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv_append (point, rcv_pid_pointer (p, pid));
}

static void rcv_pid_append_pids (RcvPid * p, Array * pids)
{

  for (int i = 0; i < p->npid; i++) {
    int pid = p->rcv[i].pid, j, * a;
    for (j = 0, a = pids->p; j < pids->len/sizeof(int); j++,a++)
      if (*a == pid)
 break;
    if (j == pids->len/sizeof(int))
      array_append (pids, &pid, sizeof(int));
  }
}

void rcv_pid_write (RcvPid * p, const char * name)
{
  for (int i = 0; i < p->npid; i++) {
    Rcv * rcv = &p->rcv[i];
    char fname[80];
    sprintf (fname, "%s-%d-%d", name, pid(), rcv->pid);
    FILE * fp = fopen (fname, "w");
    rcv_print (rcv, fp, "");
    fclose (fp);
  }
}

static void rcv_pid_print (RcvPid * p, FILE * fp, const char * prefix)
{
  for (int i = 0; i < p->npid; i++)
    rcv_print (&p->rcv[i], fp, prefix);
}

static void rcv_pid_destroy (RcvPid * p)
{
  for (int i = 0; i < p->npid; i++)
    rcv_destroy (&p->rcv[i]);
  pfree (p->rcv,__func__,__FILE__,__LINE__);
  pfree (p->name,__func__,__FILE__,__LINE__);
  pfree (p,__func__,__FILE__,__LINE__);
}

static Boundary * mpi_boundary = NULL;






void debug_mpi (FILE * fp1);

static void apply_bc (Rcv * rcv, scalar * list, scalar * listv,
        vector * listf, int l, MPI_Status s)
{
  double * b = rcv->buf;

#line 452 "/home/lisergey/basilisk/src/grid/tree.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 165 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 466 "/home/lisergey/basilisk/src/grid/tree.h"
).n; _k++) {
 point.i = (
#line 165 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 467 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].i; 
#line 165 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 165 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      memcpy (&val(s,0,0,0), b, sizeof(double)*_attribute[s.i].block);
      b += _attribute[s.i].block;
    }}}
    {vector*_i=(vector*)( listf);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
      { {
 memcpy (&val(v.x,0,0,0), b, sizeof(double)*_attribute[v.x.i].block);
 b += _attribute[v.x.i].block;
 if (*b != 1e30f && allocated(1,0,0))
   memcpy (&val(v.x,1,0,0), b, sizeof(double)*_attribute[v.x.i].block);
 b += _attribute[v.x.i].block;
      }}}}
    {scalar*_i=(scalar*)( listv);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
      for (int i = 0; i <= 1; i++)
 for (int j = 0; j <= 1; j++)







          {
     if (*b != 1e30f && allocated(i,j,0))
       memcpy (&val(s,i,j,0), b, sizeof(double)*_attribute[s.i].block);
     b += _attribute[s.i].block;
          }

    }}}
  }}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}  
#line 196 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
size_t size = b - (double *) rcv->buf;
  pfree (rcv->buf,__func__,__FILE__,__LINE__);
  rcv->buf = NULL;

  int rlen;
  MPI_Get_count (&s, MPI_DOUBLE, &rlen);
  if (rlen != size) {
    fprintf (ferr,
      "rlen (%d) != size (%ld), %d receiving from %d at level %d\n"
      "Calling debug_mpi(NULL)...\n"
      "Aborting...\n",
      rlen, size, pid(), rcv->pid, l);
    fflush (ferr);
    debug_mpi (NULL);
    MPI_Abort (MPI_COMM_WORLD, -2);
  }
}
#line 234 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
static void mpi_recv_check (void * buf, int count, MPI_Datatype datatype,
       int source, int tag,
       MPI_Comm comm, MPI_Status * status,
       const char * name)
{
#line 269 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
  int errorcode = MPI_Recv (buf, count, datatype, source, tag, comm, status);
  if (errorcode != MPI_SUCCESS) {
    char string[MPI_MAX_ERROR_STRING];
    int resultlen;
    MPI_Error_string (errorcode, string, &resultlen);
    fprintf (ferr,
      "ERROR MPI_Recv \"%s\" (count = %d, source = %d, tag = %d):\n%s\n"
      "Calling debug_mpi(NULL)...\n"
      "Aborting...\n",
      name, count, source, tag, string);
    fflush (ferr);
    debug_mpi (NULL);
    MPI_Abort (MPI_COMM_WORLD, -1);
  }





}

     
static int mpi_waitany (int count, MPI_Request array_of_requests[], int *indx,
   MPI_Status *status)
{tracing("mpi_waitany","/home/lisergey/basilisk/src/grid/tree-mpi.h",291);
  { int _ret= MPI_Waitany (count, array_of_requests, indx, status);end_tracing("mpi_waitany","/home/lisergey/basilisk/src/grid/tree-mpi.h",294);return _ret;}
end_tracing("mpi_waitany","/home/lisergey/basilisk/src/grid/tree-mpi.h",295);}

static int list_lenb (scalar * list) {
  int len = 0;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    len += _attribute[s.i].block;}}
  return len;
}

static int vectors_lenb (vector * list) {
  int len = 0;
  {vector*_i=(vector*)( list);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
    len += _attribute[v.x.i].block;}}
  return len;
}

static void rcv_pid_receive (RcvPid * m, scalar * list, scalar * listv,
        vector * listf, int l)
{
  if (m->npid == 0)
    return;

  prof_start ("rcv_pid_receive");

  int len = list_lenb (list) + 2*1*vectors_lenb (listf) +
    (1 << 1)*list_lenb (listv);

  MPI_Request r[m->npid];
  Rcv * rrcv[m->npid];
  int nr = 0;
  for (int i = 0; i < m->npid; i++) {
    Rcv * rcv = &m->rcv[i];
    if (l <= rcv->depth && rcv->halo[l].n > 0) {
      if (!(!rcv->buf)) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 328, "!rcv->buf");
      rcv->buf = pmalloc (sizeof (double)*rcv->halo[l].n*len,__func__,__FILE__,__LINE__);






      MPI_Irecv (rcv->buf, rcv->halo[l].n*len, MPI_DOUBLE, rcv->pid,
   (l), MPI_COMM_WORLD, &r[nr]);
      rrcv[nr++] = rcv;






    }
  }


  if (nr > 0) {
    int i;
    MPI_Status s;
    mpi_waitany (nr, r, &i, &s);
    while (i != MPI_UNDEFINED) {
      Rcv * rcv = rrcv[i];
      if (!(l <= rcv->depth && rcv->halo[l].n > 0)) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 355, "l <= rcv->depth && rcv->halo[l].n > 0");
      if (!(rcv->buf)) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 356, "rcv->buf");
      apply_bc (rcv, list, listv, listf, l, s);
      mpi_waitany (nr, r, &i, &s);
    }
  }

  prof_stop();
}

     
static void rcv_pid_wait (RcvPid * m)
{tracing("rcv_pid_wait","/home/lisergey/basilisk/src/grid/tree-mpi.h",366);

  for (int i = 0; i < m->npid; i++)
    rcv_free_buf (&m->rcv[i]);
end_tracing("rcv_pid_wait","/home/lisergey/basilisk/src/grid/tree-mpi.h",371);}

static void rcv_pid_send (RcvPid * m, scalar * list, scalar * listv,
     vector * listf, int l)
{
  if (m->npid == 0)
    return;

  prof_start ("rcv_pid_send");

  int len = list_lenb (list) + 2*1*vectors_lenb (listf) +
    (1 << 1)*list_lenb (listv);


  for (int i = 0; i < m->npid; i++) {
    Rcv * rcv = &m->rcv[i];
    if (l <= rcv->depth && rcv->halo[l].n > 0) {
      if (!(!rcv->buf)) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 388, "!rcv->buf");
      rcv->buf = pmalloc (sizeof (double)*rcv->halo[l].n*len,__func__,__FILE__,__LINE__);
      double * b = rcv->buf;

#line 452 "/home/lisergey/basilisk/src/grid/tree.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 391 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 466 "/home/lisergey/basilisk/src/grid/tree.h"
).n; _k++) {
 point.i = (
#line 391 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv->halo[l]
#line 467 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].i; 
#line 391 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 391 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
 {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
   memcpy (b, &val(s,0,0,0), sizeof(double)*_attribute[s.i].block);
   b += _attribute[s.i].block;
 }}}
 {vector*_i=(vector*)( listf);if(_i)for(vector v=*_i;(&v)->x.i>=0;v=*++_i){
   { {
     memcpy (b, &val(v.x,0,0,0), sizeof(double)*_attribute[v.x.i].block);
     b += _attribute[v.x.i].block;
     if (allocated(1,0,0))
       memcpy (b, &val(v.x,1,0,0), sizeof(double)*_attribute[v.x.i].block);
     else
       *b = 1e30f;
     b += _attribute[v.x.i].block;
   }}}}
 {scalar*_i=(scalar*)( listv);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
   for (int i = 0; i <= 1; i++)
     for (int j = 0; j <= 1; j++)
#line 418 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
       {
  if (allocated(i,j,0))
    memcpy (b, &val(s,i,j,0), sizeof(double)*_attribute[s.i].block);
  else
    *b = 1e30f;
  b += _attribute[s.i].block;
       }

 }}}
      }}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}      
#line 433 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
MPI_Isend (rcv->buf, (b - (double *) rcv->buf),
   MPI_DOUBLE, rcv->pid, (l), MPI_COMM_WORLD,
   &rcv->r);
    }
  }

  prof_stop();
}

static void rcv_pid_sync (SndRcv * m, scalar * list, int l)
{
  scalar * listr = NULL, * listv = NULL;
  vector * listf = NULL;
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    if (!is_constant(s) && _attribute[s.i].block > 0) {
      if (_attribute[s.i].face)
 listf = vectors_add (listf, _attribute[s.i].v);
      else if (_attribute[s.i].restriction == restriction_vertex)
 listv = list_add (listv, s);
      else
 listr = list_add (listr, s);
    }}}
  rcv_pid_send (m->snd, listr, listv, listf, l);
  rcv_pid_receive (m->rcv, listr, listv, listf, l);
  rcv_pid_wait (m->snd);
  pfree (listr,__func__,__FILE__,__LINE__);
  pfree (listf,__func__,__FILE__,__LINE__);
  pfree (listv,__func__,__FILE__,__LINE__);
}

static void snd_rcv_destroy (SndRcv * m)
{
  rcv_pid_destroy (m->rcv);
  rcv_pid_destroy (m->snd);
}

static void snd_rcv_init (SndRcv * m, const char * name)
{
  char s[strlen(name) + 5];
  strcpy (s, name);
  strcat (s, ".rcv");
  m->rcv = rcv_pid_new (s);
  strcpy (s, name);
  strcat (s, ".snd");
  m->snd = rcv_pid_new (s);
}

static void mpi_boundary_destroy (Boundary * b)
{
  MpiBoundary * m = (MpiBoundary *) b;
  snd_rcv_destroy (&m->mpi_level);
  snd_rcv_destroy (&m->mpi_level_root);
  snd_rcv_destroy (&m->restriction);
  array_free (m->send);
  array_free (m->receive);
  pfree (m,__func__,__FILE__,__LINE__);
}

     
static void mpi_boundary_level (const Boundary * b, scalar * list, int l)
{tracing("mpi_boundary_level","/home/lisergey/basilisk/src/grid/tree-mpi.h",492);
  MpiBoundary * m = (MpiBoundary *) b;
  rcv_pid_sync (&m->mpi_level, list, l);
  rcv_pid_sync (&m->mpi_level_root, list, l);
end_tracing("mpi_boundary_level","/home/lisergey/basilisk/src/grid/tree-mpi.h",497);}

     
static void mpi_boundary_restriction (const Boundary * b, scalar * list, int l)
{tracing("mpi_boundary_restriction","/home/lisergey/basilisk/src/grid/tree-mpi.h",500);
  MpiBoundary * m = (MpiBoundary *) b;
  rcv_pid_sync (&m->restriction, list, l);
end_tracing("mpi_boundary_restriction","/home/lisergey/basilisk/src/grid/tree-mpi.h",504);}

void mpi_boundary_new()
{
  mpi_boundary = (Boundary *) ((MpiBoundary *) pcalloc (1, sizeof(MpiBoundary),__func__,__FILE__,__LINE__));
  mpi_boundary->destroy = mpi_boundary_destroy;
  mpi_boundary->level = mpi_boundary_level;
  mpi_boundary->restriction = mpi_boundary_restriction;
  MpiBoundary * mpi = (MpiBoundary *) mpi_boundary;
  snd_rcv_init (&mpi->mpi_level, "mpi_level");
  snd_rcv_init (&mpi->mpi_level_root, "mpi_level_root");
  snd_rcv_init (&mpi->restriction, "restriction");
  mpi->send = array_new();
  mpi->receive = array_new();
  add_boundary (mpi_boundary);
}

static FILE * fopen_prefix (FILE * fp, const char * name, char * prefix)
{
  if (fp) {
    sprintf (prefix, "%s-%d ", name, pid());
    return fp;
  }
  else {
    strcpy (prefix, "");
    char fname[80];
    if (debug_iteration >= 0)
      sprintf (fname, "%s-%d-%d", name, debug_iteration, pid());
    else
      sprintf (fname, "%s-%d", name, pid());
    return fopen (fname, "w");
  }
}

void debug_mpi (FILE * fp1)
{
  void output_cells_internal (FILE * fp);

  char prefix[80];
  FILE * fp;


  if (fp1 == NULL) {
    char name[80];
    sprintf (name, "halo-%d", pid()); remove (name);
    sprintf (name, "cells-%d", pid()); remove (name);
    sprintf (name, "faces-%d", pid()); remove (name);
    sprintf (name, "vertices-%d", pid()); remove (name);
    sprintf (name, "neighbors-%d", pid()); remove (name);
    sprintf (name, "mpi-level-rcv-%d", pid()); remove (name);
    sprintf (name, "mpi-level-snd-%d", pid()); remove (name);
    sprintf (name, "mpi-level-root-rcv-%d", pid()); remove (name);
    sprintf (name, "mpi-level-root-snd-%d", pid()); remove (name);
    sprintf (name, "mpi-restriction-rcv-%d", pid()); remove (name);
    sprintf (name, "mpi-restriction-snd-%d", pid()); remove (name);
    sprintf (name, "mpi-border-%d", pid()); remove (name);
    sprintf (name, "exterior-%d", pid()); remove (name);
    sprintf (name, "depth-%d", pid()); remove (name);
    sprintf (name, "refined-%d", pid()); remove (name);
  }


  fp = fopen_prefix (fp1, "halo", prefix);
  for (int l = 0; l < depth(); l++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 494 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _cache = ((Tree *)grid)->prolongation[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _cache.n; _k++) {
 point.i = _cache.p[_k].i;
      
#line 569 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
        
#line 570 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d\n", prefix, x, y, z, level);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
#line 570 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 500
}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 571 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  if (!fp1) {
    fp = fopen_prefix (fp1, "cells", prefix);
    output_cells_internal (fp);
    fclose (fp);
  }

  fp = fopen_prefix (fp1, "faces", prefix);

#line 692 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 694
((Tree *)grid)->faces
#line 436
).n; _k++) {
 point.i = (
#line 694
((Tree *)grid)->faces
#line 437
).p[_k].i;






 point.level = (
#line 694
((Tree *)grid)->faces
#line 444
).p[_k].level;
 _flags = (
#line 694
((Tree *)grid)->faces
#line 445
).p[_k].flags;
#line 581 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
  
#line 699 "/home/lisergey/basilisk/src/grid/tree.h"
if (_flags & face_x) {
    int ig = -1; NOT_UNUSED(ig);    
#line 582 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 582 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d\n", prefix, x, y, z, level);}
  
#line 702 "/home/lisergey/basilisk/src/grid/tree.h"
}
#line 582 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 696
}  
#line 583 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "vertices", prefix);

#line 1708 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 1710
((Tree *)grid)->vertices
#line 436
).n; _k++) {
 point.i = (
#line 1710
((Tree *)grid)->vertices
#line 437
).p[_k].i;






 point.level = (
#line 1710
((Tree *)grid)->vertices
#line 444
).p[_k].level;
 _flags = (
#line 1710
((Tree *)grid)->vertices
#line 445
).p[_k].flags; 
#line 1710
{
    int ig = -1; NOT_UNUSED (ig);    
#line 588 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 588 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d\n", prefix, x, y, z, level);}
  
#line 1719 "/home/lisergey/basilisk/src/grid/tree.h"
}      
#line 447
}
  }
}

#line 1720
}  
#line 589 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "neighbors", prefix); 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags; 
#line 593 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 593 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    int n = 0;    
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
      
#line 596 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0))
 n++;    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
    
#line 598 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d\n", prefix, x, y, z, cell.neighbors);
    if (!(cell.neighbors == n)) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 599, "cell.neighbors == n");
  }}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}  
#line 601 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  MpiBoundary * mpi = (MpiBoundary *) mpi_boundary;

  fp = fopen_prefix (fp1, "mpi-level-rcv", prefix);
  rcv_pid_print (mpi->mpi_level.rcv, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-level-root-rcv", prefix);
  rcv_pid_print (mpi->mpi_level_root.rcv, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-restriction-rcv", prefix);
  rcv_pid_print (mpi->restriction.rcv, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-level-snd", prefix);
  rcv_pid_print (mpi->mpi_level.snd, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-level-root-snd", prefix);
  rcv_pid_print (mpi->mpi_level_root.snd, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-restriction-snd", prefix);
  rcv_pid_print (mpi->restriction.snd, fp, prefix);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "mpi-border", prefix);
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 637 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 637 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (is_border(cell))
      fprintf (fp, "%s%g %g %g %d %d %d\n",
        prefix, x, y, z, level, cell.neighbors, cell.pid);
    else
      continue;
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 646 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "exterior", prefix);
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 650 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 650 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (!is_local(cell))
      fprintf (fp, "%s%g %g %g %d %d %d %d\n",
        prefix, x, y, z, level, cell.neighbors,
        cell.pid, cell.flags & leaf);






  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 662 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "depth", prefix);
  fprintf (fp, "depth: %d %d\n", pid(), depth());
  fprintf (fp, "======= mpi_level.snd ======\n");
  RcvPid * snd = mpi->mpi_level.snd;
  for (int i = 0; i < snd->npid; i++)
    fprintf (fp, "%d %d %d\n", pid(), snd->rcv[i].pid, snd->rcv[i].maxdepth);
  fprintf (fp, "======= mpi_level.rcv ======\n");
  snd = mpi->mpi_level.rcv;
  for (int i = 0; i < snd->npid; i++)
    fprintf (fp, "%d %d %d\n", pid(), snd->rcv[i].pid, snd->rcv[i].maxdepth);
  if (!fp1)
    fclose (fp);

  fp = fopen_prefix (fp1, "refined", prefix);
#line 423 "/home/lisergey/basilisk/src/grid/tree.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 679 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
((Tree *)grid)->refined
#line 436 "/home/lisergey/basilisk/src/grid/tree.h"
).n; _k++) {
 point.i = (
#line 679 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
((Tree *)grid)->refined
#line 437 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].i;






 point.level = (
#line 679 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
((Tree *)grid)->refined
#line 444 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].level;
 _flags = (
#line 679 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
((Tree *)grid)->refined
#line 445 "/home/lisergey/basilisk/src/grid/tree.h"
).p[_k].flags;
    
#line 680 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 680 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fprintf (fp, "%s%g %g %g %d\n", prefix, x, y, z, level);}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 681 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!fp1)
    fclose (fp);
}

static void snd_rcv_free (SndRcv * p)
{
  char name[strlen(p->rcv->name) + 1];
  strcpy (name, p->rcv->name);
  rcv_pid_destroy (p->rcv);
  p->rcv = rcv_pid_new (name);
  strcpy (name, p->snd->name);
  rcv_pid_destroy (p->snd);
  p->snd = rcv_pid_new (name);
}

static bool is_root (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 698 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0))     
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
      
#line 700 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell))
 return true;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
  
#line 702 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
return false;
}


static bool is_local_prolongation (Point point, Point p)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;





   
#line 713 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (dp.x == 0 && ((!is_leaf (neighbor(-1,0,0)) && neighbor(-1,0,0).neighbors && neighbor(-1,0,0).pid >= 0) || (!is_leaf (neighbor(1,0,0)) && neighbor(1,0,0).neighbors && neighbor(1,0,0).pid >= 0)))
      return true;
    if ((!is_leaf (neighbor(dp.x,0,0)) && neighbor(dp.x,0,0).neighbors && neighbor(dp.x,0,0).pid >= 0))
      return true;
  }
  return false;
}



static void append_pid (Array * pids, int pid)
{
  for (int i = 0, * p = (int *) pids->p; i < pids->len/sizeof(int); i++, p++)
    if (*p == pid)
      return;
  array_append (pids, &pid, sizeof(int));
}

static int locals_pids (Point point, Array * pids)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
#line 734 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_leaf(cell)) {
    if (is_local(cell)) {
      Point p = point;      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 737 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
 if ((cell.pid >= 0 && cell.pid != pid()) &&
     ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) || is_local_prolongation (point, p)))
   append_pid (pids, cell.pid);
 if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0))    
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 743 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.pid >= 0 && cell.pid != pid()))
       append_pid (pids, cell.pid);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
      
#line 745 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
    
#line 746 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
  }
  else     
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
  {
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 749 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
      if ((cell.pid >= 0 && cell.pid != pid()))
 append_pid (pids, cell.pid);
      if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0))  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 754 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.pid >= 0 && cell.pid != pid()))
     append_pid (pids, cell.pid);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
    
#line 756 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
}
  
#line 757 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
return pids->len/sizeof(int);
}

static int root_pids (Point point, Array * pids)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 763 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.pid >= 0 && cell.pid != pid()))
      append_pid (pids, cell.pid);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 765 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
return pids->len/sizeof(int);
}







static void rcv_pid_row (RcvPid * m, int l, int * row)
{
  for (int i = 0; i < npe(); i++)
    row[i] = 0;
  for (int i = 0; i < m->npid; i++) {
    Rcv * rcv = &m->rcv[i];
    if (l <= rcv->depth && rcv->halo[l].n > 0)
      row[rcv->pid] = rcv->halo[l].n;
  }
}

void check_snd_rcv_matrix (SndRcv * sndrcv, const char * name)
{
  int maxlevel = depth();
  mpi_all_reduce (maxlevel, MPI_INT, MPI_MAX);
  int * row = ((int *) pmalloc ((npe())*sizeof(int),__func__,__FILE__,__LINE__));
  for (int l = 0; l <= maxlevel; l++) {
    int status = 0;
    if (pid() == 0) {


      int ** send = matrix_new (npe(), npe(), sizeof(int));
      int ** receive = matrix_new (npe(), npe(), sizeof(int));
      rcv_pid_row (sndrcv->snd, l, row);
      MPI_Gather (row, npe(), MPI_INT, &send[0][0], npe(), MPI_INT, 0,
    MPI_COMM_WORLD);
      rcv_pid_row (sndrcv->rcv, l, row);
      MPI_Gather (row, npe(), MPI_INT, &receive[0][0], npe(), MPI_INT, 0,
    MPI_COMM_WORLD);

      int * astatus = ((int *) pmalloc ((npe())*sizeof(int),__func__,__FILE__,__LINE__));
      for (int i = 0; i < npe(); i++)
 astatus[i] = 0;
      for (int i = 0; i < npe(); i++)
 for (int j = 0; j < npe(); j++)
   if (send[i][j] != receive[j][i]) {
     fprintf (ferr, "%s: %d sends    %d to   %d at level %d\n",
       name, i, send[i][j], j, l);
     fprintf (ferr, "%s: %d receives %d from %d at level %d\n",
       name, j, receive[j][i], i, l);
     fflush (ferr);
     for (int k = i - 2; k <= i + 2; k++)
       if (k >= 0 && k < npe())
  astatus[k] = 1;
     for (int k = j - 2; k <= j + 2; k++)
       if (k >= 0 && k < npe())
  astatus[k] = 1;
   }
      MPI_Scatter (astatus, 1, MPI_INT, &status, 1, MPI_INT, 0, MPI_COMM_WORLD);
      pfree (astatus,__func__,__FILE__,__LINE__);

      matrix_free (send);
      matrix_free (receive);
    }
    else {
      rcv_pid_row (sndrcv->snd, l, row);
      MPI_Gather (row, npe(), MPI_INT, NULL, npe(), MPI_INT, 0, MPI_COMM_WORLD);
      rcv_pid_row (sndrcv->rcv, l, row);
      MPI_Gather (row, npe(), MPI_INT, NULL, npe(), MPI_INT, 0, MPI_COMM_WORLD);
      MPI_Scatter (NULL, 1, MPI_INT, &status, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    if (status) {
      fprintf (ferr,
        "check_snd_rcv_matrix \"%s\" failed\n"
        "Calling debug_mpi(NULL)...\n"
        "Aborting...\n",
        name);
      fflush (ferr);
      debug_mpi (NULL);
      MPI_Abort (MPI_COMM_WORLD, -3);
    }
  }
  pfree (row,__func__,__FILE__,__LINE__);
}

static bool has_local_child (Point point)
{int ig=0;NOT_UNUSED(ig);  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
  
  
#line 354
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
    
#line 852 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell))
      return true;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
  
#line 854 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
return false;
}

     
void mpi_boundary_update_buffers()
{tracing("mpi_boundary_update_buffers","/home/lisergey/basilisk/src/grid/tree-mpi.h",858);
  if (npe() == 1)
    {end_tracing("mpi_boundary_update_buffers","/home/lisergey/basilisk/src/grid/tree-mpi.h",861);return;}

  prof_start ("mpi_boundary_update_buffers");

  MpiBoundary * m = (MpiBoundary *) mpi_boundary;
  SndRcv * mpi_level = &m->mpi_level;
  SndRcv * mpi_level_root = &m->mpi_level_root;
  SndRcv * restriction = &m->restriction;

  snd_rcv_free (mpi_level);
  snd_rcv_free (mpi_level_root);
  snd_rcv_free (restriction);

  static const unsigned short used = 1 << user;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 875 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 875 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (is_active(cell) && !is_border(cell))



      continue;

    if (cell.neighbors) {

      Array pids = {NULL, 0, 0};
      int n = locals_pids (point, &pids);
      if (n) { 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 888 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell))
     for (int i = 0, * p = (int *) pids.p; i < n; i++, p++)
       rcv_pid_append (mpi_level->snd, *p, point);    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 891 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
pfree (pids.p,__func__,__FILE__,__LINE__);
      }

      bool locals = false;
      if (is_leaf(cell)) {
 if ((cell.pid >= 0 && cell.pid != pid())) {
   Point p = point;   
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 899 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((is_local(cell) &&
   ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) || is_local_prolongation (point, p))) ||
  is_root(point)) {
       locals = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 902 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
     }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
 
#line 904 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
      }
      else  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
  {
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 908 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell) || is_root(point)) {
     locals = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 909 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
   }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
}
      
#line 911 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (locals)  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 913 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.pid >= 0 && cell.pid != pid()))
            rcv_pid_append (mpi_level->rcv, cell.pid, point),
       cell.flags |= used;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}


      
#line 918 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!is_leaf(cell)) {

 if (is_local(cell)) {
   Array pids = {NULL, 0, 0};

   int n = root_pids (point, &pids);
   if (n) {     
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 926 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
for (int i = 0, * p = (int *) pids.p; i < n; i++, p++)
  if (cell.pid >= 0 && cell.pid != *p)
    rcv_pid_append (mpi_level_root->snd, *p, point);    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }

     
#line 930 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
for (int i = 0, * p = (int *) pids.p; i < n; i++, p++)
       rcv_pid_append (restriction->snd, *p, point);
     pfree (pids.p,__func__,__FILE__,__LINE__);
   }
 }

 else if ((cell.pid >= 0 && cell.pid != pid())) {
   bool root = false;   
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 939 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell)) {
       root = true;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 940 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
     }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
   
#line 942 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (root) {
     int pid = cell.pid;     
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 945 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.pid >= 0 && cell.pid != pid()))
  rcv_pid_append (mpi_level_root->rcv, pid, point),
    cell.flags |= used;    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }

     
#line 949 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
rcv_pid_append (restriction->rcv, pid, point);
   }
 }
      }
    }


    if (level > 0) {
      if (is_local(cell)) {

 Array pids = {NULL, 0, 0};
 if ((aparent(0,0,0).pid >= 0 && aparent(0,0,0).pid != pid()))
   append_pid (&pids, aparent(0,0,0).pid);
 int n = root_pids (parent, &pids);
 if (n) {
   for (int i = 0, * p = (int *) pids.p; i < n; i++, p++)
     rcv_pid_append (restriction->snd, *p, point);
   pfree (pids.p,__func__,__FILE__,__LINE__);
 }
      }
      else if ((cell.pid >= 0 && cell.pid != pid())) {

 if (is_local(aparent(0,0,0)) || has_local_child (parent))
   rcv_pid_append (restriction->rcv, cell.pid, point);
      }
    }
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}





  
#line 981 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
static const unsigned short keep = 1 << (user + 1);
  for (int l = depth(); l >= 0; l--) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
      
#line 984 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 984 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (level == l) {
 if (level > 0 && (cell.pid < 0 || is_local(cell) || (cell.flags & used)))
   aparent(0,0,0).flags |= keep;
 if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) && !(cell.flags & keep))
   coarsen_cell (point, NULL);
 cell.flags &= ~(used|keep);
 continue;
      }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}


  
#line 994 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
m->send->len = m->receive->len = 0;
  rcv_pid_append_pids (mpi_level->snd, m->send);
  rcv_pid_append_pids (mpi_level_root->snd, m->send);
  rcv_pid_append_pids (mpi_level->rcv, m->receive);
  rcv_pid_append_pids (mpi_level_root->rcv, m->receive);

  prof_stop();
#line 1015 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
end_tracing("mpi_boundary_update_buffers","/home/lisergey/basilisk/src/grid/tree-mpi.h",1015);}

     
void mpi_boundary_refine (scalar * list)
{tracing("mpi_boundary_refine","/home/lisergey/basilisk/src/grid/tree-mpi.h",1018);
  prof_start ("mpi_boundary_refine");

  MpiBoundary * mpi = (MpiBoundary *) mpi_boundary;


  Array * snd = mpi->send;
  MPI_Request r[2*snd->len/sizeof(int)];
  int nr = 0;
  for (int i = 0, * dest = snd->p; i < snd->len/sizeof(int); i++,dest++) {
    int len = ((Tree *)grid)->refined.n;
    MPI_Isend (&((Tree *)grid)->refined.n, 1, MPI_INT, *dest,
        (128), MPI_COMM_WORLD, &r[nr++]);
    if (len > 0)
      MPI_Isend (((Tree *)grid)->refined.p, sizeof(Index)/sizeof(int)*len,
   MPI_INT, *dest, (128), MPI_COMM_WORLD, &r[nr++]);
  }



  Array * rcv = mpi->receive;
  Cache rerefined = {NULL, 0, 0};
  for (int i = 0, * source = rcv->p; i < rcv->len/sizeof(int); i++,source++) {
    int len;
    mpi_recv_check (&len, 1, MPI_INT, *source, (128),
      MPI_COMM_WORLD, MPI_STATUS_IGNORE,
      "mpi_boundary_refine (len)");
    if (len > 0) {
      Index p[len];
      mpi_recv_check (p, sizeof(Index)/sizeof(int)*len,
        MPI_INT, *source, (128),
        MPI_COMM_WORLD, MPI_STATUS_IGNORE,
        "mpi_boundary_refine (p)");
      Cache refined = {p, len, len};
#line 423 "/home/lisergey/basilisk/src/grid/tree.h"
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < refined.n; _k++) {
 point.i = refined.p[_k].i;






 point.level = refined.p[_k].level;
 _flags = refined.p[_k].flags;
 
#line 1054 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1054 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (level <= depth() && allocated(0,0,0)) {
   if (is_leaf(cell)) {
     bool neighbors = false;     
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 1058 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (allocated(0,0,0) && (is_active(cell) || is_local(aparent(0,0,0)))) {
  neighbors = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 1059 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
       }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }

     
#line 1062 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (neighbors)
       refine_cell (point, list, 0, &rerefined);
   }
 }}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
    
#line 1066 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
  }


  if (nr)
    MPI_Waitall (nr, r, MPI_STATUSES_IGNORE);


  pfree (((Tree *)grid)->refined.p,__func__,__FILE__,__LINE__);
  ((Tree *)grid)->refined = rerefined;

  prof_stop();



  mpi_all_reduce (rerefined.n, MPI_INT, MPI_SUM);
  if (rerefined.n)
    mpi_boundary_refine (list);
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    _attribute[s.i].dirty = true;}}
end_tracing("mpi_boundary_refine","/home/lisergey/basilisk/src/grid/tree-mpi.h",1086);}

static void check_depth()
{
#line 1121 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}

typedef struct {
  int refined, leaf;
} Remote;



     
void mpi_boundary_coarsen (int l, int too_fine)
{tracing("mpi_boundary_coarsen","/home/lisergey/basilisk/src/grid/tree-mpi.h",1130);
  if (npe() == 1)
    {end_tracing("mpi_boundary_coarsen","/home/lisergey/basilisk/src/grid/tree-mpi.h",1133);return;}

  check_depth();

  if (!(sizeof(Remote) == sizeof(double))) qassert ("/home/lisergey/basilisk/src/grid/tree-mpi.h", 1137, "sizeof(Remote) == sizeof(double)");

  scalar  remote=new_scalar("remote");
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1140 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1140 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (level == l) {
      if (is_local(cell)) {
 ((Remote *)&val(remote,0,0,0))->refined = (!is_leaf (cell) && cell.neighbors && cell.pid >= 0);
 ((Remote *)&val(remote,0,0,0))->leaf = is_leaf(cell);
      }
      else {
 ((Remote *)&val(remote,0,0,0))->refined = true;
 ((Remote *)&val(remote,0,0,0))->leaf = false;
      }
      continue;
    }
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 1155 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
mpi_boundary_level (mpi_boundary,((scalar[]) {remote,{-1}}), l);
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1157 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1157 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (level == l) {
      if (!is_local(cell)) {
 if ((!is_leaf (cell) && cell.neighbors && cell.pid >= 0) && !((Remote *)&val(remote,0,0,0))->refined)
   coarsen_cell_recursive (point, NULL);
 else if (is_leaf(cell) && cell.neighbors && ((Remote *)&val(remote,0,0,0))->leaf) {
   int pid = cell.pid;   
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 1165 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.pid = pid;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1166 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
      }
      continue;
    }
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

  
#line 1174 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
check_depth();

  if (l > 0) {
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1177 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1177 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
      if (level == l) {
 val(remote,0,0,0) = is_local(cell) ? cell.neighbors : 0;
 continue;
      }
      if (is_leaf(cell))
 continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
    
#line 1185 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
mpi_boundary_level (mpi_boundary,((scalar[]) {remote,{-1}}), l);
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1186 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1186 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
      if (level == l)
 if (!is_local(cell) && is_local(aparent(0,0,0)) && val(remote,0,0,0)) {
   aparent(0,0,0).flags &= ~too_fine;
   continue;
 }
      if (is_leaf(cell))
 continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 1195 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}delete((scalar*)((scalar[]){remote,{-1}}));
end_tracing("mpi_boundary_coarsen","/home/lisergey/basilisk/src/grid/tree-mpi.h",1196);}

static void flag_border_cells()
{
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1200 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1200 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    if (is_active(cell)) {
      short flags = cell.flags & ~border;      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 1203 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
 if (!is_local(cell) || (level > 0 && !is_local(aparent(0,0,0)))) {
   flags |= border;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 1205 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
 }

 if (is_refined_check())    
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 1210 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!is_local(cell)) {
       flags |= border;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 1211 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
     }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
 
#line 1213 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (flags & border)   
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 1214 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
      }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
      
#line 1216 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.flags = flags;
    }
    else {
      cell.flags &= ~border;

    }
    if (is_leaf(cell)) {
      if (cell.neighbors) { 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 1225 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.flags &= ~border;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1226 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_border(cell)) {
   bool remote = false;   
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = (
#line 1228 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
2/2
#line 5 "/home/lisergey/basilisk/src/grid/neighbors.h"
);
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 1229 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (!is_local(cell)) {
       remote = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 1230 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
     }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
   
#line 1232 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (remote)      
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 1234 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.flags |= border;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
 
#line 1235 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
      }
      continue;
    }
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 1240 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}

static int balanced_pid (long index, long nt, int nproc)
{
  long ne = ( 1 > (nt/nproc) ? 1 : (nt/nproc)), nr = nt % nproc;
  int pid = index < nr*(ne + 1) ?
    index/(ne + 1) :
    nr + (index - nr*(ne + 1))/ne;
  return ( (nproc - 1) < pid ? (nproc - 1) : pid);
}


     
void mpi_partitioning()
{tracing("mpi_partitioning","/home/lisergey/basilisk/src/grid/tree-mpi.h",1253);
  prof_start ("mpi_partitioning");

  long nt = 0; 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags;
    
#line 1259 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1259 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
nt++;}      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}


  
#line 1262 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
long i = 0;
  ((Tree *)grid)->dirty = true;
#line 255 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 156
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if ((
#line 264
(
#line 1264 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
is_active (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 182
))
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if ((
#line 264
(
#line 1264 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
is_active (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 190
))
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:
    
#line 1265 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1265 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_active (cell)) {
      if (is_leaf (cell)) {
 cell.pid = balanced_pid (i++, nt, npe());
 if (cell.neighbors > 0) {
   int pid = cell.pid;   
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 1271 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.pid = pid;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1272 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
 if (!is_local(cell))
   cell.flags &= ~active;
      }
      else {
 cell.pid = child(0,0,0).pid;
 bool inactive = true; 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 1280 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_active(cell)) {
     inactive = false;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 1281 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
   }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1283 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (inactive)
   cell.flags &= ~active;
      }
    }}      
#line 249 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
    }
  }
}
  
#line 266
}
}

  
#line 1288 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
flag_border_cells();

  prof_stop();

  mpi_boundary_update_buffers();
end_tracing("mpi_partitioning","/home/lisergey/basilisk/src/grid/tree-mpi.h",1293);}

void restore_mpi (FILE * fp, scalar * list1)
{
  long index = 0, nt = 0, start = ftell (fp);
  scalar  size=new_scalar("size"), * list = list_concat (((scalar[]){size,{-1}}), list1);;
  long offset = sizeof(double)*list_len(list);


  static const unsigned short set = 1 << user;
  scalar * listm = is_constant(cm) ? NULL : (scalar *)((vector[]){fm,{{-1}}});
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
    
#line 1305 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1305 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (balanced_pid (index, nt, npe()) <= pid()) {
      unsigned flags;
      if (fread (&flags, sizeof(unsigned), 1, fp) != 1) {
 fprintf (ferr, "restore(): error: expecting 'flags'\n");
 exit (1);
      }
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
 double val;
 if (fread (&val, sizeof(double), 1, fp) != 1) {
   fprintf (ferr, "restore(): error: expecting scalar\n");
   exit (1);
 }
 if (s.i != INT_MAX)
   val(s,0,0,0) = val;
      }}}
      if (level == 0)
 nt = val(size,0,0,0);
      cell.pid = balanced_pid (index, nt, npe());
      cell.flags |= set;
      if (!(flags & leaf) && is_leaf(cell)) {
 if (balanced_pid (index + val(size,0,0,0) - 1, nt, npe()) < pid()) {
   fseek (fp, (sizeof(unsigned) + offset)*(val(size,0,0,0) - 1), SEEK_CUR);
   index += val(size,0,0,0);
   continue;
 }
 refine_cell (point, listm, 0, NULL);
      }
      index++;
      if (is_leaf(cell))
 continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}


  
#line 1338 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
fseek (fp, start, SEEK_SET);
  index = 0;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1340 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1340 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    unsigned flags;
    if (fread (&flags, sizeof(unsigned), 1, fp) != 1) {
      fprintf (ferr, "restore(): error: expecting 'flags'\n");
      exit (1);
    }
    if (cell.flags & set)
      fseek (fp, offset, SEEK_CUR);
    else {
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){ {
 double val;
 if (fread (&val, sizeof(double), 1, fp) != 1) {
   fprintf (ferr, "restore(): error: expecting a scalar\n");
   exit (1);
 }
 if (s.i != INT_MAX)
   val(s,0,0,0) = val;
      }}}
      cell.pid = balanced_pid (index, nt, npe());
      if (is_leaf(cell) && cell.neighbors) {
 int pid = cell.pid; 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 1362 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.pid = pid;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
      
#line 1363 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
    }
    if (!(flags & leaf) && is_leaf(cell)) {
      bool locals = false;      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
 
#line 1368 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if ((cell.flags & set) && (is_local(cell) || is_root(point))) {
   locals = true;  
#line 3 "/home/lisergey/basilisk/src/grid/neighbors.h"
(_k = _nn + 1)
#line 1369 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
 }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
      
#line 1371 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (locals)
 refine_cell (point, listm, 0, NULL);
      else {
 fseek (fp, (sizeof(unsigned) + offset)*(val(size,0,0,0) - 1), SEEK_CUR);
 index += val(size,0,0,0);
 continue;
      }
    }
    index++;
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

#line 255
{
  {

    Point root = {2,0};
#line 156
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if ((
#line 264
(
#line 1385 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
is_active (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 182
))
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if ((
#line 264
(
#line 1385 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
is_active (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 190
))
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default: 
#line 1385 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1385 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
    cell.flags &= ~set;
    if (is_active (cell)) {
      if (is_leaf (cell)) {
 if (cell.neighbors > 0) {
   int pid = cell.pid;   
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
     
#line 1392 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
cell.pid = pid;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1393 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
 if (!is_local(cell))
   cell.flags &= ~active;
      }
      else if (!is_local(cell)) {
 bool inactive = true; 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 1400 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_active(cell)) {
     inactive = false;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 1401 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
   }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 1403 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (inactive)
   cell.flags &= ~active;
      }
    }
  }}      
#line 249 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
    }
  }
}
  
#line 266
}
}

  
#line 1409 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
flag_border_cells();

  mpi_boundary_update (list);
  pfree (list,__func__,__FILE__,__LINE__);delete((scalar*)((scalar[]){size,{-1}}));
}
#line 1435 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
     
double z_indexing (scalar index, bool leaves)
{tracing("z_indexing","/home/lisergey/basilisk/src/grid/tree-mpi.h",1436);



  scalar  size=new_scalar("size");
  subtree_size (size, leaves);






  double maxi = -1.;
  if (pid() == 0) 
#line 53 "/home/lisergey/basilisk/src/grid/config.h"
{
#line 1451 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
      
#line 1452 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{ _stencil_val(size,0,0,0);   }  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (0 <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[0];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = 0;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
      
#line 1452 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1452 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
maxi = val(size,0,0,0) - 1.;}      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}
#line 1452 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
#line 53 "/home/lisergey/basilisk/src/grid/config.h"
}
  




  
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    
#line 1458 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{_stencil_val_a(index,0,0,0);  }  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (0 <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[0];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = 0;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;
    
#line 1458 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1458 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
val(index,0,0,0) = 0;}      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}
  
#line 1459 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
for (int l = 0; l < depth(); l++) {
    { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {index,{-1}}), l); };
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 1461 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 1461 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
      if (level == l) {
 if (is_leaf(cell)) {
   if (is_local(cell) && cell.neighbors) {
     int i = val(index,0,0,0);     
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 1467 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
val(index,0,0,0) = i;    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
   
#line 1468 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
 }
 else {
   bool loc = is_local(cell);
   if (!loc)      
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
       
#line 1474 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (is_local(cell)) {
  loc = true;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 1475 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
;
       }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}
   
#line 1477 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
if (loc) {
     int i = val(index,0,0,0) + !leaves;     
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 1479 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
{
       val(index,0,0,0) = i;
       i += val(size,0,0,0);
     }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
   
#line 1483 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
 }
 continue;
      }
      if (is_leaf(cell))
 continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
  
#line 1490 "/home/lisergey/basilisk/src/grid/tree-mpi.h"
}
  { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->restriction) _b->restriction (_b,((scalar[]) {index,{-1}}), depth()); };

  {delete((scalar*)((scalar[]){size,{-1}}));{end_tracing("z_indexing","/home/lisergey/basilisk/src/grid/tree-mpi.h",1493);return maxi;}}delete((scalar*)((scalar[]){size,{-1}}));
end_tracing("z_indexing","/home/lisergey/basilisk/src/grid/tree-mpi.h",1494);}
#line 1738 "/home/lisergey/basilisk/src/grid/tree.h"
#line 1 "grid/balance.h"
#line 1 "/home/lisergey/basilisk/src/grid/balance.h"


typedef struct {
  short leaf, prolongation;
  int pid;
} NewPid;



#if TRASH
# define is_newpid() (!isnan(val(newpid,0,0,0)) && ((NewPid *)&val(newpid,0,0,0))->pid > 0)
#else
# define is_newpid() (((NewPid *)&val(newpid,0,0,0))->pid > 0)
#endif

Array * linear_tree (size_t size, scalar newpid)
{
  const unsigned short sent = 1 << user, next = 1 << (user + 1);
  Array * a = array_new();

#line 270 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 0; root.i <= 2*2; root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 156 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if (true)
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if (true)
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:    
#line 22 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 22 "/home/lisergey/basilisk/src/grid/balance.h"
if (level > 0 && (cell.flags & (sent|next)))
      aparent(0,0,0).flags |= next;}

      
#line 249 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 282 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}  
#line 25 "/home/lisergey/basilisk/src/grid/balance.h"
bool empty = true; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 26 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 26 "/home/lisergey/basilisk/src/grid/balance.h"
{
    if (cell.flags & sent) {
      array_append (a, &cell, size);
      cell.flags &= ~sent;
      empty = false;
    }
    else {
      if (cell.pid >= 0 && ((NewPid *)&val(newpid,0,0,0))->leaf)
 if (!(is_leaf(cell))) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 34, "is_leaf(cell)");
      if (is_refined_check()) {


 bool prolo = false;
  
 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;   
#line 40 "/home/lisergey/basilisk/src/grid/balance.h"
if (((NewPid *)&val(newpid,0,0,0))->prolongation)
     prolo = true;
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  } 
#line 42 "/home/lisergey/basilisk/src/grid/balance.h"
if (prolo) {

   cell.flags |= leaf;
   array_append (a, &cell, sizeof(Cell));
   cell.flags &= ~leaf;
 }
 else
   array_append (a, &cell, sizeof(Cell));
      }
      else
 array_append (a, &cell, sizeof(Cell));
    }
    if (cell.flags & next)
      cell.flags &= ~next;
    else
      continue;
  }}

 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}  
#line 60 "/home/lisergey/basilisk/src/grid/balance.h"
if (empty)
    a->len = 0;
  return a;
}

void macro_foreach_tree (Array * t, size_t size, scalar * list, scalar newpid)
{
  {
    const unsigned short _sent = 1 << user, _next = 1 << (user + 1);
    scalar * _list = list;
    char * _i = (char *) (t)->p; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 71 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 71 "/home/lisergey/basilisk/src/grid/balance.h"
{
      Cell * c = (Cell *) _i;
      if (c->flags & _sent) {
 _i += size;
 ;
      }
      else
 _i += sizeof(Cell);
      if (c->flags & _next) {
 if (!(c->neighbors)) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 80, "c->neighbors");
 if (!(c->flags & leaf) && is_leaf(cell) &&
     (!is_newpid() || !((NewPid *)&val(newpid,0,0,0))->leaf))

   refine_cell (point, _list, 0, NULL);
 else if (!cell.neighbors)

   alloc_children (point);
      }
      else
 continue;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}  
#line 92 "/home/lisergey/basilisk/src/grid/balance.h"
}
}

Array * neighborhood (scalar newpid, int nextpid, FILE * fp)
{
  const unsigned short sent = 1 << user;

#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 98 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 98 "/home/lisergey/basilisk/src/grid/balance.h"
{

    bool root = false;
    if ((!is_local(cell) || ((NewPid *)&val(newpid,0,0,0))->pid - 1 != nextpid) && (!is_leaf (cell) && cell.neighbors && cell.pid >= 0)) {
  
      
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 103 "/home/lisergey/basilisk/src/grid/balance.h"
if (is_local(cell) && ((NewPid *)&val(newpid,0,0,0))->pid - 1 == nextpid) {
   root = true;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 104 "/home/lisergey/basilisk/src/grid/balance.h"
;
 }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }      
#line 106 "/home/lisergey/basilisk/src/grid/balance.h"
if (root && cell.pid != nextpid) { 
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 2;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;   
#line 108 "/home/lisergey/basilisk/src/grid/balance.h"
if (cell.pid != nextpid && is_newpid()) {
     if (fp)
       fprintf (fp, "%g %g %g %d %d root\n",
         x, y, z, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid);
     cell.flags |= sent;
   }    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
      
#line 114 "/home/lisergey/basilisk/src/grid/balance.h"
}
    }

    if ((is_local(cell) && ((NewPid *)&val(newpid,0,0,0))->pid - 1 == nextpid) || root) {      
#line 4 "/home/lisergey/basilisk/src/grid/neighbors.h"
{
    const int _nn = 1;
    const int _i = point.i;
    for (int _k = - _nn; _k <= _nn; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2; 
#line 119 "/home/lisergey/basilisk/src/grid/balance.h"
if (cell.neighbors && cell.pid != nextpid)
    
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
{
  {
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;     
#line 121 "/home/lisergey/basilisk/src/grid/balance.h"
if (cell.pid != nextpid && is_newpid()) {
       if (fp)
  fprintf (fp, "%g %g %g %d %d nextpid\n",
    x, y, z, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid);
       cell.flags |= sent;
     }
    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
}    
#line 11 "/home/lisergey/basilisk/src/grid/neighbors.h"
}
    point.i = _i;
  }
    
#line 127 "/home/lisergey/basilisk/src/grid/balance.h"
}
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}  
#line 132 "/home/lisergey/basilisk/src/grid/balance.h"
return linear_tree (sizeof(Cell) + datasize, newpid);
}

static void send_tree (Array * a, int to, MPI_Request * r)
{
  MPI_Isend (&a->len, 1, MPI_LONG, to, (256), MPI_COMM_WORLD, &r[0]);
  if (a->len > 0) {
    MPI_Isend (a->p, a->len, MPI_BYTE, to, (256), MPI_COMM_WORLD, &r[1]);
    ((Tree *)grid)->dirty = true;
  }
}

static void receive_tree (int from, scalar newpid, FILE * fp)
{
  Array a;
  mpi_recv_check (&a.len, 1, MPI_LONG, from, (256),
    MPI_COMM_WORLD, MPI_STATUS_IGNORE, "receive_tree (len)");
  if (a.len > 0) {
    a.p = pmalloc (a.len,__func__,__FILE__,__LINE__);
    if (fp)
      fprintf (fp, "receiving %ld from %d\n", a.len, from);
    mpi_recv_check (a.p, a.len, MPI_BYTE, from, (256),
      MPI_COMM_WORLD, MPI_STATUS_IGNORE, "receive_tree (p)");
#line 66
{
  {
    const unsigned short _sent = 1 << user, _next = 1 << (user + 1);
    scalar * _list = NULL;
    char * _i = (char *) ((
#line 156
&a
#line 70
))->p; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 71 "/home/lisergey/basilisk/src/grid/balance.h"
{
      Cell * c = (Cell *) _i;
      if (c->flags & _sent) {
 _i += (
#line 156
sizeof(Cell) + datasize
#line 74
); 
#line 156
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 156 "/home/lisergey/basilisk/src/grid/balance.h"
{
      memcpy (((char *)&cell) + sizeof(Cell), ((char *)c) + sizeof(Cell),
       datasize);
      if (!(((NewPid *)&val(newpid,0,0,0))->pid > 0)) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 159, "NEWPID()->pid > 0");
      if (fp)
 fprintf (fp, "%g %g %g %d %d %d %d %d %d recv\n",
   x, y, z, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid,
   c->flags & leaf,
   cell.flags & leaf, from, ((NewPid *)&val(newpid,0,0,0))->leaf);
    }}      
#line 76
}
      else
 _i += sizeof(Cell);
      if (c->flags & _next) {
 if (!(c->neighbors)) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 80, "c->neighbors");
 if (!(c->flags & leaf) && is_leaf(cell) &&
     (!is_newpid() || !((NewPid *)&val(newpid,0,0,0))->leaf))

   refine_cell (point, _list, 0, NULL);
 else if (!cell.neighbors)

   alloc_children (point);
      }
      else
 continue;
    } 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}  
#line 92 "/home/lisergey/basilisk/src/grid/balance.h"
}
}
    
#line 166
pfree (a.p,__func__,__FILE__,__LINE__);
    ((Tree *)grid)->dirty = true;
  }
}

static void wait_tree (Array * a, MPI_Request * r)
{
  MPI_Wait (&r[0], MPI_STATUS_IGNORE);
  if (a->len > 0)
    MPI_Wait (&r[1], MPI_STATUS_IGNORE);
}

static void check_flags()
{







}

struct {
  int min;
  bool leaves;

  int npe;
} mpi = {
  1,
  true
};

     
bool balance()
{tracing("balance","/home/lisergey/basilisk/src/grid/balance.h",200);
  if (npe() == 1)
    {end_tracing("balance","/home/lisergey/basilisk/src/grid/balance.h",203);return false;}

  if (!(sizeof(NewPid) == sizeof(double))) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 205, "sizeof(NewPid) == sizeof(double)");

  check_flags();

  long nl = 0, nt = 0;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 210 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 210 "/home/lisergey/basilisk/src/grid/balance.h"
{
    if (is_local(cell)) {
      nt++;
      if (is_leaf(cell))
 nl++;
    }
    if (is_leaf(cell))
      continue;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}

  
#line 220 "/home/lisergey/basilisk/src/grid/balance.h"
grid->n = grid->tn = nl;
  grid->maxdepth = depth();
  long nmin = nl, nmax = nl;

  mpi_all_reduce (nmax, MPI_LONG, MPI_MAX);
  mpi_all_reduce (nmin, MPI_LONG, MPI_MIN);
  mpi_all_reduce (grid->tn, MPI_LONG, MPI_SUM);
  mpi_all_reduce (grid->maxdepth, MPI_INT, MPI_MAX);
  if (mpi.leaves)
    nt = grid->tn;
  else
    mpi_all_reduce (nt, MPI_LONG, MPI_SUM);

  long ne = ( 1 > (nt/npe()) ? 1 : (nt/npe()));

  if (ne < mpi.min) {
    mpi.npe = ( 1 > (nt/mpi.min) ? 1 : (nt/mpi.min));
    ne = ( 1 > (nt/mpi.npe) ? 1 : (nt/mpi.npe));
  }
  else
    mpi.npe = npe();

  if (nmax - nmin <= 1)
    {end_tracing("balance","/home/lisergey/basilisk/src/grid/balance.h",243);return false;}

  scalar  newpid=new_scalar("newpid");
  double zn = z_indexing (newpid, mpi.leaves);
  if (pid() == 0)
    if (!(zn + 1 == nt)) qassert ("/home/lisergey/basilisk/src/grid/balance.h", 248, "zn + 1 == nt");

  FILE * fp = NULL;
#line 260 "/home/lisergey/basilisk/src/grid/balance.h"
  bool next = false, prev = false; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 261 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 261 "/home/lisergey/basilisk/src/grid/balance.h"
{
    if (is_local(cell)) {
      int pid = balanced_pid (val(newpid,0,0,0), nt, mpi.npe);
      pid = ( pid < (cell.pid - 1) ? (cell.pid - 1) : pid > (cell.pid + 1) ? (cell.pid + 1) : pid);
      if (pid == pid() + 1)
 next = true;
      else if (pid == pid() - 1)
 prev = true;
      ((NewPid *)&val(newpid,0,0,0))->pid = pid + 1;
      ((NewPid *)&val(newpid,0,0,0))->leaf = is_leaf(cell);
      ((NewPid *)&val(newpid,0,0,0))->prolongation = (!is_leaf(cell) && !cell.neighbors && cell.pid >= 0);
      if (fp)
 fprintf (fp, "%g %g %d %d newpid\n", x, y, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid);
    }
    else
      val(newpid,0,0,0) = 0;
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}
  
#line 278 "/home/lisergey/basilisk/src/grid/balance.h"
for (int l = 0; l <= depth(); l++)
    { Boundary ** _i = boundaries, * _b; while (_i && (_b = *_i++)) if (_b->level) _b->level (_b,((scalar[]) {newpid,{-1}}), l); };
#line 304 "/home/lisergey/basilisk/src/grid/balance.h"
  Array * anext = next ? neighborhood (newpid, pid() + 1, fp) : array_new();
  Array * aprev = prev ? neighborhood (newpid, pid() - 1, fp) : array_new();

  if (fp)
    fflush (fp);

  check_flags();


  MPI_Request rprev[2], rnext[2];
  if (pid() > 0)
    send_tree (aprev, pid() - 1, rprev);
  if (pid() < npe() - 1)
    send_tree (anext, pid() + 1, rnext);


  if (pid() < npe() - 1)
    receive_tree (pid() + 1, newpid, fp);
  if (pid() > 0)
    receive_tree (pid() - 1, newpid, fp);


  if (pid() > 0)
    wait_tree (aprev, rprev);
  array_free (aprev);
  if (pid() < npe() - 1)
    wait_tree (anext, rnext);
  array_free (anext);

  if (fp)
    fflush (fp);


  int pid_changed = false; 
#line 140 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    Point root = {0};
    for (root.i = 2*Period.x; root.i <= 2*(2 - Period.x); root.i++) 
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
{

#line 67 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 338 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 338 "/home/lisergey/basilisk/src/grid/balance.h"
{
    if (cell.pid >= 0) {
      if (is_newpid()) {
 if (fp)
   fprintf (fp, "%g %g %g %d %d %d %d %d new\n",
     x, y, z, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid,
     is_leaf(cell), cell.neighbors, ((NewPid *)&val(newpid,0,0,0))->leaf);
 if (cell.pid != ((NewPid *)&val(newpid,0,0,0))->pid - 1) {
   cell.pid = ((NewPid *)&val(newpid,0,0,0))->pid - 1;
   cell.flags &= ~(active|border);
   if (is_local(cell))
     cell.flags |= active;
   pid_changed = true;
 }
 if (((NewPid *)&val(newpid,0,0,0))->leaf && !is_leaf(cell) && cell.neighbors)
   coarsen_cell_recursive (point, NULL);
      }
      else if (level > 0 && ((NewPid *)&coarse(newpid,0,0,0))->leaf)
 cell.pid = aparent(0,0,0).pid;
    }

    if (!cell.neighbors && allocated_child(0,0,0)) {
      if (fp)
 fprintf (fp, "%g %g %g %d %d freechildren\n",
   x, y, z, ((NewPid *)&val(newpid,0,0,0))->pid - 1, cell.pid);
      free_children (point);
    }
  }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
#line 22 "/home/lisergey/basilisk/src/grid/config.h"
}
  
#line 152 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
}

  
#line 367 "/home/lisergey/basilisk/src/grid/balance.h"
if (((Tree *)grid)->dirty || pid_changed) {
#line 255 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 156
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: {
 if (point.level == grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 8; };
 }
 else {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   if ((
#line 264
(
#line 370 "/home/lisergey/basilisk/src/grid/balance.h"
!is_leaf (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 182
))
     { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1:
 { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 2; };
 if ((
#line 264
(
#line 370 "/home/lisergey/basilisk/src/grid/balance.h"
!is_leaf (cell)
#line 264 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
)
#line 190
))
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; };
 break;
#line 246 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      default:
      
#line 371 "/home/lisergey/basilisk/src/grid/balance.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 371 "/home/lisergey/basilisk/src/grid/balance.h"
if (!is_leaf(cell) && !is_local(cell)) {
 unsigned short flags = cell.flags & ~active; 
#line 354 "/home/lisergey/basilisk/src/grid/tree.h"
{
    int _i = 2*point.i - 2;
    point.level++;
    for (int _k = 0; _k < 2; _k++) {
      point.i = _i + _k;      
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
   
#line 374 "/home/lisergey/basilisk/src/grid/balance.h"
if (is_active(cell)) {
     flags |= active;  
#line 353 "/home/lisergey/basilisk/src/grid/tree.h"
(_k = 2)
#line 375 "/home/lisergey/basilisk/src/grid/balance.h"
;
   }    
#line 361 "/home/lisergey/basilisk/src/grid/tree.h"
}
    point.i = (_i + 2)/2;
    point.level--;
  }
 
#line 377 "/home/lisergey/basilisk/src/grid/balance.h"
cell.flags = flags;
      }}      
#line 249 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
}
    }
  }
}
  
#line 266
}
}

    
#line 380 "/home/lisergey/basilisk/src/grid/balance.h"
flag_border_cells();
    pid_changed = true;
  }

  if (fp)
    fclose (fp);

  mpi_all_reduce (pid_changed, MPI_INT, MPI_MAX);
  if (pid_changed)
    mpi_boundary_update_buffers();

  {delete((scalar*)((scalar[]){newpid,{-1}}));{end_tracing("balance","/home/lisergey/basilisk/src/grid/balance.h",391);return pid_changed;}}delete((scalar*)((scalar[]){newpid,{-1}}));
end_tracing("balance","/home/lisergey/basilisk/src/grid/balance.h",392);}

void mpi_boundary_update (scalar * list)
{
  mpi_boundary_update_buffers();
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    _attribute[s.i].dirty = true;}}
  grid->tn = 0;
  boundary_internal ((scalar *)list, "/home/lisergey/basilisk/src/grid/balance.h", 400);
  while (balance());
}
#line 1739 "/home/lisergey/basilisk/src/grid/tree.h"
#else
void mpi_boundary_refine (scalar * list){}
void mpi_boundary_coarsen (int a, int b){}
void mpi_boundary_update (scalar * list) {
  {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
    _attribute[s.i].dirty = true;}}
  boundary_internal ((scalar *)list, "/home/lisergey/basilisk/src/grid/tree.h", 1745);
}
#endif
#line 4 "/home/lisergey/basilisk/src/grid/bitree.h"

void bitree_methods() {
  tree_methods();
}
#line 2 "wavelet.c"
void write_level (scalar * list, const char * tag, FILE * fp)
{
  for (int l = 0; l <= depth(); l++) 
#line 53 "/home/lisergey/basilisk/src/grid/config.h"
{
#line 5 "wavelet.c"
{
  
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point); 
#line 5 "wavelet.c"
{     
      
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
        { _stencil_val(s,0,0,0);  }}}  
      
    }
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i; 
#line 5 "wavelet.c"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 5 "wavelet.c"
{
      fprintf (fp, "%s%d %g ", tag, l, x);
      {scalar*_i=(scalar*)( list);if(_i)for(scalar s=*_i;(&s)->i>=0;s=*++_i){
        fprintf (fp, "%g ", val(s,0,0,0));}}
      fputc ('\n', fp);
    }}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}
#line 10 "wavelet.c"
}
#line 53 "/home/lisergey/basilisk/src/grid/config.h"
}
#line 11 "wavelet.c"
}
int main()
{
#line 47
_init_solver();  
#line 14
init_grid (128);
  tree_periodic(right);
  size (2);
  scalar  s=new_scalar("s"),  w=new_scalar("w"),  s2=new_scalar("s2");
  




  
#line 314 "/home/lisergey/basilisk/src/grid/stencils.h"
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "wavelet.c", .line = 22, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    
#line 23 "wavelet.c"
{_stencil_val_a(s,0,0,0);           }

    
#line 328 "/home/lisergey/basilisk/src/grid/stencils.h"
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags;    
#line 23 "wavelet.c"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 23 "wavelet.c"
val(s,0,0,0) = sin(2.*3.14159265358979*x) + 0.4*sin(15*3.14159265358979*x)*( (sin(2.*3.14159265358979*x)) > 0 ? (sin(2.*3.14159265358979*x)) : 0);}
      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}  
#line 24 "wavelet.c"
wavelet (s, w);
  inverse_wavelet (s2, w);
  
  
#line 314 "/home/lisergey/basilisk/src/grid/stencils.h"
{
    static int _first = 1.;
    ForeachData _loop = {
      .fname = "wavelet.c", .line = 26, .first = _first
    };
    if (baseblock) for (scalar s = baseblock[0], * i = baseblock; s.i >= 0; i++, s = *i) {
 _attribute[s.i].input = _attribute[s.i].output = _attribute[s.i].nowarning = false;
 _attribute[s.i].width = 0;
      }
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);    
#line 27 "wavelet.c"
{_stencil_val(s2,0,0,0); _stencil_val(s,0,0,0);         }

    
#line 328 "/home/lisergey/basilisk/src/grid/stencils.h"
check_stencil (&_loop);
    boundary_stencil (&_loop);
    _first = 0;
  } 
#line 684 "/home/lisergey/basilisk/src/grid/tree.h"
{
  { if (((Tree *)grid)->dirty) update_cache_f(); };
#line 423
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    int _k; unsigned short _flags; NOT_UNUSED(_flags);
    OMP(omp for schedule(static))
      for (_k = 0; _k < (
#line 686
((Tree *)grid)->leaves
#line 436
).n; _k++) {
 point.i = (
#line 686
((Tree *)grid)->leaves
#line 437
).p[_k].i;






 point.level = (
#line 686
((Tree *)grid)->leaves
#line 444
).p[_k].level;
 _flags = (
#line 686
((Tree *)grid)->leaves
#line 445
).p[_k].flags;    
#line 27 "wavelet.c"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 27 "wavelet.c"
if (!(fabs (val(s2,0,0,0) - val(s,0,0,0)) < 1e-12)) qassert ("wavelet.c", 27, "fabs (s2[] - s[]) < 1e-12");}
      
#line 447 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}

#line 688
}  
#line 28 "wavelet.c"
write_level (((scalar[]){s,w,{-1}}), "", ferr);
  for (int l = 5; l <= 6; l++) {
  
    
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);      
#line 31 "wavelet.c"
{_stencil_val_r(w,0,0,0);    }
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;      
#line 31 "wavelet.c"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 31 "wavelet.c"
val(w,0,0,0) *= (x <= 1);}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}    
#line 32 "wavelet.c"
boundary_level (((scalar[]){w,{-1}}), l);
  }
  inverse_wavelet (s2, w);
  write_level (((scalar[]){s2,w,{-1}}), "a", fout);
  wavelet (s, w);
  for (int l = 0; l < 5; l++) {
  
    
#line 347 "/home/lisergey/basilisk/src/grid/stencils.h"
if (0) {

    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);      
#line 39 "wavelet.c"
{_stencil_val_a(w,0,0,0);  }
  
#line 352 "/home/lisergey/basilisk/src/grid/stencils.h"
} 
#line 731 "/home/lisergey/basilisk/src/grid/tree.h"
{
  if (l <= depth()) {
    { if (((Tree *)grid)->dirty) update_cache_f(); };
    CacheLevel _active = ((Tree *)grid)->active[l];
#line 452
{
  OMP_PARALLEL () {
    int ig = 0, jg = 0, kg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg); NOT_UNUSED(kg);
    Point point = {0}; NOT_UNUSED (point);
    point.i = 2;






    point.level = l;
    int _k;
    OMP(omp for schedule(static))
      for (_k = 0; _k < _active.n; _k++) {
 point.i = _active.p[_k].i;      
#line 39 "wavelet.c"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 39 "wavelet.c"
val(w,0,0,0) = 0.;}
      
#line 475 "/home/lisergey/basilisk/src/grid/tree.h"
}
  }
}
  
#line 737
}
}    
#line 40 "wavelet.c"
boundary_level (((scalar[]){w,{-1}}), l);
  }
  inverse_wavelet (s2, w);
  write_level (((scalar[]){s2,w,{-1}}), "b", fout);
  wavelet (s, w);
  
  
#line 364 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
    static const int too_fine = 1 << user;
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 366 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 366 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
      if (is_leaf(cell))
 continue;
      if (is_local(cell) && ((
#line 45 "wavelet.c"
fabs(val(w,0,0,0)) < 0.1
#line 369 "/home/lisergey/basilisk/src/grid/tree-common.h"
)))
 cell.flags |= too_fine;
    }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
    
#line 372 "/home/lisergey/basilisk/src/grid/tree-common.h"
for (int _l = depth(); _l >= 0; _l--) {
#line 126 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
{
  {

    Point root = {2,0};
#line 67
{
  {
    int ig = 0, jg = 0; NOT_UNUSED(ig); NOT_UNUSED(jg);
    Point point = {0};

    struct { int l, i, stage; } stack[20];






    int _s = -1;
    { _s++; stack[_s].l = 0; stack[_s].i = root.i; stack[_s].stage = 0; };
    while (_s >= 0) {
      int stage;
      { point.level = stack[_s].l; point.i = stack[_s].i; stage = stack[_s].stage; _s--; };
      if (!allocated (0,0,0))
 continue;
      switch (stage) {
      case 0: { 
#line 373 "/home/lisergey/basilisk/src/grid/tree-common.h"
{  
#line 3 "/home/lisergey/basilisk/src/grid/variables.h"
double Delta = L0*(1./(1 << point.level));
  double Delta_x = Delta;







  double x = ((ig + 1)/2. + (point.i - 2))*Delta + X0; NOT_UNUSED(x);



  double y = 0.;

  NOT_UNUSED(y);



  double z = 0.;

  NOT_UNUSED(z);

  NOT_UNUSED(Delta);
  NOT_UNUSED(Delta_x);







  ;
  
#line 321 "/home/lisergey/basilisk/src/grid/tree.h"
int level = point.level; NOT_UNUSED(level);

  struct { int x; } child = { 2*((point.i+2)%2)-1 };
#line 333 "/home/lisergey/basilisk/src/grid/tree.h"
  NOT_UNUSED(child);
  Point parent = point; NOT_UNUSED(parent);
  parent.level--;
  parent.i = (point.i + 2)/2;
#line 373 "/home/lisergey/basilisk/src/grid/tree-common.h"
{
 if (is_leaf(cell))
   continue;
 if (level == _l) {
   if (is_local(cell) && (cell.flags & too_fine)) {
     coarsen_cell (point, all);
     cell.flags &= ~too_fine;
   }
   continue;
 }
      }} 
#line 91 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
if (point.level < grid->depth) {
   { _s++; stack[_s].l = point.level; stack[_s].i = point.i; stack[_s].stage = 1; };
   { _s++; stack[_s].l = point.level + 1; stack[_s].i = (2*point.i - 2); stack[_s].stage = 0; };
 }
 break;
      }

      case 1: { _s++; stack[_s].l = point.level + 1; stack[_s].i = ((2*point.i - 2) + 1); stack[_s].stage = 0; }; break;
#line 120 "/home/lisergey/basilisk/src/grid/foreach_cell.h"
      }
    }
  }
}
  
#line 137
}
}
      
#line 384 "/home/lisergey/basilisk/src/grid/tree-common.h"
mpi_boundary_coarsen (_l, too_fine);
    }
    mpi_boundary_update (all);
  }  
#line 46 "wavelet.c"
write_level (((scalar[]){s,w,{-1}}), "c", fout);delete((scalar*)((scalar[]){s2,w,s,{-1}}));
free_solver();}
#line 2 "ast/init_solver.h"

static void _init_solver (void)
{
  void init_solver();
  init_solver();
  {
#line 24
bitree_methods();

    

    
#line 12
{
      
      
    
      {
	
	
	
      }
#line 385 "/home/lisergey/basilisk/src/common.h"
init_const_vector((vector){{_NVARMAX+0}},"zerof",(double[]){0.,0.,0.});
init_const_vector((vector){{_NVARMAX+1}},"unityf",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+2},"unity", 1.);
init_const_scalar((scalar){_NVARMAX+3},"zeroc", 0.);



init_const_vector((vector){{_NVARMAX+4}},"fm",(double[]){1.,1.,1.});
init_const_scalar((scalar){_NVARMAX+5},"cm", 1.);    
#line 23 "ast/init_solver.h"
}
  }
  set_fpe();
}
