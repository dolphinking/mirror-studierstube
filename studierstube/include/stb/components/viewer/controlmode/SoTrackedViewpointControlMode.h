/* ========================================================================
* Copyright (C) 2005  Graz University of Technology
*
* This framework is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This framework is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this framework; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* For further information please contact Dieter Schmalstieg under
* <schmalstieg@icg.tu-graz.ac.at> or write to Dieter Schmalstieg,
* Graz University of Technology, Inffeldgasse 16a, A8010 Graz,
* Austria.
* ========================================================================
* PROJECT: Studierstube 
* ======================================================================== */
/** The header file for the SoTrackedViewpointControlMode class.
*
* @author Denis Kalkofen
*
* $Id: SoTrackedViewpointControlMode.h 25 2005-11-28 16:11:59Z denis $
* @file                                                                   */
/* ======================================================================= */

#ifndef _SOTRACKEDVIEWPOINTCONTROLMODE_H_
#define _SOTRACKEDVIEWPOINTCONTROLMODE_H_

#include <stb/components/viewer/controlmode/SoStbCameraControlMode.h>
#include <stb/base/macros.h>


#include <Inventor/fields/SoSFString.h>
#include <Inventor/engines/SoCompose.h> 
#include <Inventor/fields/SoSFVec3f.h> 

class SoTrakEngine;

BEGIN_NAMESPACE_STB

class SoTrackedViewpointControlMode :
	public SoStbCameraControlMode
{
SO_NODE_HEADER(SoTrackedViewpointControlMode);
public:
    SoSFString stbSinkName;

    /** Inventor class initialization */
    static void initClass();

    SoTrackedViewpointControlMode();

	bool activate();

	/** Offset between head tracker and eye
	* (in tracker space).
	*/
	SoSFVec3f eyeOffset; 
    SoSFString viewpointTrackerKey;
    SoSFString viewpointTrackerValue;
protected:
    /** 
	* The destructor 
    */
    ~SoTrackedViewpointControlMode();     

	void disconnectHeadTracker();
	void connectHeadTracker(SoSFVec3f *trackerTranslation, SoSFRotation *trackerRotation);
	void connectHeadTrackerStep2(SoComposeMatrix *ctw);
    void connectHeadTracker(SoTrakEngine *tracker);
    SoTrakEngine* tre;
};

END_NAMESPACE_STB

//----------------------------------------------------------------------------
#endif//_SOTRACKEDVIEWPOINTCONTROLMODE_H_

