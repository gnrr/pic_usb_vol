/********************************************************************
 FileName:     	HardwareProfile - PIC18F87J94 PIM.h
 Dependencies:	See INCLUDES section
 Processor:	    PIC18 USB Microcontrollers
 Hardware:      PIC18F87J94 PIM
 Compiler:  	Microchip C18
 Company:		Microchip Technology, Inc.

 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC� Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
********************************************************************/

#ifndef HARDWARE_PROFILE_PIC18F87J94_PIM_H
#define HARDWARE_PROFILE_PIC18F87J94_PIM_H

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    /** USB ************************************************************/
    //The PIC18F87J94 FS USB Plug-In Module supports the USE_USB_BUS_SENSE_IO
    //feature.  The USE_SELF_POWER_SENSE_IO feature is not implemented on the
    //circuit board, so the USE_SELF_POWER_SENSE_IO define should always be
    //commented for this hardware platform.

    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #if defined(USE_SELF_POWER_SENSE_IO)
    #define self_power          PORTAbits.RA2
    #else
    #define self_power          1
    #endif

    //#define USE_USB_BUS_SENSE_IO		//JP1 must be in R-U position to use this feature on this board	
    #define tris_usb_bus_sense  TRISBbits.TRISB5    // Input
    #if defined(USE_USB_BUS_SENSE_IO)
    #define USB_BUS_SENSE       PORTBbits.RB5
    #else
    #define USB_BUS_SENSE       1
    #endif


   
    //Uncomment this to make the output HEX of this project 
    //   to be able to be bootloaded using the HID bootloader
	#define PROGRAMMABLE_WITH_USB_HID_BOOTLOADER		

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    /** Board definition ***********************************************/
    //These defintions will tell the main() function which board is
    //  currently selected.  This will allow the application to add
    //  the correct configuration bits as wells use the correct
    //  initialization functions for the board.  These defitions are only
    //  required in the stack provided demos.  They are not required in
    //  final application design.
    #define DEMO_BOARD PIC18F87J94_PIM
    #define PIC18F87J94_PIM
    #define PIC18F97J94_FAMILY
    #define CLOCK_FREQ 64000000
  
    /** LED ************************************************************/
    #define mInitAllLEDs()      {LATE &= 0xFC; TRISE &= 0xFC; LATD &= 0xF3; TRISD &= 0xF3;}
    
    #define mLED_1              LATEbits.LATE0
    #define mLED_2              LATEbits.LATE1
    #define mLED_3              LATDbits.LATD2
    #define mLED_4              LATDbits.LATD3
    
    #define mGetLED_1()         mLED_1
    #define mGetLED_2()         mLED_2
    #define mGetLED_3()         mLED_3
    #define mGetLED_4()         mLED_4

    #define mLED_1_On()         mLED_1 = 1;
    #define mLED_2_On()         mLED_2 = 1;
    #define mLED_3_On()         mLED_3 = 1;
    #define mLED_4_On()         mLED_4 = 1;
    
    #define mLED_1_Off()        mLED_1 = 0;
    #define mLED_2_Off()        mLED_2 = 0;
    #define mLED_3_Off()        mLED_3 = 0;
    #define mLED_4_Off()        mLED_4 = 0;
    
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;
    #define mLED_2_Toggle()     mLED_2 = !mLED_2;
    #define mLED_3_Toggle()     mLED_3 = !mLED_3;
    #define mLED_4_Toggle()     mLED_4 = !mLED_4;
    
    /** SWITCH *********************************************************/
    #define mInitAllSwitches()  TRISBbits.TRISB4 = 1;
    #define mInitSwitch2()      TRISBbits.TRISB4 = 1;
    #define mInitSwitch3()      TRISBbits.TRISB4 = 1;
    #define sw2                 PORTBbits.RB4
    #define sw3                 PORTBbits.RB4

    /** POT ************************************************************/
    //Analog potentiometer is located on the PICDEM PIC18 Explorer Demo Board, 
    //which is connected to microcontroller pin RA0, when the PIM is plugged
    //into the board.
    #define mInitPOT()          {TRISAbits.TRISA0 = 1; \
                                ANCON1bits.ANSEL0 = 1; \
                                ADCON1H = 0x00; \
                                ADCON1L = 0x70; \
                                ADCON2H = 0x08; \
                                ADCON2L = 0x00; \
                                ADCON3H = 0x0A; \
                                ADCON3L = 0x0C; \
                                ADCON5H = 0x00; \
                                ADCON5L = 0x00; \
                                ADCHS0H = 0x00; \
                                ADCHS0L = 0x00; \
                                ADCON1Hbits.ADON = 1;}

//    ADCON1H = 0x00; //10-bit mode, right justified unsigned
//    ADCON1L = 0x70; //Initiate auto-convert by manually setting SAMP bit
//    ADCON2H = 0x08; //AVDD/AVSS used as references, index result buffer mode (AN3 result goes in ADRES3)
//    ADCON2L = 0x00; //Only use MUX A, interrupt after each sample
//    ADCON3H = 0x0A; //10 Tad acquisition
//    ADCON3L = 0x0C; //13 Tcy per Tad = 812.5ns Tads at 64MHz CPU
//    ADCON5H = 0x00; //No auto scan or compare operations
//    ADCON5L = 0x00; //Write all results, do not use compare mode
//    ADCHS0H = 0x00; //Single ended AN0 selected in MUX B
//    ADCHS0L = 0x00; //Single ended AN0 selected in MUX A
//    ADCON1Hbits.ADON = 1;   //Enable the ADC now
//    //Set SAMP bit to begin sampling and subsequent conversion.

   
    /** I/O pin definitions ********************************************/
    #define INPUT_PIN 1
    #define OUTPUT_PIN 0

    #define SetUsbInterruptToLowPriority()  IPR2bits.USBIP = 0;
    
	/*** Audio    ************************************************/
	#ifdef AUDIO_SAMPLING_FREQUENCY_48000
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 48
   		#define PWM_PERIOD	(CLOCK_FREQ/48000)-1
	#elif defined AUDIO_SAMPLING_FREQUENCY_32000
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 32
   		#define PWM_PERIOD	(CLOCK_FREQ/32000)-1
	#elif defined AUDIO_SAMPLING_FREQUENCY_44100
   		#define NO_OF_SAMPLES_IN_A_USB_FRAME 44
   		#define PWM_PERIOD	(CLOCK_FREQ/44100)-1
	#endif 	
	
	/*** Intialize Audio Driver in Speech Playback Card *********************************************/
 	#define mInitAudioDriver()  {TRISAbits.TRISA4=OUTPUT_PIN; LATAbits.LATA4 = 1; } 
	#define mAudioDriverON()	LATAbits.LATA4 = 0;    
	#define mAudioDriverOFF()	LATAbits.LATA4 = 1;
	
	/****** PWM Intialization************************************/ 
	// configure RC2 as output for PWM 
	// PWM mode, Single output, Active High
	#define mInitPWM() 			{ PR2 = PWM_PERIOD;\
								  CCPR1L = 0;\
								  RPOR10_11bits.RPO11R = 4;\
								  TRISCbits.TRISC2 = 0;\
								  mInitTimer();\
								  CCP1CON = 0x0c;\
								}
	#define DUTY_CYCLE CCPR1L  // Duty Cycle register of the PWM Peripheral.
	/****** Timer2 Intialization************************************/ 	
	// Enable Interrupt priority
	// Enable all unmasked low priority interrupts
	// Enable all unmasked high priority interrupts	
	// Timer2 interrupt is low priority 							
	#define mInitTimerInterrupt() {RCONbits.IPEN = 1; IPR1bits.TMR2IP = 1; INTCONbits.GIEL = 1; INTCONbits.GIEH = 1;}
	
	// Timer 2 on, Prescaler is 1, Postscaler is 1
	// unmask timer 2 interrupt
	#define mInitTimer() {TMR2 = 0; T2CON = 0x00; PIE1bits.TMR2IE = 0; T2CONbits.TMR2ON =1;}
	#define PWM_INTERRUPT_FLAG PIR1bits.TMR2IF
	#define TimerInterruptEnable PIE1bits.TMR2IE
	
	
    /****** Unmask Timer2 Interrupt ************************************/
    #define mStartAudio()  {PIE1bits.TMR2IE = 1;} // unmask timer 2 interrupt
    
    /******* Mask Timer2 Interrupt  ***********************************/
    #define mStopAudio()   {PIE1bits.TMR2IE = 0;}// mask timer 2 interrupt
	

	
#endif  //HARDWARE_PROFILE_PIC18F87J94_PIM_H
