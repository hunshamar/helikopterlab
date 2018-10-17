/*
 * Oppgave_4_fml.c
 *
 * Code generation for model "Oppgave_4_fml".
 *
 * Model version              : 1.72
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Oct 16 23:12:03 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Oppgave_4_fml.h"
#include "Oppgave_4_fml_private.h"
#include "Oppgave_4_fml_dt.h"

/* Block signals (auto storage) */
B_Oppgave_4_fml_T Oppgave_4_fml_B;

/* Continuous states */
X_Oppgave_4_fml_T Oppgave_4_fml_X;

/* Block states (auto storage) */
DW_Oppgave_4_fml_T Oppgave_4_fml_DW;

/* Real-time model */
RT_MODEL_Oppgave_4_fml_T Oppgave_4_fml_M_;
RT_MODEL_Oppgave_4_fml_T *const Oppgave_4_fml_M = &Oppgave_4_fml_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Oppgave_4_fml_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Oppgave_4_fml_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Oppgave_4_fml_M->Timing.TaskCounters.TID[1] == 0) {
    Oppgave_4_fml_M->Timing.RateInteraction.TID1_2 =
      (Oppgave_4_fml_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Oppgave_4_fml_M->Timing.perTaskSampleHits[5] =
      Oppgave_4_fml_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Oppgave_4_fml_M->Timing.TaskCounters.TID[2])++;
  if ((Oppgave_4_fml_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Oppgave_4_fml_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Oppgave_4_fml_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Oppgave_4_fml_output0(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_Sum[2];
  int32_T i;
  real_T tmp[5];
  real_T tmp_0[6];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T tmp_3[6];
  int32_T i_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  real_T u0;
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* set solver stop time */
    if (!(Oppgave_4_fml_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Oppgave_4_fml_M->solverInfo,
                            ((Oppgave_4_fml_M->Timing.clockTickH0 + 1) *
        Oppgave_4_fml_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Oppgave_4_fml_M->solverInfo,
                            ((Oppgave_4_fml_M->Timing.clockTick0 + 1) *
        Oppgave_4_fml_M->Timing.stepSize0 + Oppgave_4_fml_M->Timing.clockTickH0 *
        Oppgave_4_fml_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Oppgave_4_fml_M)) {
    Oppgave_4_fml_M->Timing.t[0] = rtsiGetT(&Oppgave_4_fml_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: Oppgave_4_fml/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Oppgave_4_fml_DW.HILReadEncoderTimebase_Task, 1,
         &Oppgave_4_fml_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          Oppgave_4_fml_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          Oppgave_4_fml_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          Oppgave_4_fml_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Integrator: '<S5>/Integrator2' */
  for (i = 0; i < 6; i++) {
    Oppgave_4_fml_B.Integrator2[i] = Oppgave_4_fml_X.Integrator2_CSTATE[i];
  }

  /* End of Integrator: '<S5>/Integrator2' */
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* Constant: '<Root>/Constant' */
    Oppgave_4_fml_B.Constant = Oppgave_4_fml_P.Constant_Value;
  }

  /* RateTransition: '<S3>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    if (Oppgave_4_fml_M->Timing.RateInteraction.TID1_2) {
      Oppgave_4_fml_B.RateTransitionx = Oppgave_4_fml_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (Oppgave_4_fml_B.RateTransitionx > Oppgave_4_fml_P.DeadZonex_End) {
      u0 = Oppgave_4_fml_B.RateTransitionx - Oppgave_4_fml_P.DeadZonex_End;
    } else if (Oppgave_4_fml_B.RateTransitionx >=
               Oppgave_4_fml_P.DeadZonex_Start) {
      u0 = 0.0;
    } else {
      u0 = Oppgave_4_fml_B.RateTransitionx - Oppgave_4_fml_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    Oppgave_4_fml_B.Joystick_gain_x = Oppgave_4_fml_P.Gainx_Gain * u0 *
      Oppgave_4_fml_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (Oppgave_4_fml_M->Timing.RateInteraction.TID1_2) {
      Oppgave_4_fml_B.RateTransitiony = Oppgave_4_fml_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (Oppgave_4_fml_B.RateTransitiony > Oppgave_4_fml_P.DeadZoney_End) {
      u0 = Oppgave_4_fml_B.RateTransitiony - Oppgave_4_fml_P.DeadZoney_End;
    } else if (Oppgave_4_fml_B.RateTransitiony >=
               Oppgave_4_fml_P.DeadZoney_Start) {
      u0 = 0.0;
    } else {
      u0 = Oppgave_4_fml_B.RateTransitiony - Oppgave_4_fml_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    Oppgave_4_fml_B.Joystick_gain_y = Oppgave_4_fml_P.Gainy_Gain * u0 *
      Oppgave_4_fml_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain P ' incorporates:
     *  SignalConversion: '<Root>/TmpSignal ConversionAtGain P Inport1'
     */
    Oppgave_4_fml_B.GainP[0] = 0.0;
    Oppgave_4_fml_B.GainP[0] += Oppgave_4_fml_P.P[0] *
      Oppgave_4_fml_B.Joystick_gain_x;
    Oppgave_4_fml_B.GainP[0] += Oppgave_4_fml_P.P[2] *
      Oppgave_4_fml_B.Joystick_gain_y;
    Oppgave_4_fml_B.GainP[1] = 0.0;
    Oppgave_4_fml_B.GainP[1] += Oppgave_4_fml_P.P[1] *
      Oppgave_4_fml_B.Joystick_gain_x;
    Oppgave_4_fml_B.GainP[1] += Oppgave_4_fml_P.P[3] *
      Oppgave_4_fml_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S3>/Rate Transition: x' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtK Inport1' incorporates:
   *  Gain: '<Root>/K '
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S4>/Integrator2'
   */
  tmp[0] = Oppgave_4_fml_B.Integrator2[0];
  tmp[1] = Oppgave_4_fml_B.Integrator2[1];
  tmp[2] = Oppgave_4_fml_B.Integrator2[3];
  tmp[3] = Oppgave_4_fml_X.Integrator1_CSTATE;
  tmp[4] = Oppgave_4_fml_X.Integrator2_CSTATE_l;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/K '
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += Oppgave_4_fml_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    rtb_Sum[i] = Oppgave_4_fml_B.GainP[i] - u0;
  }

  /* End of Sum: '<Root>/Sum' */

  /* Sum: '<Root>/Sum4' */
  Oppgave_4_fml_B.Sum4 = rtb_Sum[0] + Oppgave_4_fml_B.Constant;
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* Gain: '<S2>/Elevation: Count to rad' */
    Oppgave_4_fml_B.ElevationCounttorad =
      Oppgave_4_fml_P.ElevationCounttorad_Gain * rtb_HILReadEncoderTimebase_o3;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S2>/Elevation: Transfer Fcn'
   */
  Oppgave_4_fml_B.Gain = (Oppgave_4_fml_P.ElevationTransferFcn_C *
    Oppgave_4_fml_X.ElevationTransferFcn_CSTATE +
    Oppgave_4_fml_P.ElevationTransferFcn_D * Oppgave_4_fml_B.ElevationCounttorad)
    * Oppgave_4_fml_P.Gain_Gain;
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S13>/Gain'
     */
    Oppgave_4_fml_B.Sum = Oppgave_4_fml_P.Gain_Gain_l *
      Oppgave_4_fml_B.ElevationCounttorad + Oppgave_4_fml_P.Constant_Value_d;

    /* Gain: '<S2>/Pitch: Count to rad' */
    Oppgave_4_fml_B.PitchCounttorad = Oppgave_4_fml_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S15>/Gain'
     */
    Oppgave_4_fml_B.Sum1 = Oppgave_4_fml_P.Gain_Gain_a *
      Oppgave_4_fml_B.PitchCounttorad - Oppgave_4_fml_P.Constant1_Value;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  Oppgave_4_fml_B.Gain_b = (Oppgave_4_fml_P.PitchTransferFcn_C *
    Oppgave_4_fml_X.PitchTransferFcn_CSTATE + Oppgave_4_fml_P.PitchTransferFcn_D
    * Oppgave_4_fml_B.PitchCounttorad) * Oppgave_4_fml_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* Gain: '<S2>/Travel: Count to rad' */
    Oppgave_4_fml_B.TravelCounttorad = Oppgave_4_fml_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  TransferFcn: '<S2>/Travel: Transfer Fcn'
   */
  Oppgave_4_fml_B.Gain_d = (Oppgave_4_fml_P.TravelTransferFcn_C *
    Oppgave_4_fml_X.TravelTransferFcn_CSTATE +
    Oppgave_4_fml_P.TravelTransferFcn_D * Oppgave_4_fml_B.TravelCounttorad) *
    Oppgave_4_fml_P.Gain_Gain_lu;
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* Gain: '<S17>/Gain' */
    Oppgave_4_fml_B.Gain_p = Oppgave_4_fml_P.Gain_Gain_ar *
      Oppgave_4_fml_B.TravelCounttorad;

    /* Gain: '<S7>/Gain1' */
    Oppgave_4_fml_B.Gain1 = Oppgave_4_fml_P.Gain1_Gain * Oppgave_4_fml_B.Sum;

    /* Gain: '<S9>/Gain1' */
    Oppgave_4_fml_B.Gain1_g = Oppgave_4_fml_P.Gain1_Gain_a *
      Oppgave_4_fml_B.Sum1;

    /* Gain: '<S11>/Gain1' */
    Oppgave_4_fml_B.Gain1_c = Oppgave_4_fml_P.Gain1_Gain_m *
      Oppgave_4_fml_B.Gain_p;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_Sum[1] + Oppgave_4_fml_B.Sum4) * Oppgave_4_fml_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > Oppgave_4_fml_P.FrontmotorSaturation_UpperSat) {
    Oppgave_4_fml_B.FrontmotorSaturation =
      Oppgave_4_fml_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < Oppgave_4_fml_P.FrontmotorSaturation_LowerSat) {
    Oppgave_4_fml_B.FrontmotorSaturation =
      Oppgave_4_fml_P.FrontmotorSaturation_LowerSat;
  } else {
    Oppgave_4_fml_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (Oppgave_4_fml_B.Sum4 - rtb_Sum[1]) * Oppgave_4_fml_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > Oppgave_4_fml_P.BackmotorSaturation_UpperSat) {
    Oppgave_4_fml_B.BackmotorSaturation =
      Oppgave_4_fml_P.BackmotorSaturation_UpperSat;
  } else if (u0 < Oppgave_4_fml_P.BackmotorSaturation_LowerSat) {
    Oppgave_4_fml_B.BackmotorSaturation =
      Oppgave_4_fml_P.BackmotorSaturation_LowerSat;
  } else {
    Oppgave_4_fml_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: Oppgave_4_fml/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      Oppgave_4_fml_DW.HILWriteAnalog_Buffer[0] =
        Oppgave_4_fml_B.FrontmotorSaturation;
      Oppgave_4_fml_DW.HILWriteAnalog_Buffer[1] =
        Oppgave_4_fml_B.BackmotorSaturation;
      result = hil_write_analog(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILWriteAnalog_channels, 2,
        &Oppgave_4_fml_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      }
    }
  }

  /* Sum: '<S4>/Sum2' */
  Oppgave_4_fml_B.Sum2 = Oppgave_4_fml_B.Integrator2[0] -
    Oppgave_4_fml_B.Joystick_gain_x;

  /* Sum: '<S4>/Sum1' */
  Oppgave_4_fml_B.Sum1_d = Oppgave_4_fml_B.Integrator2[3] -
    Oppgave_4_fml_B.Joystick_gain_y;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtK 2Inport1' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S8>/Gain1'
   */
  tmp_0[0] = Oppgave_4_fml_B.Gain1_g;
  tmp_0[1] = Oppgave_4_fml_P.Gain1_Gain_k * Oppgave_4_fml_B.Gain_b;
  tmp_0[2] = Oppgave_4_fml_B.Gain1;
  tmp_0[3] = Oppgave_4_fml_P.Gain1_Gain_c * Oppgave_4_fml_B.Gain;
  tmp_0[4] = Oppgave_4_fml_B.Gain1_c;
  tmp_0[5] = Oppgave_4_fml_P.Gain1_Gain_n * Oppgave_4_fml_B.Gain_d;

  /* Gain: '<S5>/K 2' incorporates:
   *  Sum: '<S5>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_1[i] += Oppgave_4_fml_P.C_L[3 * i_0 + i] * tmp_0[i_0];
    }
  }

  /* End of Gain: '<S5>/K 2' */

  /* Gain: '<S5>/K 3' incorporates:
   *  Sum: '<S5>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_2[i] += Oppgave_4_fml_P.C_L[3 * i_0 + i] *
        Oppgave_4_fml_B.Integrator2[i_0];
    }
  }

  /* End of Gain: '<S5>/K 3' */

  /* Sum: '<S5>/Sum5' incorporates:
   *  Gain: '<S5>/K 5'
   */
  u0 = tmp_1[0] - tmp_2[0];
  unnamed_idx_1 = tmp_1[1] - tmp_2[1];
  unnamed_idx_2 = tmp_1[2] - tmp_2[2];
  for (i = 0; i < 6; i++) {
    /* Gain: '<S5>/K 5' incorporates:
     *  Sum: '<S5>/Sum1'
     */
    tmp_0[i] = Oppgave_4_fml_P.L[i + 12] * unnamed_idx_2 + (Oppgave_4_fml_P.L[i
      + 6] * unnamed_idx_1 + Oppgave_4_fml_P.L[i] * u0);

    /* Gain: '<S5>/K 4' incorporates:
     *  SignalConversion: '<S5>/TmpSignal ConversionAtK 4Inport1'
     *  Sum: '<S5>/Sum1'
     */
    tmp_3[i] = Oppgave_4_fml_P.B_L[i + 6] * rtb_Sum[0] + Oppgave_4_fml_P.B_L[i] *
      rtb_Sum[1];
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/K 1'
   */
  for (i = 0; i < 6; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      u0 += Oppgave_4_fml_P.A_L[6 * i_0 + i] * Oppgave_4_fml_B.Integrator2[i_0];
    }

    Oppgave_4_fml_B.Sum1_j[i] = (tmp_0[i] + tmp_3[i]) + u0;
  }

  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    /* ToFile: '<Root>/To File1' */
    if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
      {
        if (!(++Oppgave_4_fml_DW.ToFile1_IWORK.Decimation % 1) &&
            (Oppgave_4_fml_DW.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
          FILE *fp = (FILE *) Oppgave_4_fml_DW.ToFile1_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[2];
            Oppgave_4_fml_DW.ToFile1_IWORK.Decimation = 0;
            u[0] = Oppgave_4_fml_M->Timing.t[1];
            u[1] = 0.0;
            if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
              rtmSetErrorStatus(Oppgave_4_fml_M,
                                "Error writing to MAT-file actualstates2s.mat");
              return;
            }

            if (((++Oppgave_4_fml_DW.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file actualstates2s.mat.\n");
            }
          }
        }
      }
    }

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
      {
        if (!(++Oppgave_4_fml_DW.ToFile_IWORK.Decimation % 1) &&
            (Oppgave_4_fml_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
          FILE *fp = (FILE *) Oppgave_4_fml_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[2];
            Oppgave_4_fml_DW.ToFile_IWORK.Decimation = 0;
            u[0] = Oppgave_4_fml_M->Timing.t[1];
            u[1] = 0.0;
            if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
              rtmSetErrorStatus(Oppgave_4_fml_M,
                                "Error writing to MAT-file estimates2s.mat");
              return;
            }

            if (((++Oppgave_4_fml_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file estimates2s.mat.\n");
            }
          }
        }
      }
    }
  }
}

/* Model update function for TID0 */
void Oppgave_4_fml_update0(void)       /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Oppgave_4_fml_M)) {
    rt_ertODEUpdateContinuousStates(&Oppgave_4_fml_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Oppgave_4_fml_M->Timing.clockTick0)) {
    ++Oppgave_4_fml_M->Timing.clockTickH0;
  }

  Oppgave_4_fml_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Oppgave_4_fml_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Oppgave_4_fml_M->Timing.clockTick1)) {
    ++Oppgave_4_fml_M->Timing.clockTickH1;
  }

  Oppgave_4_fml_M->Timing.t[1] = Oppgave_4_fml_M->Timing.clockTick1 *
    Oppgave_4_fml_M->Timing.stepSize1 + Oppgave_4_fml_M->Timing.clockTickH1 *
    Oppgave_4_fml_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Oppgave_4_fml_derivatives(void)
{
  int32_T i;
  XDot_Oppgave_4_fml_T *_rtXdot;
  _rtXdot = ((XDot_Oppgave_4_fml_T *) Oppgave_4_fml_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator2_CSTATE[i] = Oppgave_4_fml_B.Sum1_j[i];
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator2' */

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Oppgave_4_fml_B.Sum2;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_l = Oppgave_4_fml_B.Sum1_d;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += Oppgave_4_fml_P.ElevationTransferFcn_A
    * Oppgave_4_fml_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += Oppgave_4_fml_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += Oppgave_4_fml_P.PitchTransferFcn_A *
    Oppgave_4_fml_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += Oppgave_4_fml_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += Oppgave_4_fml_P.TravelTransferFcn_A *
    Oppgave_4_fml_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += Oppgave_4_fml_B.TravelCounttorad;
}

/* Model output function for TID2 */
void Oppgave_4_fml_output2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: Oppgave_4_fml/Joystick/Game Controller (game_controller_block) */
  {
    if (Oppgave_4_fml_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(Oppgave_4_fml_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        Oppgave_4_fml_B.GameController_o4 = state.x;
        Oppgave_4_fml_B.GameController_o5 = state.y;
      }
    } else {
      Oppgave_4_fml_B.GameController_o4 = 0;
      Oppgave_4_fml_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void Oppgave_4_fml_update2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  Oppgave_4_fml_DW.RateTransitionx_Buffer0 = Oppgave_4_fml_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  Oppgave_4_fml_DW.RateTransitiony_Buffer0 = Oppgave_4_fml_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Oppgave_4_fml_M->Timing.clockTick2)) {
    ++Oppgave_4_fml_M->Timing.clockTickH2;
  }

  Oppgave_4_fml_M->Timing.t[2] = Oppgave_4_fml_M->Timing.clockTick2 *
    Oppgave_4_fml_M->Timing.stepSize2 + Oppgave_4_fml_M->Timing.clockTickH2 *
    Oppgave_4_fml_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void Oppgave_4_fml_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Oppgave_4_fml_output0();
    break;

   case 2 :
    Oppgave_4_fml_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void Oppgave_4_fml_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Oppgave_4_fml_update0();
    break;

   case 2 :
    Oppgave_4_fml_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Oppgave_4_fml_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Oppgave_4_fml/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Oppgave_4_fml_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Oppgave_4_fml_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Oppgave_4_fml_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      return;
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Oppgave_4_fml_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Oppgave_4_fml_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Oppgave_4_fml_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Oppgave_4_fml_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_analog_input_chan, 8U,
        &Oppgave_4_fml_DW.HILInitialize_AIMinimums[0],
        &Oppgave_4_fml_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_analog_output && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Oppgave_4_fml_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Oppgave_4_fml_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Oppgave_4_fml_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Oppgave_4_fml_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_analog_output_cha, 8U,
        &Oppgave_4_fml_DW.HILInitialize_AOMinimums[0],
        &Oppgave_4_fml_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Oppgave_4_fml_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_analog_output_cha, 8U,
        &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if (Oppgave_4_fml_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Oppgave_4_fml_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Oppgave_4_fml_DW.HILInitialize_Card,
         Oppgave_4_fml_P.HILInitialize_analog_output_cha, 8U,
         &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_encoder_param && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Oppgave_4_fml_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Oppgave_4_fml_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Oppgave_4_fml_DW.HILInitialize_Card,
         Oppgave_4_fml_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &Oppgave_4_fml_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_encoder_count && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Oppgave_4_fml_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            Oppgave_4_fml_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_encoder_channels, 8U,
        &Oppgave_4_fml_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Oppgave_4_fml_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Oppgave_4_fml_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Oppgave_4_fml_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Oppgave_4_fml_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &Oppgave_4_fml_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Oppgave_4_fml_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Oppgave_4_fml_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Oppgave_4_fml_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = Oppgave_4_fml_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Oppgave_4_fml_DW.HILInitialize_Card,
          &Oppgave_4_fml_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Oppgave_4_fml_DW.HILInitialize_Card,
          &Oppgave_4_fml_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Oppgave_4_fml_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Oppgave_4_fml_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Oppgave_4_fml_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Oppgave_4_fml_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Oppgave_4_fml_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Oppgave_4_fml_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &Oppgave_4_fml_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Oppgave_4_fml_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Oppgave_4_fml_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Oppgave_4_fml_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Oppgave_4_fml_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Oppgave_4_fml_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_pwm_channels, 8U,
        &Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[0],
        &Oppgave_4_fml_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Oppgave_4_fml_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Oppgave_4_fml_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Oppgave_4_fml_DW.HILInitialize_Card,
        Oppgave_4_fml_P.HILInitialize_pwm_channels, 8U,
        &Oppgave_4_fml_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }

    if (Oppgave_4_fml_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &Oppgave_4_fml_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Oppgave_4_fml_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Oppgave_4_fml_DW.HILInitialize_Card,
         Oppgave_4_fml_P.HILInitialize_pwm_channels, 8U,
         &Oppgave_4_fml_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: Oppgave_4_fml/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Oppgave_4_fml_DW.HILInitialize_Card,
      Oppgave_4_fml_P.HILReadEncoderTimebase_samples_,
      Oppgave_4_fml_P.HILReadEncoderTimebase_channels, 3,
      &Oppgave_4_fml_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  Oppgave_4_fml_B.RateTransitionx = Oppgave_4_fml_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  Oppgave_4_fml_B.RateTransitiony = Oppgave_4_fml_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: Oppgave_4_fml/Joystick/Game Controller (game_controller_block) */
  {
    if (Oppgave_4_fml_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (Oppgave_4_fml_P.GameController_ControllerNumber,
         Oppgave_4_fml_P.GameController_BufferSize, deadzone, saturation,
         Oppgave_4_fml_P.GameController_AutoCenter, 0, 1.0,
         &Oppgave_4_fml_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
      }
    }
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    char fileName[509] = "actualstates2s.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Oppgave_4_fml_M,
                        "Error creating .mat file actualstates2s.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(Oppgave_4_fml_M,
                        "Error writing mat file header to file actualstates2s.mat");
      return;
    }

    Oppgave_4_fml_DW.ToFile1_IWORK.Count = 0;
    Oppgave_4_fml_DW.ToFile1_IWORK.Decimation = -1;
    Oppgave_4_fml_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "estimates2s.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Oppgave_4_fml_M,
                        "Error creating .mat file estimates2s.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(Oppgave_4_fml_M,
                        "Error writing mat file header to file estimates2s.mat");
      return;
    }

    Oppgave_4_fml_DW.ToFile_IWORK.Count = 0;
    Oppgave_4_fml_DW.ToFile_IWORK.Decimation = -1;
    Oppgave_4_fml_DW.ToFile_PWORK.FilePtr = fp;
  }

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    for (i = 0; i < 6; i++) {
      Oppgave_4_fml_X.Integrator2_CSTATE[i] = Oppgave_4_fml_P.Integrator2_IC;
    }

    /* End of InitializeConditions for Integrator: '<S5>/Integrator2' */

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    Oppgave_4_fml_X.Integrator1_CSTATE = Oppgave_4_fml_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S4>/Integrator2' */
    Oppgave_4_fml_X.Integrator2_CSTATE_l = Oppgave_4_fml_P.Integrator2_IC_i;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    Oppgave_4_fml_DW.RateTransitionx_Buffer0 =
      Oppgave_4_fml_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    Oppgave_4_fml_DW.RateTransitiony_Buffer0 =
      Oppgave_4_fml_P.RateTransitiony_X0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    Oppgave_4_fml_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    Oppgave_4_fml_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    Oppgave_4_fml_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void Oppgave_4_fml_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Oppgave_4_fml/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Oppgave_4_fml_DW.HILInitialize_Card);
    hil_monitor_stop_all(Oppgave_4_fml_DW.HILInitialize_Card);
    is_switching = false;
    if ((Oppgave_4_fml_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Oppgave_4_fml_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Oppgave_4_fml_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (Oppgave_4_fml_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Oppgave_4_fml_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Oppgave_4_fml_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Oppgave_4_fml_DW.HILInitialize_Card
                         , Oppgave_4_fml_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Oppgave_4_fml_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0]
                         , &Oppgave_4_fml_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Oppgave_4_fml_DW.HILInitialize_Card,
            Oppgave_4_fml_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &Oppgave_4_fml_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Oppgave_4_fml_DW.HILInitialize_Card,
            Oppgave_4_fml_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &Oppgave_4_fml_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Oppgave_4_fml_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Oppgave_4_fml_DW.HILInitialize_Card);
    hil_monitor_delete_all(Oppgave_4_fml_DW.HILInitialize_Card);
    hil_close(Oppgave_4_fml_DW.HILInitialize_Card);
    Oppgave_4_fml_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: Oppgave_4_fml/Joystick/Game Controller (game_controller_block) */
  {
    if (Oppgave_4_fml_P.GameController_Enabled) {
      game_controller_close(Oppgave_4_fml_DW.GameController_Controller);
      Oppgave_4_fml_DW.GameController_Controller = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) Oppgave_4_fml_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "actualstates2s.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error closing MAT-file actualstates2s.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error reopening MAT-file actualstates2s.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, Oppgave_4_fml_DW.ToFile1_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error writing header for ans to MAT-file actualstates2s.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error closing MAT-file actualstates2s.mat");
        return;
      }

      Oppgave_4_fml_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) Oppgave_4_fml_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "estimates2s.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error closing MAT-file estimates2s.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error reopening MAT-file estimates2s.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, Oppgave_4_fml_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error writing header for ans to MAT-file estimates2s.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Oppgave_4_fml_M,
                          "Error closing MAT-file estimates2s.mat");
        return;
      }

      Oppgave_4_fml_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Oppgave_4_fml_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Oppgave_4_fml_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Oppgave_4_fml_initialize();
}

void MdlTerminate(void)
{
  Oppgave_4_fml_terminate();
}

/* Registration function */
RT_MODEL_Oppgave_4_fml_T *Oppgave_4_fml(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Oppgave_4_fml_M, 0,
                sizeof(RT_MODEL_Oppgave_4_fml_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Oppgave_4_fml_M->solverInfo,
                          &Oppgave_4_fml_M->Timing.simTimeStep);
    rtsiSetTPtr(&Oppgave_4_fml_M->solverInfo, &rtmGetTPtr(Oppgave_4_fml_M));
    rtsiSetStepSizePtr(&Oppgave_4_fml_M->solverInfo,
                       &Oppgave_4_fml_M->Timing.stepSize0);
    rtsiSetdXPtr(&Oppgave_4_fml_M->solverInfo,
                 &Oppgave_4_fml_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Oppgave_4_fml_M->solverInfo, (real_T **)
                         &Oppgave_4_fml_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Oppgave_4_fml_M->solverInfo,
      &Oppgave_4_fml_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Oppgave_4_fml_M->solverInfo, (&rtmGetErrorStatus
      (Oppgave_4_fml_M)));
    rtsiSetRTModelPtr(&Oppgave_4_fml_M->solverInfo, Oppgave_4_fml_M);
  }

  rtsiSetSimTimeStep(&Oppgave_4_fml_M->solverInfo, MAJOR_TIME_STEP);
  Oppgave_4_fml_M->ModelData.intgData.f[0] = Oppgave_4_fml_M->ModelData.odeF[0];
  Oppgave_4_fml_M->ModelData.contStates = ((real_T *) &Oppgave_4_fml_X);
  rtsiSetSolverData(&Oppgave_4_fml_M->solverInfo, (void *)
                    &Oppgave_4_fml_M->ModelData.intgData);
  rtsiSetSolverName(&Oppgave_4_fml_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Oppgave_4_fml_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Oppgave_4_fml_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Oppgave_4_fml_M->Timing.sampleTimes =
      (&Oppgave_4_fml_M->Timing.sampleTimesArray[0]);
    Oppgave_4_fml_M->Timing.offsetTimes =
      (&Oppgave_4_fml_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Oppgave_4_fml_M->Timing.sampleTimes[0] = (0.0);
    Oppgave_4_fml_M->Timing.sampleTimes[1] = (0.002);
    Oppgave_4_fml_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    Oppgave_4_fml_M->Timing.offsetTimes[0] = (0.0);
    Oppgave_4_fml_M->Timing.offsetTimes[1] = (0.0);
    Oppgave_4_fml_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Oppgave_4_fml_M, &Oppgave_4_fml_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Oppgave_4_fml_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Oppgave_4_fml_M->Timing.perTaskSampleHitsArray;
    Oppgave_4_fml_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Oppgave_4_fml_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Oppgave_4_fml_M, -1);
  Oppgave_4_fml_M->Timing.stepSize0 = 0.002;
  Oppgave_4_fml_M->Timing.stepSize1 = 0.002;
  Oppgave_4_fml_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  Oppgave_4_fml_M->Sizes.checksums[0] = (925455789U);
  Oppgave_4_fml_M->Sizes.checksums[1] = (2141067826U);
  Oppgave_4_fml_M->Sizes.checksums[2] = (3809046519U);
  Oppgave_4_fml_M->Sizes.checksums[3] = (382735183U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Oppgave_4_fml_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Oppgave_4_fml_M->extModeInfo,
      &Oppgave_4_fml_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Oppgave_4_fml_M->extModeInfo,
                        Oppgave_4_fml_M->Sizes.checksums);
    rteiSetTPtr(Oppgave_4_fml_M->extModeInfo, rtmGetTPtr(Oppgave_4_fml_M));
  }

  Oppgave_4_fml_M->solverInfoPtr = (&Oppgave_4_fml_M->solverInfo);
  Oppgave_4_fml_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Oppgave_4_fml_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Oppgave_4_fml_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Oppgave_4_fml_M->ModelData.blockIO = ((void *) &Oppgave_4_fml_B);

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      Oppgave_4_fml_B.Integrator2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      Oppgave_4_fml_B.Sum1_j[i] = 0.0;
    }

    Oppgave_4_fml_B.Constant = 0.0;
    Oppgave_4_fml_B.RateTransitionx = 0.0;
    Oppgave_4_fml_B.Joystick_gain_x = 0.0;
    Oppgave_4_fml_B.RateTransitiony = 0.0;
    Oppgave_4_fml_B.Joystick_gain_y = 0.0;
    Oppgave_4_fml_B.GainP[0] = 0.0;
    Oppgave_4_fml_B.GainP[1] = 0.0;
    Oppgave_4_fml_B.Sum4 = 0.0;
    Oppgave_4_fml_B.ElevationCounttorad = 0.0;
    Oppgave_4_fml_B.Gain = 0.0;
    Oppgave_4_fml_B.Sum = 0.0;
    Oppgave_4_fml_B.PitchCounttorad = 0.0;
    Oppgave_4_fml_B.Sum1 = 0.0;
    Oppgave_4_fml_B.Gain_b = 0.0;
    Oppgave_4_fml_B.TravelCounttorad = 0.0;
    Oppgave_4_fml_B.Gain_d = 0.0;
    Oppgave_4_fml_B.Gain_p = 0.0;
    Oppgave_4_fml_B.Gain1 = 0.0;
    Oppgave_4_fml_B.Gain1_g = 0.0;
    Oppgave_4_fml_B.Gain1_c = 0.0;
    Oppgave_4_fml_B.FrontmotorSaturation = 0.0;
    Oppgave_4_fml_B.BackmotorSaturation = 0.0;
    Oppgave_4_fml_B.GameController_o4 = 0.0;
    Oppgave_4_fml_B.GameController_o5 = 0.0;
    Oppgave_4_fml_B.Sum2 = 0.0;
    Oppgave_4_fml_B.Sum1_d = 0.0;
  }

  /* parameters */
  Oppgave_4_fml_M->ModelData.defaultParam = ((real_T *)&Oppgave_4_fml_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Oppgave_4_fml_X;
    Oppgave_4_fml_M->ModelData.contStates = (x);
    (void) memset((void *)&Oppgave_4_fml_X, 0,
                  sizeof(X_Oppgave_4_fml_T));
  }

  /* states (dwork) */
  Oppgave_4_fml_M->ModelData.dwork = ((void *) &Oppgave_4_fml_DW);
  (void) memset((void *)&Oppgave_4_fml_DW, 0,
                sizeof(DW_Oppgave_4_fml_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Oppgave_4_fml_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  Oppgave_4_fml_DW.RateTransitionx_Buffer0 = 0.0;
  Oppgave_4_fml_DW.RateTransitiony_Buffer0 = 0.0;
  Oppgave_4_fml_DW.HILWriteAnalog_Buffer[0] = 0.0;
  Oppgave_4_fml_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Oppgave_4_fml_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Oppgave_4_fml_M->Sizes.numContStates = (11);/* Number of continuous states */
  Oppgave_4_fml_M->Sizes.numY = (0);   /* Number of model outputs */
  Oppgave_4_fml_M->Sizes.numU = (0);   /* Number of model inputs */
  Oppgave_4_fml_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Oppgave_4_fml_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Oppgave_4_fml_M->Sizes.numBlocks = (73);/* Number of blocks */
  Oppgave_4_fml_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  Oppgave_4_fml_M->Sizes.numBlockPrms = (251);/* Sum of parameter "widths" */
  return Oppgave_4_fml_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
