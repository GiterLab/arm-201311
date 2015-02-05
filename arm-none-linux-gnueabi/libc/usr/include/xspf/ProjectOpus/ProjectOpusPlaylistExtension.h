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
 * @file ProjectOpusPlaylistExtension.h
 * Interface of ProjectOpusPlaylistExtension.
 */

#ifndef XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_H
#define XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_H


#include "../XspfExtension.h"

namespace Xspf {
namespace ProjectOpus {


#define PROJECT_OPUS_NS_HOME      _PT("http://www.projectopus.com")  ///< Project Opus namespace URI
#define PROJECT_OPUS_NS_HOME_LEN  26                                 ///< Project Opus namespace URI string length


/**
 * Specifies a playlist type.
 */
enum ProjectOpusPlaylistType {
	TYPE_PLAYLIST, ///< Playlist is a regular playlist
	TYPE_ALBUM ///< Playlist is an album
};


class ProjectOpusPlaylistExtensionPrivate;


/**
 * Represents a Project Opus playlist extension.
 */
class ProjectOpusPlaylistExtension : public XspfExtension {

private:
	/// @cond DOXYGEN_NON_API
	ProjectOpusPlaylistExtensionPrivate * const d; ///< D pointer
	/// @endcond

public:
	/**
	 * Creates a new Project Opus playlist extension.
	 */
	ProjectOpusPlaylistExtension();

	/**
	 * Copy constructor.
	 *
	 * @param source  Source to copy from
	 */
	ProjectOpusPlaylistExtension(ProjectOpusPlaylistExtension const & source);

	/**
	 * Assignment operator.
	 *
	 * @param source  Source to copy from
	 */
	ProjectOpusPlaylistExtension & operator=(ProjectOpusPlaylistExtension const & source);

	/**
	 * Destroys this extension.
	 */
	~ProjectOpusPlaylistExtension();

	/**
	 * Returns the type of the playlist.
	 *
	 * @return	Playlist type
	 */
	ProjectOpusPlaylistType getType() const;

	/**
	 * Returns the node ID.
	 *
	 * @return	Node ID
	 */
	unsigned int getNodeId() const;

	/**
	 * Sets the playlist type.
	 *
	 * @param type	Playlist type to set
	 */
	void setType(ProjectOpusPlaylistType type);

	/**
	 * Sets the playlist type.
	 *
	 * @param nodeId	Playlist type to set
	 */
	void setNodeId(unsigned int nodeId);

	XspfExtension * clone() const;

private:
	XspfExtensionWriter * newWriter(XspfXmlFormatter * output,
			XML_Char const * baseUri) const;

public:
	/**
	 * Returns a string representation of the given playlist type.
	 *
	 * @param type	Playlist type
	 * @return		Corresponding string
	 */
	static XML_Char const * typeToString(ProjectOpusPlaylistType type);

	/**
	 * Converts the given node ID to a string.
	 *
	 * @param nodeId	Node ID
	 * @return			Node ID string, delete on your own
	 */
	static XML_Char * nodeIdToString(unsigned int nodeId);

	static XML_Char const * const namespaceKey; ///< Namespace key pointer
	static XML_Char const * const applicationURI; ///< Application URI

};


}
}

#endif // XSPF_PROJECT_OPUS_PLAYLIST_EXTENSION_H
