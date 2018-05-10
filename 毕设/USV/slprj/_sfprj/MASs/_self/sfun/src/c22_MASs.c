/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c22_MASs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MASs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c22_debug_family_names[30] = { "Q", "A", "beita", "C", "g",
  "np", "Aj", "Ain", "Aw", "Ein", "En", "E0", "h", "Xt", "Vs", "p", "q", "r",
  "V", "Vj", "i", "nargin", "nargout", "n", "sita", "u", "v", "Xp", "Yp", "Np" };

/* Function Declarations */
static void initialize_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void initialize_params_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void enable_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void disable_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_MASs(SFc22_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c22_MASs(SFc22_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c22_MASs(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_st);
static void finalize_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void sf_gateway_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void mdl_start_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void c22_chartstep_c22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void initSimStructsc22_MASs(SFc22_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_Np, const char_T *c22_identifier);
static real_T c22_b_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c22_inData_data[], int32_T *c22_inData_sizes);
static void c22_c_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId, creal_T
  c22_y_data[], int32_T *c22_y_sizes);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, creal_T c22_outData_data[],
  int32_T *c22_outData_sizes);
static real_T c22_rdivide(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x,
  real_T c22_y);
static real_T c22_mpower(SFc22_MASsInstanceStruct *chartInstance, real_T c22_a);
static void c22_scalarEg(SFc22_MASsInstanceStruct *chartInstance);
static void c22_dimagree(SFc22_MASsInstanceStruct *chartInstance);
static boolean_T c22_fltpower_domain_error(SFc22_MASsInstanceStruct
  *chartInstance, real_T c22_a, real_T c22_b);
static void c22_error(SFc22_MASsInstanceStruct *chartInstance);
static real_T c22_b_mpower(SFc22_MASsInstanceStruct *chartInstance, real_T c22_a);
static real_T c22_sqrt(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x);
static void c22_b_error(SFc22_MASsInstanceStruct *chartInstance);
static void c22_roots(SFc22_MASsInstanceStruct *chartInstance, real_T c22_c[4],
                      creal_T c22_r_data[], int32_T *c22_r_sizes);
static boolean_T c22_isfinite(SFc22_MASsInstanceStruct *chartInstance, real_T
  c22_x);
static void c22_c_error(SFc22_MASsInstanceStruct *chartInstance);
static real_T c22_abs(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x);
static void c22_check_forloop_overflow_error(SFc22_MASsInstanceStruct
  *chartInstance, boolean_T c22_overflow);
static void c22_eig(SFc22_MASsInstanceStruct *chartInstance, creal_T c22_A_data[],
                    int32_T c22_A_sizes[2], creal_T c22_V_data[], int32_T
                    *c22_V_sizes);
static void c22_d_error(SFc22_MASsInstanceStruct *chartInstance);
static void c22_e_error(SFc22_MASsInstanceStruct *chartInstance, int32_T
  c22_varargin_2);
static void c22_warning(SFc22_MASsInstanceStruct *chartInstance);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_d_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_e_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_MASs, const char_T *c22_identifier);
static uint8_T c22_f_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sqrt(SFc22_MASsInstanceStruct *chartInstance, real_T *c22_x);
static void init_dsm_address_info(SFc22_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc22_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc22_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_is_active_c22_MASs = 0U;
}

static void initialize_params_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_MASs(SFc22_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c22_MASs(SFc22_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  real_T c22_hoistedGlobal;
  real_T c22_b_u;
  const mxArray *c22_b_y = NULL;
  real_T c22_b_hoistedGlobal;
  real_T c22_c_u;
  const mxArray *c22_c_y = NULL;
  real_T c22_c_hoistedGlobal;
  real_T c22_d_u;
  const mxArray *c22_d_y = NULL;
  uint8_T c22_d_hoistedGlobal;
  uint8_T c22_e_u;
  const mxArray *c22_e_y = NULL;
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(4, 1), false);
  c22_hoistedGlobal = *chartInstance->c22_Np;
  c22_b_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_b_hoistedGlobal = *chartInstance->c22_Xp;
  c22_c_u = c22_b_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  c22_c_hoistedGlobal = *chartInstance->c22_Yp;
  c22_d_u = c22_c_hoistedGlobal;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 2, c22_d_y);
  c22_d_hoistedGlobal = chartInstance->c22_is_active_c22_MASs;
  c22_e_u = c22_d_hoistedGlobal;
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 3, c22_e_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_MASs(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_st)
{
  const mxArray *c22_b_u;
  chartInstance->c22_doneDoubleBufferReInit = true;
  c22_b_u = sf_mex_dup(c22_st);
  *chartInstance->c22_Np = c22_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Np", c22_b_u, 0)), "Np");
  *chartInstance->c22_Xp = c22_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xp", c22_b_u, 1)), "Xp");
  *chartInstance->c22_Yp = c22_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Yp", c22_b_u, 2)), "Yp");
  chartInstance->c22_is_active_c22_MASs = c22_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c22_MASs", c22_b_u, 3)),
    "is_active_c22_MASs");
  sf_mex_destroy(&c22_b_u);
  c22_update_debugger_state_c22_MASs(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_v, 3U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_u, 2U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_sita, 1U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_n, 0U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  chartInstance->c22_sfEvent = CALL_EVENT;
  c22_chartstep_c22_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Xp, 4U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Yp, 5U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Np, 6U, 1U, 0U,
                        chartInstance->c22_sfEvent, false);
}

static void mdl_start_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_chartstep_c22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  real_T c22_hoistedGlobal;
  real_T c22_b_hoistedGlobal;
  real_T c22_c_hoistedGlobal;
  real_T c22_d_hoistedGlobal;
  real_T c22_b_n;
  real_T c22_b_sita;
  real_T c22_b_u;
  real_T c22_b_v;
  uint32_T c22_debug_family_var_map[30];
  real_T c22_Q;
  real_T c22_A;
  real_T c22_beita;
  real_T c22_C;
  real_T c22_g;
  real_T c22_np;
  real_T c22_Aj;
  real_T c22_Ain;
  real_T c22_Aw;
  real_T c22_Ein;
  real_T c22_En;
  real_T c22_E0;
  real_T c22_h;
  real_T c22_Xt;
  real_T c22_Vs;
  real_T c22_p;
  real_T c22_q;
  real_T c22_r;
  int32_T c22_V_sizes;
  creal_T c22_V_data[3];
  real_T c22_Vj;
  real_T c22_i;
  real_T c22_nargin = 4.0;
  real_T c22_nargout = 3.0;
  real_T c22_b_Xp;
  real_T c22_b_Yp;
  real_T c22_b_Np;
  real_T c22_b_A;
  real_T c22_c_A;
  real_T c22_y;
  real_T c22_d_A;
  real_T c22_b_y;
  real_T c22_a;
  real_T c22_b_a;
  real_T c22_c_a;
  real_T c22_x;
  real_T c22_d_a;
  real_T c22_ar;
  real_T c22_c;
  real_T c22_dv0[4];
  int32_T c22_tmp_sizes;
  creal_T c22_tmp_data[3];
  int32_T c22_loop_ub;
  int32_T c22_i0;
  real_T c22_d0;
  int32_T c22_i1;
  int32_T c22_b_i;
  real_T c22_d1;
  real_T c22_b_x;
  real_T c22_c_x;
  real_T c22_d_x;
  real_T c22_e_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c22_sfEvent);
  c22_hoistedGlobal = *chartInstance->c22_n;
  c22_b_hoistedGlobal = *chartInstance->c22_sita;
  c22_c_hoistedGlobal = *chartInstance->c22_u;
  c22_d_hoistedGlobal = *chartInstance->c22_v;
  c22_b_n = c22_hoistedGlobal;
  c22_b_sita = c22_b_hoistedGlobal;
  c22_b_u = c22_c_hoistedGlobal;
  c22_b_v = c22_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_Q, 0U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_A, 1U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_beita, 2U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_C, 3U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_g, 4U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_np, 5U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_Aj, 6U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_Ain, 7U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_Aw, 8U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_Ein, 9U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_En, 10U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_E0, 11U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_h, 12U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_Xt, 13U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_Vs, 14U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_p, 15U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_q, 16U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_r, 17U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c22_V_data, (const int32_T *)
    &c22_V_sizes, NULL, 0, 18, (void *)c22_b_sf_marshallOut, (void *)
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_Vj, 19U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_i, 20U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 21U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 22U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_n, 23U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_sita, 24U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_u, 25U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_b_v, 26U, c22_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_Xp, 27U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_Yp, 28U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_Np, 29U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 3);
  c22_Q = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 4);
  c22_A = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 5);
  c22_beita = 0.9025;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 6);
  c22_C = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 7);
  c22_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 8);
  c22_np = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 9);
  c22_Aj = 0.049087385212340517;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 10);
  c22_Ain = 0.83200000000000007;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 11);
  c22_Aw = 0.78539816339744828;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 12);
  c22_Ein = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 13);
  c22_En = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 14);
  c22_E0 = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 15);
  c22_h = 0.6;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 17);
  c22_Xt = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 19);
  c22_b_A = c22_b_sita * 3.1415926535897931;
  c22_b_sita = c22_rdivide(chartInstance, c22_b_A, 180.0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 20);
  c22_Vs = c22_b_mpower(chartInstance, c22_mpower(chartInstance, c22_b_u) +
                        c22_mpower(chartInstance, c22_b_v));
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 22);
  c22_p = 25.036379540825354;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 23);
  c22_c_A = 0.9025 * c22_mpower(chartInstance, c22_Vs);
  c22_y = c22_rdivide(chartInstance, c22_c_A, 19.6);
  c22_q = 481.05637508093707 * (0.6 - c22_y);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 24);
  c22_d_A = c22_b_n;
  c22_b_y = c22_rdivide(chartInstance, c22_d_A, 1000.0);
  c22_a = c22_b_y;
  c22_b_a = c22_a;
  c22_c_a = c22_b_a;
  c22_x = c22_c_a;
  c22_d_a = c22_x;
  c22_ar = c22_d_a;
  c22_c = muDoubleScalarPower(c22_ar, 3.0);
  if (c22_fltpower_domain_error(chartInstance, c22_c_a, 3.0)) {
    c22_error(chartInstance);
  }

  c22_r = -10.0 * c22_c * 0.8;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 29);
  c22_dv0[0] = 25.036379540825354;
  c22_dv0[1] = 0.0;
  c22_dv0[2] = c22_q;
  c22_dv0[3] = c22_r;
  c22_roots(chartInstance, c22_dv0, c22_tmp_data, &c22_tmp_sizes);
  c22_V_sizes = c22_tmp_sizes;
  c22_loop_ub = c22_tmp_sizes - 1;
  for (c22_i0 = 0; c22_i0 <= c22_loop_ub; c22_i0++) {
    c22_V_data[c22_i0] = c22_tmp_data[c22_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 30);
  c22_Vj = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 32);
  c22_d0 = (real_T)c22_V_sizes;
  c22_i1 = (int32_T)c22_d0 - 1;
  c22_i = 1.0;
  c22_b_i = 0;
  while (c22_b_i <= c22_i1) {
    c22_i = 1.0 + (real_T)c22_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 33);
    if (c22_fltpower_domain_error(chartInstance, 10.0, -10.0)) {
      c22_error(chartInstance);
    }

    c22_d1 = c22_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 869, 4, MAX_uint32_T, (int32_T)c22_i, 1, c22_V_sizes)
      - 1].im;
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c22_d1, 1.0E-10, -1, 2U,
          c22_d1 < 1.0E-10))) {
      _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 34);
      c22_Vj = c22_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 904, 4, MAX_uint32_T, (int32_T)c22_i, 1,
        c22_V_sizes) - 1].re;
    }

    c22_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 37);
  c22_b_x = c22_b_sita;
  c22_c_x = c22_b_x;
  c22_c_x = muDoubleScalarCos(c22_c_x);
  c22_b_Xp = 49.087385212340514 * c22_Vj * (c22_Vj - 0.95 * c22_Vs) * c22_c_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 38);
  c22_d_x = c22_b_sita;
  c22_e_x = c22_d_x;
  c22_e_x = muDoubleScalarSin(c22_e_x);
  c22_b_Yp = 49.087385212340514 * c22_Vj * (c22_Vj - 0.95 * c22_Vs) * c22_e_x;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 39);
  c22_b_Np = c22_b_Yp * 3.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c22_Xp = c22_b_Xp;
  *chartInstance->c22_Yp = c22_b_Yp;
  *chartInstance->c22_Np = c22_b_Np;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c22_sfEvent);
}

static void initSimStructsc22_MASs(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_b_u;
  const mxArray *c22_y = NULL;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_b_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real_T c22_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_Np, const char_T *c22_identifier)
{
  real_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_thisId.bParentIsCell = false;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_Np),
    &c22_thisId);
  sf_mex_destroy(&c22_b_Np);
  return c22_y;
}

static real_T c22_b_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d2;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_b_u), &c22_d2, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d2;
  sf_mex_destroy(&c22_b_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_Np;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_b_Np = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_thisId.bParentIsCell = false;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_Np),
    &c22_thisId);
  sf_mex_destroy(&c22_b_Np);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c22_inData_data[], int32_T *c22_inData_sizes)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u_sizes;
  int32_T c22_loop_ub;
  int32_T c22_i2;
  creal_T c22_u_data[3];
  const mxArray *c22_y = NULL;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u_sizes = *c22_inData_sizes;
  c22_loop_ub = *c22_inData_sizes - 1;
  for (c22_i2 = 0; c22_i2 <= c22_loop_ub; c22_i2++) {
    c22_u_data[c22_i2] = c22_inData_data[c22_i2];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u_data, 0, 1U, 1U, 0U, 1,
    c22_u_sizes), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static void c22_c_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId, creal_T
  c22_y_data[], int32_T *c22_y_sizes)
{
  static uint32_T c22_uv0[1] = { 3U };

  uint32_T c22_uv1[1];
  static boolean_T c22_bv0[1] = { true };

  boolean_T c22_bv1[1];
  int32_T c22_tmp_sizes;
  creal_T c22_tmp_data[3];
  int32_T c22_loop_ub;
  int32_T c22_i3;
  (void)chartInstance;
  c22_uv1[0] = c22_uv0[0];
  c22_bv1[0] = c22_bv0[0];
  sf_mex_import_vs(c22_parentId, sf_mex_dup(c22_b_u), c22_tmp_data, 1, 0, 1U, 1,
                   0U, 1, c22_bv1, c22_uv1, &c22_tmp_sizes);
  *c22_y_sizes = c22_tmp_sizes;
  c22_loop_ub = c22_tmp_sizes - 1;
  for (c22_i3 = 0; c22_i3 <= c22_loop_ub; c22_i3++) {
    c22_y_data[c22_i3] = c22_tmp_data[c22_i3];
  }

  sf_mex_destroy(&c22_b_u);
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, creal_T c22_outData_data[],
  int32_T *c22_outData_sizes)
{
  const mxArray *c22_V;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y_sizes;
  creal_T c22_y_data[3];
  int32_T c22_loop_ub;
  int32_T c22_i4;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_V = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_thisId.bParentIsCell = false;
  c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_V), &c22_thisId,
    c22_y_data, &c22_y_sizes);
  sf_mex_destroy(&c22_V);
  *c22_outData_sizes = c22_y_sizes;
  c22_loop_ub = c22_y_sizes - 1;
  for (c22_i4 = 0; c22_i4 <= c22_loop_ub; c22_i4++) {
    c22_outData_data[c22_i4] = c22_y_data[c22_i4];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c22_nameCaptureInfo;
}

static real_T c22_rdivide(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x,
  real_T c22_y)
{
  real_T c22_b_x;
  real_T c22_b_y;
  (void)chartInstance;
  c22_b_x = c22_x;
  c22_b_y = c22_y;
  return c22_b_x / c22_b_y;
}

static real_T c22_mpower(SFc22_MASsInstanceStruct *chartInstance, real_T c22_a)
{
  real_T c22_c;
  real_T c22_b_a;
  real_T c22_c_a;
  real_T c22_x;
  real_T c22_d_a;
  c22_b_a = c22_a;
  c22_c_a = c22_b_a;
  c22_x = c22_c_a;
  c22_d_a = c22_x;
  c22_c = c22_d_a * c22_d_a;
  if (c22_fltpower_domain_error(chartInstance, c22_c_a, 2.0)) {
    c22_error(chartInstance);
  }

  return c22_c;
}

static void c22_scalarEg(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_dimagree(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c22_fltpower_domain_error(SFc22_MASsInstanceStruct
  *chartInstance, real_T c22_a, real_T c22_b)
{
  boolean_T c22_p;
  real_T c22_x;
  boolean_T c22_b_b;
  real_T c22_b_x;
  real_T c22_c_x;
  boolean_T c22_b0;
  boolean_T c22_b1;
  boolean_T guard1 = false;
  (void)chartInstance;
  c22_p = false;
  if (c22_a < 0.0) {
    c22_x = c22_b;
    c22_b_b = muDoubleScalarIsNaN(c22_x);
    guard1 = false;
    if (c22_b_b) {
      guard1 = true;
    } else {
      c22_b_x = c22_b;
      c22_c_x = c22_b_x;
      c22_c_x = muDoubleScalarFloor(c22_c_x);
      if (c22_c_x == c22_b) {
        guard1 = true;
      } else {
        c22_b0 = false;
      }
    }

    if (guard1 == true) {
      c22_b0 = true;
    }

    c22_b1 = !c22_b0;
    c22_p = c22_b1;
  }

  return c22_p;
}

static void c22_error(SFc22_MASsInstanceStruct *chartInstance)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c22_y));
}

static real_T c22_b_mpower(SFc22_MASsInstanceStruct *chartInstance, real_T c22_a)
{
  real_T c22_c;
  real_T c22_b_a;
  real_T c22_c_a;
  real_T c22_x;
  real_T c22_d_a;
  c22_b_a = c22_a;
  c22_c_a = c22_b_a;
  c22_x = c22_c_a;
  c22_d_a = c22_x;
  c22_c = c22_d_a;
  c22_b_sqrt(chartInstance, &c22_c);
  if (c22_fltpower_domain_error(chartInstance, c22_c_a, 0.5)) {
    c22_error(chartInstance);
  }

  return c22_c;
}

static real_T c22_sqrt(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x)
{
  real_T c22_b_x;
  c22_b_x = c22_x;
  c22_b_sqrt(chartInstance, &c22_b_x);
  return c22_b_x;
}

static void c22_b_error(SFc22_MASsInstanceStruct *chartInstance)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c22_b_y = NULL;
  static char_T c22_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c22_y, 14, c22_b_y));
}

static void c22_roots(SFc22_MASsInstanceStruct *chartInstance, real_T c22_c[4],
                      creal_T c22_r_data[], int32_T *c22_r_sizes)
{
  boolean_T c22_p;
  int32_T c22_k;
  int32_T c22_b_k;
  int32_T c22_i5;
  int32_T c22_k1;
  int32_T c22_a;
  int32_T c22_k2;
  int32_T c22_b_a;
  int32_T c22_b;
  int32_T c22_nTrailingZeros;
  int32_T c22_c_a;
  int32_T c22_b_b;
  int32_T c22_companDim;
  int32_T c22_j;
  int32_T c22_d_a;
  int32_T c22_c_b;
  int32_T c22_b_c;
  real_T c22_A;
  real_T c22_B;
  real_T c22_y;
  real_T c22_ctmp[4];
  real_T c22_x;
  boolean_T c22_d_b;
  int32_T c22_e_a;
  int32_T c22_f_a;
  int32_T c22_g_a;
  boolean_T c22_b2;
  boolean_T c22_b3;
  boolean_T c22_b4;
  int32_T c22_i6;
  int32_T c22_i7;
  int32_T c22_a_sizes[2];
  int32_T c22_h_a;
  int32_T c22_i_a;
  int32_T c22_loop_ub;
  int32_T c22_i8;
  creal_T c22_a_data[9];
  int32_T c22_j_a;
  int32_T c22_i9;
  int32_T c22_e_b;
  int32_T c22_f_b;
  boolean_T c22_overflow;
  int32_T c22_c_k;
  int32_T c22_d_k;
  int32_T c22_k_a;
  int32_T c22_c_c;
  static creal_T c22_dc0 = { 1.0, 0.0 };

  int32_T c22_b_nTrailingZeros;
  int32_T c22_g_b;
  int32_T c22_h_b;
  boolean_T c22_b_overflow;
  int32_T c22_e_k;
  static creal_T c22_dc1 = { 0.0, 0.0 };

  int32_T c22_b_a_sizes[2];
  int32_T c22_l_a;
  int32_T c22_m_a;
  int32_T c22_b_loop_ub;
  int32_T c22_i10;
  creal_T c22_b_a_data[9];
  int32_T c22_eiga_sizes;
  creal_T c22_eiga_data[3];
  int32_T c22_b_companDim;
  int32_T c22_i_b;
  int32_T c22_j_b;
  boolean_T c22_c_overflow;
  int32_T c22_f_k;
  int32_T c22_n_a;
  int32_T c22_k_b;
  int32_T c22_d_c;
  int32_T c22_o_a;
  int32_T c22_l_b;
  int32_T c22_nRoots;
  const mxArray *c22_b_y = NULL;
  static char_T c22_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  int32_T c22_i11;
  boolean_T c22_b5;
  boolean_T c22_b6;
  boolean_T c22_b7;
  int32_T c22_i12;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  c22_p = false;
  c22_k = 1;
  exitg5 = false;
  while ((exitg5 == false) && (c22_k < 5)) {
    c22_b_k = c22_k - 1;
    if (!c22_isfinite(chartInstance, c22_c[c22_b_k])) {
      c22_p = true;
      exitg5 = true;
    } else {
      c22_k++;
    }
  }

  if (c22_p) {
    c22_c_error(chartInstance);
  }

  *c22_r_sizes = 3;
  for (c22_i5 = 0; c22_i5 < 3; c22_i5++) {
    c22_r_data[c22_i5].re = 0.0;
    c22_r_data[c22_i5].im = 0.0;
  }

  c22_k1 = 1;
  exitg4 = false;
  while ((exitg4 == false) && (c22_k1 <= 4)) {
    if (c22_c[c22_k1 - 1] != 0.0) {
      exitg4 = true;
    } else {
      c22_a = c22_k1 + 1;
      c22_k1 = c22_a;
    }
  }

  c22_k2 = 4;
  exitg3 = false;
  while ((exitg3 == false) && (c22_k2 >= c22_k1)) {
    if (c22_c[c22_k2 - 1] != 0.0) {
      exitg3 = true;
    } else {
      c22_b_a = c22_k2 - 1;
      c22_k2 = c22_b_a;
    }
  }

  c22_b = c22_k2;
  c22_nTrailingZeros = 4 - c22_b;
  if (c22_k1 < c22_k2) {
    c22_c_a = c22_k2;
    c22_b_b = c22_k1;
    c22_companDim = c22_c_a - c22_b_b;
    exitg1 = false;
    while ((exitg1 == false) && (c22_companDim > 0)) {
      c22_j = 1;
      exitg2 = false;
      while ((exitg2 == false) && (c22_j <= c22_companDim)) {
        c22_d_a = c22_k1;
        c22_c_b = c22_j;
        c22_b_c = (c22_d_a + c22_c_b) - 1;
        c22_A = c22_c[c22_b_c];
        c22_B = c22_c[c22_k1 - 1];
        c22_y = c22_rdivide(chartInstance, c22_A, c22_B);
        c22_ctmp[c22_j - 1] = c22_y;
        c22_x = c22_abs(chartInstance, c22_ctmp[c22_j - 1]);
        c22_d_b = muDoubleScalarIsInf(c22_x);
        if (c22_d_b) {
          exitg2 = true;
        } else {
          c22_e_a = c22_j + 1;
          c22_j = c22_e_a;
        }
      }

      if (c22_j > c22_companDim) {
        exitg1 = true;
      } else {
        c22_f_a = c22_k1 + 1;
        c22_k1 = c22_f_a;
        c22_g_a = c22_companDim - 1;
        c22_companDim = c22_g_a;
      }
    }

    if (c22_companDim < 1) {
      c22_b2 = (1 > c22_nTrailingZeros);
      c22_b3 = c22_b2;
      c22_b4 = c22_b3;
      if (c22_b4) {
        c22_i6 = 0;
      } else {
        c22_i6 = c22_nTrailingZeros;
      }

      *c22_r_sizes = c22_i6;
    } else {
      c22_i7 = c22_companDim;
      c22_a_sizes[0] = c22_i7;
      c22_a_sizes[1] = c22_i7;
      c22_h_a = c22_a_sizes[0];
      c22_i_a = c22_a_sizes[1];
      c22_loop_ub = c22_i7 * c22_i7 - 1;
      for (c22_i8 = 0; c22_i8 <= c22_loop_ub; c22_i8++) {
        c22_a_data[c22_i8].re = 0.0;
        c22_a_data[c22_i8].im = 0.0;
      }

      c22_j_a = c22_companDim - 1;
      c22_i9 = c22_j_a;
      c22_e_b = c22_i9;
      c22_f_b = c22_e_b;
      if (1 > c22_f_b) {
        c22_overflow = false;
      } else {
        c22_overflow = (c22_f_b > 2147483646);
      }

      if (c22_overflow) {
        c22_check_forloop_overflow_error(chartInstance, true);
      }

      for (c22_c_k = 1; c22_c_k <= c22_i9; c22_c_k++) {
        c22_d_k = c22_c_k - 1;
        c22_a_data[c22_a_sizes[0] * c22_d_k].re = -c22_ctmp[c22_d_k];
        c22_a_data[c22_a_sizes[0] * c22_d_k].im = 0.0;
        c22_k_a = c22_d_k + 2;
        c22_c_c = c22_k_a - 1;
        c22_a_data[c22_c_c + c22_a_sizes[0] * c22_d_k] = c22_dc0;
      }

      c22_a_data[c22_a_sizes[0] * (c22_companDim - 1)].re =
        -c22_ctmp[c22_companDim - 1];
      c22_a_data[c22_a_sizes[0] * (c22_companDim - 1)].im = 0.0;
      c22_b_nTrailingZeros = c22_nTrailingZeros;
      c22_g_b = c22_b_nTrailingZeros;
      c22_h_b = c22_g_b;
      if (1 > c22_h_b) {
        c22_b_overflow = false;
      } else {
        c22_b_overflow = (c22_h_b > 2147483646);
      }

      if (c22_b_overflow) {
        c22_check_forloop_overflow_error(chartInstance, true);
      }

      for (c22_e_k = 1; c22_e_k <= c22_b_nTrailingZeros; c22_e_k++) {
        c22_d_k = c22_e_k - 1;
        c22_r_data[c22_d_k] = c22_dc1;
      }

      c22_b_a_sizes[0] = c22_a_sizes[0];
      c22_b_a_sizes[1] = c22_a_sizes[1];
      c22_l_a = c22_b_a_sizes[0];
      c22_m_a = c22_b_a_sizes[1];
      c22_b_loop_ub = c22_a_sizes[0] * c22_a_sizes[1] - 1;
      for (c22_i10 = 0; c22_i10 <= c22_b_loop_ub; c22_i10++) {
        c22_b_a_data[c22_i10] = c22_a_data[c22_i10];
      }

      c22_eig(chartInstance, c22_b_a_data, c22_b_a_sizes, c22_eiga_data,
              &c22_eiga_sizes);
      c22_b_companDim = c22_companDim;
      c22_i_b = c22_b_companDim;
      c22_j_b = c22_i_b;
      if (1 > c22_j_b) {
        c22_c_overflow = false;
      } else {
        c22_c_overflow = (c22_j_b > 2147483646);
      }

      if (c22_c_overflow) {
        c22_check_forloop_overflow_error(chartInstance, true);
      }

      for (c22_f_k = 1; c22_f_k <= c22_b_companDim; c22_f_k++) {
        c22_d_k = c22_f_k;
        c22_n_a = c22_d_k;
        c22_k_b = c22_nTrailingZeros;
        c22_d_c = (c22_n_a + c22_k_b) - 1;
        c22_r_data[c22_d_c] = c22_eiga_data[c22_d_k - 1];
      }

      c22_o_a = c22_nTrailingZeros;
      c22_l_b = c22_companDim;
      c22_nRoots = c22_o_a + c22_l_b;
      if (c22_nRoots <= 4) {
      } else {
        c22_b_y = NULL;
        sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c22_b_y));
      }

      c22_i11 = c22_nRoots;
      *c22_r_sizes = c22_i11;
    }
  } else {
    c22_b5 = (1 > c22_nTrailingZeros);
    c22_b6 = c22_b5;
    c22_b7 = c22_b6;
    if (c22_b7) {
      c22_i12 = 0;
    } else {
      c22_i12 = c22_nTrailingZeros;
    }

    *c22_r_sizes = c22_i12;
  }
}

static boolean_T c22_isfinite(SFc22_MASsInstanceStruct *chartInstance, real_T
  c22_x)
{
  real_T c22_b_x;
  boolean_T c22_b_b;
  boolean_T c22_b8;
  real_T c22_c_x;
  boolean_T c22_c_b;
  boolean_T c22_b9;
  (void)chartInstance;
  c22_b_x = c22_x;
  c22_b_b = muDoubleScalarIsInf(c22_b_x);
  c22_b8 = !c22_b_b;
  c22_c_x = c22_x;
  c22_c_b = muDoubleScalarIsNaN(c22_c_x);
  c22_b9 = !c22_c_b;
  return c22_b8 && c22_b9;
}

static void c22_c_error(SFc22_MASsInstanceStruct *chartInstance)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'o', 'o',
    't', 's', ':', 'N', 'o', 'n', 'F', 'i', 'n', 'i', 't', 'e', 'I', 'n', 'p',
    'u', 't' };

  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c22_y));
}

static real_T c22_abs(SFc22_MASsInstanceStruct *chartInstance, real_T c22_x)
{
  real_T c22_b_x;
  real_T c22_c_x;
  (void)chartInstance;
  c22_b_x = c22_x;
  c22_c_x = c22_b_x;
  return muDoubleScalarAbs(c22_c_x);
}

static void c22_check_forloop_overflow_error(SFc22_MASsInstanceStruct
  *chartInstance, boolean_T c22_overflow)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c22_b_y = NULL;
  static char_T c22_c_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c22_overflow;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c22_y, 14, c22_b_y));
}

static void c22_eig(SFc22_MASsInstanceStruct *chartInstance, creal_T c22_A_data[],
                    int32_T c22_A_sizes[2], creal_T c22_V_data[], int32_T
                    *c22_V_sizes)
{
  static creal_T c22_dc2 = { 0.0, 0.0 };

  int32_T c22_lda;
  int32_T c22_b_n;
  int32_T c22_b_A_sizes[2];
  int32_T c22_A;
  int32_T c22_b_A;
  int32_T c22_loop_ub;
  int32_T c22_i13;
  creal_T c22_b_A_data[9];
  ptrdiff_t c22_ldvl_t;
  ptrdiff_t c22_ldvr_t;
  ptrdiff_t c22_n_t;
  ptrdiff_t c22_lda_t;
  creal_T c22_vr;
  creal_T c22_vl;
  ptrdiff_t c22_info_t;
  int32_T c22_info;
  int32_T c22_b_info;
  int32_T c22_c_info;
  boolean_T c22_p;
  boolean_T c22_b_p;
  int32_T c22_V;
  int32_T c22_b_loop_ub;
  int32_T c22_i14;
  int32_T c22_d_info;
  int32_T c22_e_info;
  c22_dc2.re = rtNaN;
  c22_lda = c22_A_sizes[0];
  c22_b_n = c22_A_sizes[1];
  c22_b_A_sizes[0] = c22_A_sizes[0];
  c22_b_A_sizes[1] = c22_A_sizes[1];
  c22_A = c22_b_A_sizes[0];
  c22_b_A = c22_b_A_sizes[1];
  c22_loop_ub = c22_A_sizes[0] * c22_A_sizes[1] - 1;
  for (c22_i13 = 0; c22_i13 <= c22_loop_ub; c22_i13++) {
    c22_b_A_data[c22_i13] = c22_A_data[c22_i13];
  }

  c22_ldvl_t = (ptrdiff_t)1;
  c22_ldvr_t = (ptrdiff_t)1;
  c22_n_t = (ptrdiff_t)c22_b_n;
  c22_lda_t = (ptrdiff_t)c22_lda;
  *c22_V_sizes = c22_b_n;
  c22_info_t = LAPACKE_zgeev(102, 'N', 'N', c22_n_t, (lapack_complex_double *)
    &c22_b_A_data[0], c22_lda_t, (lapack_complex_double *)&c22_V_data[0],
    (lapack_complex_double *)&c22_vl, c22_ldvl_t, (lapack_complex_double *)
    &c22_vr, c22_ldvr_t);
  c22_info = (int32_T)c22_info_t;
  c22_b_info = c22_info;
  c22_c_info = c22_b_info;
  c22_p = (c22_c_info < 0);
  if (c22_p) {
    if (c22_b_info == -1010) {
      c22_d_error(chartInstance);
    } else {
      c22_e_error(chartInstance, c22_b_info);
    }

    c22_b_p = true;
  } else {
    c22_b_p = false;
  }

  if (c22_b_p) {
    c22_V = *c22_V_sizes;
    *c22_V_sizes = c22_V;
    c22_b_loop_ub = c22_V - 1;
    for (c22_i14 = 0; c22_i14 <= c22_b_loop_ub; c22_i14++) {
      c22_V_data[c22_i14] = c22_dc2;
    }
  }

  c22_d_info = c22_info;
  c22_e_info = c22_d_info;
  if ((real_T)c22_e_info != 0.0) {
    c22_warning(chartInstance);
  }
}

static void c22_d_error(SFc22_MASsInstanceStruct *chartInstance)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c22_y));
}

static void c22_e_error(SFc22_MASsInstanceStruct *chartInstance, int32_T
  c22_varargin_2)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c22_b_y = NULL;
  static char_T c22_c_u[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g',
    'e', 'e', 'v' };

  int32_T c22_d_u;
  const mxArray *c22_c_y = NULL;
  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_c_u, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  c22_d_u = c22_varargin_2;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c22_y, 14, c22_b_y, 14, c22_c_y));
}

static void c22_warning(SFc22_MASsInstanceStruct *chartInstance)
{
  const mxArray *c22_y = NULL;
  static char_T c22_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c22_b_y = NULL;
  static char_T c22_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c22_c_y = NULL;
  static char_T c22_msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", c22_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c22_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c22_b_y, 14, c22_c_y));
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_b_u;
  const mxArray *c22_y = NULL;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_b_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_d_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i15;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_b_u), &c22_i15, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i15;
  sf_mex_destroy(&c22_b_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_thisId.bParentIsCell = false;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_is_active_c22_MASs, const char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_thisId.bParentIsCell = false;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_MASs), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_MASs);
  return c22_y;
}

static uint8_T c22_f_emlrt_marshallIn(SFc22_MASsInstanceStruct *chartInstance,
  const mxArray *c22_b_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_b_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_b_u);
  return c22_y;
}

static void c22_b_sqrt(SFc22_MASsInstanceStruct *chartInstance, real_T *c22_x)
{
  real_T c22_b_x;
  boolean_T c22_b10;
  boolean_T c22_p;
  c22_b_x = *c22_x;
  c22_b10 = (c22_b_x < 0.0);
  c22_p = c22_b10;
  if (c22_p) {
    c22_b_error(chartInstance);
  }

  *c22_x = muDoubleScalarSqrt(*c22_x);
}

static void init_dsm_address_info(SFc22_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc22_MASsInstanceStruct *chartInstance)
{
  chartInstance->c22_n = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c22_Xp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_sita = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_Yp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c22_Np = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c22_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c22_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c22_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4080151286U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1653495989U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1402088011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3534870435U);
}

mxArray* sf_c22_MASs_get_post_codegen_info(void);
mxArray *sf_c22_MASs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("S7gGSFTXzXNRQ3ZUCmf5FC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c22_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c22_MASs_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c22_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c22_MASs_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c22_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Np\",},{M[1],M[5],T\"Xp\",},{M[1],M[8],T\"Yp\",},{M[8],M[0],T\"is_active_c22_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_MASsInstanceStruct *chartInstance = (SFc22_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           22,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_MASsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_MASsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _MASsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"n");
          _SFD_SET_DATA_PROPS(1,1,1,0,"sita");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u");
          _SFD_SET_DATA_PROPS(3,1,1,0,"v");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Xp");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Yp");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Np");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1003);
        _SFD_CV_INIT_EML_IF(0,1,0,861,885,-1,918);
        _SFD_CV_INIT_EML_FOR(0,1,0,839,857,922);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,864,885,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _MASsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_MASsInstanceStruct *chartInstance = (SFc22_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c22_n);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c22_Xp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c22_sita);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c22_Yp);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c22_Np);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c22_u);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c22_v);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVnreL6srNnvOymngDFKm9D";
}

static void sf_opaque_initialize_c22_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
  initialize_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c22_MASs(void *chartInstanceVar)
{
  enable_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c22_MASs(void *chartInstanceVar)
{
  disable_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c22_MASs(void *chartInstanceVar)
{
  sf_gateway_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c22_MASs(SimStruct* S)
{
  return get_sim_state_c22_MASs((SFc22_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c22_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c22_MASs((SFc22_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c22_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_MASs((SFc22_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_MASs((SFc22_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c22_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 22);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(900581958U));
  ssSetChecksum1(S,(1917346770U));
  ssSetChecksum2(S,(2379783741U));
  ssSetChecksum3(S,(3711375616U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_MASs(SimStruct *S)
{
  SFc22_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc22_MASsInstanceStruct *)utMalloc(sizeof
    (SFc22_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc22_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c22_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c22_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c22_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c22_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c22_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c22_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c22_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c22_MASs;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c22_MASs(chartInstance);
}

void c22_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
