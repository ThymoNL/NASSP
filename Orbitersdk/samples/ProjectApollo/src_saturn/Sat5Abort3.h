/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2018



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

  **************************************************************************/

class Sat5Abort3: public VESSEL3 {

public:

	Sat5Abort3 (OBJHANDLE hObj, int fmodel);
	virtual ~Sat5Abort3();
	void init();
	void Setup();
	virtual void SetState(bool lowres);
	void clbkSaveState(FILEHANDLE scn);
	void clbkLoadStateEx(FILEHANDLE scn, void *status);

	void clbkSetClassCaps(FILEHANDLE cfg);

protected:

	bool LowRes;                    ///< Mesh resolution flag

	//
	// We don't actually seem to use any of these variables, even though they're
	// set. Maybe this isn't neccesary at all?
	//

	double Offset1st;

};
