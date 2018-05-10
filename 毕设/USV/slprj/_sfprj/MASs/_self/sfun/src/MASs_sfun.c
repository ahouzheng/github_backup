/* Include files */

#include "MASs_sfun.h"
#include "MASs_sfun_debug_macros.h"
#include "c8_MASs.h"
#include "c15_MASs.h"
#include "c22_MASs.h"
#include "c29_MASs.h"
#include "c36_MASs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _MASsMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void MASs_initializer(void)
{
}

void MASs_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_MASs_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==8) {
    c8_MASs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_MASs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_MASs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_MASs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_MASs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_MASs_uses_exported_functions(int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_MASs_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3724352861U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3015960371U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1416158836U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1841808927U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 8:
        {
          extern void sf_c8_MASs_get_check_sum(mxArray *plhs[]);
          sf_c8_MASs_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_MASs_get_check_sum(mxArray *plhs[]);
          sf_c15_MASs_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_MASs_get_check_sum(mxArray *plhs[]);
          sf_c22_MASs_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_MASs_get_check_sum(mxArray *plhs[]);
          sf_c29_MASs_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_MASs_get_check_sum(mxArray *plhs[]);
          sf_c36_MASs_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2228015324U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1719833054U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4047056744U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3399837229U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(930993002U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3848107051U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3084672818U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1137310953U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_MASs_autoinheritance_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(aiChksum, "S7gGSFTXzXNRQ3ZUCmf5FC") == 0) {
          extern mxArray *sf_c8_MASs_get_autoinheritance_info(void);
          plhs[0] = sf_c8_MASs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "S7gGSFTXzXNRQ3ZUCmf5FC") == 0) {
          extern mxArray *sf_c15_MASs_get_autoinheritance_info(void);
          plhs[0] = sf_c15_MASs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "S7gGSFTXzXNRQ3ZUCmf5FC") == 0) {
          extern mxArray *sf_c22_MASs_get_autoinheritance_info(void);
          plhs[0] = sf_c22_MASs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "S7gGSFTXzXNRQ3ZUCmf5FC") == 0) {
          extern mxArray *sf_c29_MASs_get_autoinheritance_info(void);
          plhs[0] = sf_c29_MASs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "S7gGSFTXzXNRQ3ZUCmf5FC") == 0) {
          extern mxArray *sf_c36_MASs_get_autoinheritance_info(void);
          plhs[0] = sf_c36_MASs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_MASs_get_eml_resolved_functions_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        extern const mxArray *sf_c8_MASs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_MASs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_MASs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_MASs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_MASs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_MASs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray *sf_c29_MASs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_MASs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray *sf_c36_MASs_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_MASs_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_MASs_third_party_uses_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c8_MASs_third_party_uses_info(void);
          plhs[0] = sf_c8_MASs_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c15_MASs_third_party_uses_info(void);
          plhs[0] = sf_c15_MASs_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c22_MASs_third_party_uses_info(void);
          plhs[0] = sf_c22_MASs_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c29_MASs_third_party_uses_info(void);
          plhs[0] = sf_c29_MASs_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c36_MASs_third_party_uses_info(void);
          plhs[0] = sf_c36_MASs_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_MASs_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c8_MASs_jit_fallback_info(void);
          plhs[0] = sf_c8_MASs_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c15_MASs_jit_fallback_info(void);
          plhs[0] = sf_c15_MASs_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c22_MASs_jit_fallback_info(void);
          plhs[0] = sf_c22_MASs_jit_fallback_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c29_MASs_jit_fallback_info(void);
          plhs[0] = sf_c29_MASs_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c36_MASs_jit_fallback_info(void);
          plhs[0] = sf_c36_MASs_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_MASs_updateBuildInfo_args_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 8:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c8_MASs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_MASs_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c15_MASs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_MASs_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c22_MASs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_MASs_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c29_MASs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_MASs_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
          extern mxArray *sf_c36_MASs_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_MASs_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_MASs_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 8:
    {
      if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
        extern mxArray *sf_c8_MASs_get_post_codegen_info(void);
        plhs[0] = sf_c8_MASs_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
        extern mxArray *sf_c15_MASs_get_post_codegen_info(void);
        plhs[0] = sf_c15_MASs_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
        extern mxArray *sf_c22_MASs_get_post_codegen_info(void);
        plhs[0] = sf_c22_MASs_get_post_codegen_info();
        return;
      }
    }
    break;

   case 29:
    {
      if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
        extern mxArray *sf_c29_MASs_get_post_codegen_info(void);
        plhs[0] = sf_c29_MASs_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "sVnreL6srNnvOymngDFKm9D") == 0) {
        extern mxArray *sf_c36_MASs_get_post_codegen_info(void);
        plhs[0] = sf_c36_MASs_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void MASs_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _MASsMachineNumber_ = sf_debug_initialize_machine(debugInstance,"MASs","sfun",
    0,35,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_MASsMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_MASsMachineNumber_,0);
}

void MASs_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_MASs_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("MASs", "MASs");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_MASs_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
