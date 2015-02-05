/*
 * libxspf - XSPF playlist handling library
 *
 * Copyright (C) 2006-2008, Sebastian Pipping / Xiph.Org Foundation
 * All rights reserved.
 *
 * Redistribution  and use in source and binary forms, with or without
 * modification,  are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions   of  source  code  must  retain  the   above
 *       copyright  notice, this list of conditions and the  following
 *       disclaimer.
 *
 *     * Redistributions  in  binary  form must  reproduce  the  above
 *       copyright  notice, this list of conditions and the  following
 *       disclaimer   in  the  documentation  and/or  other  materials
 *       provided with the distribution.
 *
 *     * Neither  the name of the Xiph.Org Foundation nor the names of
 *       its  contributors may be used to endorse or promote  products
 *       derived  from  this software without specific  prior  written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT  NOT
 * LIMITED  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS
 * FOR  A  PARTICULAR  PURPOSE ARE DISCLAIMED. IN NO EVENT  SHALL  THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL,    SPECIAL,   EXEMPLARY,   OR   CONSEQUENTIAL   DAMAGES
 * (INCLUDING,  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT  LIABILITY,  OR  TORT (INCLUDING  NEGLIGENCE  OR  OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Sebastian Pipping, sping@xiph.org
 */

/**
 * @file ProjectOpusPlaylistExtensionWriter.h
 * Interface of ProjectOpusPlaylistExtensionWriter.
 */

#ifndef XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_WRITER_H
#define XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_WRITER_H


#include "../XspfExtensionWriter.h"

namespace Xspf {


class XspfExtension;
class XspfXmlFormatter;


namespace ProjectOpus {


class ProjectOpusPlaylistExtension;
class ProjectOpusPlaylistExtensionWriterPrivate;





/**
 * Writes a Project Opus playlist extension.
 */
class ProjectOpusPlaylistExtensionWriter : public XspfExtensionWriter {

private:
	/// @cond DOXYGEN_NON_API
	ProjectOpusPlaylistExtensionWriterPrivate * const d; ///< D pointer
	/// @endcond

public:
	/**
	 * Creates a new Project Opus playlist extension writer.
	 *
	 * @param extension		Extension to write
	 * @param output		Formatter to write to
	 * @param baseUri		Absolute base URI to reduce URIs against
	 */
	ProjectOpusPlaylistExtensionWriter(
			ProjectOpusPlaylistExtension const * extension,
			XspfXmlFormatter * output, XML_Char const * baseUri);
	/**
	 * Copy constructor.
	 *
	 * @param source  Source to copy from
	 */
	ProjectOpusPlaylistExtensionWriter(ProjectOpusPlaylistExtensionWriter const & source);

	/**
	 * Assignment operator.
	 *
	 * @param source  Source to copy from
	 */
	ProjectOpusPlaylistExtensionWriter & operator=(ProjectOpusPlaylistExtensionWriter const & source);

	/**
	 * Destroys this extension writer.
	 */
	~ProjectOpusPlaylistExtensionWriter();

private:
	void writeExtensionBody();
	XML_Char const * const * getNamespaceRegs() const;

};


}
}

#endif // XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_WRITER_H
