/*
 * saman.c
 *
 * Code generation for model "saman".
 *
 * Model version              : 1.64
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sat Oct 13 16:15:51 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "saman.h"
#include "saman_private.h"
#include "saman_dt.h"

/* Block signals (auto storage) */
B_saman_T saman_B;

/* Continuous states */
X_saman_T saman_X;

/* Block states (auto storage) */
DW_saman_T saman_DW;

/* Real-time model */
RT_MODEL_saman_T saman_M_;
RT_MODEL_saman_T *const saman_M = &saman_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(saman_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(saman_M, 2);
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
  if (saman_M->Timing.TaskCounters.TID[1] == 0) {
    saman_M->Timing.RateInteraction.TID1_2 = (saman_M->Timing.TaskCounters.TID[2]
      == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    saman_M->Timing.perTaskSampleHits[5] =
      saman_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (saman_M->Timing.TaskCounters.TID[2])++;
  if ((saman_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    saman_M->Timing.TaskCounters.TID[2] = 0;
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
  saman_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void saman_output0(void)               /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_DeadZoney;
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
  if (rtmIsMajorTimeStep(saman_M)) {
    /* set solver stop time */
    if (!(saman_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&saman_M->solverInfo, ((saman_M->Timing.clockTickH0
        + 1) * saman_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&saman_M->solverInfo, ((saman_M->Timing.clockTick0 +
        1) * saman_M->Timing.stepSize0 + saman_M->Timing.clockTickH0 *
        saman_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(saman_M)) {
    saman_M->Timing.t[0] = rtsiGetT(&saman_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(saman_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: saman/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(saman_DW.HILReadEncoderTimebase_Task, 1,
        &saman_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = saman_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_DeadZoney = saman_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 = saman_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Integrator: '<S5>/Integrator2' */
  for (i = 0; i < 6; i++) {
    saman_B.Integrator2[i] = saman_X.Integrator2_CSTATE[i];
  }

  /* End of Integrator: '<S5>/Integrator2' */
  if (rtmIsMajorTimeStep(saman_M)) {
    /* Gain: '<S2>/Pitch: Count to rad' */
    saman_B.PitchCounttorad = saman_P.PitchCounttorad_Gain * rtb_DeadZoney;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  saman_B.Gain = (saman_P.PitchTransferFcn_C * saman_X.PitchTransferFcn_CSTATE +
                  saman_P.PitchTransferFcn_D * saman_B.PitchCounttorad) *
    saman_P.Gain_Gain;

  /* Gain: '<S8>/Gain1' */
  saman_B.Gain1 = saman_P.Gain1_Gain * saman_B.Gain;
  if (rtmIsMajorTimeStep(saman_M)) {
  }

  /* RateTransition: '<S3>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(saman_M)) {
    if (saman_M->Timing.RateInteraction.TID1_2) {
      saman_B.RateTransitionx = saman_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (saman_B.RateTransitionx > saman_P.DeadZonex_End) {
      rtb_DeadZoney = saman_B.RateTransitionx - saman_P.DeadZonex_End;
    } else if (saman_B.RateTransitionx >= saman_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = saman_B.RateTransitionx - saman_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    saman_B.Joystick_gain_x = saman_P.Gainx_Gain * rtb_DeadZoney *
      saman_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (saman_M->Timing.RateInteraction.TID1_2) {
      saman_B.RateTransitiony = saman_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (saman_B.RateTransitiony > saman_P.DeadZoney_End) {
      rtb_DeadZoney = saman_B.RateTransitiony - saman_P.DeadZoney_End;
    } else if (saman_B.RateTransitiony >= saman_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = saman_B.RateTransitiony - saman_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    saman_B.Joystick_gain_y = saman_P.Gainy_Gain * rtb_DeadZoney *
      saman_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain P ' incorporates:
     *  SignalConversion: '<Root>/TmpSignal ConversionAtGain P Inport1'
     */
    saman_B.GainP[0] = 0.0;
    saman_B.GainP[0] += saman_P.P[0] * saman_B.Joystick_gain_x;
    saman_B.GainP[0] += saman_P.P[2] * saman_B.Joystick_gain_y;
    saman_B.GainP[1] = 0.0;
    saman_B.GainP[1] += saman_P.P[1] * saman_B.Joystick_gain_x;
    saman_B.GainP[1] += saman_P.P[3] * saman_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S3>/Rate Transition: x' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtK Inport1' incorporates:
   *  Gain: '<Root>/K '
   *  Integrator: '<S6>/Integrator1'
   *  Integrator: '<S6>/Integrator2'
   */
  tmp[0] = saman_B.Integrator2[0];
  tmp[1] = saman_B.Integrator2[1];
  tmp[2] = saman_B.Integrator2[3];
  tmp[3] = saman_X.Integrator1_CSTATE;
  tmp[4] = saman_X.Integrator2_CSTATE_n;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/K '
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += saman_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    saman_B.Sum[i] = saman_B.GainP[i] - u0;
  }

  /* End of Sum: '<Root>/Sum' */
  if (rtmIsMajorTimeStep(saman_M)) {
    /* Gain: '<S2>/Elevation: Count to rad' */
    saman_B.ElevationCounttorad = saman_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S13>/Gain'
     */
    saman_B.Sum_n = saman_P.Gain_Gain_l * saman_B.ElevationCounttorad +
      saman_P.Constant_Value;

    /* Gain: '<S7>/Gain1' */
    saman_B.Gain1_j = saman_P.Gain1_Gain_n * saman_B.Sum_n;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S2>/Elevation: Transfer Fcn'
   */
  saman_B.Gain_d = (saman_P.ElevationTransferFcn_C *
                    saman_X.ElevationTransferFcn_CSTATE +
                    saman_P.ElevationTransferFcn_D * saman_B.ElevationCounttorad)
    * saman_P.Gain_Gain_n;

  /* Gain: '<S12>/Gain1' */
  saman_B.Gain1_jm = saman_P.Gain1_Gain_c * saman_B.Gain_d;
  if (rtmIsMajorTimeStep(saman_M)) {
    /* Constant: '<Root>/Constant' */
    saman_B.Constant = saman_P.Constant_Value_i;
  }

  /* Sum: '<Root>/Sum4' */
  saman_B.Sum4 = saman_B.Constant + saman_B.Sum[0];
  if (rtmIsMajorTimeStep(saman_M)) {
    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S15>/Gain'
     */
    saman_B.Sum1 = saman_P.Gain_Gain_a * saman_B.PitchCounttorad -
      saman_P.Constant1_Value;

    /* Gain: '<S2>/Travel: Count to rad' */
    saman_B.TravelCounttorad = saman_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  TransferFcn: '<S2>/Travel: Transfer Fcn'
   */
  saman_B.Gain_dc = (saman_P.TravelTransferFcn_C *
                     saman_X.TravelTransferFcn_CSTATE +
                     saman_P.TravelTransferFcn_D * saman_B.TravelCounttorad) *
    saman_P.Gain_Gain_lu;
  if (rtmIsMajorTimeStep(saman_M)) {
    /* Gain: '<S17>/Gain' */
    saman_B.Gain_p = saman_P.Gain_Gain_ar * saman_B.TravelCounttorad;

    /* Gain: '<S9>/Gain1' */
    saman_B.Gain1_g = saman_P.Gain1_Gain_a * saman_B.Sum1;

    /* Gain: '<S11>/Gain1' */
    saman_B.Gain1_c = saman_P.Gain1_Gain_m * saman_B.Gain_p;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (saman_B.Sum[1] + saman_B.Sum4) * saman_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > saman_P.FrontmotorSaturation_UpperSat) {
    saman_B.FrontmotorSaturation = saman_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < saman_P.FrontmotorSaturation_LowerSat) {
    saman_B.FrontmotorSaturation = saman_P.FrontmotorSaturation_LowerSat;
  } else {
    saman_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (saman_B.Sum4 - saman_B.Sum[1]) * saman_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > saman_P.BackmotorSaturation_UpperSat) {
    saman_B.BackmotorSaturation = saman_P.BackmotorSaturation_UpperSat;
  } else if (u0 < saman_P.BackmotorSaturation_LowerSat) {
    saman_B.BackmotorSaturation = saman_P.BackmotorSaturation_LowerSat;
  } else {
    saman_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(saman_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: saman/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      saman_DW.HILWriteAnalog_Buffer[0] = saman_B.FrontmotorSaturation;
      saman_DW.HILWriteAnalog_Buffer[1] = saman_B.BackmotorSaturation;
      result = hil_write_analog(saman_DW.HILInitialize_Card,
        saman_P.HILWriteAnalog_channels, 2, &saman_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
      }
    }
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtK 2Inport1' incorporates:
   *  Gain: '<S10>/Gain1'
   */
  tmp_0[0] = saman_B.Gain1_g;
  tmp_0[1] = saman_B.Gain1;
  tmp_0[2] = saman_B.Gain1_j;
  tmp_0[3] = saman_B.Gain1_jm;
  tmp_0[4] = saman_B.Gain1_c;
  tmp_0[5] = saman_P.Gain1_Gain_nh * saman_B.Gain_dc;

  /* Gain: '<S5>/K 2' incorporates:
   *  Sum: '<S5>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_1[i] += saman_P.C_L[3 * i_0 + i] * tmp_0[i_0];
    }
  }

  /* End of Gain: '<S5>/K 2' */

  /* Gain: '<S5>/K 3' incorporates:
   *  Sum: '<S5>/Sum5'
   */
  for (i = 0; i < 3; i++) {
    tmp_2[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_2[i] += saman_P.C_L[3 * i_0 + i] * saman_B.Integrator2[i_0];
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
    tmp_0[i] = saman_P.L[i + 12] * unnamed_idx_2 + (saman_P.L[i + 6] *
      unnamed_idx_1 + saman_P.L[i] * u0);

    /* Gain: '<S5>/K 4' incorporates:
     *  SignalConversion: '<S5>/TmpSignal ConversionAtK 4Inport1'
     *  Sum: '<S5>/Sum1'
     */
    tmp_3[i] = saman_P.B_L[i + 6] * saman_B.Sum[0] + saman_P.B_L[i] *
      saman_B.Sum[1];
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/K 1'
   */
  for (i = 0; i < 6; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      u0 += saman_P.A_L[6 * i_0 + i] * saman_B.Integrator2[i_0];
    }

    saman_B.Sum1_m[i] = (tmp_0[i] + tmp_3[i]) + u0;
  }

  /* Sum: '<S6>/Sum2' */
  saman_B.Sum2 = saman_B.Integrator2[0] - saman_B.Joystick_gain_x;

  /* Sum: '<S6>/Sum1' */
  saman_B.Sum1_j = saman_B.Integrator2[3] - saman_B.Joystick_gain_y;
}

/* Model update function for TID0 */
void saman_update0(void)               /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(saman_M)) {
    rt_ertODEUpdateContinuousStates(&saman_M->solverInfo);
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
  if (!(++saman_M->Timing.clockTick0)) {
    ++saman_M->Timing.clockTickH0;
  }

  saman_M->Timing.t[0] = rtsiGetSolverStopTime(&saman_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++saman_M->Timing.clockTick1)) {
    ++saman_M->Timing.clockTickH1;
  }

  saman_M->Timing.t[1] = saman_M->Timing.clockTick1 * saman_M->Timing.stepSize1
    + saman_M->Timing.clockTickH1 * saman_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void saman_derivatives(void)
{
  int32_T i;
  XDot_saman_T *_rtXdot;
  _rtXdot = ((XDot_saman_T *) saman_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator2_CSTATE[i] = saman_B.Sum1_m[i];
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator2' */

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += saman_P.PitchTransferFcn_A *
    saman_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += saman_B.PitchCounttorad;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = saman_B.Sum2;

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_n = saman_B.Sum1_j;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += saman_P.ElevationTransferFcn_A *
    saman_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += saman_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += saman_P.TravelTransferFcn_A *
    saman_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += saman_B.TravelCounttorad;
}

/* Model output function for TID2 */
void saman_output2(void)               /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: saman/Joystick/Game Controller (game_controller_block) */
  {
    if (saman_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(saman_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        saman_B.GameController_o4 = state.x;
        saman_B.GameController_o5 = state.y;
      }
    } else {
      saman_B.GameController_o4 = 0;
      saman_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void saman_update2(void)               /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  saman_DW.RateTransitionx_Buffer0 = saman_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  saman_DW.RateTransitiony_Buffer0 = saman_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++saman_M->Timing.clockTick2)) {
    ++saman_M->Timing.clockTickH2;
  }

  saman_M->Timing.t[2] = saman_M->Timing.clockTick2 * saman_M->Timing.stepSize2
    + saman_M->Timing.clockTickH2 * saman_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void saman_output(int_T tid)
{
  switch (tid) {
   case 0 :
    saman_output0();
    break;

   case 2 :
    saman_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void saman_update(int_T tid)
{
  switch (tid) {
   case 0 :
    saman_update0();
    break;

   case 2 :
    saman_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void saman_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: saman/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &saman_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(saman_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(saman_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(saman_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(saman_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(saman_M, _rt_error_message);
      return;
    }

    if ((saman_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (saman_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &saman_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = saman_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &saman_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = saman_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_analog_input_chan, 8U,
        &saman_DW.HILInitialize_AIMinimums[0],
        &saman_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_analog_output && !is_switching) ||
        (saman_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &saman_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = saman_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &saman_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = saman_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_analog_output_cha, 8U,
        &saman_DW.HILInitialize_AOMinimums[0],
        &saman_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (saman_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &saman_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = saman_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_analog_output_cha, 8U,
        &saman_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if (saman_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &saman_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = saman_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (saman_DW.HILInitialize_Card, saman_P.HILInitialize_analog_output_cha,
         8U, &saman_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_encoder_param && !is_switching) ||
        (saman_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &saman_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = saman_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode *)
        &saman_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_encoder_count && !is_switching) ||
        (saman_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &saman_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = saman_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_encoder_channels, 8U,
        &saman_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (saman_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &saman_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = saman_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &saman_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          saman_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &saman_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            saman_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            saman_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              saman_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            saman_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            saman_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              saman_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(saman_DW.HILInitialize_Card,
          &saman_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &saman_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(saman_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(saman_DW.HILInitialize_Card,
          &saman_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &saman_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(saman_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &saman_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = saman_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &saman_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = saman_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &saman_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = saman_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &saman_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &saman_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &saman_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &saman_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = saman_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &saman_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = saman_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_pwm_channels, 8U,
        &saman_DW.HILInitialize_POSortedFreqs[0],
        &saman_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if ((saman_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (saman_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &saman_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = saman_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_pwm_channels, 8U,
        &saman_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }

    if (saman_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &saman_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = saman_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(saman_DW.HILInitialize_Card,
        saman_P.HILInitialize_pwm_channels, 8U,
        &saman_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: saman/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(saman_DW.HILInitialize_Card,
      saman_P.HILReadEncoderTimebase_samples_,
      saman_P.HILReadEncoderTimebase_channels, 3,
      &saman_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(saman_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  saman_B.RateTransitionx = saman_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  saman_B.RateTransitiony = saman_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: saman/Joystick/Game Controller (game_controller_block) */
  {
    if (saman_P.GameController_Enabled) {
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

      result = game_controller_open(saman_P.GameController_ControllerNumber,
        saman_P.GameController_BufferSize, deadzone, saturation,
        saman_P.GameController_AutoCenter, 0, 1.0,
        &saman_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(saman_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    for (i = 0; i < 6; i++) {
      saman_X.Integrator2_CSTATE[i] = saman_P.Integrator2_IC;
    }

    /* End of InitializeConditions for Integrator: '<S5>/Integrator2' */

    /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
    saman_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    saman_X.Integrator1_CSTATE = saman_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    saman_X.Integrator2_CSTATE_n = saman_P.Integrator2_IC_p;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    saman_DW.RateTransitionx_Buffer0 = saman_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    saman_DW.RateTransitiony_Buffer0 = saman_P.RateTransitiony_X0;

    /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
    saman_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
    saman_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void saman_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: saman/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(saman_DW.HILInitialize_Card);
    hil_monitor_stop_all(saman_DW.HILInitialize_Card);
    is_switching = false;
    if ((saman_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (saman_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &saman_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = saman_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((saman_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (saman_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &saman_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = saman_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(saman_DW.HILInitialize_Card
                         , saman_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , saman_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &saman_DW.HILInitialize_AOVoltages[0]
                         , &saman_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(saman_DW.HILInitialize_Card,
            saman_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &saman_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(saman_DW.HILInitialize_Card,
            saman_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &saman_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(saman_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(saman_DW.HILInitialize_Card);
    hil_monitor_delete_all(saman_DW.HILInitialize_Card);
    hil_close(saman_DW.HILInitialize_Card);
    saman_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: saman/Joystick/Game Controller (game_controller_block) */
  {
    if (saman_P.GameController_Enabled) {
      game_controller_close(saman_DW.GameController_Controller);
      saman_DW.GameController_Controller = NULL;
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
  saman_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  saman_update(tid);
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
  saman_initialize();
}

void MdlTerminate(void)
{
  saman_terminate();
}

/* Registration function */
RT_MODEL_saman_T *saman(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)saman_M, 0,
                sizeof(RT_MODEL_saman_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&saman_M->solverInfo, &saman_M->Timing.simTimeStep);
    rtsiSetTPtr(&saman_M->solverInfo, &rtmGetTPtr(saman_M));
    rtsiSetStepSizePtr(&saman_M->solverInfo, &saman_M->Timing.stepSize0);
    rtsiSetdXPtr(&saman_M->solverInfo, &saman_M->ModelData.derivs);
    rtsiSetContStatesPtr(&saman_M->solverInfo, (real_T **)
                         &saman_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&saman_M->solverInfo, &saman_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&saman_M->solverInfo, (&rtmGetErrorStatus(saman_M)));
    rtsiSetRTModelPtr(&saman_M->solverInfo, saman_M);
  }

  rtsiSetSimTimeStep(&saman_M->solverInfo, MAJOR_TIME_STEP);
  saman_M->ModelData.intgData.f[0] = saman_M->ModelData.odeF[0];
  saman_M->ModelData.contStates = ((real_T *) &saman_X);
  rtsiSetSolverData(&saman_M->solverInfo, (void *)&saman_M->ModelData.intgData);
  rtsiSetSolverName(&saman_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = saman_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    saman_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    saman_M->Timing.sampleTimes = (&saman_M->Timing.sampleTimesArray[0]);
    saman_M->Timing.offsetTimes = (&saman_M->Timing.offsetTimesArray[0]);

    /* task periods */
    saman_M->Timing.sampleTimes[0] = (0.0);
    saman_M->Timing.sampleTimes[1] = (0.002);
    saman_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    saman_M->Timing.offsetTimes[0] = (0.0);
    saman_M->Timing.offsetTimes[1] = (0.0);
    saman_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(saman_M, &saman_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = saman_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = saman_M->Timing.perTaskSampleHitsArray;
    saman_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    saman_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(saman_M, -1);
  saman_M->Timing.stepSize0 = 0.002;
  saman_M->Timing.stepSize1 = 0.002;
  saman_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  saman_M->Sizes.checksums[0] = (3066847763U);
  saman_M->Sizes.checksums[1] = (2544204378U);
  saman_M->Sizes.checksums[2] = (2398438036U);
  saman_M->Sizes.checksums[3] = (3678136854U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    saman_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(saman_M->extModeInfo,
      &saman_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(saman_M->extModeInfo, saman_M->Sizes.checksums);
    rteiSetTPtr(saman_M->extModeInfo, rtmGetTPtr(saman_M));
  }

  saman_M->solverInfoPtr = (&saman_M->solverInfo);
  saman_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&saman_M->solverInfo, 0.002);
  rtsiSetSolverMode(&saman_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  saman_M->ModelData.blockIO = ((void *) &saman_B);

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      saman_B.Integrator2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      saman_B.Sum1_m[i] = 0.0;
    }

    saman_B.PitchCounttorad = 0.0;
    saman_B.Gain = 0.0;
    saman_B.Gain1 = 0.0;
    saman_B.RateTransitionx = 0.0;
    saman_B.Joystick_gain_x = 0.0;
    saman_B.RateTransitiony = 0.0;
    saman_B.Joystick_gain_y = 0.0;
    saman_B.GainP[0] = 0.0;
    saman_B.GainP[1] = 0.0;
    saman_B.Sum[0] = 0.0;
    saman_B.Sum[1] = 0.0;
    saman_B.ElevationCounttorad = 0.0;
    saman_B.Sum_n = 0.0;
    saman_B.Gain1_j = 0.0;
    saman_B.Gain_d = 0.0;
    saman_B.Gain1_jm = 0.0;
    saman_B.Constant = 0.0;
    saman_B.Sum4 = 0.0;
    saman_B.Sum1 = 0.0;
    saman_B.TravelCounttorad = 0.0;
    saman_B.Gain_dc = 0.0;
    saman_B.Gain_p = 0.0;
    saman_B.Gain1_g = 0.0;
    saman_B.Gain1_c = 0.0;
    saman_B.FrontmotorSaturation = 0.0;
    saman_B.BackmotorSaturation = 0.0;
    saman_B.GameController_o4 = 0.0;
    saman_B.GameController_o5 = 0.0;
    saman_B.Sum2 = 0.0;
    saman_B.Sum1_j = 0.0;
  }

  /* parameters */
  saman_M->ModelData.defaultParam = ((real_T *)&saman_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &saman_X;
    saman_M->ModelData.contStates = (x);
    (void) memset((void *)&saman_X, 0,
                  sizeof(X_saman_T));
  }

  /* states (dwork) */
  saman_M->ModelData.dwork = ((void *) &saman_DW);
  (void) memset((void *)&saman_DW, 0,
                sizeof(DW_saman_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      saman_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  saman_DW.RateTransitionx_Buffer0 = 0.0;
  saman_DW.RateTransitiony_Buffer0 = 0.0;
  saman_DW.HILWriteAnalog_Buffer[0] = 0.0;
  saman_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    saman_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  saman_M->Sizes.numContStates = (11); /* Number of continuous states */
  saman_M->Sizes.numY = (0);           /* Number of model outputs */
  saman_M->Sizes.numU = (0);           /* Number of model inputs */
  saman_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  saman_M->Sizes.numSampTimes = (3);   /* Number of sample times */
  saman_M->Sizes.numBlocks = (74);     /* Number of blocks */
  saman_M->Sizes.numBlockIO = (30);    /* Number of block outputs */
  saman_M->Sizes.numBlockPrms = (251); /* Sum of parameter "widths" */
  return saman_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
