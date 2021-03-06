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
 * For further information please contact Denis Kalkofen under
 * <kalkofen@icg.tu-graz.ac.at> or write to Denis Kalkofen,
 * Graz University of Technology, Inffeldgasse 16a, A8010 Graz,
 * Austria.
 * ========================================================================
 * PROJECT: OpenVideo
 * ======================================================================== */
/** The header file for the DSVLSrc class.
  *
  * @author Daniel Wagner
  *
  * $Id: DSVLSrc.h 148 2006-05-26 14:53:05Z daniel $
  * @file                                                                   */
 /* ======================================================================= */


#ifndef _DSVLSRC_H
#define _DSVLSRC_H

#include <openvideo/openVideo.h>
#include <openvideo/State.h>

#ifdef ENABLE_DSVLSRC

#include <string>

#include <openvideo/Node.h>


class DSVL_VideoSource;


namespace openvideo {


class OPENVIDEO_API DSVLSrc : public openvideo::Node
{
public:
	enum {
		MAX_BUFFERS = 10
	};

	/**
	*
	*/
	DSVLSrc();	

	/**
	*
	*/
	~DSVLSrc();

	/**
	*	Sets all relevant parameters. 
	*/
	virtual bool setParameter(std::string key, std::string value);

	/**
	*	This function calls initializes the DSVL. it then opens and starts the video stream.
	*	Finally it creates a new context where it puts the video specific data on.
	*/
	virtual void init();

	/**
	*	Updates the video frame at its context object.
	*/
	virtual void process();

	/**
	*	releases the videoframe (which was previously locked by the process function.
	*/
	virtual void postProcess();

	virtual void preProcess();
	virtual void initPixelFormats();

protected:
	/// name of the DSVL config file
	std::string configFileName;


	DSVL_VideoSource* dsvlSource;

	bool flipV;
	int numBuffers;
	unsigned int updateCtr;
};


}//namespace openvideo {

#endif // ENABLE_DSVLSRC

#endif // _DSVLSRC_H
