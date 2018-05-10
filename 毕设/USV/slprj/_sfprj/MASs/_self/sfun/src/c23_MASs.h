#ifndef __c23_MASs_h__
#define __c23_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_MASsInstanceStruct
#define typedef_SFc23_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_MASs;
  real_T *c23_B;
  real_T *c23_Xs;
  real_T *c23_d;
  real_T *c23_L;
  real_T *c23_Cb;
  real_T *c23_m;
  real_T *c23_Ys;
  real_T *c23_Ns;
  real_T *c23_u;
  real_T *c23_v;
  real_T *c23_r;
} SFc23_MASsInstanceStruct;

#endif                                 /*typedef_SFc23_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_MASs_get_check_sum(mxArray *plhs[]);
extern void c23_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
