/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MASs_sfun.h"
#include "c30_MASs.h"
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
static const char * c30_debug_family_names[33] = { "P", "K", "dA", "df", "d1",
  "d2", "t", "U", "deta", "S", "vv", "Re", "Cf", "Ks", "deCf", "Xu", "Yv", "Yr",
  "Nv", "Nr", "nargin", "nargout", "B", "d", "L", "Cb", "m", "u", "v", "r", "Xs",
  "Ys", "Ns" };

/* Function Declarations */
static void initialize_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void initialize_params_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void enable_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void disable_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_MASs(SFc30_MASsInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c30_MASs(SFc30_MASsInstanceStruct
  *chartInstance);
static void set_sim_state_c30_MASs(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_st);
static void finalize_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void sf_gateway_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void mdl_start_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void c30_chartstep_c30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void initSimStructsc30_MASs(SFc30_MASsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_Ns, const char_T *c30_identifier);
static real_T c30_b_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static real_T c30_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a);
static void c30_scalarEg(SFc30_MASsInstanceStruct *chartInstance);
static void c30_dimagree(SFc30_MASsInstanceStruct *chartInstance);
static boolean_T c30_fltpower_domain_error(SFc30_MASsInstanceStruct
  *chartInstance, real_T c30_a, real_T c30_b);
static void c30_error(SFc30_MASsInstanceStruct *chartInstance);
static real_T c30_b_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a);
static void c30_b_error(SFc30_MASsInstanceStruct *chartInstance);
static real_T c30_c_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a,
  real_T c30_b);
static real_T c30_d_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a);
static real_T c30_log10(SFc30_MASsInstanceStruct *chartInstance, real_T c30_x);
static void c30_c_error(SFc30_MASsInstanceStruct *chartInstance);
static real_T c30_e_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_c_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_d_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_is_active_c30_MASs, const char_T *c30_identifier);
static uint8_T c30_e_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_log10(SFc30_MASsInstanceStruct *chartInstance, real_T *c30_x);
static void init_dsm_address_info(SFc30_MASsInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc30_MASsInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc30_MASs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c30_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c30_is_active_c30_MASs = 0U;
}

static void initialize_params_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c30_update_debugger_state_c30_MASs(SFc30_MASsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c30_MASs(SFc30_MASsInstanceStruct
  *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  real_T c30_hoistedGlobal;
  real_T c30_b_u;
  const mxArray *c30_b_y = NULL;
  real_T c30_b_hoistedGlobal;
  real_T c30_c_u;
  const mxArray *c30_c_y = NULL;
  real_T c30_c_hoistedGlobal;
  real_T c30_d_u;
  const mxArray *c30_d_y = NULL;
  uint8_T c30_d_hoistedGlobal;
  uint8_T c30_e_u;
  const mxArray *c30_e_y = NULL;
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellmatrix(4, 1), false);
  c30_hoistedGlobal = *chartInstance->c30_Ns;
  c30_b_u = c30_hoistedGlobal;
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_b_hoistedGlobal = *chartInstance->c30_Xs;
  c30_c_u = c30_b_hoistedGlobal;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  c30_c_hoistedGlobal = *chartInstance->c30_Ys;
  c30_d_u = c30_c_hoistedGlobal;
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", &c30_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 2, c30_d_y);
  c30_d_hoistedGlobal = chartInstance->c30_is_active_c30_MASs;
  c30_e_u = c30_d_hoistedGlobal;
  c30_e_y = NULL;
  sf_mex_assign(&c30_e_y, sf_mex_create("y", &c30_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c30_y, 3, c30_e_y);
  sf_mex_assign(&c30_st, c30_y, false);
  return c30_st;
}

static void set_sim_state_c30_MASs(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_st)
{
  const mxArray *c30_b_u;
  chartInstance->c30_doneDoubleBufferReInit = true;
  c30_b_u = sf_mex_dup(c30_st);
  *chartInstance->c30_Ns = c30_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ns", c30_b_u, 0)), "Ns");
  *chartInstance->c30_Xs = c30_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Xs", c30_b_u, 1)), "Xs");
  *chartInstance->c30_Ys = c30_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ys", c30_b_u, 2)), "Ys");
  chartInstance->c30_is_active_c30_MASs = c30_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c30_MASs", c30_b_u, 3)),
    "is_active_c30_MASs");
  sf_mex_destroy(&c30_b_u);
  c30_update_debugger_state_c30_MASs(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_r, 7U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_v, 6U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_u, 5U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_m, 4U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_Cb, 3U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_L, 2U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_d, 1U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_B, 0U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  chartInstance->c30_sfEvent = CALL_EVENT;
  c30_chartstep_c30_MASs(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MASsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_Xs, 8U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_Ys, 9U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c30_Ns, 10U, 1U, 0U,
                        chartInstance->c30_sfEvent, false);
}

static void mdl_start_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c30_chartstep_c30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  real_T c30_hoistedGlobal;
  real_T c30_b_hoistedGlobal;
  real_T c30_c_hoistedGlobal;
  real_T c30_d_hoistedGlobal;
  real_T c30_e_hoistedGlobal;
  real_T c30_f_hoistedGlobal;
  real_T c30_g_hoistedGlobal;
  real_T c30_h_hoistedGlobal;
  real_T c30_b_B;
  real_T c30_b_d;
  real_T c30_b_L;
  real_T c30_b_Cb;
  real_T c30_b_m;
  real_T c30_b_u;
  real_T c30_b_v;
  real_T c30_b_r;
  uint32_T c30_debug_family_var_map[33];
  real_T c30_P;
  real_T c30_K;
  real_T c30_dA;
  real_T c30_df;
  real_T c30_d1;
  real_T c30_d2;
  real_T c30_t;
  real_T c30_U;
  real_T c30_deta;
  real_T c30_S;
  real_T c30_vv;
  real_T c30_Re;
  real_T c30_Cf;
  real_T c30_Ks;
  real_T c30_deCf;
  real_T c30_Xu;
  real_T c30_Yv;
  real_T c30_Yr;
  real_T c30_Nv;
  real_T c30_Nr;
  real_T c30_nargin = 8.0;
  real_T c30_nargout = 3.0;
  real_T c30_b_Xs;
  real_T c30_b_Ys;
  real_T c30_b_Ns;
  real_T c30_A;
  real_T c30_c_B;
  real_T c30_x;
  real_T c30_y;
  real_T c30_b_x;
  real_T c30_b_y;
  real_T c30_b_A;
  real_T c30_c_x;
  real_T c30_d_x;
  real_T c30_c_A;
  real_T c30_e_x;
  real_T c30_f_x;
  real_T c30_c_y;
  real_T c30_d_A;
  real_T c30_g_x;
  real_T c30_h_x;
  real_T c30_d0;
  real_T c30_d_B;
  real_T c30_d_y;
  real_T c30_e_y;
  real_T c30_e_B;
  real_T c30_f_y;
  real_T c30_g_y;
  real_T c30_h_y;
  real_T c30_e_A;
  real_T c30_f_B;
  real_T c30_i_x;
  real_T c30_i_y;
  real_T c30_j_x;
  real_T c30_j_y;
  real_T c30_k_y;
  real_T c30_g_B;
  real_T c30_l_y;
  real_T c30_m_y;
  real_T c30_n_y;
  real_T c30_h_B;
  real_T c30_o_y;
  real_T c30_p_y;
  real_T c30_q_y;
  real_T c30_f_A;
  real_T c30_i_B;
  real_T c30_k_x;
  real_T c30_r_y;
  real_T c30_l_x;
  real_T c30_s_y;
  real_T c30_t_y;
  real_T c30_g_A;
  real_T c30_j_B;
  real_T c30_m_x;
  real_T c30_u_y;
  real_T c30_n_x;
  real_T c30_v_y;
  real_T c30_w_y;
  real_T c30_a;
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_o_x;
  real_T c30_d_a;
  real_T c30_ar;
  real_T c30_c;
  real_T c30_k_B;
  real_T c30_x_y;
  real_T c30_y_y;
  real_T c30_ab_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
  c30_hoistedGlobal = *chartInstance->c30_B;
  c30_b_hoistedGlobal = *chartInstance->c30_d;
  c30_c_hoistedGlobal = *chartInstance->c30_L;
  c30_d_hoistedGlobal = *chartInstance->c30_Cb;
  c30_e_hoistedGlobal = *chartInstance->c30_m;
  c30_f_hoistedGlobal = *chartInstance->c30_u;
  c30_g_hoistedGlobal = *chartInstance->c30_v;
  c30_h_hoistedGlobal = *chartInstance->c30_r;
  c30_b_B = c30_hoistedGlobal;
  c30_b_d = c30_b_hoistedGlobal;
  c30_b_L = c30_c_hoistedGlobal;
  c30_b_Cb = c30_d_hoistedGlobal;
  c30_b_m = c30_e_hoistedGlobal;
  c30_b_u = c30_f_hoistedGlobal;
  c30_b_v = c30_g_hoistedGlobal;
  c30_b_r = c30_h_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c30_debug_family_names,
    c30_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_P, 0U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_K, 1U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_dA, 2U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_df, 3U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_d1, 4U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_d2, 5U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_t, 6U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_U, 7U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_deta, 8U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_S, 9U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_vv, 10U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Re, 11U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Cf, 12U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_Ks, 13U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_deCf, 14U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Xu, 15U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Yv, 16U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Yr, 17U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Nv, 18U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_Nr, 19U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargin, 20U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_nargout, 21U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_B, 22U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_d, 23U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_L, 24U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_Cb, 25U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_m, 26U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_u, 27U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_v, 28U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c30_b_r, 29U, c30_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_Xs, 30U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_Ys, 31U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c30_b_Ns, 32U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 3);
  c30_P = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 4);
  c30_A = 2.0 * c30_b_d;
  c30_c_B = c30_b_L;
  c30_x = c30_A;
  c30_y = c30_c_B;
  c30_b_x = c30_x;
  c30_b_y = c30_y;
  c30_K = c30_b_x / c30_b_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 5);
  c30_dA = 0.67;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 6);
  c30_df = 0.72;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 7);
  c30_d1 = -0.049999999999999933;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 8);
  c30_d2 = 0.69500000000000006;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 9);
  c30_t = -0.071942446043165367;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 10);
  c30_U = c30_b_mpower(chartInstance, c30_mpower(chartInstance, c30_b_u) +
                       c30_mpower(chartInstance, c30_b_v));
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 11);
  c30_b_A = c30_b_m;
  c30_c_x = c30_b_A;
  c30_d_x = c30_c_x;
  c30_deta = c30_d_x / 1025.0;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 12);
  c30_c_A = c30_deta;
  c30_e_x = c30_c_A;
  c30_f_x = c30_e_x;
  c30_c_y = c30_f_x / 3.0;
  c30_S = c30_d_mpower(chartInstance, c30_c_mpower(chartInstance, 3.14, c30_c_y)
                       + 0.5 * c30_b_L);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 13);
  c30_vv = 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 14);
  c30_d_A = c30_b_L * c30_U;
  c30_g_x = c30_d_A;
  c30_h_x = c30_g_x;
  c30_Re = c30_h_x / 1.07854E-6;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 15);
  c30_d0 = c30_Re;
  c30_b_log10(chartInstance, &c30_d0);
  c30_d_B = c30_mpower(chartInstance, c30_d0 - 2.0);
  c30_d_y = c30_d_B;
  c30_e_y = c30_d_y;
  c30_Cf = 0.075 / c30_e_y;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 16);
  c30_Ks = 0.00015;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 17);
  c30_e_B = c30_b_L;
  c30_f_y = c30_e_B;
  c30_g_y = c30_f_y;
  c30_h_y = 0.00015 / c30_g_y;
  c30_deCf = (105.0 * c30_d_mpower(chartInstance, c30_h_y) - 0.64) *
    c30_e_mpower(chartInstance, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 19);
  c30_Xu = 0.5 * c30_P * c30_S * c30_mpower(chartInstance, c30_b_u) * (c30_Cf +
    c30_deCf);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 20);
  c30_e_A = 1.4 * c30_b_Cb * c30_b_B;
  c30_f_B = c30_b_L;
  c30_i_x = c30_e_A;
  c30_i_y = c30_f_B;
  c30_j_x = c30_i_x;
  c30_j_y = c30_i_y;
  c30_k_y = c30_j_x / c30_j_y;
  c30_g_B = c30_b_d;
  c30_l_y = c30_g_B;
  c30_m_y = c30_l_y;
  c30_n_y = -0.0482014388489208 / c30_m_y;
  c30_Yv = -0.5 * c30_P * c30_b_L * c30_b_d * c30_U * ((1.5707963267948966 *
    c30_K + c30_k_y) * (1.0 + c30_n_y));
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 21);
  c30_h_B = c30_b_d;
  c30_o_y = c30_h_B;
  c30_p_y = c30_o_y;
  c30_q_y = -0.057553956834532294 / c30_p_y;
  c30_Yr = 0.5 * c30_P * c30_b_L * c30_b_L * c30_b_d * c30_U *
    (0.78539816339744828 * c30_K * (1.0 + c30_q_y));
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 22);
  c30_f_A = 1.4 * c30_b_Cb * c30_b_B;
  c30_i_B = c30_b_L;
  c30_k_x = c30_f_A;
  c30_r_y = c30_i_B;
  c30_l_x = c30_k_x;
  c30_s_y = c30_r_y;
  c30_t_y = c30_l_x / c30_s_y;
  c30_g_A = 0.27 * (1.5707963267948966 + c30_t_y) * c30_t;
  c30_j_B = c30_b_d;
  c30_m_x = c30_g_A;
  c30_u_y = c30_j_B;
  c30_n_x = c30_m_x;
  c30_v_y = c30_u_y;
  c30_w_y = c30_n_x / c30_v_y;
  c30_Nv = -0.5 * c30_P * c30_b_L * c30_b_L * c30_b_d * c30_U * (c30_K - c30_w_y);
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 23);
  c30_a = c30_b_L;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_o_x = c30_c_a;
  c30_d_a = c30_o_x;
  c30_ar = c30_d_a;
  c30_c = muDoubleScalarPower(c30_ar, 3.0);
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, 3.0)) {
    c30_error(chartInstance);
  }

  c30_k_B = c30_b_d;
  c30_x_y = c30_k_B;
  c30_y_y = c30_x_y;
  c30_ab_y = -0.02158273381294961 / c30_y_y;
  c30_Nr = 0.5 * c30_P * c30_c * c30_b_d * c30_U * (-(0.54 * c30_K - c30_mpower
    (chartInstance, c30_K)) * (1.0 + c30_ab_y));
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 25);
  c30_b_Xs = c30_Xu;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 26);
  c30_b_Ys = c30_Yv * c30_b_v + c30_Yr * c30_b_r;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, 27);
  c30_b_Ns = c30_Nv * c30_b_v + c30_Nr * c30_b_r;
  _SFD_EML_CALL(0U, chartInstance->c30_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c30_Xs = c30_b_Xs;
  *chartInstance->c30_Ys = c30_b_Ys;
  *chartInstance->c30_Ns = c30_b_Ns;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c30_sfEvent);
}

static void initSimStructsc30_MASs(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber, uint32_T c30_instanceNumber)
{
  (void)c30_machineNumber;
  (void)c30_chartNumber;
  (void)c30_instanceNumber;
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_b_u;
  const mxArray *c30_y = NULL;
  SFc30_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc30_MASsInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_b_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static real_T c30_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_Ns, const char_T *c30_identifier)
{
  real_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_thisId.bParentIsCell = false;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_Ns),
    &c30_thisId);
  sf_mex_destroy(&c30_b_Ns);
  return c30_y;
}

static real_T c30_b_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d1;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_b_u), &c30_d1, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d1;
  sf_mex_destroy(&c30_b_u);
  return c30_y;
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_Ns;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc30_MASsInstanceStruct *)chartInstanceVoid;
  c30_b_Ns = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_thisId.bParentIsCell = false;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_Ns),
    &c30_thisId);
  sf_mex_destroy(&c30_b_Ns);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_MASs_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c30_nameCaptureInfo;
}

static real_T c30_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a)
{
  real_T c30_c;
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_x;
  real_T c30_d_a;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_x = c30_c_a;
  c30_d_a = c30_x;
  c30_c = c30_d_a * c30_d_a;
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, 2.0)) {
    c30_error(chartInstance);
  }

  return c30_c;
}

static void c30_scalarEg(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c30_dimagree(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c30_fltpower_domain_error(SFc30_MASsInstanceStruct
  *chartInstance, real_T c30_a, real_T c30_b)
{
  boolean_T c30_p;
  real_T c30_x;
  boolean_T c30_b_b;
  real_T c30_b_x;
  real_T c30_c_x;
  boolean_T c30_b0;
  boolean_T c30_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  (void)chartInstance;
  c30_p = false;
  if (c30_a < 0.0) {
    guard1 = false;
    if (c30_p) {
      guard1 = true;
    } else {
      c30_x = c30_b;
      c30_b_b = muDoubleScalarIsNaN(c30_x);
      guard2 = false;
      if (c30_b_b) {
        guard2 = true;
      } else {
        c30_b_x = c30_b;
        c30_c_x = c30_b_x;
        c30_c_x = muDoubleScalarFloor(c30_c_x);
        if (c30_c_x == c30_b) {
          guard2 = true;
        } else {
          c30_b0 = false;
        }
      }

      if (guard2 == true) {
        c30_b0 = true;
      }

      if (!c30_b0) {
        guard1 = true;
      } else {
        c30_b1 = false;
      }
    }

    if (guard1 == true) {
      c30_b1 = true;
    }

    c30_p = c30_b1;
  }

  return c30_p;
}

static void c30_error(SFc30_MASsInstanceStruct *chartInstance)
{
  const mxArray *c30_y = NULL;
  static char_T c30_b_u[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_b_u, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c30_y));
}

static real_T c30_b_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a)
{
  real_T c30_c;
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_x;
  real_T c30_d_a;
  real_T c30_b_x;
  real_T c30_c_x;
  boolean_T c30_b2;
  boolean_T c30_p;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_x = c30_c_a;
  c30_d_a = c30_x;
  c30_b_x = c30_d_a;
  c30_c = c30_b_x;
  c30_c_x = c30_c;
  c30_b2 = (c30_c_x < 0.0);
  c30_p = c30_b2;
  if (c30_p) {
    c30_b_error(chartInstance);
  }

  c30_c = muDoubleScalarSqrt(c30_c);
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, 0.5)) {
    c30_error(chartInstance);
  }

  return c30_c;
}

static void c30_b_error(SFc30_MASsInstanceStruct *chartInstance)
{
  const mxArray *c30_y = NULL;
  static char_T c30_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c30_b_y = NULL;
  static char_T c30_c_u[4] = { 's', 'q', 'r', 't' };

  (void)chartInstance;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c30_y, 14, c30_b_y));
}

static real_T c30_c_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a,
  real_T c30_b)
{
  real_T c30_c;
  real_T c30_b_a;
  real_T c30_b_b;
  real_T c30_c_a;
  real_T c30_c_b;
  real_T c30_x;
  real_T c30_y;
  real_T c30_d_a;
  real_T c30_d_b;
  real_T c30_ar;
  real_T c30_br;
  c30_b_a = c30_a;
  c30_b_b = c30_b;
  c30_c_a = c30_b_a;
  c30_c_b = c30_b_b;
  c30_x = c30_c_a;
  c30_y = c30_c_b;
  c30_d_a = c30_x;
  c30_d_b = c30_y;
  c30_ar = c30_d_a;
  c30_br = c30_d_b;
  c30_c = muDoubleScalarPower(c30_ar, c30_br);
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, c30_c_b)) {
    c30_error(chartInstance);
  }

  return c30_c;
}

static real_T c30_d_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a)
{
  real_T c30_c;
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_x;
  real_T c30_d_a;
  real_T c30_ar;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_x = c30_c_a;
  c30_d_a = c30_x;
  c30_ar = c30_d_a;
  c30_c = muDoubleScalarPower(c30_ar, 0.33333333333333331);
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, 0.33333333333333331)) {
    c30_error(chartInstance);
  }

  return c30_c;
}

static real_T c30_log10(SFc30_MASsInstanceStruct *chartInstance, real_T c30_x)
{
  real_T c30_b_x;
  c30_b_x = c30_x;
  c30_b_log10(chartInstance, &c30_b_x);
  return c30_b_x;
}

static void c30_c_error(SFc30_MASsInstanceStruct *chartInstance)
{
  const mxArray *c30_y = NULL;
  static char_T c30_b_u[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *c30_b_y = NULL;
  static char_T c30_c_u[5] = { 'l', 'o', 'g', '1', '0' };

  (void)chartInstance;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", c30_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", c30_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c30_y, 14, c30_b_y));
}

static real_T c30_e_mpower(SFc30_MASsInstanceStruct *chartInstance, real_T c30_a)
{
  real_T c30_c;
  real_T c30_b_a;
  real_T c30_c_a;
  real_T c30_x;
  real_T c30_d_a;
  real_T c30_ar;
  c30_b_a = c30_a;
  c30_c_a = c30_b_a;
  c30_x = c30_c_a;
  c30_d_a = c30_x;
  c30_ar = c30_d_a;
  c30_c = muDoubleScalarPower(c30_ar, -3.0);
  if (c30_fltpower_domain_error(chartInstance, c30_c_a, -3.0)) {
    c30_error(chartInstance);
  }

  return c30_c;
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_b_u;
  const mxArray *c30_y = NULL;
  SFc30_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc30_MASsInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_b_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, false);
  return c30_mxArrayOutData;
}

static int32_T c30_c_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_b_u), &c30_i0, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i0;
  sf_mex_destroy(&c30_b_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_b_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc30_MASsInstanceStruct *)chartInstanceVoid;
  c30_b_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_thisId.bParentIsCell = false;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_b_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_b_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_d_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_is_active_c30_MASs, const char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_thisId.bParentIsCell = false;
  c30_y = c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_b_is_active_c30_MASs), &c30_thisId);
  sf_mex_destroy(&c30_b_is_active_c30_MASs);
  return c30_y;
}

static uint8_T c30_e_emlrt_marshallIn(SFc30_MASsInstanceStruct *chartInstance,
  const mxArray *c30_b_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  (void)chartInstance;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_b_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_b_u);
  return c30_y;
}

static void c30_b_log10(SFc30_MASsInstanceStruct *chartInstance, real_T *c30_x)
{
  real_T c30_b_x;
  boolean_T c30_b3;
  boolean_T c30_p;
  c30_b_x = *c30_x;
  c30_b3 = (c30_b_x < 0.0);
  c30_p = c30_b3;
  if (c30_p) {
    c30_c_error(chartInstance);
  }

  *c30_x = muDoubleScalarLog10(*c30_x);
}

static void init_dsm_address_info(SFc30_MASsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc30_MASsInstanceStruct *chartInstance)
{
  chartInstance->c30_B = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c30_Xs = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c30_d = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c30_L = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    2);
  chartInstance->c30_Cb = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c30_m = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c30_Ys = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c30_Ns = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c30_u = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c30_v = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c30_r = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    7);
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

void sf_c30_MASs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3631436933U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(85359349U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(999221842U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1459522431U);
}

mxArray* sf_c30_MASs_get_post_codegen_info(void);
mxArray *sf_c30_MASs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8lzI7HIT1Nn9dVAUuTjloF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c30_MASs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c30_MASs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c30_MASs_jit_fallback_info(void)
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

mxArray *sf_c30_MASs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c30_MASs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c30_MASs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"Ns\",},{M[1],M[5],T\"Xs\",},{M[1],M[8],T\"Ys\",},{M[8],M[0],T\"is_active_c30_MASs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_MASs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_MASsInstanceStruct *chartInstance = (SFc30_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MASsMachineNumber_,
           30,
           1,
           1,
           0,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"B");
          _SFD_SET_DATA_PROPS(1,1,1,0,"d");
          _SFD_SET_DATA_PROPS(2,1,1,0,"L");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Cb");
          _SFD_SET_DATA_PROPS(4,1,1,0,"m");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u");
          _SFD_SET_DATA_PROPS(6,1,1,0,"v");
          _SFD_SET_DATA_PROPS(7,1,1,0,"r");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Xs");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Ys");
          _SFD_SET_DATA_PROPS(10,2,0,1,"Ns");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,612);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);
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
    SFc30_MASsInstanceStruct *chartInstance = (SFc30_MASsInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c30_B);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c30_Xs);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c30_d);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c30_L);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c30_Cb);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c30_m);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c30_Ys);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c30_Ns);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c30_u);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c30_v);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c30_r);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "szgERixxwJPfc78HRHoQdVF";
}

static void sf_opaque_initialize_c30_MASs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc30_MASsInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
  initialize_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c30_MASs(void *chartInstanceVar)
{
  enable_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c30_MASs(void *chartInstanceVar)
{
  disable_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c30_MASs(void *chartInstanceVar)
{
  sf_gateway_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c30_MASs(SimStruct* S)
{
  return get_sim_state_c30_MASs((SFc30_MASsInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c30_MASs(SimStruct* S, const mxArray *st)
{
  set_sim_state_c30_MASs((SFc30_MASsInstanceStruct*)sf_get_chart_instance_ptr(S),
    st);
}

static void sf_opaque_terminate_c30_MASs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_MASsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MASs_optimization_info();
    }

    finalize_c30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc30_MASs((SFc30_MASsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_MASs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_MASs((SFc30_MASsInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c30_MASs(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MASs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,30,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 30);
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,30);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,30,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,30,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 8; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1341359853U));
  ssSetChecksum1(S,(64740173U));
  ssSetChecksum2(S,(2753240075U));
  ssSetChecksum3(S,(1312549397U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c30_MASs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_MASs(SimStruct *S)
{
  SFc30_MASsInstanceStruct *chartInstance;
  chartInstance = (SFc30_MASsInstanceStruct *)utMalloc(sizeof
    (SFc30_MASsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc30_MASsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c30_MASs;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c30_MASs;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c30_MASs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c30_MASs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c30_MASs;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c30_MASs;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c30_MASs;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c30_MASs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_MASs;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_MASs;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c30_MASs;
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
  mdl_start_c30_MASs(chartInstance);
}

void c30_MASs_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_MASs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_MASs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_MASs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_MASs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
