/* Mednafen - Multi-system Emulator
 *
 * Copyright notice for this file:
 *  Copyright (C) 2003 Xodnizel
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "share.h"

namespace MDFN_IEN_NES
{

static uint8 HSVal,HSValR;


static uint8 HS_Read(int w, uint8 ret)
{
 if(w) ret|=HSValR;

 return(ret);
}

static void HS_Strobe(void)
{
 HSValR=HSVal<<1;
}

static void HS_Update(void *data)
{
 HSVal=*(uint8*)data;
}

static void StateActionFC(StateMem *sm, const unsigned load, const bool data_only)
{
 SFORMAT StateRegs[] =
 {
   SFVAR(HSVal),
   SFEND
 };

 MDFNSS_StateAction(sm, load, data_only, StateRegs, "HSHT", true);

 if(load)
 {

 }
}

static INPUTCFC HyperShot={HS_Read,0,HS_Strobe,HS_Update,0,0, StateActionFC };

INPUTCFC *MDFN_InitHS(void)
{
 HSVal=HSValR=0;
 return(&HyperShot);
}

}
