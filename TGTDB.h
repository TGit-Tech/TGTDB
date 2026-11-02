/*******************************************************************************************************************//**
 * @file TGTDB.h
 * @brief Debug Pre-Compiler Constants
 **********************************************************************************************************************/
#ifndef _TGTDB_H
#define _TGTDB_H

/*********************************************//**
 * @defgroup DB Debug Directives
 * @brief    DBERROR | DBENTER | DBINFO.
 *            - Pre-Compiler Directives for Debug Messaging.
 *            - Each-Type (ERROR,ENTER,INFO) allows (1,2,3) [A]rgument Variables.
 *            - Use '\n' in debug message for new-line
 *            - Message-Type output is '!ERROR!', '...', 'Info'
 *            - **NO** trailing ';' in source code.
 *          DBUI | DBHW | DBL | DBDB | DBH | DBS
 *            - Code Sectioning (DBUIERROR, DBDBENTER, DBHINFO, etc...)
 * @code{.c} 
 *          DBERROR(("no new line"))
 *          DBERROR(("new line \n"))
 *          DBAERROR((Variable),("Error Message"))
 *          DBAAERROR((Variable),(Variable),("Error Message"))
 *          DBAAINFO((Variable),(Variable),("Info Message with new line \n"))
 * @endcode
 * @{
 ************************************************/
// ON/OFF Importance-Level debug (All 0 for release; Code-Section won't matter.)
#ifndef DB_ERROR
  #define DB_ERROR  0
#endif
#ifndef DB_ENTER
  #define DB_ENTER  0
#endif
#ifndef DB_INFO
  #define DB_INFO   0
#endif

// ON/OFF Code-Sections
// 0=All Importance-Levels OFF in this code-section.
// 1=Active; Importance-levels as assigned above.
// DB_GEN No Section      DBERROR | DBENTER | DBINFO
// DBUI	  User Interface	Menus, displays, buttons, user input, and other user-facing interactions.
// DBHW	  Hardware	      GPIO, sensors, relays, physical interfaces, and hardware control logic.
// DBL	  Links	          RF, serial, USB, and communications between devices, classes, or subsystems.
// DBDB	  Database	      Complex data structures, DIT records, structured data storage, and handling.
// DBH	  Helpers	        Encoding, decoding, conversions, bit manipulation, and reusable utility functions.
// DBS	  System	        Initialization, configuration, system state, and overall system operation.
#ifndef DB_GEN
  #define DB_GEN    0
#endif
#ifndef DBUI
  #define DBUI      0
#endif
#ifndef DBHW
  #define DBHW      0
#endif
#ifndef DBDB
  #define DBDB      0
#endif
#ifndef DBL
  #define DBL       0
#endif
#ifndef DBH
  #define DBH       0
#endif
#ifndef DBS
  #define DBS       0
#endif

#define SERLINEZ(z) Serial.print((F(z)));
#define SERLINEYZ(y,z) Serial.print y;Serial.print(F(")"));SERLINEZ(z)
#define SERLINEXYZ(x,y,z) Serial.print x;Serial.print(F(","));SERLINEYZ(y,z)
#define SERLINEWXYZ(w,x,y,z) Serial.print w;Serial.print(F(","));SERLINEXYZ(x,y,z)
//----------------------------------------------------------------------------------
// GEN Code-Section DBERROR, DBENTER, DBINFO Macros
//----------------------------------------------------------------------------------
#define COMMA ,
#if (DB_ERROR && DB_GEN)
#define DBAAAERROR(w,x,y,z) Serial.print(F("!ERROR! ("));SERLINEWXYZ(w,x,y,z)
#define DBAAERROR(x,y,z) Serial.print(F("!ERROR! ("));SERLINEXYZ(x,y,z)
#define DBAERROR(y,z) Serial.print(F("!ERROR! ("));SERLINEYZ(y,z)
#define DBERROR(z) Serial.print(F("!ERROR! "));SERLINEZ(z)
#define DBERRORSP(z) Serial.print z;
#else
#define DBAAAERROR(w,x,y,z)
#define DBAAERROR(x,y,z)
#define DBAERROR(y,z)
#define DBERROR(z)
#define DBERRORSP(z)
#endif

#if (DB_ENTER && DB_GEN)
#define DBAAAENTER(w,x,y,z) Serial.print(F("__> ("));SERLINEWXYZ(w,x,y,z)
#define DBAAENTER(x,y,z) Serial.print(F("__> ("));SERLINEXYZ(x,y,z)
#define DBAENTER(y,z) Serial.print(F("__> ("));SERLINEYZ(y,z)
#define DBENTER(z) Serial.print(F("__> "));SERLINEZ(z)
#define DBENTERSP(z) Serial.print z;
#else
#define DBAAAENTER(w,x,y,z)
#define DBAAENTER(x,y,z)
#define DBAENTER(y,z)
#define DBENTER(z)
#define DBENTERSP(z)
#endif

#if (DB_INFO && DB_GEN)
#define DBAAAINFO(w,x,y,z) Serial.print(F("...("));SERLINEWXYZ(w,x,y,z)
#define DBAAINFO(x,y,z) Serial.print(F("...("));SERLINEXYZ(x,y,z)
#define DBAINFO(y,z) Serial.print(F("...("));SERLINEYZ(y,z)
#define DBINFO(z) Serial.print(F("... "));SERLINEZ(z)
#define DBINFOSP(z) Serial.print z;
#else
#define DBAAAINFO(w,x,y,z)
#define DBAAINFO(x,y,z)
#define DBAINFO(y,z)
#define DBINFO(z)
#define DBINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// UI Code-Section DBUIERROR, DBUIENTER, DBUIINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBUI)
#define DBUIAAAERROR(w,x,y,z) Serial.print(F("!ERROR!UI ("));SERLINEWXYZ(w,x,y,z)
#define DBUIAAERROR(x,y,z) Serial.print(F("!ERROR!UI ("));SERLINEXYZ(x,y,z)
#define DBUIAERROR(y,z) Serial.print(F("!ERROR!UI ("));SERLINEYZ(y,z)
#define DBUIERROR(z) Serial.print(F("!ERROR!UI "));SERLINEZ(z)
#define DBUIERRORSP(z) Serial.print z;
#else
#define DBUIAAAERROR(w,x,y,z)
#define DBUIAAERROR(x,y,z)
#define DBUIAERROR(y,z)
#define DBUIERROR(z)
#define DBUIERRORSP(z)
#endif

#if (DB_ENTER && DBUI)
#define DBUIAAAENTER(w,x,y,z) Serial.print(F("__UI> ("));SERLINEWXYZ(w,x,y,z)
#define DBUIAAENTER(x,y,z) Serial.print(F("__UI> ("));SERLINEXYZ(x,y,z)
#define DBUIAENTER(y,z) Serial.print(F("__UI> ("));SERLINEYZ(y,z)
#define DBUIENTER(z) Serial.print(F("__UI> "));SERLINEZ(z)
#define DBUIENTERSP(z) Serial.print z;
#else
#define DBUIAAAENTER(w,x,y,z)
#define DBUIAAENTER(x,y,z)
#define DBUIAENTER(y,z)
#define DBUIENTER(z)
#define DBUIENTERSP(z)
#endif

#if (DB_INFO && DBUI)
#define DBUIAAAINFO(w,x,y,z) Serial.print(F("...UI("));SERLINEWXYZ(w,x,y,z)
#define DBUIAAINFO(x,y,z) Serial.print(F("...UI("));SERLINEXYZ(x,y,z)
#define DBUIAINFO(y,z) Serial.print(F("...UI("));SERLINEYZ(y,z)
#define DBUIINFO(z) Serial.print(F("...UI "));SERLINEZ(z)
#define DBUIINFOSP(z) Serial.print z;
#else
#define DBUIAAAINFO(w,x,y,z)
#define DBUIAAINFO(x,y,z)
#define DBUIAINFO(y,z)
#define DBUIINFO(z)
#define DBUIINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// HW Code-Section DBHWERROR, DBHWENTER, DBHWINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBHW)
#define DBHWAAAERROR(w,x,y,z) Serial.print(F("!ERROR!HW ("));SERLINEWXYZ(w,x,y,z)
#define DBHWAAERROR(x,y,z) Serial.print(F("!ERROR!HW ("));SERLINEXYZ(x,y,z)
#define DBHWAERROR(y,z) Serial.print(F("!ERROR!HW ("));SERLINEYZ(y,z)
#define DBHWERROR(z) Serial.print(F("!ERROR!HW "));SERLINEZ(z)
#define DBHWERRORSP(z) Serial.print z;
#else
#define DBHWAAAERROR(w,x,y,z)
#define DBHWAAERROR(x,y,z)
#define DBHWAERROR(y,z)
#define DBHWERROR(z)
#define DBHWERRORSP(z)
#endif

#if (DB_ENTER && DBHW)
#define DBHWAAAENTER(w,x,y,z) Serial.print(F("__HW> ("));SERLINEWXYZ(w,x,y,z)
#define DBHWAAENTER(x,y,z) Serial.print(F("__HW> ("));SERLINEXYZ(x,y,z)
#define DBHWAENTER(y,z) Serial.print(F("__HW> ("));SERLINEYZ(y,z)
#define DBHWENTER(z) Serial.print(F("__HW> "));SERLINEZ(z)
#define DBHWENTERSP(z) Serial.print z;
#else
#define DBHWAAAENTER(w,x,y,z)
#define DBHWAAENTER(x,y,z)
#define DBHWAENTER(y,z)
#define DBHWENTER(z)
#define DBHWENTERSP(z)
#endif

#if (DB_INFO && DBHW)
#define DBHWAAAINFO(w,x,y,z) Serial.print(F("...HW("));SERLINEWXYZ(w,x,y,z)
#define DBHWAAINFO(x,y,z) Serial.print(F("...HW("));SERLINEXYZ(x,y,z)
#define DBHWAINFO(y,z) Serial.print(F("...HW("));SERLINEYZ(y,z)
#define DBHWINFO(z) Serial.print(F("...HW "));SERLINEZ(z)
#define DBHWINFOSP(z) Serial.print z;
#else
#define DBHWAAAINFO(w,x,y,z)
#define DBHWAAINFO(x,y,z)
#define DBHWAINFO(y,z)
#define DBHWINFO(z)
#define DBHWINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// DB Code-Section DBDBERROR, DBDBENTER, DBDBINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBDB)
#define DBDBAAAERROR(w,x,y,z) Serial.print(F("!ERROR!DB ("));SERLINEWXYZ(w,x,y,z)
#define DBDBAAERROR(x,y,z) Serial.print(F("!ERROR!DB ("));SERLINEXYZ(x,y,z)
#define DBDBAERROR(y,z) Serial.print(F("!ERROR!DB ("));SERLINEYZ(y,z)
#define DBDBERROR(z) Serial.print(F("!ERROR!DB "));SERLINEZ(z)
#define DBDBERRORSP(z) Serial.print z;
#else
#define DBDBAAAERROR(w,x,y,z)
#define DBDBAAERROR(x,y,z)
#define DBDBAERROR(y,z)
#define DBDBERROR(z)
#define DBDBERRORSP(z)
#endif

#if (DB_ENTER && DBDB)
#define DBDBAAAENTER(w,x,y,z) Serial.print(F("__DB> ("));SERLINEWXYZ(w,x,y,z)
#define DBDBAAENTER(x,y,z) Serial.print(F("__DB> ("));SERLINEXYZ(x,y,z)
#define DBDBAENTER(y,z) Serial.print(F("__DB> ("));SERLINEYZ(y,z)
#define DBDBENTER(z) Serial.print(F("__DB> "));SERLINEZ(z)
#define DBDBENTERSP(z) Serial.print z;
#else
#define DBDBAAAENTER(w,x,y,z)
#define DBDBAAENTER(x,y,z)
#define DBDBAENTER(y,z)
#define DBDBENTER(z)
#define DBDBENTERSP(z)
#endif

#if (DB_INFO && DBDB)
#define DBDBAAAINFO(w,x,y,z) Serial.print(F("...DB("));SERLINEWXYZ(w,x,y,z)
#define DBDBAAINFO(x,y,z) Serial.print(F("...DB("));SERLINEXYZ(x,y,z)
#define DBDBAINFO(y,z) Serial.print(F("...DB("));SERLINEYZ(y,z)
#define DBDBINFO(z) Serial.print(F("...DB "));SERLINEZ(z)
#define DBDBINFOSP(z) Serial.print z;
#else
#define DBDBAAAINFO(w,x,y,z)
#define DBDBAAINFO(x,y,z)
#define DBDBAINFO(y,z)
#define DBDBINFO(z)
#define DBDBINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// L Code-Section DBLERROR, DBLENTER, DBLINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBL)
#define DBLAAAERROR(w,x,y,z) Serial.print(F("!ERROR!L ("));SERLINEWXYZ(w,x,y,z)
#define DBLAAERROR(x,y,z) Serial.print(F("!ERROR!L ("));SERLINEXYZ(x,y,z)
#define DBLAERROR(y,z) Serial.print(F("!ERROR!L ("));SERLINEYZ(y,z)
#define DBLERROR(z) Serial.print(F("!ERROR!L "));SERLINEZ(z)
#define DBLERRORSP(z) Serial.print z;
#else
#define DBLAAAERROR(w,x,y,z)
#define DBLAAERROR(x,y,z)
#define DBLAERROR(y,z)
#define DBLERROR(z)
#define DBLERRORSP(z)
#endif

#if (DB_ENTER && DBL)
#define DBLAAAENTER(w,x,y,z) Serial.print(F("__L> ("));SERLINEWXYZ(w,x,y,z)
#define DBLAAENTER(x,y,z) Serial.print(F("__L> ("));SERLINEXYZ(x,y,z)
#define DBLAENTER(y,z) Serial.print(F("__L> ("));SERLINEYZ(y,z)
#define DBLENTER(z) Serial.print(F("__L> "));SERLINEZ(z)
#define DBLENTERSP(z) Serial.print z;
#else
#define DBLAAAENTER(w,x,y,z)
#define DBLAAENTER(x,y,z)
#define DBLAENTER(y,z)
#define DBLENTER(z)
#define DBLENTERSP(z)
#endif

#if (DB_INFO && DBL)
#define DBLAAAINFO(w,x,y,z) Serial.print(F("...L("));SERLINEWXYZ(w,x,y,z)
#define DBLAAINFO(x,y,z) Serial.print(F("...L("));SERLINEXYZ(x,y,z)
#define DBLAINFO(y,z) Serial.print(F("...L("));SERLINEYZ(y,z)
#define DBLINFO(z) Serial.print(F("...L "));SERLINEZ(z)
#define DBLINFOSP(z) Serial.print z;
#else
#define DBLAAAINFO(w,x,y,z)
#define DBLAAINFO(x,y,z)
#define DBLAINFO(y,z)
#define DBLINFO(z)
#define DBLINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// H Code-Section DBHERROR, DBHENTER, DBHINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBH)
#define DBHAAAERROR(w,x,y,z) Serial.print(F("!ERROR!H ("));SERLINEWXYZ(w,x,y,z)
#define DBHAAERROR(x,y,z) Serial.print(F("!ERROR!H ("));SERLINEXYZ(x,y,z)
#define DBHAERROR(y,z) Serial.print(F("!ERROR!H ("));SERLINEYZ(y,z)
#define DBHERROR(z) Serial.print(F("!ERROR!H "));SERLINEZ(z)
#define DBHERRORSP(z) Serial.print z;
#else
#define DBHAAAERROR(w,x,y,z)
#define DBHAAERROR(x,y,z)
#define DBHAERROR(y,z)
#define DBHERROR(z)
#define DBHERRORSP(z)
#endif

#if (DB_ENTER && DBH)
#define DBHAAAENTER(w,x,y,z) Serial.print(F("__H> ("));SERLINEWXYZ(w,x,y,z)
#define DBHAAENTER(x,y,z) Serial.print(F("__H> ("));SERLINEXYZ(x,y,z)
#define DBHAENTER(y,z) Serial.print(F("__H> ("));SERLINEYZ(y,z)
#define DBHENTER(z) Serial.print(F("__H> "));SERLINEZ(z)
#define DBHENTERSP(z) Serial.print z;
#else
#define DBHAAAENTER(w,x,y,z)
#define DBHAAENTER(x,y,z)
#define DBHAENTER(y,z)
#define DBHENTER(z)
#define DBHENTERSP(z)
#endif

#if (DB_INFO && DBH)
#define DBHAAAINFO(w,x,y,z) Serial.print(F("...H("));SERLINEWXYZ(w,x,y,z)
#define DBHAAINFO(x,y,z) Serial.print(F("...H("));SERLINEXYZ(x,y,z)
#define DBHAINFO(y,z) Serial.print(F("...H("));SERLINEYZ(y,z)
#define DBHINFO(z) Serial.print(F("...H "));SERLINEZ(z)
#define DBHINFOSP(z) Serial.print z;
#else
#define DBHAAAINFO(w,x,y,z)
#define DBHAAINFO(x,y,z)
#define DBHAINFO(y,z)
#define DBHINFO(z)
#define DBHINFOSP(z)
#endif
//----------------------------------------------------------------------------------
// S Code-Section DBSERROR, DBSENTER, DBSINFO Macros
//----------------------------------------------------------------------------------
#if (DB_ERROR && DBS)
#define DBSAAAERROR(w,x,y,z) Serial.print(F("!ERROR!S ("));SERLINEWXYZ(w,x,y,z)
#define DBSAAERROR(x,y,z) Serial.print(F("!ERROR!S ("));SERLINEXYZ(x,y,z)
#define DBSAERROR(y,z) Serial.print(F("!ERROR!S ("));SERLINEYZ(y,z)
#define DBSERROR(z) Serial.print(F("!ERROR!S "));SERLINEZ(z)
#define DBSERRORSP(z) Serial.print z;
#else
#define DBSAAAERROR(w,x,y,z)
#define DBSAAERROR(x,y,z)
#define DBSAERROR(y,z)
#define DBSERROR(z)
#define DBSERRORSP(z)
#endif

#if (DB_ENTER && DBS)
#define DBSAAAENTER(w,x,y,z) Serial.print(F("__S> ("));SERLINEWXYZ(w,x,y,z)
#define DBSAAENTER(x,y,z) Serial.print(F("__S> ("));SERLINEXYZ(x,y,z)
#define DBSAENTER(y,z) Serial.print(F("__S> ("));SERLINEYZ(y,z)
#define DBSENTER(z) Serial.print(F("__S> "));SERLINEZ(z)
#define DBSENTERSP(z) Serial.print z;
#else
#define DBSAAAENTER(w,x,y,z)
#define DBSAAENTER(x,y,z)
#define DBSAENTER(y,z)
#define DBSENTER(z)
#define DBSENTERSP(z)
#endif

#if (DB_INFO && DBS)
#define DBSAAAINFO(w,x,y,z) Serial.print(F("...S("));SERLINEWXYZ(w,x,y,z)
#define DBSAAINFO(x,y,z) Serial.print(F("...S("));SERLINEXYZ(x,y,z)
#define DBSAINFO(y,z) Serial.print(F("...S("));SERLINEYZ(y,z)
#define DBSINFO(z) Serial.print(F("...S "));SERLINEZ(z)
#define DBSINFOSP(z) Serial.print z;
#else
#define DBSAAAINFO(w,x,y,z)
#define DBSAAINFO(x,y,z)
#define DBSAINFO(y,z)
#define DBSINFO(z)
#define DBSINFOSP(z)
#endif
///@}
//_____________________________________________________________________________________________________________________
#endif
