/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c36_MASs.h"
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
static const char * c36_debug_family_names[30] = { "Q", "A", "beita", "C", "g",
  "np", "Aj", "Ain", "Aw", "Ein", "En", "E0", "h", "Xt", "Vs", "p", "q", "r",
  "V", "Vj", "i", "nargin", "nargout", "n", "sita", "u", "v", "Xp", "Yp", "Np" };

/* Function Declarations */
static void initialize_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void initialize_params_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void enable_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void disable_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void c36_update_debugger_state_c36_MASs(SFc36_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c36_MASs(SFc36_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c36_MASs(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_st);
static void finalize_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void sf_gateway_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void mdl_start_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void c36_chartstep_c36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void initSimStructsc36_MASs(SFc36_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_Np, const char_T *c36_identifier);
static real_T c36_b_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c36_inData_data[], int32_T *c36_inData_sizes);
static void c36_c_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId, creal_T
  c36_y_data[], int32_T *c36_y_sizes);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, creal_T c36_outData_data[],
  int32_T *c36_outData_sizes);
static real_T c36_rdivide(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x,
  real_T c36_y);
static real_T c36_mpower(SFc36_MASsInstanceStruct *chartInstance, real_T c36_a);
static void c36_scalarEg(SFc36_MASsInstanceStruct *chartInstance);
static void c36_dimagree(SFc36_MASsInstanceStruct *chartInstance);
static boolean_T c36_fltpower_domain_error(SFc36_MASsInstanceStruct
  *chartInstance, real_T c36_a, real_T c36_b);
static void c36_error(SFc36_MASsInstanceStruct *chartInstance);
static real_T c36_b_mpower(SFc36_MASsInstanceStruct *chartInstance, real_T c36_a);
static real_T c36_sqrt(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x);
static void c36_b_error(SFc36_MASsInstanceStruct *chartInstance);
static void c36_roots(SFc36_MASsInstanceStruct *chartInstance, real_T c36_c[4],
                      creal_T c36_r_data[], int32_T *c36_r_sizes);
static boolean_T c36_isfinite(SFc36_MASsInstanceStruct *chartInstance, real_T
  c36_x);
static void c36_c_error(SFc36_MASsInstanceStruct *chartInstance);
static real_T c36_abs(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x);
static void c36_check_forloop_overflow_error(SFc36_MASsInstanceStruct
  *chartInstance, boolean_T c36_overflow);
static void c36_eig(SFc36_MASsInstanceStruct *chartInstance, creal_T c36_A_data[],
                    int32_T c36_A_sizes[2], creal_T c36_V_data[], int32_T
                    *c36_V_sizes);
static void c36_d_error(SFc36_MASsInstanceStruct *chartInstance);
static void c36_e_error(SFc36_MASsInstanceStruct *chartInstance, int32_T
  c36_varargin_2);
static void c36_warning(SFc36_MASsInstanceStruct *chartInstance);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_d_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_e_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_is_active_c36_MASs, const char_T *c36_identifier);
static uint8_T c36_f_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sqrt(SFc36_MASsInstanceStruct *chartInstance, real_T *c36_x);
static void init_dsm_address_info(SFc36_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc36_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc36_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c36_is_active_c36_MASs = 0U;
}

static void initialize_params_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c36_update_debugger_state_c36_MASs(SFc36_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c36_MASs(SFc36_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  real_T c36_hoistedGlobal;
  real_T c36_b_u;
  const mxArray *c36_b_y = NULL;
  real_T c36_b_hoistedGlobal;
  real_T c36_c_u;
  const mxArray *c36_c_y = NULL;
  real_T c36_c_hoistedGlobal;
  real_T c36_d_u;
  const mxArray *c36_d_y = NULL;
  uint8_T c36_d_hoistedGlobal;
  uint8_T c36_e_u;
  const mxArray *c36_e_y = NULL;
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellmatrix(4, 1), false);
  c36_hoistedGlobal = *chartInstance->c36_Np;
  c36_b_u = c36_hoistedGlobal;
  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", &c36_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 0, c36_b_y);
  c36_b_hoistedGlobal = *chartInstance->c36_Xp;
  c36_c_u = c36_b_hoistedGlobal;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 1, c36_c_y);
  c36_c_hoistedGlobal = *chartInstance->c36_Yp;
  c36_d_u = c36_c_hoistedGlobal;
  c36_d_y = NULL;
  sf_mex_assign(&c36_d_y, sf_mex_create("y", &c36_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 2, c36_d_y);
  c36_d_hoistedGlobal = chartInstance->c36_is_active_c36_MASs;
  c36_e_u = c36_d_hoistedGlobal;
  c36_e_y = NULL;
  sf_mex_assign(&c36_e_y, sf_mex_create("y", &c36_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 3, c36_e_y);
  sf_mex_assign(&c36_st, c36_y, false);
  return c36_st;
}

static void set_sim_state_c36_MASs(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_st)
{
  const mxArray *c36_b_u;
  chartInstance->c36_doneDoubleBufferReInit = true;
  c36_b_u = sf_mex_dup(c36_st);
  *chartInstance->c36_Np = c36_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Np", c36_b_u, 0)), "Np");
  *chartInstance->c36_Xp = c36_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xp", c36_b_u, 1)), "Xp");
  *chartInstance->c36_Yp = c36_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Yp", c36_b_u, 2)), "Yp");
  chartInstance->c36_is_active_c36_MASs = c36_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c36_MASs", c36_b_u, 3)),
    "is_active_c36_MASs");
  sf_mex_destroy(&c36_b_u);
  c36_update_debugger_state_c36_MASs(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 28U, chartInstance->c36_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_v, 3U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_u, 2U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_sita, 1U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_n, 0U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  chartInstance->c36_sfEvent = CALL_EVENT;
  c36_chartstep_c36_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_Xp, 4U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_Yp, 5U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c36_Np, 6U, 1U, 0U,
                        chartInstance->c36_sfEvent, false);
}

static void mdl_start_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c36_chartstep_c36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  real_T c36_hoistedGlobal;
  real_T c36_b_hoistedGlobal;
  real_T c36_c_hoistedGlobal;
  real_T c36_d_hoistedGlobal;
  real_T c36_b_n;
  real_T c36_b_sita;
  real_T c36_b_u;
  real_T c36_b_v;
  uint32_T c36_debug_family_var_map[30];
  real_T c36_Q;
  real_T c36_A;
  real_T c36_beita;
  real_T c36_C;
  real_T c36_g;
  real_T c36_np;
  real_T c36_Aj;
  real_T c36_Ain;
  real_T c36_Aw;
  real_T c36_Ein;
  real_T c36_En;
  real_T c36_E0;
  real_T c36_h;
  real_T c36_Xt;
  real_T c36_Vs;
  real_T c36_p;
  real_T c36_q;
  real_T c36_r;
  int32_T c36_V_sizes;
  creal_T c36_V_data[3];
  real_T c36_Vj;
  real_T c36_i;
  real_T c36_nargin = 4.0;
  real_T c36_nargout = 3.0;
  real_T c36_b_Xp;
  real_T c36_b_Yp;
  real_T c36_b_Np;
  real_T c36_b_A;
  real_T c36_c_A;
  real_T c36_y;
  real_T c36_d_A;
  real_T c36_b_y;
  real_T c36_a;
  real_T c36_b_a;
  real_T c36_c_a;
  real_T c36_x;
  real_T c36_d_a;
  real_T c36_ar;
  real_T c36_c;
  real_T c36_dv0[4];
  int32_T c36_tmp_sizes;
  creal_T c36_tmp_data[3];
  int32_T c36_loop_ub;
  int32_T c36_i0;
  real_T c36_d0;
  int32_T c36_i1;
  int32_T c36_b_i;
  real_T c36_d1;
  real_T c36_b_x;
  real_T c36_c_x;
  real_T c36_d_x;
  real_T c36_e_x;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c36_sfEvent);
  c36_hoistedGlobal = *chartInstance->c36_n;
  c36_b_hoistedGlobal = *chartInstance->c36_sita;
  c36_c_hoistedGlobal = *chartInstance->c36_u;
  c36_d_hoistedGlobal = *chartInstance->c36_v;
  c36_b_n = c36_hoistedGlobal;
  c36_b_sita = c36_b_hoistedGlobal;
  c36_b_u = c36_c_hoistedGlobal;
  c36_b_v = c36_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c36_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_Q, 0U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_A, 1U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_beita, 2U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_C, 3U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_g, 4U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_np, 5U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_Aj, 6U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_Ain, 7U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_Aw, 8U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_Ein, 9U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_En, 10U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_E0, 11U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_h, 12U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_Xt, 13U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_Vs, 14U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_p, 15U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_q, 16U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_r, 17U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c36_V_data, (const int32_T *)
    &c36_V_sizes, NULL, 0, 18, (void *)c36_b_sf_marshallOut, (void *)
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_Vj, 19U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_i, 20U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 21U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 22U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_b_n, 23U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_b_sita, 24U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_b_u, 25U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_b_v, 26U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_Xp, 27U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_Yp, 28U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_b_Np, 29U, c36_sf_marshallOut,
    c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 3);
  c36_Q = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 4);
  c36_A = 0.95;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 5);
  c36_beita = 0.9025;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 6);
  c36_C = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 7);
  c36_g = 9.8;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 8);
  c36_np = 0.8;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 9);
  c36_Aj = 0.049087385212340517;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 10);
  c36_Ain = 0.83200000000000007;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 11);
  c36_Aw = 0.78539816339744828;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 12);
  c36_Ein = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 13);
  c36_En = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 14);
  c36_E0 = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 15);
  c36_h = 0.6;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 17);
  c36_Xt = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 19);
  c36_b_A = c36_b_sita * 3.1415926535897931;
  c36_b_sita = c36_rdivide(chartInstance, c36_b_A, 180.0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 20);
  c36_Vs = c36_b_mpower(chartInstance, c36_mpower(chartInstance, c36_b_u) +
                        c36_mpower(chartInstance, c36_b_v));
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 22);
  c36_p = 25.036379540825354;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 23);
  c36_c_A = 0.9025 * c36_mpower(chartInstance, c36_Vs);
  c36_y = c36_rdivide(chartInstance, c36_c_A, 19.6);
  c36_q = 481.05637508093707 * (0.6 - c36_y);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 24);
  c36_d_A = c36_b_n;
  c36_b_y = c36_rdivide(chartInstance, c36_d_A, 1000.0);
  c36_a = c36_b_y;
  c36_b_a = c36_a;
  c36_c_a = c36_b_a;
  c36_x = c36_c_a;
  c36_d_a = c36_x;
  c36_ar = c36_d_a;
  c36_c = muDoubleScalarPower(c36_ar, 3.0);
  if (c36_fltpower_domain_error(chartInstance, c36_c_a, 3.0)) {
    c36_error(chartInstance);
  }

  c36_r = -10.0 * c36_c * 0.8;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 29);
  c36_dv0[0] = 25.036379540825354;
  c36_dv0[1] = 0.0;
  c36_dv0[2] = c36_q;
  c36_dv0[3] = c36_r;
  c36_roots(chartInstance, c36_dv0, c36_tmp_data, &c36_tmp_sizes);
  c36_V_sizes = c36_tmp_sizes;
  c36_loop_ub = c36_tmp_sizes - 1;
  for (c36_i0 = 0; c36_i0 <= c36_loop_ub; c36_i0++) {
    c36_V_data[c36_i0] = c36_tmp_data[c36_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 30);
  c36_Vj = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 32);
  c36_d0 = (real_T)c36_V_sizes;
  c36_i1 = (int32_T)c36_d0 - 1;
  c36_i = 1.0;
  c36_b_i = 0;
  while (c36_b_i <= c36_i1) {
    c36_i = 1.0 + (real_T)c36_b_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 33);
    if (c36_fltpower_domain_error(chartInstance, 10.0, -10.0)) {
      c36_error(chartInstance);
    }

    c36_d1 = c36_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 869, 4, MAX_uint32_T, (int32_T)c36_i, 1, c36_V_sizes)
      - 1].im;
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c36_d1, 1.0E-10, -1, 2U,
          c36_d1 < 1.0E-10))) {
      _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 34);
      c36_Vj = c36_V_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 904, 4, MAX_uint32_T, (int32_T)c36_i, 1,
        c36_V_sizes) - 1].re;
    }

    c36_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 37);
  c36_b_x = c36_b_sita;
  c36_c_x = c36_b_x;
  c36_c_x = muDoubleScalarCos(c36_c_x);
  c36_b_Xp = 49.087385212340514 * c36_Vj * (c36_Vj - 0.95 * c36_Vs) * c36_c_x;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 38);
  c36_d_x = c36_b_sita;
  c36_e_x = c36_d_x;
  c36_e_x = muDoubleScalarSin(c36_e_x);
  c36_b_Yp = 49.087385212340514 * c36_Vj * (c36_Vj - 0.95 * c36_Vs) * c36_e_x;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 39);
  c36_b_Np = c36_b_Yp * 3.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c36_Xp = c36_b_Xp;
  *chartInstance->c36_Yp = c36_b_Yp;
  *chartInstance->c36_Np = c36_b_Np;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c36_sfEvent);
}

static void initSimStructsc36_MASs(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber)
{
  (void)c36_machineNumber;
  (void)c36_chartNumber;
  (void)c36_instanceNumber;
}

static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_b_u;
  const mxArray *c36_y = NULL;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_b_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static real_T c36_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_Np, const char_T *c36_identifier)
{
  real_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_thisId.bParentIsCell = false;
  c36_y = c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_Np),
    &c36_thisId);
  sf_mex_destroy(&c36_b_Np);
  return c36_y;
}

static real_T c36_b_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId)
{
  real_T c36_y;
  real_T c36_d2;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_b_u), &c36_d2, 1, 0, 0U, 0, 0U, 0);
  c36_y = c36_d2;
  sf_mex_destroy(&c36_b_u);
  return c36_y;
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_Np;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_b_Np = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_thisId.bParentIsCell = false;
  c36_y = c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_Np),
    &c36_thisId);
  sf_mex_destroy(&c36_b_Np);
  *(real_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, creal_T
  c36_inData_data[], int32_T *c36_inData_sizes)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u_sizes;
  int32_T c36_loop_ub;
  int32_T c36_i2;
  creal_T c36_u_data[3];
  const mxArray *c36_y = NULL;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u_sizes = *c36_inData_sizes;
  c36_loop_ub = *c36_inData_sizes - 1;
  for (c36_i2 = 0; c36_i2 <= c36_loop_ub; c36_i2++) {
    c36_u_data[c36_i2] = c36_inData_data[c36_i2];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u_data, 0, 1U, 1U, 0U, 1,
    c36_u_sizes), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_c_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId, creal_T
  c36_y_data[], int32_T *c36_y_sizes)
{
  static uint32_T c36_uv0[1] = { 3U };

  uint32_T c36_uv1[1];
  static boolean_T c36_bv0[1] = { true };

  boolean_T c36_bv1[1];
  int32_T c36_tmp_sizes;
  creal_T c36_tmp_data[3];
  int32_T c36_loop_ub;
  int32_T c36_i3;
  (void)chartInstance;
  c36_uv1[0] = c36_uv0[0];
  c36_bv1[0] = c36_bv0[0];
  sf_mex_import_vs(c36_parentId, sf_mex_dup(c36_b_u), c36_tmp_data, 1, 0, 1U, 1,
                   0U, 1, c36_bv1, c36_uv1, &c36_tmp_sizes);
  *c36_y_sizes = c36_tmp_sizes;
  c36_loop_ub = c36_tmp_sizes - 1;
  for (c36_i3 = 0; c36_i3 <= c36_loop_ub; c36_i3++) {
    c36_y_data[c36_i3] = c36_tmp_data[c36_i3];
  }

  sf_mex_destroy(&c36_b_u);
}

static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, creal_T c36_outData_data[],
  int32_T *c36_outData_sizes)
{
  const mxArray *c36_V;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y_sizes;
  creal_T c36_y_data[3];
  int32_T c36_loop_ub;
  int32_T c36_i4;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_V = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_thisId.bParentIsCell = false;
  c36_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_V), &c36_thisId,
    c36_y_data, &c36_y_sizes);
  sf_mex_destroy(&c36_V);
  *c36_outData_sizes = c36_y_sizes;
  c36_loop_ub = c36_y_sizes - 1;
  for (c36_i4 = 0; c36_i4 <= c36_loop_ub; c36_i4++) {
    c36_outData_data[c36_i4] = c36_y_data[c36_i4];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

const mxArray *sf_c36_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  sf_mex_assign(&c36_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c36_nameCaptureInfo;
}

static real_T c36_rdivide(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x,
  real_T c36_y)
{
  real_T c36_b_x;
  real_T c36_b_y;
  (void)chartInstance;
  c36_b_x = c36_x;
  c36_b_y = c36_y;
  return c36_b_x / c36_b_y;
}

static real_T c36_mpower(SFc36_MASsInstanceStruct *chartInstance, real_T c36_a)
{
  real_T c36_c;
  real_T c36_b_a;
  real_T c36_c_a;
  real_T c36_x;
  real_T c36_d_a;
  c36_b_a = c36_a;
  c36_c_a = c36_b_a;
  c36_x = c36_c_a;
  c36_d_a = c36_x;
  c36_c = c36_d_a * c36_d_a;
  if (c36_fltpower_domain_error(chartInstance, c36_c_a, 2.0)) {
    c36_error(chartInstance);
  }

  return c36_c;
}

static void c36_scalarEg(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c36_dimagree(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c36_fltpower_domain_error(SFc36_MASsInstanceStruct
  *chartInstance, real_T c36_a, real_T c36_b)
{
  boolean_T c36_p;
  real_T c36_x;
  boolean_T c36_b_b;
  real_T c36_b_x;
  real_T c36_c_x;
  boolean_T c36_b0;
  boolean_T c36_b1;
  boolean_T guard1 = false;
  (void)chartInstance;
  c36_p = false;
  if (c36_a < 0.0) {
    c36_x = c36_b;
    c36_b_b = muDoubleScalarIsNaN(c36_x);
    guard1 = false;
    if (c36_b_b) {
      guard1 = true;
    } else {
      c36_b_x = c36_b;
      c36_c_x = c36_b_x;
      c36_c_x = muDoubleScalarFloor(c36_c_x);
      if (c36_c_x == c36_b) {
        guard1 = true;
      } else {
        c36_b0 = false;
      }
    }

    if (guard1 == true) {
      c36_b0 = true;
    }

    c36_b1 = !c36_b0;
    c36_p = c36_b1;
  }

  return c36_p;
}

static void c36_error(SFc36_MASsInstanceStruct *chartInstance)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c36_y));
}

static real_T c36_b_mpower(SFc36_MASsInstanceStruct *chartInstance, real_T c36_a)
{
  real_T c36_c;
  real_T c36_b_a;
  real_T c36_c_a;
  real_T c36_x;
  real_T c36_d_a;
  c36_b_a = c36_a;
  c36_c_a = c36_b_a;
  c36_x = c36_c_a;
  c36_d_a = c36_x;
  c36_c = c36_d_a;
  c36_b_sqrt(chartInstance, &c36_c);
  if (c36_fltpower_domain_error(chartInstance, c36_c_a, 0.5)) {
    c36_error(chartInstance);
  }

  return c36_c;
}

static real_T c36_sqrt(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x)
{
  real_T c36_b_x;
  c36_b_x = c36_x;
  c36_b_sqrt(chartInstance, &c36_b_x);
  return c36_b_x;
}

static void c36_b_error(SFc36_MASsInstanceStruct *chartInstance)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c36_b_y = NULL;
  static char_T c36_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c36_y, 14, c36_b_y));
}

static void c36_roots(SFc36_MASsInstanceStruct *chartInstance, real_T c36_c[4],
                      creal_T c36_r_data[], int32_T *c36_r_sizes)
{
  boolean_T c36_p;
  int32_T c36_k;
  int32_T c36_b_k;
  int32_T c36_i5;
  int32_T c36_k1;
  int32_T c36_a;
  int32_T c36_k2;
  int32_T c36_b_a;
  int32_T c36_b;
  int32_T c36_nTrailingZeros;
  int32_T c36_c_a;
  int32_T c36_b_b;
  int32_T c36_companDim;
  int32_T c36_j;
  int32_T c36_d_a;
  int32_T c36_c_b;
  int32_T c36_b_c;
  real_T c36_A;
  real_T c36_B;
  real_T c36_y;
  real_T c36_ctmp[4];
  real_T c36_x;
  boolean_T c36_d_b;
  int32_T c36_e_a;
  int32_T c36_f_a;
  int32_T c36_g_a;
  boolean_T c36_b2;
  boolean_T c36_b3;
  boolean_T c36_b4;
  int32_T c36_i6;
  int32_T c36_i7;
  int32_T c36_a_sizes[2];
  int32_T c36_h_a;
  int32_T c36_i_a;
  int32_T c36_loop_ub;
  int32_T c36_i8;
  creal_T c36_a_data[9];
  int32_T c36_j_a;
  int32_T c36_i9;
  int32_T c36_e_b;
  int32_T c36_f_b;
  boolean_T c36_overflow;
  int32_T c36_c_k;
  int32_T c36_d_k;
  int32_T c36_k_a;
  int32_T c36_c_c;
  static creal_T c36_dc0 = { 1.0, 0.0 };

  int32_T c36_b_nTrailingZeros;
  int32_T c36_g_b;
  int32_T c36_h_b;
  boolean_T c36_b_overflow;
  int32_T c36_e_k;
  static creal_T c36_dc1 = { 0.0, 0.0 };

  int32_T c36_b_a_sizes[2];
  int32_T c36_l_a;
  int32_T c36_m_a;
  int32_T c36_b_loop_ub;
  int32_T c36_i10;
  creal_T c36_b_a_data[9];
  int32_T c36_eiga_sizes;
  creal_T c36_eiga_data[3];
  int32_T c36_b_companDim;
  int32_T c36_i_b;
  int32_T c36_j_b;
  boolean_T c36_c_overflow;
  int32_T c36_f_k;
  int32_T c36_n_a;
  int32_T c36_k_b;
  int32_T c36_d_c;
  int32_T c36_o_a;
  int32_T c36_l_b;
  int32_T c36_nRoots;
  const mxArray *c36_b_y = NULL;
  static char_T c36_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  int32_T c36_i11;
  boolean_T c36_b5;
  boolean_T c36_b6;
  boolean_T c36_b7;
  int32_T c36_i12;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  c36_p = false;
  c36_k = 1;
  exitg5 = false;
  while ((exitg5 == false) && (c36_k < 5)) {
    c36_b_k = c36_k - 1;
    if (!c36_isfinite(chartInstance, c36_c[c36_b_k])) {
      c36_p = true;
      exitg5 = true;
    } else {
      c36_k++;
    }
  }

  if (c36_p) {
    c36_c_error(chartInstance);
  }

  *c36_r_sizes = 3;
  for (c36_i5 = 0; c36_i5 < 3; c36_i5++) {
    c36_r_data[c36_i5].re = 0.0;
    c36_r_data[c36_i5].im = 0.0;
  }

  c36_k1 = 1;
  exitg4 = false;
  while ((exitg4 == false) && (c36_k1 <= 4)) {
    if (c36_c[c36_k1 - 1] != 0.0) {
      exitg4 = true;
    } else {
      c36_a = c36_k1 + 1;
      c36_k1 = c36_a;
    }
  }

  c36_k2 = 4;
  exitg3 = false;
  while ((exitg3 == false) && (c36_k2 >= c36_k1)) {
    if (c36_c[c36_k2 - 1] != 0.0) {
      exitg3 = true;
    } else {
      c36_b_a = c36_k2 - 1;
      c36_k2 = c36_b_a;
    }
  }

  c36_b = c36_k2;
  c36_nTrailingZeros = 4 - c36_b;
  if (c36_k1 < c36_k2) {
    c36_c_a = c36_k2;
    c36_b_b = c36_k1;
    c36_companDim = c36_c_a - c36_b_b;
    exitg1 = false;
    while ((exitg1 == false) && (c36_companDim > 0)) {
      c36_j = 1;
      exitg2 = false;
      while ((exitg2 == false) && (c36_j <= c36_companDim)) {
        c36_d_a = c36_k1;
        c36_c_b = c36_j;
        c36_b_c = (c36_d_a + c36_c_b) - 1;
        c36_A = c36_c[c36_b_c];
        c36_B = c36_c[c36_k1 - 1];
        c36_y = c36_rdivide(chartInstance, c36_A, c36_B);
        c36_ctmp[c36_j - 1] = c36_y;
        c36_x = c36_abs(chartInstance, c36_ctmp[c36_j - 1]);
        c36_d_b = muDoubleScalarIsInf(c36_x);
        if (c36_d_b) {
          exitg2 = true;
        } else {
          c36_e_a = c36_j + 1;
          c36_j = c36_e_a;
        }
      }

      if (c36_j > c36_companDim) {
        exitg1 = true;
      } else {
        c36_f_a = c36_k1 + 1;
        c36_k1 = c36_f_a;
        c36_g_a = c36_companDim - 1;
        c36_companDim = c36_g_a;
      }
    }

    if (c36_companDim < 1) {
      c36_b2 = (1 > c36_nTrailingZeros);
      c36_b3 = c36_b2;
      c36_b4 = c36_b3;
      if (c36_b4) {
        c36_i6 = 0;
      } else {
        c36_i6 = c36_nTrailingZeros;
      }

      *c36_r_sizes = c36_i6;
    } else {
      c36_i7 = c36_companDim;
      c36_a_sizes[0] = c36_i7;
      c36_a_sizes[1] = c36_i7;
      c36_h_a = c36_a_sizes[0];
      c36_i_a = c36_a_sizes[1];
      c36_loop_ub = c36_i7 * c36_i7 - 1;
      for (c36_i8 = 0; c36_i8 <= c36_loop_ub; c36_i8++) {
        c36_a_data[c36_i8].re = 0.0;
        c36_a_data[c36_i8].im = 0.0;
      }

      c36_j_a = c36_companDim - 1;
      c36_i9 = c36_j_a;
      c36_e_b = c36_i9;
      c36_f_b = c36_e_b;
      if (1 > c36_f_b) {
        c36_overflow = false;
      } else {
        c36_overflow = (c36_f_b > 2147483646);
      }

      if (c36_overflow) {
        c36_check_forloop_overflow_error(chartInstance, true);
      }

      for (c36_c_k = 1; c36_c_k <= c36_i9; c36_c_k++) {
        c36_d_k = c36_c_k - 1;
        c36_a_data[c36_a_sizes[0] * c36_d_k].re = -c36_ctmp[c36_d_k];
        c36_a_data[c36_a_sizes[0] * c36_d_k].im = 0.0;
        c36_k_a = c36_d_k + 2;
        c36_c_c = c36_k_a - 1;
        c36_a_data[c36_c_c + c36_a_sizes[0] * c36_d_k] = c36_dc0;
      }

      c36_a_data[c36_a_sizes[0] * (c36_companDim - 1)].re =
        -c36_ctmp[c36_companDim - 1];
      c36_a_data[c36_a_sizes[0] * (c36_companDim - 1)].im = 0.0;
      c36_b_nTrailingZeros = c36_nTrailingZeros;
      c36_g_b = c36_b_nTrailingZeros;
      c36_h_b = c36_g_b;
      if (1 > c36_h_b) {
        c36_b_overflow = false;
      } else {
        c36_b_overflow = (c36_h_b > 2147483646);
      }

      if (c36_b_overflow) {
        c36_check_forloop_overflow_error(chartInstance, true);
      }

      for (c36_e_k = 1; c36_e_k <= c36_b_nTrailingZeros; c36_e_k++) {
        c36_d_k = c36_e_k - 1;
        c36_r_data[c36_d_k] = c36_dc1;
      }

      c36_b_a_sizes[0] = c36_a_sizes[0];
      c36_b_a_sizes[1] = c36_a_sizes[1];
      c36_l_a = c36_b_a_sizes[0];
      c36_m_a = c36_b_a_sizes[1];
      c36_b_loop_ub = c36_a_sizes[0] * c36_a_sizes[1] - 1;
      for (c36_i10 = 0; c36_i10 <= c36_b_loop_ub; c36_i10++) {
        c36_b_a_data[c36_i10] = c36_a_data[c36_i10];
      }

      c36_eig(chartInstance, c36_b_a_data, c36_b_a_sizes, c36_eiga_data,
              &c36_eiga_sizes);
      c36_b_companDim = c36_companDim;
      c36_i_b = c36_b_companDim;
      c36_j_b = c36_i_b;
      if (1 > c36_j_b) {
        c36_c_overflow = false;
      } else {
        c36_c_overflow = (c36_j_b > 2147483646);
      }

      if (c36_c_overflow) {
        c36_check_forloop_overflow_error(chartInstance, true);
      }

      for (c36_f_k = 1; c36_f_k <= c36_b_companDim; c36_f_k++) {
        c36_d_k = c36_f_k;
        c36_n_a = c36_d_k;
        c36_k_b = c36_nTrailingZeros;
        c36_d_c = (c36_n_a + c36_k_b) - 1;
        c36_r_data[c36_d_c] = c36_eiga_data[c36_d_k - 1];
      }

      c36_o_a = c36_nTrailingZeros;
      c36_l_b = c36_companDim;
      c36_nRoots = c36_o_a + c36_l_b;
      if (c36_nRoots <= 4) {
      } else {
        c36_b_y = NULL;
        sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c36_b_y));
      }

      c36_i11 = c36_nRoots;
      *c36_r_sizes = c36_i11;
    }
  } else {
    c36_b5 = (1 > c36_nTrailingZeros);
    c36_b6 = c36_b5;
    c36_b7 = c36_b6;
    if (c36_b7) {
      c36_i12 = 0;
    } else {
      c36_i12 = c36_nTrailingZeros;
    }

    *c36_r_sizes = c36_i12;
  }
}

static boolean_T c36_isfinite(SFc36_MASsInstanceStruct *chartInstance, real_T
  c36_x)
{
  real_T c36_b_x;
  boolean_T c36_b_b;
  boolean_T c36_b8;
  real_T c36_c_x;
  boolean_T c36_c_b;
  boolean_T c36_b9;
  (void)chartInstance;
  c36_b_x = c36_x;
  c36_b_b = muDoubleScalarIsInf(c36_b_x);
  c36_b8 = !c36_b_b;
  c36_c_x = c36_x;
  c36_c_b = muDoubleScalarIsNaN(c36_c_x);
  c36_b9 = !c36_c_b;
  return c36_b8 && c36_b9;
}

static void c36_c_error(SFc36_MASsInstanceStruct *chartInstance)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'r', 'o', 'o',
    't', 's', ':', 'N', 'o', 'n', 'F', 'i', 'n', 'i', 't', 'e', 'I', 'n', 'p',
    'u', 't' };

  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c36_y));
}

static real_T c36_abs(SFc36_MASsInstanceStruct *chartInstance, real_T c36_x)
{
  real_T c36_b_x;
  real_T c36_c_x;
  (void)chartInstance;
  c36_b_x = c36_x;
  c36_c_x = c36_b_x;
  return muDoubleScalarAbs(c36_c_x);
}

static void c36_check_forloop_overflow_error(SFc36_MASsInstanceStruct
  *chartInstance, boolean_T c36_overflow)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c36_b_y = NULL;
  static char_T c36_c_u[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c36_overflow;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c36_y, 14, c36_b_y));
}

static void c36_eig(SFc36_MASsInstanceStruct *chartInstance, creal_T c36_A_data[],
                    int32_T c36_A_sizes[2], creal_T c36_V_data[], int32_T
                    *c36_V_sizes)
{
  static creal_T c36_dc2 = { 0.0, 0.0 };

  int32_T c36_lda;
  int32_T c36_b_n;
  int32_T c36_b_A_sizes[2];
  int32_T c36_A;
  int32_T c36_b_A;
  int32_T c36_loop_ub;
  int32_T c36_i13;
  creal_T c36_b_A_data[9];
  ptrdiff_t c36_ldvl_t;
  ptrdiff_t c36_ldvr_t;
  ptrdiff_t c36_n_t;
  ptrdiff_t c36_lda_t;
  creal_T c36_vr;
  creal_T c36_vl;
  ptrdiff_t c36_info_t;
  int32_T c36_info;
  int32_T c36_b_info;
  int32_T c36_c_info;
  boolean_T c36_p;
  boolean_T c36_b_p;
  int32_T c36_V;
  int32_T c36_b_loop_ub;
  int32_T c36_i14;
  int32_T c36_d_info;
  int32_T c36_e_info;
  c36_dc2.re = rtNaN;
  c36_lda = c36_A_sizes[0];
  c36_b_n = c36_A_sizes[1];
  c36_b_A_sizes[0] = c36_A_sizes[0];
  c36_b_A_sizes[1] = c36_A_sizes[1];
  c36_A = c36_b_A_sizes[0];
  c36_b_A = c36_b_A_sizes[1];
  c36_loop_ub = c36_A_sizes[0] * c36_A_sizes[1] - 1;
  for (c36_i13 = 0; c36_i13 <= c36_loop_ub; c36_i13++) {
    c36_b_A_data[c36_i13] = c36_A_data[c36_i13];
  }

  c36_ldvl_t = (ptrdiff_t)1;
  c36_ldvr_t = (ptrdiff_t)1;
  c36_n_t = (ptrdiff_t)c36_b_n;
  c36_lda_t = (ptrdiff_t)c36_lda;
  *c36_V_sizes = c36_b_n;
  c36_info_t = LAPACKE_zgeev(102, 'N', 'N', c36_n_t, (lapack_complex_double *)
    &c36_b_A_data[0], c36_lda_t, (lapack_complex_double *)&c36_V_data[0],
    (lapack_complex_double *)&c36_vl, c36_ldvl_t, (lapack_complex_double *)
    &c36_vr, c36_ldvr_t);
  c36_info = (int32_T)c36_info_t;
  c36_b_info = c36_info;
  c36_c_info = c36_b_info;
  c36_p = (c36_c_info < 0);
  if (c36_p) {
    if (c36_b_info == -1010) {
      c36_d_error(chartInstance);
    } else {
      c36_e_error(chartInstance, c36_b_info);
    }

    c36_b_p = true;
  } else {
    c36_b_p = false;
  }

  if (c36_b_p) {
    c36_V = *c36_V_sizes;
    *c36_V_sizes = c36_V;
    c36_b_loop_ub = c36_V - 1;
    for (c36_i14 = 0; c36_i14 <= c36_b_loop_ub; c36_i14++) {
      c36_V_data[c36_i14] = c36_dc2;
    }
  }

  c36_d_info = c36_info;
  c36_e_info = c36_d_info;
  if ((real_T)c36_e_info != 0.0) {
    c36_warning(chartInstance);
  }
}

static void c36_d_error(SFc36_MASsInstanceStruct *chartInstance)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 12),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c36_y));
}

static void c36_e_error(SFc36_MASsInstanceStruct *chartInstance, int32_T
  c36_varargin_2)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  const mxArray *c36_b_y = NULL;
  static char_T c36_c_u[13] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z', 'g',
    'e', 'e', 'v' };

  int32_T c36_d_u;
  const mxArray *c36_c_y = NULL;
  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_c_u, 10, 0U, 1U, 0U, 2, 1, 13),
                false);
  c36_d_u = c36_varargin_2;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    3U, 14, c36_y, 14, c36_b_y, 14, c36_c_y));
}

static void c36_warning(SFc36_MASsInstanceStruct *chartInstance)
{
  const mxArray *c36_y = NULL;
  static char_T c36_b_u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *c36_b_y = NULL;
  static char_T c36_c_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c36_c_y = NULL;
  static char_T c36_msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  (void)chartInstance;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_b_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_c_u, 10, 0U, 1U, 0U, 2, 1, 7),
                false);
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", c36_msgID, 10, 0U, 1U, 0U, 2, 1, 24),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 0U, 2U, 14, c36_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "feval", 1U,
    2U, 14, c36_b_y, 14, c36_c_y));
}

static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_b_u;
  const mxArray *c36_y = NULL;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_b_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static int32_T c36_d_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i15;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_b_u), &c36_i15, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i15;
  sf_mex_destroy(&c36_b_u);
  return c36_y;
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_sfEvent;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y;
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)chartInstanceVoid;
  c36_b_sfEvent = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_thisId.bParentIsCell = false;
  c36_y = c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_sfEvent),
    &c36_thisId);
  sf_mex_destroy(&c36_b_sfEvent);
  *(int32_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static uint8_T c36_e_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_is_active_c36_MASs, const char_T *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_thisId.bParentIsCell = false;
  c36_y = c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_MASs), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_MASs);
  return c36_y;
}

static uint8_T c36_f_emlrt_marshallIn(SFc36_MASsInstanceStruct *chartInstance,
  const mxArray *c36_b_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_b_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_b_u);
  return c36_y;
}

static void c36_b_sqrt(SFc36_MASsInstanceStruct *chartInstance, real_T *c36_x)
{
  real_T c36_b_x;
  boolean_T c36_b10;
  boolean_T c36_p;
  c36_b_x = *c36_x;
  c36_b10 = (c36_b_x < 0.0);
  c36_p = c36_b10;
  if (c36_p) {
    c36_b_error(chartInstance);
  }

  *c36_x = muDoubleScalarSqrt(*c36_x);
}

static void init_dsm_address_info(SFc36_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc36_MASsInstanceStruct *chartInstance)
{
  chartInstance->c36_n = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c36_Xp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c36_sita = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c36_Yp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c36_Np = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c36_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c36_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
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

void sf_c36_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4080151286U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1653495989U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1402088011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3534870435U);
}

mxArray* sf_c36_MASs_get_post_codegen_info(void);
mxArray *sf_c36_MASs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c36_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c36_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.lapack.LAPACKApi"));
  return(mxcell3p);
}

mxArray *sf_c36_MASs_jit_fallback_info(void)
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

mxArray *sf_c36_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c36_MASs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c36_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Np\",},{M[1],M[5],T\"Xp\",},{M[1],M[8],T\"Yp\",},{M[8],M[0],T\"is_active_c36_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_MASsInstanceStruct *chartInstance = (SFc36_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           36,
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
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)c36_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)c36_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)c36_sf_marshallIn);
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
    SFc36_MASsInstanceStruct *chartInstance = (SFc36_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c36_n);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c36_Xp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c36_sita);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c36_Yp);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c36_Np);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c36_u);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c36_v);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sVnreL6srNnvOymngDFKm9D";
}

static void sf_opaque_initialize_c36_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
  initialize_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c36_MASs(void *chartInstanceVar)
{
  enable_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c36_MASs(void *chartInstanceVar)
{
  disable_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c36_MASs(void *chartInstanceVar)
{
  sf_gateway_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c36_MASs(SimStruct* S)
{
  return get_sim_state_c36_MASs((SFc36_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c36_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c36_MASs((SFc36_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c36_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc36_MASs((SFc36_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c36_MASs((SFc36_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c36_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,36,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 36);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,36);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,36,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,36,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,36);
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

static void mdlRTW_c36_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_MASs(SimStruct *S)
{
  SFc36_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc36_MASsInstanceStruct *)utMalloc(sizeof
    (SFc36_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc36_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c36_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c36_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c36_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c36_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c36_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c36_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c36_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c36_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c36_MASs;
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
  mdl_start_c36_MASs(chartInstance);
}

void c36_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
