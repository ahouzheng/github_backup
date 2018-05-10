#ifndef __c16_MASs_h__
#define __c16_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_MASsInstanceStruct
#define typedef_SFc16_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_MASs;
  real_T *c16_B;
  real_T *c16_Xs;
  real_T *c16_d;
  real_T *c16_L;
  real_T *c16_Cb;
  real_T *c16_m;
  real_T *c16_Ys;
  real_T *c16_Ns;
  real_T *c16_u;
  real_T *c16_v;
  real_T *c16_r;
} SFc16_MASsInstanceStruct;

#endif                                 /*typedef_SFc16_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_MASs_get_check_sum(mxArray *plhs[]);
extern void c16_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
