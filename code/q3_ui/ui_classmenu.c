//Based off of the PClass Menu of Trent Gordon of the AVM team, who never comments!!!!!!!!!!
//-JG




#include "ui_local.h"

#define MYCIVMAIN_FRAME	"menu/art/cut_frame"
#define MYMARINEMAIN_FRAME	"menu/art/cut_frame"

#define ID_HUNTER		200
#define ID_SECURITY		201
#define ID_DOCTOR		202
#define ID_POSTALWORKER	203
#define ID_BRUTE		204
#define ID_STANDARD		205
#define ID_PETITE		206

//int teamFlag; //1 is alien, 2 is drone, 3 is sarge, 4 is grunt, 5 is support, 6 is rocket


/*
=============================================================================

START CIVILIAN MENU *****

=============================================================================
*/
   typedef struct
   {
      menuframework_s	mycivmenu;
      menubitmap_s		myframe;
      menutext_s		joinHunter;//Text options-Hunter
      menutext_s		joinSecurity;//Text options-Security
      menutext_s		joinDoctor;//Text options-Doctor
      menutext_s		joinPostal;//Text options-Postal
   
   }mycivmain_t;

   static mycivmain_t	s_mycivmain;



/*
===============
MyCivMain_MenuEvent
===============
*/
    static void MyCivMain_MenuEvent( void* ptr, int event ) {
      if( event != QM_ACTIVATED ) {
         return;
      }
   
      switch( ((menucommon_s*)ptr)->id ) {
      
         case ID_HUNTER:
            trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team hunter\n" );//Hunter
            UI_ForceMenuOff();
            break;
      
         case ID_SECURITY:
            trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team security\n" );//Security
            UI_ForceMenuOff();
            break;
         case ID_DOCTOR:
            trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team doctor\n" );//Doctor
            UI_ForceMenuOff();
            break;
         case ID_POSTALWORKER:
            trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team postalworker\n" );//Postal
            UI_ForceMenuOff();
            break;
      }
   }

/*
===============
MyCivMain_MenuInit
===============
*/
	//Initializes the Menu by choosing the type of text, the color, etc. Look up tutorials for more info.
	//Also calls the MyCivMain_MenuEvent as the function(method call in java)-JG
    void MyCivMain_MenuInit( void ) {
      int		y;
      int		gametype;
      char	info[MAX_INFO_STRING];
   
      memset( &s_mycivmain, 0, sizeof(s_mycivmain) );
   
   
      y = 149;
   
      s_mycivmain.mycivmenu.wrapAround = qtrue;
      s_mycivmain.mycivmenu.fullscreen = qfalse;
   
      s_mycivmain.joinHunter.generic.type     = MTYPE_PTEXT;
      s_mycivmain.joinHunter.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
      s_mycivmain.joinHunter.generic.id       = ID_HUNTER;
      s_mycivmain.joinHunter.generic.callback = MyCivMain_MenuEvent;
      s_mycivmain.joinHunter.generic.x        = 320;
      s_mycivmain.joinHunter.generic.y        = y;
      s_mycivmain.joinHunter.string           = "HUNTER";//Sniper(Alp)
      s_mycivmain.joinHunter.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
      s_mycivmain.joinHunter.color            = color_blue;
      y += 30;
   
      s_mycivmain.joinSecurity.generic.type     = MTYPE_PTEXT;
      s_mycivmain.joinSecurity.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
      s_mycivmain.joinSecurity.generic.id       = ID_SECURITY;
      s_mycivmain.joinSecurity.generic.callback = MyCivMain_MenuEvent;
      s_mycivmain.joinSecurity.generic.x        = 320;
      s_mycivmain.joinSecurity.generic.y        = y;
      s_mycivmain.joinSecurity.string           = "MALL SECURITY";//Security(Johnny)
      s_mycivmain.joinSecurity.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
      s_mycivmain.joinSecurity.color            = color_blue;
      y += 30;
   
      s_mycivmain.joinDoctor.generic.type     = MTYPE_PTEXT;
      s_mycivmain.joinDoctor.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
      s_mycivmain.joinDoctor.generic.id       = ID_DOCTOR;
      s_mycivmain.joinDoctor.generic.callback = MyCivMain_MenuEvent;
      s_mycivmain.joinDoctor.generic.x        = 320;
      s_mycivmain.joinDoctor.generic.y        = y;
      s_mycivmain.joinDoctor.string           = "DOCTOR";//Doctor(Sandro)
      s_mycivmain.joinDoctor.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
      s_mycivmain.joinDoctor.color            = color_blue;
      y += 30;
   
      s_mycivmain.joinPostal.generic.type     = MTYPE_PTEXT;
      s_mycivmain.joinPostal.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
      s_mycivmain.joinPostal.generic.id       = ID_POSTALWORKER;
      s_mycivmain.joinPostal.generic.callback = MyCivMain_MenuEvent;
      s_mycivmain.joinPostal.generic.x        = 320;
      s_mycivmain.joinPostal.generic.y        = y;
      s_mycivmain.joinPostal.string           = "POSTALWORKER";//PostalWorker(Jared)
      s_mycivmain.joinPostal.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
      s_mycivmain.joinPostal.color            = color_blue;
      y += 30;
   
      trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);   
      gametype = atoi( Info_ValueForKey( info,"g_gametype" ) );
   		      
   //Adds the actual menu in-JG
      Menu_AddItem( &s_mycivmain.mycivmenu, (void*) &s_mycivmain.joinHunter );
      Menu_AddItem( &s_mycivmain.mycivmenu, (void*) &s_mycivmain.joinSecurity );
      Menu_AddItem( &s_mycivmain.mycivmenu, (void*) &s_mycivmain.joinDoctor );
      Menu_AddItem( &s_mycivmain.mycivmenu, (void*) &s_mycivmain.joinPostal );
   
   }


/*
===============
MyCivMain_Cache
===============
*/
//Sets the Shader-JG
    void MyCivMain_Cache( void ) {
      trap_R_RegisterShaderNoMip( MYCIVMAIN_FRAME );
   }

/*
===============
UI_MyCivMainMenu
===============
*///Sets the Shader-JG
    void UI_MyCivMainMenu( void ) {
      MyCivMain_MenuInit();
      UI_PushMenu ( &s_mycivmain.mycivmenu);
   }



