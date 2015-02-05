/*
 * xspf_c - Simple C interface for libxspf
 *
 * Copyright (C) 2007, Ed Schouten / Xiph.Org Foundation
 * Copyright (C) 2008, Sebastian Pipping / Xiph.Org Foundation
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
 * Ed Schouten <ed@fxq.nl>
 * Sebastian Pipping <sping@xiph.org>
 */
/**
 * @file xspf_c.h
 * @brief Simple libxspf C bindings.
 */

#ifndef XSPF_C_H
#define XSPF_C_H

/**
 * @brief Linked list for values inside tracks or lists with string
 *        values.
 */
struct xspf_mvalue {
	/**
	 * @brief Value of the current list entry.
	 */
	char *value;
	/**
	 * @brief Pointer to next object in the list.
	 */
	struct xspf_mvalue *next;

	/**
	 * @brief Private data that can be freely used.
	 */
	void *pdata;
};

/**
 * @brief Single track in an XSPF list.
 */
struct xspf_track {
	/**
	 * @brief Track's creator.
	 */
	char *creator;
	/**
	 * @brief Track's display name.
	 */
	char *title;
	/**
	 * @brief Album or collection of origin.
	 */
	char *album;

	/**
	 * @brief Track duration in milliseconds.
	 */
	int duration;
	/**
	 * @brief Track number.
	 */
	int tracknum;

	/**
	 * @brief Track's file locations.
	 */
	struct xspf_mvalue *locations;
	/**
	 * @brief Unique track identifiers.
	 */
	struct xspf_mvalue *identifiers;

	/**
	 * @brief Pointer to next track.
	 */
	struct xspf_track *next;

	/**
	 * @brief Private data that can be freely used.
	 */
	void *pdata;
};

/**
 * @brief Parsed XSPF file.
 */
struct xspf_list {
	/**
	 * @brief Playlist's license.
	 */
	char *license;
	/**
	 * @brief Playlist's file location.
	 */
	char *location;
	/**
	 * @brief Playlist's unique indentifier.
	 */
	char *identifier;

	/**
	 * @brief Linked list of tracks inside the playlist.
	 */
	struct xspf_track *tracks;

	/**
	 * @brief Private data that can be freely used.
	 */
	void *pdata;
};

/**
 * @brief Easy interface for walking through tracks.
 */
#define XSPF_LIST_FOREACH_TRACK(l,t) \
    for ((t) = (l)->tracks; (t) != NULL; (t) = (t)->next)
/**
 * @brief Easy interface for walking through locations.
 */
#define XSPF_TRACK_FOREACH_LOCATION(t,l) \
    for ((l) = (t)->locations; (l) != NULL; (l) = (l)->next)
/**
 * @brief Easy interface for walking through identifiers.
 */
#define XSPF_TRACK_FOREACH_IDENTIFIER(t,i) \
    for ((i) = (t)->identifiers; (i) != NULL; (i) = (i)->next)

/**
 * @brief Parse an XSPF file by filename.
 */
struct xspf_list *xspf_parse(char const *filename, char const *baseuri);
/**
 * @brief Parse an XSPF file from memory.
 * @since 1.2.0
 */
struct xspf_list *xspf_parse_memory(char const *memory, int len_bytes, char const *baseuri);
/**
 * @brief Create a new empty XSPF playlist.
 */
struct xspf_list *xspf_new(void);
/**
 * @brief Free the parser results.
 */
void xspf_free(struct xspf_list *list);
/**
 * @brief Set or overwrite a value in the xspf_list, xspf_track or
 *        xspf_mvalue structures. Passing NULL will unset the string.
 */
void xspf_setvalue(char **str, char const *nstr);
/**
 * @brief Insert a new mvalue to the linked list before the specified
 *        one. This routine can also be used to insert a new mvalue to
 *        the end of the list (or an empty list) by passing the address
 *        of the mvalue list or the next field in the last object.
 */
struct xspf_mvalue *xspf_new_mvalue_before(
    struct xspf_mvalue **mvalue);
/**
 * @brief Insert a new track to the linked list before the specified
 *        one. This routine can also be used to insert a new track to
 *        the end of the list (or an empty list) by passing the address
 *        of the track list or the next field in the last object.
 */
struct xspf_track *xspf_new_track_before(
    struct xspf_track **track);
/**
 * @brief Write the Xspf playlist to a file.
 */
int xspf_write(struct xspf_list *list, char const *filename, char const *baseuri);

#endif /* !XSPF_C_H */
