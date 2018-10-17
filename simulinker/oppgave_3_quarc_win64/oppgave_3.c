/*
 * oppgave_3.c
 *
 * Code generation for model "oppgave_3".
 *
 * Model version              : 1.69
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Oct 16 22:29:45 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "oppgave_3.h"
#include "oppgave_3_private.h"
#include "oppgave_3_dt.h"

/* Block signals (auto storage) */
B_oppgave_3_T oppgave_3_B;

/* Continuous states */
X_oppgave_3_T oppgave_3_X;

/* Block states (auto storage) */
DW_oppgave_3_T oppgave_3_DW;

/* Real-time model */
RT_MODEL_oppgave_3_T oppgave_3_M_;
RT_MODEL_oppgave_3_T *const oppgave_3_M = &oppgave_3_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(oppgave_3_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(oppgave_3_M, 2);
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
  if (oppgave_3_M->Timing.TaskCounters.TID[1] == 0) {
    oppgave_3_M->Timing.RateInteraction.TID1_2 =
      (oppgave_3_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    oppgave_3_M->Timing.perTaskSampleHits[5] =
      oppgave_3_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (oppgave_3_M->Timing.TaskCounters.TID[2])++;
  if ((oppgave_3_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    oppgave_3_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  oppgave_3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void oppgave_3_output0(void)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  real_T rtb_Gain1;
  real_T rtb_Sum[2];
  real_T tmp[5];
  int32_T i;
  int32_T i_0;
  real_T u0;
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* set solver stop time */
    if (!(oppgave_3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&oppgave_3_M->solverInfo,
                            ((oppgave_3_M->Timing.clockTickH0 + 1) *
        oppgave_3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&oppgave_3_M->solverInfo,
                            ((oppgave_3_M->Timing.clockTick0 + 1) *
        oppgave_3_M->Timing.stepSize0 + oppgave_3_M->Timing.clockTickH0 *
        oppgave_3_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(oppgave_3_M)) {
    oppgave_3_M->Timing.t[0] = rtsiGetT(&oppgave_3_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

    /* S-Function Block: oppgave_3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(oppgave_3_DW.HILReadEncoderTimebase_Task, 1,
        &oppgave_3_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          oppgave_3_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          oppgave_3_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = oppgave_3_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Constant: '<Root>/Constant' */
    oppgave_3_B.Constant = oppgave_3_P.Constant_Value;

    /* Gain: '<S2>/Pitch: Count to rad' */
    oppgave_3_B.PitchCounttorad = oppgave_3_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Gain: '<S13>/Gain'
     */
    oppgave_3_B.Sum1 = oppgave_3_P.Gain_Gain * oppgave_3_B.PitchCounttorad -
      oppgave_3_P.Constant1_Value;

    /* Gain: '<S7>/Gain1' */
    oppgave_3_B.Gain1 = oppgave_3_P.Gain1_Gain * oppgave_3_B.Sum1;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  TransferFcn: '<S2>/Pitch: Transfer Fcn'
   */
  oppgave_3_B.Gain = (oppgave_3_P.PitchTransferFcn_C *
                      oppgave_3_X.PitchTransferFcn_CSTATE +
                      oppgave_3_P.PitchTransferFcn_D *
                      oppgave_3_B.PitchCounttorad) * oppgave_3_P.Gain_Gain_a;
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* Gain: '<S2>/Elevation: Count to rad' */
    oppgave_3_B.ElevationCounttorad = oppgave_3_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;
  }

  /* Gain: '<S12>/Gain' incorporates:
   *  TransferFcn: '<S2>/Elevation: Transfer Fcn'
   */
  oppgave_3_B.Gain_d = (oppgave_3_P.ElevationTransferFcn_C *
                        oppgave_3_X.ElevationTransferFcn_CSTATE +
                        oppgave_3_P.ElevationTransferFcn_D *
                        oppgave_3_B.ElevationCounttorad) *
    oppgave_3_P.Gain_Gain_n;

  /* Gain: '<S10>/Gain1' */
  rtb_Gain1 = oppgave_3_P.Gain1_Gain_c * oppgave_3_B.Gain_d;

  /* RateTransition: '<S3>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    if (oppgave_3_M->Timing.RateInteraction.TID1_2) {
      oppgave_3_B.RateTransitionx = oppgave_3_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (oppgave_3_B.RateTransitionx > oppgave_3_P.DeadZonex_End) {
      rtb_DeadZoney = oppgave_3_B.RateTransitionx - oppgave_3_P.DeadZonex_End;
    } else if (oppgave_3_B.RateTransitionx >= oppgave_3_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = oppgave_3_B.RateTransitionx - oppgave_3_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    oppgave_3_B.Joystick_gain_x = oppgave_3_P.Gainx_Gain * rtb_DeadZoney *
      oppgave_3_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (oppgave_3_M->Timing.RateInteraction.TID1_2) {
      oppgave_3_B.RateTransitiony = oppgave_3_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (oppgave_3_B.RateTransitiony > oppgave_3_P.DeadZoney_End) {
      rtb_DeadZoney = oppgave_3_B.RateTransitiony - oppgave_3_P.DeadZoney_End;
    } else if (oppgave_3_B.RateTransitiony >= oppgave_3_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = oppgave_3_B.RateTransitiony - oppgave_3_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    oppgave_3_B.Joystick_gain_y = oppgave_3_P.Gainy_Gain * rtb_DeadZoney *
      oppgave_3_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain P ' incorporates:
     *  SignalConversion: '<Root>/TmpSignal ConversionAtGain P Inport1'
     */
    oppgave_3_B.GainP[0] = 0.0;
    oppgave_3_B.GainP[0] += oppgave_3_P.P[0] * oppgave_3_B.Joystick_gain_x;
    oppgave_3_B.GainP[0] += oppgave_3_P.P[2] * oppgave_3_B.Joystick_gain_y;
    oppgave_3_B.GainP[1] = 0.0;
    oppgave_3_B.GainP[1] += oppgave_3_P.P[1] * oppgave_3_B.Joystick_gain_x;
    oppgave_3_B.GainP[1] += oppgave_3_P.P[3] * oppgave_3_B.Joystick_gain_y;
  }

  /* End of RateTransition: '<S3>/Rate Transition: x' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtK Inport1' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S4>/Integrator2'
   */
  tmp[0] = oppgave_3_B.Gain1;
  tmp[1] = oppgave_3_P.Gain1_Gain_k * oppgave_3_B.Gain;
  tmp[2] = rtb_Gain1;
  tmp[3] = oppgave_3_X.Integrator1_CSTATE;
  tmp[4] = oppgave_3_X.Integrator2_CSTATE;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/K '
   */
  for (i = 0; i < 2; i++) {
    u0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      u0 += oppgave_3_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    rtb_Sum[i] = oppgave_3_B.GainP[i] - u0;
  }

  /* End of Sum: '<Root>/Sum' */

  /* Sum: '<Root>/Sum4' */
  oppgave_3_B.Sum4 = rtb_Sum[0] + oppgave_3_B.Constant;
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S11>/Gain'
     */
    oppgave_3_B.Sum = oppgave_3_P.Gain_Gain_l * oppgave_3_B.ElevationCounttorad
      + oppgave_3_P.Constant_Value_d;

    /* Gain: '<S2>/Travel: Count to rad' */
    oppgave_3_B.TravelCounttorad = oppgave_3_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  TransferFcn: '<S2>/Travel: Transfer Fcn'
   */
  oppgave_3_B.Gain_dc = (oppgave_3_P.TravelTransferFcn_C *
    oppgave_3_X.TravelTransferFcn_CSTATE + oppgave_3_P.TravelTransferFcn_D *
    oppgave_3_B.TravelCounttorad) * oppgave_3_P.Gain_Gain_lu;
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* Gain: '<S15>/Gain' */
    oppgave_3_B.Gain_p = oppgave_3_P.Gain_Gain_ar * oppgave_3_B.TravelCounttorad;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_Sum[1] + oppgave_3_B.Sum4) * oppgave_3_P.Frontgain_Gain;

  /* Saturate: '<S2>/Front motor: Saturation' */
  if (u0 > oppgave_3_P.FrontmotorSaturation_UpperSat) {
    oppgave_3_B.FrontmotorSaturation = oppgave_3_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < oppgave_3_P.FrontmotorSaturation_LowerSat) {
    oppgave_3_B.FrontmotorSaturation = oppgave_3_P.FrontmotorSaturation_LowerSat;
  } else {
    oppgave_3_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (oppgave_3_B.Sum4 - rtb_Sum[1]) * oppgave_3_P.Backgain_Gain;

  /* Saturate: '<S2>/Back motor: Saturation' */
  if (u0 > oppgave_3_P.BackmotorSaturation_UpperSat) {
    oppgave_3_B.BackmotorSaturation = oppgave_3_P.BackmotorSaturation_UpperSat;
  } else if (u0 < oppgave_3_P.BackmotorSaturation_LowerSat) {
    oppgave_3_B.BackmotorSaturation = oppgave_3_P.BackmotorSaturation_LowerSat;
  } else {
    oppgave_3_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S2>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: oppgave_3/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      oppgave_3_DW.HILWriteAnalog_Buffer[0] = oppgave_3_B.FrontmotorSaturation;
      oppgave_3_DW.HILWriteAnalog_Buffer[1] = oppgave_3_B.BackmotorSaturation;
      result = hil_write_analog(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILWriteAnalog_channels, 2,
        &oppgave_3_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      }
    }

    /* Sum: '<S4>/Sum2' */
    oppgave_3_B.Sum2 = oppgave_3_B.Gain1 - oppgave_3_B.Joystick_gain_x;
  }

  /* Sum: '<S4>/Sum1' */
  oppgave_3_B.Sum1_j = rtb_Gain1 - oppgave_3_B.Joystick_gain_y;
}

/* Model update function for TID0 */
void oppgave_3_update0(void)           /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(oppgave_3_M)) {
    rt_ertODEUpdateContinuousStates(&oppgave_3_M->solverInfo);
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
  if (!(++oppgave_3_M->Timing.clockTick0)) {
    ++oppgave_3_M->Timing.clockTickH0;
  }

  oppgave_3_M->Timing.t[0] = rtsiGetSolverStopTime(&oppgave_3_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++oppgave_3_M->Timing.clockTick1)) {
    ++oppgave_3_M->Timing.clockTickH1;
  }

  oppgave_3_M->Timing.t[1] = oppgave_3_M->Timing.clockTick1 *
    oppgave_3_M->Timing.stepSize1 + oppgave_3_M->Timing.clockTickH1 *
    oppgave_3_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void oppgave_3_derivatives(void)
{
  XDot_oppgave_3_T *_rtXdot;
  _rtXdot = ((XDot_oppgave_3_T *) oppgave_3_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += oppgave_3_P.PitchTransferFcn_A *
    oppgave_3_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += oppgave_3_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += oppgave_3_P.ElevationTransferFcn_A *
    oppgave_3_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += oppgave_3_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = oppgave_3_B.Sum2;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = oppgave_3_B.Sum1_j;

  /* Derivatives for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += oppgave_3_P.TravelTransferFcn_A *
    oppgave_3_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += oppgave_3_B.TravelCounttorad;
}

/* Model output function for TID2 */
void oppgave_3_output2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: oppgave_3/Joystick/Game Controller (game_controller_block) */
  {
    if (oppgave_3_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(oppgave_3_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        oppgave_3_B.GameController_o4 = state.x;
        oppgave_3_B.GameController_o5 = state.y;
      }
    } else {
      oppgave_3_B.GameController_o4 = 0;
      oppgave_3_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void oppgave_3_update2(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  oppgave_3_DW.RateTransitionx_Buffer0 = oppgave_3_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  oppgave_3_DW.RateTransitiony_Buffer0 = oppgave_3_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++oppgave_3_M->Timing.clockTick2)) {
    ++oppgave_3_M->Timing.clockTickH2;
  }

  oppgave_3_M->Timing.t[2] = oppgave_3_M->Timing.clockTick2 *
    oppgave_3_M->Timing.stepSize2 + oppgave_3_M->Timing.clockTickH2 *
    oppgave_3_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void oppgave_3_output(int_T tid)
{
  switch (tid) {
   case 0 :
    oppgave_3_output0();
    break;

   case 2 :
    oppgave_3_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void oppgave_3_update(int_T tid)
{
  switch (tid) {
   case 0 :
    oppgave_3_update0();
    break;

   case 2 :
    oppgave_3_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void oppgave_3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: oppgave_3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &oppgave_3_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(oppgave_3_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(oppgave_3_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      return;
    }

    if ((oppgave_3_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &oppgave_3_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = oppgave_3_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &oppgave_3_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = oppgave_3_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_analog_input_chan, 8U,
        &oppgave_3_DW.HILInitialize_AIMinimums[0],
        &oppgave_3_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_analog_output && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &oppgave_3_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = oppgave_3_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &oppgave_3_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = oppgave_3_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_analog_output_cha, 8U,
        &oppgave_3_DW.HILInitialize_AOMinimums[0],
        &oppgave_3_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &oppgave_3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = oppgave_3_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_analog_output_cha, 8U,
        &oppgave_3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if (oppgave_3_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &oppgave_3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = oppgave_3_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (oppgave_3_DW.HILInitialize_Card,
         oppgave_3_P.HILInitialize_analog_output_cha, 8U,
         &oppgave_3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_encoder_param && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &oppgave_3_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = oppgave_3_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &oppgave_3_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_encoder_count && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &oppgave_3_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = oppgave_3_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_encoder_channels, 8U,
        &oppgave_3_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &oppgave_3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = oppgave_3_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &oppgave_3_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          oppgave_3_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &oppgave_3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            oppgave_3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            oppgave_3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              oppgave_3_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            oppgave_3_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            oppgave_3_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              oppgave_3_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(oppgave_3_DW.HILInitialize_Card,
          &oppgave_3_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &oppgave_3_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(oppgave_3_DW.HILInitialize_Card,
          &oppgave_3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &oppgave_3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &oppgave_3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = oppgave_3_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &oppgave_3_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = oppgave_3_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &oppgave_3_DW.HILInitialize_POPolarityVals
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = oppgave_3_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &oppgave_3_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &oppgave_3_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &oppgave_3_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &oppgave_3_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = oppgave_3_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &oppgave_3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = oppgave_3_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_pwm_channels, 8U,
        &oppgave_3_DW.HILInitialize_POSortedFreqs[0],
        &oppgave_3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if ((oppgave_3_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &oppgave_3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = oppgave_3_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(oppgave_3_DW.HILInitialize_Card,
        oppgave_3_P.HILInitialize_pwm_channels, 8U,
        &oppgave_3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }

    if (oppgave_3_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &oppgave_3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = oppgave_3_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (oppgave_3_DW.HILInitialize_Card, oppgave_3_P.HILInitialize_pwm_channels,
         8U, &oppgave_3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S2>/HIL Read Encoder Timebase' */

  /* S-Function Block: oppgave_3/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(oppgave_3_DW.HILInitialize_Card,
      oppgave_3_P.HILReadEncoderTimebase_samples_,
      oppgave_3_P.HILReadEncoderTimebase_channels, 3,
      &oppgave_3_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  oppgave_3_B.RateTransitionx = oppgave_3_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  oppgave_3_B.RateTransitiony = oppgave_3_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: oppgave_3/Joystick/Game Controller (game_controller_block) */
  {
    if (oppgave_3_P.GameController_Enabled) {
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

      result = game_controller_open(oppgave_3_P.GameController_ControllerNumber,
        oppgave_3_P.GameController_BufferSize, deadzone, saturation,
        oppgave_3_P.GameController_AutoCenter, 0, 1.0,
        &oppgave_3_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S2>/Pitch: Transfer Fcn' */
  oppgave_3_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S2>/Elevation: Transfer Fcn' */
  oppgave_3_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  oppgave_3_X.Integrator1_CSTATE = oppgave_3_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  oppgave_3_X.Integrator2_CSTATE = oppgave_3_P.Integrator2_IC;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
  oppgave_3_DW.RateTransitionx_Buffer0 = oppgave_3_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
  oppgave_3_DW.RateTransitiony_Buffer0 = oppgave_3_P.RateTransitiony_X0;

  /* InitializeConditions for TransferFcn: '<S2>/Travel: Transfer Fcn' */
  oppgave_3_X.TravelTransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void oppgave_3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: oppgave_3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(oppgave_3_DW.HILInitialize_Card);
    hil_monitor_stop_all(oppgave_3_DW.HILInitialize_Card);
    is_switching = false;
    if ((oppgave_3_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &oppgave_3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = oppgave_3_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((oppgave_3_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (oppgave_3_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &oppgave_3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = oppgave_3_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(oppgave_3_DW.HILInitialize_Card
                         , oppgave_3_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , oppgave_3_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &oppgave_3_DW.HILInitialize_AOVoltages[0]
                         , &oppgave_3_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(oppgave_3_DW.HILInitialize_Card,
            oppgave_3_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &oppgave_3_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(oppgave_3_DW.HILInitialize_Card,
            oppgave_3_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &oppgave_3_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(oppgave_3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(oppgave_3_DW.HILInitialize_Card);
    hil_monitor_delete_all(oppgave_3_DW.HILInitialize_Card);
    hil_close(oppgave_3_DW.HILInitialize_Card);
    oppgave_3_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: oppgave_3/Joystick/Game Controller (game_controller_block) */
  {
    if (oppgave_3_P.GameController_Enabled) {
      game_controller_close(oppgave_3_DW.GameController_Controller);
      oppgave_3_DW.GameController_Controller = NULL;
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
  oppgave_3_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  oppgave_3_update(tid);
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
  oppgave_3_initialize();
}

void MdlTerminate(void)
{
  oppgave_3_terminate();
}

/* Registration function */
RT_MODEL_oppgave_3_T *oppgave_3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)oppgave_3_M, 0,
                sizeof(RT_MODEL_oppgave_3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&oppgave_3_M->solverInfo,
                          &oppgave_3_M->Timing.simTimeStep);
    rtsiSetTPtr(&oppgave_3_M->solverInfo, &rtmGetTPtr(oppgave_3_M));
    rtsiSetStepSizePtr(&oppgave_3_M->solverInfo, &oppgave_3_M->Timing.stepSize0);
    rtsiSetdXPtr(&oppgave_3_M->solverInfo, &oppgave_3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&oppgave_3_M->solverInfo, (real_T **)
                         &oppgave_3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&oppgave_3_M->solverInfo,
      &oppgave_3_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&oppgave_3_M->solverInfo, (&rtmGetErrorStatus
      (oppgave_3_M)));
    rtsiSetRTModelPtr(&oppgave_3_M->solverInfo, oppgave_3_M);
  }

  rtsiSetSimTimeStep(&oppgave_3_M->solverInfo, MAJOR_TIME_STEP);
  oppgave_3_M->ModelData.intgData.f[0] = oppgave_3_M->ModelData.odeF[0];
  oppgave_3_M->ModelData.contStates = ((real_T *) &oppgave_3_X);
  rtsiSetSolverData(&oppgave_3_M->solverInfo, (void *)
                    &oppgave_3_M->ModelData.intgData);
  rtsiSetSolverName(&oppgave_3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = oppgave_3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    oppgave_3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    oppgave_3_M->Timing.sampleTimes = (&oppgave_3_M->Timing.sampleTimesArray[0]);
    oppgave_3_M->Timing.offsetTimes = (&oppgave_3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    oppgave_3_M->Timing.sampleTimes[0] = (0.0);
    oppgave_3_M->Timing.sampleTimes[1] = (0.002);
    oppgave_3_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    oppgave_3_M->Timing.offsetTimes[0] = (0.0);
    oppgave_3_M->Timing.offsetTimes[1] = (0.0);
    oppgave_3_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(oppgave_3_M, &oppgave_3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = oppgave_3_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = oppgave_3_M->Timing.perTaskSampleHitsArray;
    oppgave_3_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    oppgave_3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(oppgave_3_M, -1);
  oppgave_3_M->Timing.stepSize0 = 0.002;
  oppgave_3_M->Timing.stepSize1 = 0.002;
  oppgave_3_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  oppgave_3_M->Sizes.checksums[0] = (1952390639U);
  oppgave_3_M->Sizes.checksums[1] = (3491925909U);
  oppgave_3_M->Sizes.checksums[2] = (2519365302U);
  oppgave_3_M->Sizes.checksums[3] = (3298142408U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    oppgave_3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(oppgave_3_M->extModeInfo,
      &oppgave_3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(oppgave_3_M->extModeInfo, oppgave_3_M->Sizes.checksums);
    rteiSetTPtr(oppgave_3_M->extModeInfo, rtmGetTPtr(oppgave_3_M));
  }

  oppgave_3_M->solverInfoPtr = (&oppgave_3_M->solverInfo);
  oppgave_3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&oppgave_3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&oppgave_3_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  oppgave_3_M->ModelData.blockIO = ((void *) &oppgave_3_B);

  {
    oppgave_3_B.Constant = 0.0;
    oppgave_3_B.PitchCounttorad = 0.0;
    oppgave_3_B.Sum1 = 0.0;
    oppgave_3_B.Gain1 = 0.0;
    oppgave_3_B.Gain = 0.0;
    oppgave_3_B.ElevationCounttorad = 0.0;
    oppgave_3_B.Gain_d = 0.0;
    oppgave_3_B.RateTransitionx = 0.0;
    oppgave_3_B.Joystick_gain_x = 0.0;
    oppgave_3_B.RateTransitiony = 0.0;
    oppgave_3_B.Joystick_gain_y = 0.0;
    oppgave_3_B.GainP[0] = 0.0;
    oppgave_3_B.GainP[1] = 0.0;
    oppgave_3_B.Sum4 = 0.0;
    oppgave_3_B.Sum = 0.0;
    oppgave_3_B.TravelCounttorad = 0.0;
    oppgave_3_B.Gain_dc = 0.0;
    oppgave_3_B.Gain_p = 0.0;
    oppgave_3_B.FrontmotorSaturation = 0.0;
    oppgave_3_B.BackmotorSaturation = 0.0;
    oppgave_3_B.GameController_o4 = 0.0;
    oppgave_3_B.GameController_o5 = 0.0;
    oppgave_3_B.Sum2 = 0.0;
    oppgave_3_B.Sum1_j = 0.0;
  }

  /* parameters */
  oppgave_3_M->ModelData.defaultParam = ((real_T *)&oppgave_3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &oppgave_3_X;
    oppgave_3_M->ModelData.contStates = (x);
    (void) memset((void *)&oppgave_3_X, 0,
                  sizeof(X_oppgave_3_T));
  }

  /* states (dwork) */
  oppgave_3_M->ModelData.dwork = ((void *) &oppgave_3_DW);
  (void) memset((void *)&oppgave_3_DW, 0,
                sizeof(DW_oppgave_3_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      oppgave_3_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  oppgave_3_DW.RateTransitionx_Buffer0 = 0.0;
  oppgave_3_DW.RateTransitiony_Buffer0 = 0.0;
  oppgave_3_DW.HILWriteAnalog_Buffer[0] = 0.0;
  oppgave_3_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    oppgave_3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  oppgave_3_M->Sizes.numContStates = (5);/* Number of continuous states */
  oppgave_3_M->Sizes.numY = (0);       /* Number of model outputs */
  oppgave_3_M->Sizes.numU = (0);       /* Number of model inputs */
  oppgave_3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  oppgave_3_M->Sizes.numSampTimes = (3);/* Number of sample times */
  oppgave_3_M->Sizes.numBlocks = (57); /* Number of blocks */
  oppgave_3_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  oppgave_3_M->Sizes.numBlockPrms = (163);/* Sum of parameter "widths" */
  return oppgave_3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
