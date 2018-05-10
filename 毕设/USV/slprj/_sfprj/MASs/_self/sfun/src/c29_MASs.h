#ifndef __c29_MASs_h__
#define __c29_MASs_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stdlib.h>
#include "lapacke.h"
#ifndef typedef_SFc29_MASsInstanceStruct
#define typedef_SFc29_MASsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c29_sfEvent;
  boolean_T c29_isStable;
  boolean_T c29_doneDoubleBufferReInit;
  uint8_T c29_is_active_c29_MASs;
  real_T *c29_n;
  real_T *c29_Xp;
  real_T *c29_sita;
  real_T *c29_Yp;
  real_T *c29_Np;
  real_T *c29_u;
  real_T *c29_v;
} SFc29_MASsInstanceStruct;

#endif                                 /*typedef_SFc29_MASsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c29_MASs_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c29_MASs_get_check_sum(mxArray *plhs[]);
extern void c29_MASs_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
