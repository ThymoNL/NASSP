/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005 Mark Grant

  ORBITER vessel module: CSM caution and warning system code.

  Project Apollo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Project Apollo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Project Apollo; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  See http://nassp.sourceforge.net/license/ for more details.

  **************************** Revision History ****************************
  *	$Log$
  *	Revision 1.1  2005/08/13 14:59:24  movieman523
  *	Added initial null implementation of CSM caution and warning system, and removed 'master alarm' flag from Saturn class.
  *	
  **************************************************************************/


#if !defined(_PA_CSMCAUTIONWARNING_H)
#define _PA_CSMCAUTIONWARNING_H

class CSMCautionWarningSystem : public CautionWarningSystem {

public:
	CSMCautionWarningSystem(Sound &s);
	void TimeStep(double simt);
	void RenderLights(SURFHANDLE surf, SURFHANDLE lightsurf, bool leftpanel);

protected:

	//
	// Don't need to be saved.
	//

	double NextUpdateTime;

	//
	// Helper functions.
	//

	void RenderLightPanel(SURFHANDLE surf, SURFHANDLE lightsurf, bool *LightState, bool LightTest, int sdx, int sdy);
};

#endif
