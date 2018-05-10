/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c15_MASs.h"
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
static const char * c15_debug_family_names[30] = { "Q", "A", "beita", "C", "g",
  "np", "Aj", "Ain", "Aw", "Ein", "En", "E0", "h", "Xt", "Vs", "p", "q", "r",
  "V", "Vj", "i", "nargin", "nargout", "n", "sita", "u", "v", "Xp", "Yp", "Np" };

/* Function Declarations */
static void initialize_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void initialize_params_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void enable_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void disable_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_MASs(SFc15_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c15_MASs(SFc15_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c15_MASs(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_st);
static void finalize_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void sf_gateway_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void mdl_start_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void c15_chartstep_c15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void initSimStructsc15_MASs(SFc15_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_Np, const char_T *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c15_inData_data[], int32_T *c15_inData_sizes);
static void c15_c_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId, creal_T
  c15_y_data[], int32_T *c15_y_sizes);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, creal_T c15_outData_data[],
  int32_T *c15_outData_sizes);
static real_T c15_rdivide(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x,
  real_T c15_y);
static real_T c15_mpower(SFc15_MASsInstanceStruct *chartInstance, real_T c15_a);
static void c15_scalarEg(SFc15_MASsInstanceStruct *chartInstance);
static void c15_dimagree(SFc15_MASsInstanceStruct *chartInstance);
static boolean_T c15_fltpower_domain_error(SFc15_MASsInstanceStruct
  *chartInstance, real_T c15_a, real_T c15_b);
static void c15_error(SFc15_MASsInstanceStruct *chartInstance);
static real_T c15_b_mpower(SFc15_MASsInstanceStruct *chartInstance, real_T c15_a);
static real_T c15_sqrt(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x);
static void c15_b_error(SFc15_MASsInstanceStruct *chartInstance);
static void c15_roots(SFc15_MASsInstanceStruct *chartInstance, real_T c15_c[4],
                      creal_T c15_r_data[], int32_T *c15_r_sizes);
static boolean_T c15_isfinite(SFc15_MASsInstanceStruct *chartInstance, real_T
  c15_x);
static void c15_c_error(SFc15_MASsInstanceStruct *chartInstance);
static real_T c15_abs(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x);
static void c15_check_forloop_overflow_error(SFc15_MASsInstanceStruct
  *chartInstance, boolean_T c15_overflow);
static void c15_eig(SFc15_MASsInstanceStruct *chartInstance, creal_T c15_A_data[],
                    int32_T c15_A_sizes[2], creal_T c15_V_data[], int32_T
                    *c15_V_sizes);
static void c15_d_error(SFc15_MASsInstanceStruct *chartInstance);
static void c15_e_error(SFc15_MASsInstanceStruct *chartInstance, int32_T
  c15_varargin_2);
static void c15_warning(SFc15_MASsInstanceStruct *chartInstance);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_e_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_is_active_c15_MASs, const char_T *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sqrt(SFc15_MASsInstanceStruct *chartInstance, real_T *c15_x);
static void init_dsm_address_info(SFc15_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc15_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc15_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_MASs = 0U;
}

static void initialize_params_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_MASs(SFc15_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_MASs(SFc15_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_b_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_c_hoistedGlobal;
  real_T c15_d_u;
  const mxArray *c15_d_y = NULL;
  uint8_T c15_d_hoistedGlobal;
  uint8_T c15_e_u;
  const mxArray *c15_e_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(4, 1), false);
  c15_hoistedGlobal = *chartInstance->c15_Np;
  c15_b_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = *chartInstance->c15_Xp;
  c15_c_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_c_hoistedGlobal = *chartInstance->c15_Yp;
  c15_d_u = c15_c_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  c15_d_hoistedGlobal = chartInstance->c15_is_active_c15_MASs;
  c15_e_u = c15_d_hoistedGlobal;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c15_y, 3, c15_e_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_MASs(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_st)
{
  const mxArray *c15_b_u;
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_b_u = sf_mex_dup(c15_st);
  *chartInstance->c15_Np = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Np", c15_b_u, 0)), "Np");
  *chartInstance->c15_Xp = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xp", c15_b_u, 1)), "Xp");
  *chartInstance->c15_Yp = c15_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Yp", c15_b_u, 2)), "Yp");
  chartInstance->c15_is_active_c15_MASs = c15_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c15_MASs", c15_b_u, 3)),
    "is_active_c15_MASs");
  sf_mex_destroy(&c15_b_u);
  c15_update_debugger_state_c15_MASs(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_v, 3U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_u, 2U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_sita, 1U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_n, 0U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Xp, 4U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Yp, 5U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_Np, 6U, 1U, 0U,
                        chartInstance->c15_sfEvent, false);
}

static void mdl_start_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c15_chartstep_c15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_hoistedGlobal;
  real_T c15_d_hoistedGlobal;
  real_T c15_b_n;
  real_T c15_b_sita;
  real_T c15_b_u;
  real_T c15_b_v;
  uint32_T c15_debug_family_var_map[30];
  real_T c15_Q;
  real_T c15_A;
  real_T c15_beita;
  real_T c15_C;
  real_T c15_g;
  real_T c15_np;
  real_T c15_Aj;
  real_T c15_Ain;
  real_T c15_Aw;
  real_T c15_Ein;
  real_T c15_En;
  real_T c15_E0;
  real_T c15_h;
  real_T c15_Xt;
  real_T c15_Vs;
  real_T c15_p;
  real_T c15_q;
  real_T c15_r;
  int32_T c15_V_sizes;
  creal_T c15_V_data[3];
  real_T c15_Vj;
  real_T c15_i;
  real_T c15_nargin = 4.0;
  real_T c15_nargout = 3.0;
  real_T c15_b_Xp;
  real_T c15_b_Yp;
  real_T c15_b_Np;
  real_T c15_b_A;
  real_T c15_c_A;
  real_T c15_y;
  real_T c15_d_A;
  real_T c15_b_y;
  real_T c15_a;
  real_T c15_b_a;
  real_T c15_c_a;
  real_T c15_x;
  real_T c15_d_a;
  real_T c15_ar;
  real_T c15_c;
  real_T c15_dv0[4];
  int32_T c15_tmp_sizes;
  creal_T c15_tmp_data[3];
  int32_T c15_loop_ub;
  int32_T c15_i0;
  real_T c15_d0;
  int32_T c15_i1;
  int32_T c15_b_i;
  real_T c15_d1;
  real_T c15_b_x;
  real_T c15_c_x;
  real_T c15_d_x;
  real_T c15_e_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = *chartInstance->c15_n;
  c15_b_hoistedGlobal = *chartInstance->c15_sita;
  c15_c_hoistedGlobal = *chartInstance->c15_u;
  c15_d_hoistedGlobal = *chartInstance->c15_v;
  c15_b_n = c15_hoistedGlobal;
  c15_b_sita = c15_b_hoistedGlobal;
  c15_b_u = c15_c_hoistedGlobal;
  c15_b_v = c15_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Q, 0U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_A, 1U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_beita, 2U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_C, 3U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_g, 4U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_np, 5U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Aj, 6U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Ain, 7U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Aw, 8U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Ein, 9U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_En, 10U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_E0, 11U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_h, 12U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Xt, 13U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Vs, 14U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_p, 15U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_q, 16U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_r, 17U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c15_V_data, (const int32_T *)
    &c15_V_sizes, NULL, 0, 18, (void *)c15_b_sf_marshallOut, (void *)
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Vj, 19U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_i, 20U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 21U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 22U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_n, 23U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_sita, 24U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_u, 25U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_b_v, 26U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Xp, 27U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Yp, 28U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_Np, 29U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 3);
  c15_Q = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  c15_A = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 5);
  c15_beita = 0.9025;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 6);
  c15_C = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_np = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
  c15_Aj = 0.049087385212340517;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 10);
  c15_Ain = 0.83200000000000007;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 11);
  c15_Aw = 0.78539816339744828;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
  c15_Ein = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  c15_En = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  c15_E0 = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_h = 0.6;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
  c15_Xt = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
  c15_b_A = c15_b_sita * 3.1415926535897931;
  c15_b_sita = c15_rdivide(chartInstance, c15_b_A, 180.0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 20);
  c15_Vs = c15_b_mpower(chartInstance, c15_mpower(chartInstance, c15_b_u) +
                        c15_mpower(chartInstance, c15_b_v));
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 22);
  c15_p = 25.036379540825354;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 23);
  c15_c_A = 0.9025 * c15_mpower(chartInstance, c15_Vs);
  c15_y = c15_rdivide(chartInstance, c15_c_A, 19.6);
  c15_q = 481.05637508093707 * (0.6 - c15_y);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 24);
  c15_d_A = c15_b_n;
  c15_b_y = c15_rdivide(chartInstance, c15_d_A, 1000.0);
  c15_a = c15_b_y;
  c15_b_a = c15_a;
  c15_c_a = c15_b_a;
  c15_x = c15_c_a;
  c15_d_a = c15_x;
  c15_ar = c15_d_a;
  c15_c = muDoubleScalarPower(c15_ar, 3.0);
  if (c15_fltpower_domain_error(chartInstance, c15_c_a, 3.0)) {
    c15_error(chartInstance);
  }

  c15_r = -10.0 * c15_c * 0.8;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 29);
  c15_dv0[0] = 25.036379540825354;
  c15_dv0[1] = 0.0;
  c15_dv0[2] = c15_q;
  c15_dv0[3] = c15_r;
  c15_roots(chartInstance, c15_dv0, c15_tmp_data, &c15_tmp_sizes);
  c15_V_sizes = c15_tmp_sizes;
  c15_loop_ub = c15_tmp_sizes - 1;
  for (c15_i0 = 0; c15_i0 <= c15_loop_ub; c15_i0++) {
    c15_V_data[c15_i0] = c15_tmp_data[c15_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 30);
  c15_Vj = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 32);
  c15_d0 = (real_T)c15_V_sizes;
  c15_i1 = (int32_T)c15_d0 - 1;
  c15_i = 1.0;
  c15_b_i = 0;
  while (c15_b_i <= c15_i1) {
    c15_i = 1.0 + (real_T)c15_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 33);
    if (c15_fltpower_domain_error(chartInstance, 10.0, -10.0)) {
      c15_error(chartInstance);
    }

    c15_d1 = c15_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 869, 4, MAX_uint32_T, (int32_T)c15_i, 1, c15_V_sizes)
      - 1].im;
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c15_d1, 1.0E-10, -1, 2U,
          c15_d1 < 1.0E-10))) {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 34);
      c15_Vj = c15_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 904, 4, MAX_uint32_T, (int32_T)c15_i, 1,
        c15_V_sizes) - 1].re;
    }

    c15_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 37);
  c15_b_x = c15_b_sita;
  c15_c_x = c15_b_x;
  c15_c_x = muDoubleScalarCos(c15_c_x);
  c15_b_Xp = 49.087385212340514 * c15_Vj * (c15_Vj - 0.95 * c15_Vs) * c15_c_x;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 38);
  c15_d_x = c15_b_sita;
  c15_e_x = c15_d_x;
  c15_e_x = muDoubleScalarSin(c15_e_x);
  c15_b_Yp = 49.087385212340514 * c15_Vj * (c15_Vj - 0.95 * c15_Vs) * c15_e_x;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 39);
  c15_b_Np = c15_b_Yp * 3.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c15_Xp = c15_b_Xp;
  *chartInstance->c15_Yp = c15_b_Yp;
  *chartInstance->c15_Np = c15_b_Np;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_MASs(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)c15_machineNumber;
  (void)c15_chartNumber;
  (void)c15_instanceNumber;
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_b_u;
  const mxArray *c15_y = NULL;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_b_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_Np, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Np),
    &c15_thisId);
  sf_mex_destroy(&c15_b_Np);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d2;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_d2, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d2;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_Np;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_b_Np = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_Np),
    &c15_thisId);
  sf_mex_destroy(&c15_b_Np);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c15_inData_data[], int32_T *c15_inData_sizes)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u_sizes;
  int32_T c15_loop_ub;
  int32_T c15_i2;
  creal_T c15_u_data[3];
  const mxArray *c15_y = NULL;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u_sizes = *c15_inData_sizes;
  c15_loop_ub = *c15_inData_sizes - 1;
  for (c15_i2 = 0; c15_i2 <= c15_loop_ub; c15_i2++) {
    c15_u_data[c15_i2] = c15_inData_data[c15_i2];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u_data, 0, 1U, 1U, 0U, 1,
    c15_u_sizes), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId, creal_T
  c15_y_data[], int32_T *c15_y_sizes)
{
  static uint32_T c15_uv0[1] = { 3U };

  uint32_T c15_uv1[1];
  static boolean_T c15_bv0[1] = { true };

  boolean_T c15_bv1[1];
  int32_T c15_tmp_sizes;
  creal_T c15_tmp_data[3];
  int32_T c15_loop_ub;
  int32_T c15_i3;
  (void)chartInstance;
  c15_uv1[0] = c15_uv0[0];
  c15_bv1[0] = c15_bv0[0];
  sf_mex_import_vs(c15_parentId, sf_mex_dup(c15_b_u), c15_tmp_data, 1, 0, 1U, 1,
                   0U, 1, c15_bv1, c15_uv1, &c15_tmp_sizes);
  *c15_y_sizes = c15_tmp_sizes;
  c15_loop_ub = c15_tmp_sizes - 1;
  for (c15_i3 = 0; c15_i3 <= c15_loop_ub; c15_i3++) {
    c15_y_data[c15_i3] = c15_tmp_data[c15_i3];
  }

  sf_mex_destroy(&c15_b_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, creal_T c15_outData_data[],
  int32_T *c15_outData_sizes)
{
  const mxArray *c15_V;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y_sizes;
  creal_T c15_y_data[3];
  int32_T c15_loop_ub;
  int32_T c15_i4;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_V = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_V), &c15_thisId,
    c15_y_data, &c15_y_sizes);
  sf_mex_destroy(&c15_V);
  *c15_outData_sizes = c15_y_sizes;
  c15_loop_ub = c15_y_sizes - 1;
  for (c15_i4 = 0; c15_i4 <= c15_loop_ub; c15_i4++) {
    c15_outData_data[c15_i4] = c15_y_data[c15_i4];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c15_nameCaptureInfo;
}

static real_T c15_rdivide(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x,
  real_T c15_y)
{
  real_T c15_b_x;
  real_T c15_b_y;
  (void)chartInstance;
  c15_b_x = c15_x;
  c15_b_y = c15_y;
  return c15_b_x / c15_b_y;
}

static real_T c15_mpower(SFc15_MASsInstanceStruct *chartInstance, real_T c15_a)
{
  real_T c15_c;
  real_T c15_b_a;
  real_T c15_c_a;
  real_T c15_x;
  real_T c15_d_a;
  c15_b_a = c15_a;
  c15_c_a = c15_b_a;
  c15_x = c15_c_a;
  c15_d_a = c15_x;
  c15_c = c15_d_a * c15_d_a;
  if (c15_fltpower_domain_error(chartInstance, c15_c_a, 2.0)) {
    c15_error(chartInstance);
  }

  return c15_c;
}

static void c15_scalarEg(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c15_dimagree(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c15_fltpower_domain_error(SFc15_MASsInstanceStruct
  *chartInstance, real_T c15_a, real_T c15_b)
{
  boolean_T c15_p;
  real_T c15_x;
  boolean_T c15_b_b;
  real_T c15_b_x;
  real_T c15_c_x;
  boolean_T c15_b0;
  boolean_T c15_b1;
  boolean_T guard1 = false;
  (void)chartInstance;
  c15_p = false;
  if (c15_a < 0.0) {
    c15_x = c15_b;
    c15_b_b = muDoubleScalarIsNaN(c15_x);
    guard1 = false;
    if (c15_b_b) {
      guard1 = true;
    } else {
      c15_b_x = c15_b;
      c15_c_x = c15_b_x;
      c15_c_x = muDoubleScalarFloor(c15_c_x);
      if (c15_c_x == c15_b) {
        guard1 = true;
      } else {
        c15_b0 = false;
      }
    }

    if (guard1 == true) {
      c15_b0 = true;
    }

    c15_b1 = !c15_b0;
    c15_p = c15_b1;
  }

  return c15_p;
}

static void c15_error(SFc15_MASsInstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_y));
}

static real_T c15_b_mpower(SFc15_MASsInstanceStruct *chartInstance, real_T c15_a)
{
  real_T c15_c;
  real_T c15_b_a;
  real_T c15_c_a;
  real_T c15_x;
  real_T c15_d_a;
  c15_b_a = c15_a;
  c15_c_a = c15_b_a;
  c15_x = c15_c_a;
  c15_d_a = c15_x;
  c15_c = c15_d_a;
  c15_b_sqrt(chartInstance, &c15_c);
  if (c15_fltpower_domain_error(chartInstance, c15_c_a, 0.5)) {
    c15_error(chartInstance);
  }

  return c15_c;
}

static real_T c15_sqrt(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x)
{
  real_T c15_b_x;
  c15_b_x = c15_x;
  c15_b_sqrt(chartInstance, &c15_b_x);
  return c15_b_x;
}

static void c15_b_error(SFc15_MASsInstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c15_b_y = NULL;
  static char_T c15_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c15_y, 14, c15_b_y));
}

static void c15_roots(SFc15_MASsInstanceStruct *chartInstance, real_T c15_c[4],
                      creal_T c15_r_data[], int32_T *c15_r_sizes)
{
  boolean_T c15_p;
  int32_T c15_k;
  int32_T c15_b_k;
  int32_T c15_i5;
  int32_T c15_k1;
  int32_T c15_a;
  int32_T c15_k2;
  int32_T c15_b_a;
  int32_T c15_b;
  int32_T c15_nTrailingZeros;
  int32_T c15_c_a;
  int32_T c15_b_b;
  int32_T c15_companDim;
  int32_T c15_j;
  int32_T c15_d_a;
  int32_T c15_c_b;
  int32_T c15_b_c;
  real_T c15_A;
  real_T c15_B;
  real_T c15_y;
  real_T c15_ctmp[4];
  real_T c15_x;
  boolean_T c15_d_b;
  int32_T c15_e_a;
  int32_T c15_f_a;
  int32_T c15_g_a;
  boolean_T c15_b2;
  boolean_T c15_b3;
  boolean_T c15_b4;
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_a_sizes[2];
  int32_T c15_h_a;
  int32_T c15_i_a;
  int32_T c15_loop_ub;
  int32_T c15_i8;
  creal_T c15_a_data[9];
  int32_T c15_j_a;
  int32_T c15_i9;
  int32_T c15_e_b;
  int32_T c15_f_b;
  boolean_T c15_overflow;
  int32_T c15_c_k;
  int32_T c15_d_k;
  int32_T c15_k_a;
  int32_T c15_c_c;
  static creal_T c15_dc0 = { 1.0, 0.0 };

  int32_T c15_b_nTrailingZeros;
  int32_T c15_g_b;
  int32_T c15_h_b;
  boolean_T c15_b_overflow;
  int32_T c15_e_k;
  static creal_T c15_dc1 = { 0.0, 0.0 };

  int32_T c15_b_a_sizes[2];
  int32_T c15_l_a;
  int32_T c15_m_a;
  int32_T c15_b_loop_ub;
  int32_T c15_i10;
  creal_T c15_b_a_data[9];
  int32_T c15_eiga_sizes;
  creal_T c15_eiga_data[3];
  int32_T c15_b_companDim;
  int32_T c15_i_b;
  int32_T c15_j_b;
  boolean_T c15_c_overflow;
  int32_T c15_f_k;
  int32_T c15_n_a;
  int32_T c15_k_b;
  int32_T c15_d_c;
  int32_T c15_o_a;
  int32_T c15_l_b;
  int32_T c15_nRoots;
  const mxArray *c15_b_y = NULL;
  static char_T c15_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  int32_T c15_i11;
  boolean_T c15_b5;
  boolean_T c15_b6;
  boolean_T c15_b7;
  int32_T c15_i12;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  c15_p = false;
  c15_k = 1;
  exitg5 = false;
  while ((exitg5 == false) && (c15_k < 5)) {
    c15_b_k = c15_k - 1;
    if (!c15_isfinite(chartInstance, c15_c[c15_b_k])) {
      c15_p = true;
      exitg5 = true;
    } else {
      c15_k++;
    }
  }

  if (c15_p) {
    c15_c_error(chartInstance);
  }

  *c15_r_sizes = 3;
  for (c15_i5 = 0; c15_i5 < 3; c15_i5++) {
    c15_r_data[c15_i5].re = 0.0;
    c15_r_data[c15_i5].im = 0.0;
  }

  c15_k1 = 1;
  exitg4 = false;
  while ((exitg4 == false) && (c15_k1 <= 4)) {
    if (c15_c[c15_k1 - 1] != 0.0) {
      exitg4 = true;
    } else {
      c15_a = c15_k1 + 1;
      c15_k1 = c15_a;
    }
  }

  c15_k2 = 4;
  exitg3 = false;
  while ((exitg3 == false) && (c15_k2 >= c15_k1)) {
    if (c15_c[c15_k2 - 1] != 0.0) {
      exitg3 = true;
    } else {
      c15_b_a = c15_k2 - 1;
      c15_k2 = c15_b_a;
    }
  }

  c15_b = c15_k2;
  c15_nTrailingZeros = 4 - c15_b;
  if (c15_k1 < c15_k2) {
    c15_c_a = c15_k2;
    c15_b_b = c15_k1;
    c15_companDim = c15_c_a - c15_b_b;
    exitg1 = false;
    while ((exitg1 == false) && (c15_companDim > 0)) {
      c15_j = 1;
      exitg2 = false;
      while ((exitg2 == false) && (c15_j <= c15_companDim)) {
        c15_d_a = c15_k1;
        c15_c_b = c15_j;
        c15_b_c = (c15_d_a + c15_c_b) - 1;
        c15_A = c15_c[c15_b_c];
        c15_B = c15_c[c15_k1 - 1];
        c15_y = c15_rdivide(chartInstance, c15_A, c15_B);
        c15_ctmp[c15_j - 1] = c15_y;
        c15_x = c15_abs(chartInstance, c15_ctmp[c15_j - 1]);
        c15_d_b = muDoubleScalarIsInf(c15_x);
        if (c15_d_b) {
          exitg2 = true;
        } else {
          c15_e_a = c15_j + 1;
          c15_j = c15_e_a;
        }
      }

      if (c15_j > c15_companDim) {
        exitg1 = true;
      } else {
        c15_f_a = c15_k1 + 1;
        c15_k1 = c15_f_a;
        c15_g_a = c15_companDim - 1;
        c15_companDim = c15_g_a;
      }
    }

    if (c15_companDim < 1) {
      c15_b2 = (1 > c15_nTrailingZeros);
      c15_b3 = c15_b2;
      c15_b4 = c15_b3;
      if (c15_b4) {
        c15_i6 = 0;
      } else {
        c15_i6 = c15_nTrailingZeros;
      }

      *c15_r_sizes = c15_i6;
    } else {
      c15_i7 = c15_companDim;
      c15_a_sizes[0] = c15_i7;
      c15_a_sizes[1] = c15_i7;
      c15_h_a = c15_a_sizes[0];
      c15_i_a = c15_a_sizes[1];
      c15_loop_ub = c15_i7 * c15_i7 - 1;
      for (c15_i8 = 0; c15_i8 <= c15_loop_ub; c15_i8++) {
        c15_a_data[c15_i8].re = 0.0;
        c15_a_data[c15_i8].im = 0.0;
      }

      c15_j_a = c15_companDim - 1;
      c15_i9 = c15_j_a;
      c15_e_b = c15_i9;
      c15_f_b = c15_e_b;
      if (1 > c15_f_b) {
        c15_overflow = false;
      } else {
        c15_overflow = (c15_f_b > 2147483646);
      }

      if (c15_overflow) {
        c15_check_forloop_overflow_error(chartInstance, true);
      }

      for (c15_c_k = 1; c15_c_k <= c15_i9; c15_c_k++) {
        c15_d_k = c15_c_k - 1;
        c15_a_data[c15_a_sizes[0] * c15_d_k].re = -c15_ctmp[c15_d_k];
        c15_a_data[c15_a_sizes[0] * c15_d_k].im = 0.0;
        c15_k_a = c15_d_k + 2;
        c15_c_c = c15_k_a - 1;
        c15_a_data[c15_c_c + c15_a_sizes[0] * c15_d_k] = c15_dc0;
      }

      c15_a_data[c15_a_sizes[0] * (c15_companDim - 1)].re =
        -c15_ctmp[c15_companDim - 1];
      c15_a_data[c15_a_sizes[0] * (c15_companDim - 1)].im = 0.0;
      c15_b_nTrailingZeros = c15_nTrailingZeros;
      c15_g_b = c15_b_nTrailingZeros;
      c15_h_b = c15_g_b;
      if (1 > c15_h_b) {
        c15_b_overflow = false;
      } else {
        c15_b_overflow = (c15_h_b > 2147483646);
      }

      if (c15_b_overflow) {
        c15_check_forloop_overflow_error(chartInstance, true);
      }

      for (c15_e_k = 1; c15_e_k <= c15_b_nTrailingZeros; c15_e_k++) {
        c15_d_k = c15_e_k - 1;
        c15_r_data[c15_d_k] = c15_dc1;
      }

      c15_b_a_sizes[0] = c15_a_sizes[0];
      c15_b_a_sizes[1] = c15_a_sizes[1];
      c15_l_a = c15_b_a_sizes[0];
      c15_m_a = c15_b_a_sizes[1];
      c15_b_loop_ub = c15_a_sizes[0] * c15_a_sizes[1] - 1;
      for (c15_i10 = 0; c15_i10 <= c15_b_loop_ub; c15_i10++) {
        c15_b_a_data[c15_i10] = c15_a_data[c15_i10];
      }

      c15_eig(chartInstance, c15_b_a_data, c15_b_a_sizes, c15_eiga_data,
              &c15_eiga_sizes);
      c15_b_companDim = c15_companDim;
      c15_i_b = c15_b_companDim;
      c15_j_b = c15_i_b;
      if (1 > c15_j_b) {
        c15_c_overflow = false;
      } else {
        c15_c_overflow = (c15_j_b > 2147483646);
      }

      if (c15_c_overflow) {
        c15_check_forloop_overflow_error(chartInstance, true);
      }

      for (c15_f_k = 1; c15_f_k <= c15_b_companDim; c15_f_k++) {
        c15_d_k = c15_f_k;
        c15_n_a = c15_d_k;
        c15_k_b = c15_nTrailingZeros;
        c15_d_c = (c15_n_a + c15_k_b) - 1;
        c15_r_data[c15_d_c] = c15_eiga_data[c15_d_k - 1];
      }

      c15_o_a = c15_nTrailingZeros;
      c15_l_b = c15_companDim;
      c15_nRoots = c15_o_a + c15_l_b;
      if (c15_nRoots <= 4) {
      } else {
        c15_b_y = NULL;
        sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c15_b_y));
      }

      c15_i11 = c15_nRoots;
      *c15_r_sizes = c15_i11;
    }
  } else {
    c15_b5 = (1 > c15_nTrailingZeros);
    c15_b6 = c15_b5;
    c15_b7 = c15_b6;
    if (c15_b7) {
      c15_i12 = 0;
    } else {
      c15_i12 = c15_nTrailingZeros;
    }

    *c15_r_sizes = c15_i12;
  }
}

static boolean_T c15_isfinite(SFc15_MASsInstanceStruct *chartInstance, real_T
  c15_x)
{
  real_T c15_b_x;
  boolean_T c15_b_b;
  boolean_T c15_b8;
  real_T c15_c_x;
  boolean_T c15_c_b;
  boolean_T c15_b9;
  (void)chartInstance;
  c15_b_x = c15_x;
  c15_b_b = muDoubleScalarIsInf(c15_b_x);
  c15_b8 = !c15_b_b;
  c15_c_x = c15_x;
  c15_c_b = muDoubleScalarIsNaN(c15_c_x);
  c15_b9 = !c15_c_b;
  return c15_b8 && c15_b9;
}

static void c15_c_error(SFc15_MASsInstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'o', 'o',
    't', 's', ':', 'N', 'o', 'n', 'F', 'i', 'n', 'i', 't', 'e', 'I', 'n', 'p',
    'u', 't' };

  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_y));
}

static real_T c15_abs(SFc15_MASsInstanceStruct *chartInstance, real_T c15_x)
{
  real_T c15_b_x;
  real_T c15_c_x;
  (void)chartInstance;
  c15_b_x = c15_x;
  c15_c_x = c15_b_x;
  return muDoubleScalarAbs(c15_c_x);
}

static void c15_check_forloop_overflow_error(SFc15_MASsInstanceStruct
  *chartInstance, boolean_T c15_overflow)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c15_b_y = NULL;
  static char_T c15_c_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c15_overflow;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c15_y, 14, c15_b_y));
}

static void c15_eig(SFc15_MASsInstanceStruct *chartInstance, creal_T c15_A_data[],
                    int32_T c15_A_sizes[2], creal_T c15_V_data[], int32_T
                    *c15_V_sizes)
{
  static creal_T c15_dc2 = { 0.0, 0.0 };

  int32_T c15_lda;
  int32_T c15_b_n;
  int32_T c15_b_A_sizes[2];
  int32_T c15_A;
  int32_T c15_b_A;
  int32_T c15_loop_ub;
  int32_T c15_i13;
  creal_T c15_b_A_data[9];
  ptrdiff_t c15_ldvl_t;
  ptrdiff_t c15_ldvr_t;
  ptrdiff_t c15_n_t;
  ptrdiff_t c15_lda_t;
  creal_T c15_vr;
  creal_T c15_vl;
  ptrdiff_t c15_info_t;
  int32_T c15_info;
  int32_T c15_b_info;
  int32_T c15_c_info;
  boolean_T c15_p;
  boolean_T c15_b_p;
  int32_T c15_V;
  int32_T c15_b_loop_ub;
  int32_T c15_i14;
  int32_T c15_d_info;
  int32_T c15_e_info;
  c15_dc2.re = rtNaN;
  c15_lda = c15_A_sizes[0];
  c15_b_n = c15_A_sizes[1];
  c15_b_A_sizes[0] = c15_A_sizes[0];
  c15_b_A_sizes[1] = c15_A_sizes[1];
  c15_A = c15_b_A_sizes[0];
  c15_b_A = c15_b_A_sizes[1];
  c15_loop_ub = c15_A_sizes[0] * c15_A_sizes[1] - 1;
  for (c15_i13 = 0; c15_i13 <= c15_loop_ub; c15_i13++) {
    c15_b_A_data[c15_i13] = c15_A_data[c15_i13];
  }

  c15_ldvl_t = (ptrdiff_t)1;
  c15_ldvr_t = (ptrdiff_t)1;
  c15_n_t = (ptrdiff_t)c15_b_n;
  c15_lda_t = (ptrdiff_t)c15_lda;
  *c15_V_sizes = c15_b_n;
  c15_info_t = LAPACKE_zgeev(102, 'N', 'N', c15_n_t, (lapack_complex_double *)
    &c15_b_A_data[0], c15_lda_t, (lapack_complex_double *)&c15_V_data[0],
    (lapack_complex_double *)&c15_vl, c15_ldvl_t, (lapack_complex_double *)
    &c15_vr, c15_ldvr_t);
  c15_info = (int32_T)c15_info_t;
  c15_b_info = c15_info;
  c15_c_info = c15_b_info;
  c15_p = (c15_c_info < 0);
  if (c15_p) {
    if (c15_b_info == -1010) {
      c15_d_error(chartInstance);
    } else {
      c15_e_error(chartInstance, c15_b_info);
    }

    c15_b_p = true;
  } else {
    c15_b_p = false;
  }

  if (c15_b_p) {
    c15_V = *c15_V_sizes;
    *c15_V_sizes = c15_V;
    c15_b_loop_ub = c15_V - 1;
    for (c15_i14 = 0; c15_i14 <= c15_b_loop_ub; c15_i14++) {
      c15_V_data[c15_i14] = c15_dc2;
    }
  }

  c15_d_info = c15_info;
  c15_e_info = c15_d_info;
  if ((real_T)c15_e_info != 0.0) {
    c15_warning(chartInstance);
  }
}

static void c15_d_error(SFc15_MASsInstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_y));
}

static void c15_e_error(SFc15_MASsInstanceStruct *chartInstance, int32_T
  c15_varargin_2)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c15_b_y = NULL;
  static char_T c15_c_u[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g',
    'e', 'e', 'v' };

  int32_T c15_d_u;
  const mxArray *c15_c_y = NULL;
  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_c_u, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  c15_d_u = c15_varargin_2;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c15_y, 14, c15_b_y, 14, c15_c_y));
}

static void c15_warning(SFc15_MASsInstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c15_b_y = NULL;
  static char_T c15_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c15_c_y = NULL;
  static char_T c15_msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c15_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c15_b_y, 14, c15_c_y));
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_b_u;
  const mxArray *c15_y = NULL;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_b_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i15;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_i15, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i15;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_is_active_c15_MASs, const char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_MASs), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_MASs);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_MASsInstanceStruct *chartInstance,
  const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_b_sqrt(SFc15_MASsInstanceStruct *chartInstance, real_T *c15_x)
{
  real_T c15_b_x;
  boolean_T c15_b10;
  boolean_T c15_p;
  c15_b_x = *c15_x;
  c15_b10 = (c15_b_x < 0.0);
  c15_p = c15_b10;
  if (c15_p) {
    c15_b_error(chartInstance);
  }

  *c15_x = muDoubleScalarSqrt(*c15_x);
}

static void init_dsm_address_info(SFc15_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_MASsInstanceStruct *chartInstance)
{
  chartInstance->c15_n = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c15_Xp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_sita = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c15_Yp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c15_Np = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c15_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c15_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
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

void sf_c15_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4080151286U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1653495989U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1402088011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3534870435U);
}

mxArray* sf_c15_MASs_get_post_codegen_info(void);
mxArray *sf_c15_MASs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c15_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c15_MASs_jit_fallback_info(void)
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

mxArray *sf_c15_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_MASs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c15_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Np\",},{M[1],M[5],T\"Xp\",},{M[1],M[8],T\"Yp\",},{M[8],M[0],T\"is_active_c15_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_MASsInstanceStruct *chartInstance = (SFc15_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           15,
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
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
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
    SFc15_MASsInstanceStruct *chartInstance = (SFc15_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c15_n);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c15_Xp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c15_sita);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c15_Yp);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c15_Np);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c15_u);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c15_v);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVnreL6srNnvOymngDFKm9D";
}

static void sf_opaque_initialize_c15_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
  initialize_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c15_MASs(void *chartInstanceVar)
{
  enable_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_MASs(void *chartInstanceVar)
{
  disable_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c15_MASs(void *chartInstanceVar)
{
  sf_gateway_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_MASs(SimStruct* S)
{
  return get_sim_state_c15_MASs((SFc15_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c15_MASs((SFc15_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c15_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_MASs((SFc15_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_MASs((SFc15_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c15_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 15);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
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

static void mdlRTW_c15_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_MASs(SimStruct *S)
{
  SFc15_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc15_MASsInstanceStruct *)utMalloc(sizeof
    (SFc15_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc15_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c15_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c15_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c15_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c15_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c15_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c15_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_MASs;
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
  mdl_start_c15_MASs(chartInstance);
}

void c15_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
