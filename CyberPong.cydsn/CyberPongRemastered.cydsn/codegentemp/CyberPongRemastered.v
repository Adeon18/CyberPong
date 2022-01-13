// ======================================================================
// CyberPongRemastered.v generated from TopDesign.cysch
// 01/13/2022 at 19:30
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: B_FanTach_v4_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanTach_v4_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanTach_v4_10\B_FanTach_v4_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanTach_v4_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanTach_v4_10\B_FanTach_v4_10.v"
`endif

// Component: B_FanController_v4_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanController_v4_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanController_v4_10\B_FanController_v4_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanController_v4_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_FanController_v4_10\B_FanController_v4_10.v"
`endif

// FanController_v4_10(AcousticNoiseReduction=0, AlertEnable=0, CoefDerivative=20, CoefIntegral=80, CoefLowerOutputLimit=40, CoefOutputAttenuation=-16, CoefProportional=100, CoefUpperOutputLimit=100, Connection=1, CtlModeReplacementString=AsyncCtl, DampingFactor=1, ExternalClock=0, FanMode=0, FanModeManual=false, FanPWMFreq=0, FanPWMRes=1, FanTolerance=1, InitialRPM01=4000, InitialRPM02=4000, InitialRPM03=4000, InitialRPM04=4000, InitialRPM05=5000, InitialRPM06=5000, InitialRPM07=5000, InitialRPM08=5000, InitialRPM09=5000, InitialRPM10=5000, InitialRPM11=5000, InitialRPM12=5000, InitialRPM13=5000, InitialRPM14=5000, InitialRPM15=5000, InitialRPM16=5000, MaxDuty01=100, MaxDuty02=100, MaxDuty03=100, MaxDuty04=100, MaxDuty05=100, MaxDuty06=100, MaxDuty07=100, MaxDuty08=100, MaxDuty09=100, MaxDuty10=100, MaxDuty11=100, MaxDuty12=100, MaxDuty13=100, MaxDuty14=100, MaxDuty15=100, MaxDuty16=100, MaxRPM01=4800, MaxRPM02=4800, MaxRPM03=4800, MaxRPM04=4800, MaxRPM05=10000, MaxRPM06=10000, MaxRPM07=10000, MaxRPM08=10000, MaxRPM09=10000, MaxRPM10=10000, MaxRPM11=10000, MaxRPM12=10000, MaxRPM13=10000, MaxRPM14=10000, MaxRPM15=10000, MaxRPM16=10000, MinDuty01=55, MinDuty02=55, MinDuty03=55, MinDuty04=55, MinDuty05=25, MinDuty06=25, MinDuty07=25, MinDuty08=25, MinDuty09=25, MinDuty10=25, MinDuty11=25, MinDuty12=25, MinDuty13=25, MinDuty14=25, MinDuty15=25, MinDuty16=25, MinRPM01=2200, MinRPM02=2200, MinRPM03=2200, MinRPM04=2200, MinRPM05=1000, MinRPM06=1000, MinRPM07=1000, MinRPM08=1000, MinRPM09=1000, MinRPM10=1000, MinRPM11=1000, MinRPM12=100, MinRPM13=100, MinRPM14=1000, MinRPM15=1000, MinRPM16=1000, MotorType=0, NineOrMoreFans=false, NumberOfBanks=0, NumberOfFanOutputs=4, NumberOfFans=4, pid_A1=8192, pid_A2=-5734, pid_A3=819, pid_output_gain=16, pid_output_sat_H=62914560, pid_output_sat_L=25165824, Psoc3or5=true, pwm_period=960, ShowFanOutputs=false, SpeedErrorCount=16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=FanController_v4_10, CY_CONFIG_TITLE=FanController, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=FanController, CY_INSTANCE_SHORT_NAME=FanController, CY_MAJOR_VERSION=4, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=FanController, )
module FanController_v4_10_0 (
    alert,
    bank,
    bank1,
    bank2,
    bank3,
    bank4,
    bank5,
    bank6,
    bank7,
    bank8,
    clock,
    eoc,
    fan,
    fan1,
    fan10,
    fan11,
    fan12,
    fan13,
    fan14,
    fan15,
    fan16,
    fan2,
    fan3,
    fan4,
    fan5,
    fan6,
    fan7,
    fan8,
    fan9,
    tach,
    tach1,
    tach10,
    tach11,
    tach12,
    tach13,
    tach14,
    tach15,
    tach16,
    tach2,
    tach3,
    tach4,
    tach5,
    tach6,
    tach7,
    tach8,
    tach9);
    output      alert;
    output     [8:1] bank;
    output      bank1;
    output      bank2;
    output      bank3;
    output      bank4;
    output      bank5;
    output      bank6;
    output      bank7;
    output      bank8;
    input       clock;
    output      eoc;
    output     [16:1] fan;
    output      fan1;
    output      fan10;
    output      fan11;
    output      fan12;
    output      fan13;
    output      fan14;
    output      fan15;
    output      fan16;
    output      fan2;
    output      fan3;
    output      fan4;
    output      fan5;
    output      fan6;
    output      fan7;
    output      fan8;
    output      fan9;
    input      [16:1] tach;
    input       tach1;
    input       tach10;
    input       tach11;
    input       tach12;
    input       tach13;
    input       tach14;
    input       tach15;
    input       tach16;
    input       tach2;
    input       tach3;
    input       tach4;
    input       tach5;
    input       tach6;
    input       tach7;
    input       tach8;
    input       tach9;

    parameter FanMode = 0;
    parameter MotorType = 0;

          wire  wtch4;
          wire  wtch7;
          wire  wtch1;
          wire [15:0] alert_mask;
          wire  wtch3;
          wire  override;
          wire  wtch8;
          wire  wtch12;
          wire  wtch2;
          wire  wtch6;
          wire [16:1] btch;
          wire  enable;
          wire  wtch15;
          wire  wtch13;
          wire  wtch11;
          wire [16:1] pwm;
          wire [3:0] address;
          wire  wtch10;
          wire  wtch14;
          wire [15:0] tach_bus;
          wire  wtch9;
          wire  wtch16;
          wire  wtch5;
          wire  sync;
          wire  fan_clk;
          wire  Net_65;
          wire  Net_64;
          wire  Net_63;
          wire  Net_62;
          wire  Net_61;
          wire  Net_60;
          wire  Net_59;
          wire  alrt;
          wire  tach_clk;
          wire  drq;
          wire  Net_235;
          wire  Net_39;
          wire  Net_6547;
          wire  Net_6129;
          wire [15:0] Net_6149;
          wire  nrq;
          wire  Net_6081;
          wire  Net_6559;
          wire  Net_3900;
          wire  Net_3899;
          wire  Net_6505;
          wire  Net_6146;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign tach_bus[0] = wtch1;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign tach_bus[1] = wtch2;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tach_bus[2] = wtch3;

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign tach_bus[7] = wtch8;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign tach_bus[4] = wtch5;

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign tach_bus[5] = wtch6;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign tach_bus[6] = wtch7;

	// VirtualMux_9 (cy_virtualmux_v1_0)
	assign tach_bus[11] = wtch12;

	// VirtualMux_10 (cy_virtualmux_v1_0)
	assign tach_bus[8] = wtch9;

	// VirtualMux_11 (cy_virtualmux_v1_0)
	assign tach_bus[9] = wtch10;

	// VirtualMux_12 (cy_virtualmux_v1_0)
	assign tach_bus[10] = wtch11;

	// VirtualMux_13 (cy_virtualmux_v1_0)
	assign tach_bus[15] = wtch16;

	// VirtualMux_14 (cy_virtualmux_v1_0)
	assign tach_bus[12] = wtch13;

	// VirtualMux_15 (cy_virtualmux_v1_0)
	assign tach_bus[13] = wtch14;

	// VirtualMux_16 (cy_virtualmux_v1_0)
	assign tach_bus[14] = wtch15;


	cy_clock_v1_0
		#(.id("115d90c7-a4da-4992-9a46-0c38de3465e3/800937c1-14f8-4f2d-8a24-5eeec3527130"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("2000000000"),
		  .is_direct(0),
		  .is_digital(1))
		TACH_CLK_500K
		 (.clock_out(tach_clk));



	cy_clock_v1_0
		#(.id("115d90c7-a4da-4992-9a46-0c38de3465e3/e5ec931a-b9ca-4d80-aabe-a9fd89aef066"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("41666666.6666667"),
		  .is_direct(0),
		  .is_digital(1))
		PWM_CLOCK_25k_10b
		 (.clock_out(Net_6559));


	// VirtualMux_53 (cy_virtualmux_v1_0)
	assign Net_6129 = Net_6559;


	cy_dma_v1_0
		#(.drq_type(2'b10))
		TachOutDMA
		 (.drq(drq),
		  .nrq(Net_6081),
		  .trq(1'b0));


	// VirtualMux_17 (cy_virtualmux_v1_0)
	assign fan_clk = Net_6129;

	// VirtualMux_26 (cy_virtualmux_v1_0)
	assign nrq = Net_6081;


	cy_clock_v1_0
		#(.id("115d90c7-a4da-4992-9a46-0c38de3465e3/229df128-31d0-4840-a20f-367f50b4df48"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BUS_CLK
		 (.clock_out(Net_39));


    B_FanTach_v4_10 FanTach (
        .addr(address[3:0]),
        .drq(drq),
        .en(enable),
        .override(override),
        .pid_int(Net_235),
        .speed_dn(Net_6505),
        .speed_up(Net_6146),
        .stall(Net_6149[15:0]),
        .stl_mask(alert_mask[15:0]),
        .tach_clock(tach_clk),
        .tch(tach_bus[15:0]));
    defparam FanTach.ClosedLoop = 0;
    defparam FanTach.DampingFactor = 1;
    defparam FanTach.FanModeManual = 0;
    defparam FanTach.MotorType = 0;
    defparam FanTach.NumberOfFans = 4;

    B_FanController_v4_10 B_FanCtrl (
        .addr(address[3:0]),
        .alert(alrt),
        .alt_mask(alert_mask[15:0]),
        .bus_clock(Net_39),
        .clock(fan_clk),
        .en(enable),
        .eoc(sync),
        .nrq(nrq),
        .ovrd(override),
        .pwm(pwm[16:1]),
        .spd_dn(Net_6505),
        .spd_up(Net_6146),
        .stall(Net_6149[15:0]));
    defparam B_FanCtrl.ErrorCount = 16;
    defparam B_FanCtrl.FanModeManual = 0;
    defparam B_FanCtrl.Mode = 0;
    defparam B_FanCtrl.NumOfFans = 4;
    defparam B_FanCtrl.Resolution = 10;


	cy_isr_v1_0
		#(.int_type(2'b10))
		PID_ISR
		 (.int_signal(Net_235));


	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign tach_bus[3] = wtch4;


    assign alert = alrt;

    assign bank = pwm[8:1];

    assign bank1 = pwm[1];

    assign bank2 = pwm[2];

    assign bank3 = pwm[3];

    assign bank4 = pwm[4];

    assign bank5 = pwm[5];

    assign bank6 = pwm[6];

    assign bank7 = pwm[7];

    assign bank8 = pwm[8];

    assign eoc = sync;

    assign fan = pwm[16:1];

    assign fan1 = pwm[1];

    assign fan10 = pwm[10];

    assign fan11 = pwm[11];

    assign fan12 = pwm[12];

    assign fan13 = pwm[13];

    assign fan14 = pwm[14];

    assign fan15 = pwm[15];

    assign fan16 = pwm[16];

    assign fan2 = pwm[2];

    assign fan3 = pwm[3];

    assign fan4 = pwm[4];

    assign fan5 = pwm[5];

    assign fan6 = pwm[6];

    assign fan7 = pwm[7];

    assign fan8 = pwm[8];

    assign fan9 = pwm[9];

    assign btch[16:1] = tach;

    assign wtch1 = tach1;

    assign wtch10 = tach10;

    assign wtch11 = tach11;

    assign wtch12 = tach12;

    assign wtch13 = tach13;

    assign wtch14 = tach14;

    assign wtch15 = tach15;

    assign wtch16 = tach16;

    assign wtch2 = tach2;

    assign wtch3 = tach3;

    assign wtch4 = tach4;

    assign wtch5 = tach5;

    assign wtch6 = tach6;

    assign wtch7 = tach7;

    assign wtch8 = tach8;

    assign wtch9 = tach9;


endmodule

// Component: FreqDiv_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\FreqDiv_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\FreqDiv_v1_0\FreqDiv_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\FreqDiv_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\FreqDiv_v1_0\FreqDiv_v1_0.v"
`endif

// Component: B_UART_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`endif

// UART_v2_50(Address1=0, Address2=0, BaudRate=115200, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=true, InternalClock=true, InternalClockToleranceMinus=3.93736842105263, InternalClockTolerancePlus=3.93736842105263, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=921600, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=UART_v2_50, CY_CONFIG_TITLE=UART, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=UART, )
module UART_v2_50_1 (
    clock,
    cts_n,
    reset,
    rts_n,
    rx,
    rx_clk,
    rx_data,
    rx_interrupt,
    tx,
    tx_clk,
    tx_data,
    tx_en,
    tx_interrupt);
    input       clock;
    input       cts_n;
    input       reset;
    output      rts_n;
    input       rx;
    output      rx_clk;
    output      rx_data;
    output      rx_interrupt;
    output      tx;
    output      tx_clk;
    output      tx_data;
    output      tx_en;
    output      tx_interrupt;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 1;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("1085069444.44444"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_50 BUART (
        .clock(Net_61),
        .cts_n(cts_n),
        .reset(reset),
        .rts_n(rts_n),
        .rx(rx),
        .rx_clk(rx_clk),
        .rx_data(rx_data),
        .rx_interrupt(rx_interrupt),
        .tx(tx),
        .tx_clk(tx_clk),
        .tx_data(tx_data),
        .tx_en(tx_en),
        .tx_interrupt(tx_interrupt));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 1;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// top
module top ;

          wire  Net_114;
          wire  Net_113;
          wire  Net_112;
          wire  Net_111;
          wire  Net_110;
          wire  Net_109;
          wire  Net_108;
          wire  Net_107;
          wire  Net_106;
          wire  Net_105;
          wire  Net_104;
          wire  Net_103;
          wire  Net_102;
          wire  Net_68;
          wire  Net_67;
          wire  Net_65;
          wire  Net_64;
          wire  Net_63;
          wire  Net_61;
          wire  Net_60;
          wire  Net_59;
          wire  Net_57;
          wire  Net_55;
          wire  Net_53;
          wire  Net_56;
          wire  Net_9;
          wire  Net_8;
          wire  Net_7;
          wire  Net_6;
          wire  Net_5;
          wire  Net_16;
          wire  Net_15;
          wire  Net_14;
          wire  Net_13;
          wire  Net_12;
          wire  Net_11;
          wire  Net_10;
          wire [4:1] Net_43;
          wire  Net_26;
          wire  Net_41;
          wire  Net_40;
          wire  Net_39;
          wire  Net_38;
          wire  Net_33;
          wire  Net_32;
          wire  Net_31;
          wire  Net_30;
          wire  Net_29;
          wire  Net_28;
          wire  Net_27;
          wire [4:1] Net_44;
          wire  Net_42;
          wire  Net_45;
          wire  Net_25;
          wire  Net_24;
          wire  Net_23;
          wire  Net_22;
          wire  Net_21;
          wire  Net_20;
          wire  Net_19;
          wire  Net_18;
          wire [8:1] Net_46;
          wire  Net_17;
          wire  Net_71;
          wire  Net_70;
          wire  Net_69;
          wire  Net_52;
          wire  Net_4;
          wire  Net_3;
          wire  Net_2;
          wire  Net_1;

    FanController_v4_10_0 FanController (
        .alert(Net_17),
        .bank(Net_46[8:1]),
        .bank1(Net_18),
        .bank2(Net_19),
        .bank3(Net_20),
        .bank4(Net_21),
        .bank5(Net_22),
        .bank6(Net_23),
        .bank7(Net_24),
        .bank8(Net_25),
        .clock(1'b0),
        .eoc(Net_42),
        .fan(Net_44[4:1]),
        .fan1(Net_52),
        .fan10(Net_27),
        .fan11(Net_28),
        .fan12(Net_29),
        .fan13(Net_30),
        .fan14(Net_31),
        .fan15(Net_32),
        .fan16(Net_33),
        .fan2(Net_69),
        .fan3(Net_70),
        .fan4(Net_71),
        .fan5(Net_38),
        .fan6(Net_39),
        .fan7(Net_40),
        .fan8(Net_41),
        .fan9(Net_26),
        .tach(16'b0),
        .tach1(Net_1),
        .tach10(1'b0),
        .tach11(1'b0),
        .tach12(1'b0),
        .tach13(1'b0),
        .tach14(1'b0),
        .tach15(1'b0),
        .tach16(1'b0),
        .tach2(Net_2),
        .tach3(Net_3),
        .tach4(Net_4),
        .tach5(1'b0),
        .tach6(1'b0),
        .tach7(1'b0),
        .tach8(1'b0),
        .tach9(1'b0));
    defparam FanController.FanMode = 0;
    defparam FanController.MotorType = 0;

	wire [0:0] tmpOE__Pin_Input_LEFT_net;
	wire [0:0] tmpIO_0__Pin_Input_LEFT_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Input_LEFT_net;
	electrical [0:0] tmpSIOVREF__Pin_Input_LEFT_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Input_LEFT
		 (.oe(tmpOE__Pin_Input_LEFT_net),
		  .y({1'b0}),
		  .fb({Net_56}),
		  .io({tmpIO_0__Pin_Input_LEFT_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Input_LEFT_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Input_LEFT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Input_LEFT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Output_LEFT_net;
	wire [0:0] tmpFB_0__Pin_Output_LEFT_net;
	wire [0:0] tmpIO_0__Pin_Output_LEFT_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Output_LEFT_net;
	electrical [0:0] tmpSIOVREF__Pin_Output_LEFT_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Output_LEFT
		 (.oe(tmpOE__Pin_Output_LEFT_net),
		  .y({Net_52}),
		  .fb({tmpFB_0__Pin_Output_LEFT_net[0:0]}),
		  .io({tmpIO_0__Pin_Output_LEFT_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Output_LEFT_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Output_LEFT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Output_LEFT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    FreqDiv_v1_0 FreqDiv_1 (
        .clock(Net_56),
        .div(Net_1),
        .en(1'b1),
        .reset(1'b0));
    defparam FreqDiv_1.Divider = 2;
    defparam FreqDiv_1.highPulse = 1;
    defparam FreqDiv_1.numBits = 1;

    FreqDiv_v1_0 FreqDiv_2 (
        .clock(Net_57),
        .div(Net_2),
        .en(1'b1),
        .reset(1'b0));
    defparam FreqDiv_2.Divider = 2;
    defparam FreqDiv_2.highPulse = 1;
    defparam FreqDiv_2.numBits = 1;

    FreqDiv_v1_0 FreqDiv_3 (
        .clock(Net_61),
        .div(Net_3),
        .en(1'b1),
        .reset(1'b0));
    defparam FreqDiv_3.Divider = 2;
    defparam FreqDiv_3.highPulse = 1;
    defparam FreqDiv_3.numBits = 1;

    FreqDiv_v1_0 FreqDiv_4 (
        .clock(Net_65),
        .div(Net_4),
        .en(1'b1),
        .reset(1'b0));
    defparam FreqDiv_4.Divider = 2;
    defparam FreqDiv_4.highPulse = 1;
    defparam FreqDiv_4.numBits = 1;

	wire [0:0] tmpOE__Pin_Input_RIGHT_net;
	wire [0:0] tmpIO_0__Pin_Input_RIGHT_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Input_RIGHT_net;
	electrical [0:0] tmpSIOVREF__Pin_Input_RIGHT_net;

	cy_psoc3_pins_v1_10
		#(.id("bab24b65-fd76-4a6f-8792-7cc442a30b60"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Input_RIGHT
		 (.oe(tmpOE__Pin_Input_RIGHT_net),
		  .y({1'b0}),
		  .fb({Net_57}),
		  .io({tmpIO_0__Pin_Input_RIGHT_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Input_RIGHT_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Input_RIGHT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Input_RIGHT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Input_UP_net;
	wire [0:0] tmpIO_0__Pin_Input_UP_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Input_UP_net;
	electrical [0:0] tmpSIOVREF__Pin_Input_UP_net;

	cy_psoc3_pins_v1_10
		#(.id("bd47af03-1858-4004-a03f-3827f0af1186"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Input_UP
		 (.oe(tmpOE__Pin_Input_UP_net),
		  .y({1'b0}),
		  .fb({Net_61}),
		  .io({tmpIO_0__Pin_Input_UP_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Input_UP_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Input_UP_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Input_UP_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Input_DOWN_net;
	wire [0:0] tmpIO_0__Pin_Input_DOWN_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Input_DOWN_net;
	electrical [0:0] tmpSIOVREF__Pin_Input_DOWN_net;

	cy_psoc3_pins_v1_10
		#(.id("9062ac12-0e99-4a55-a8d6-3a1b12713f7e"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Input_DOWN
		 (.oe(tmpOE__Pin_Input_DOWN_net),
		  .y({1'b0}),
		  .fb({Net_65}),
		  .io({tmpIO_0__Pin_Input_DOWN_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Input_DOWN_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Input_DOWN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Input_DOWN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Output_RIGHT_net;
	wire [0:0] tmpFB_0__Pin_Output_RIGHT_net;
	wire [0:0] tmpIO_0__Pin_Output_RIGHT_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Output_RIGHT_net;
	electrical [0:0] tmpSIOVREF__Pin_Output_RIGHT_net;

	cy_psoc3_pins_v1_10
		#(.id("6803ab6f-8630-4745-b022-a41302049f8d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Output_RIGHT
		 (.oe(tmpOE__Pin_Output_RIGHT_net),
		  .y({Net_69}),
		  .fb({tmpFB_0__Pin_Output_RIGHT_net[0:0]}),
		  .io({tmpIO_0__Pin_Output_RIGHT_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Output_RIGHT_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Output_RIGHT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Output_RIGHT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Output_UP_net;
	wire [0:0] tmpFB_0__Pin_Output_UP_net;
	wire [0:0] tmpIO_0__Pin_Output_UP_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Output_UP_net;
	electrical [0:0] tmpSIOVREF__Pin_Output_UP_net;

	cy_psoc3_pins_v1_10
		#(.id("1c9d0c6c-64db-48a5-8194-d25d11c255ac"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Output_UP
		 (.oe(tmpOE__Pin_Output_UP_net),
		  .y({Net_70}),
		  .fb({tmpFB_0__Pin_Output_UP_net[0:0]}),
		  .io({tmpIO_0__Pin_Output_UP_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Output_UP_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Output_UP_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Output_UP_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Pin_Output_DOWN_net;
	wire [0:0] tmpFB_0__Pin_Output_DOWN_net;
	wire [0:0] tmpIO_0__Pin_Output_DOWN_net;
	wire [0:0] tmpINTERRUPT_0__Pin_Output_DOWN_net;
	electrical [0:0] tmpSIOVREF__Pin_Output_DOWN_net;

	cy_psoc3_pins_v1_10
		#(.id("9f9cc96a-a016-4c4e-9ac0-97165e31f97f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_Output_DOWN
		 (.oe(tmpOE__Pin_Output_DOWN_net),
		  .y({Net_71}),
		  .fb({tmpFB_0__Pin_Output_DOWN_net[0:0]}),
		  .io({tmpIO_0__Pin_Output_DOWN_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_Output_DOWN_net),
		  .interrupt({tmpINTERRUPT_0__Pin_Output_DOWN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Output_DOWN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    UART_v2_50_1 UART (
        .clock(1'b0),
        .cts_n(1'b0),
        .reset(1'b0),
        .rts_n(Net_105),
        .rx(Net_106),
        .rx_clk(Net_107),
        .rx_data(Net_108),
        .rx_interrupt(Net_109),
        .tx(Net_110),
        .tx_clk(Net_111),
        .tx_data(Net_112),
        .tx_en(Net_113),
        .tx_interrupt(Net_114));
    defparam UART.Address1 = 0;
    defparam UART.Address2 = 0;
    defparam UART.EnIntRXInterrupt = 0;
    defparam UART.EnIntTXInterrupt = 0;
    defparam UART.FlowControl = 0;
    defparam UART.HalfDuplexEn = 0;
    defparam UART.HwTXEnSignal = 1;
    defparam UART.NumDataBits = 8;
    defparam UART.NumStopBits = 1;
    defparam UART.ParityType = 0;
    defparam UART.RXEnable = 1;
    defparam UART.TXEnable = 1;

	wire [0:0] tmpOE__Rx_1_net;
	wire [0:0] tmpIO_0__Rx_1_net;
	wire [0:0] tmpINTERRUPT_0__Rx_1_net;
	electrical [0:0] tmpSIOVREF__Rx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Rx_1
		 (.oe(tmpOE__Rx_1_net),
		  .y({1'b0}),
		  .fb({Net_106}),
		  .io({tmpIO_0__Rx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Rx_1_net),
		  .interrupt({tmpINTERRUPT_0__Rx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Rx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Tx_1_net;
	wire [0:0] tmpFB_0__Tx_1_net;
	wire [0:0] tmpIO_0__Tx_1_net;
	wire [0:0] tmpINTERRUPT_0__Tx_1_net;
	electrical [0:0] tmpSIOVREF__Tx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Tx_1
		 (.oe(tmpOE__Tx_1_net),
		  .y({Net_110}),
		  .fb({tmpFB_0__Tx_1_net[0:0]}),
		  .io({tmpIO_0__Tx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Tx_1_net),
		  .interrupt({tmpINTERRUPT_0__Tx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Tx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

